#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include "CentralDB.h"

#define DEPOSIT_FEE_NONPRIMARY 1000
#define WITHDRAWAL_FEE_PRIMARY 1000
#define WITHDRAWAL_FEE_NONPRIMARY 2000
#define TRANSFER_FEE_BETWEEN_PRIMARY 2000
#define TRANSFER_FEE_BETWEEN_NONPRIMARY 4000
#define TRANSFER_FEE_BETWEEN_PRIMARY_AND_NONPRIMARY 3000
#define CASH_TRANSFER_FEE 5000

#define DEPOSIT 1
#define WITHDRAW 2
#define TRANSFER 3

#define MAX_WITHDRAWALS 3

using namespace std;
using namespace Records;
int displayDBMenu(CentralDB& inDB);
void DepositCashinATM(CentralDB& inDB);
void makeATM(CentralDB& inDB);
void makeAccountandCard(CentralDB& inDB, int bankNum);
void displayAdminMode(CentralDB& inDB);
void bankMode(CentralDB& inDB);
void ATMMode(CentralDB& inDB);
void ATMUI_ADMIN(CentralDB& inDB, Bank& inBank, ATM& inATM);
void KR_ATMUI_ADMIN(CentralDB& inDB, Bank& inBank, ATM& inATM);
void ATMUI(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount);
void KR_ATMUI(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount);
int ATMADMINMENU(CentralDB& inDB, string inBankName);
int KR_ATMADMINMENU(CentralDB& inDB, string inBankName);
int ATMMenu(CentralDB& inDB, string inBankName);
int KR_ATMMenu(CentralDB& inDB, string inBankName);
int bankSelect(CentralDB& inDB);
int ATMSelect(CentralDB& inDB);
void deposit(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount);
void KR_deposit(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount);
void withdraw(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount);
void KR_withdraw(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount);
void transfer(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount);
void KR_transfer(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount);
int input(CentralDB& inDB);
string input_str(CentralDB& inDB);

int main() {
    CentralDB DB;
    Bank KakaoBank = DB.addBank("KakaoBank");
    Bank ShinhanBank = DB.addBank("ShinhanBank");
    Bank TossBank = DB.addBank("TossBank");

    bool done = false;

    while(!done) {
        int selection = displayDBMenu(DB);
        switch(selection) {
        case 1: // Go to ADMINMODE
            cout << endl;
            displayAdminMode(DB);
            break;
        case 2: // Go to Bank Select
            cout << endl;
            bankMode(DB);
            break;
        case 3:
            cout << endl;
            ATMMode(DB);
            break;
        case 10:
            DB.displayATM();
            break;
        case 11:
            DB.displayAccount();
            break;
        case 12:
            DB.displayCard();
            break;
        case 0:
            done = true;
            break;
        default:
            cerr << "Unknown command." << endl;
        }
    }
}

int displayDBMenu(CentralDB& inDB) {
        int selection;
        cout << endl;
        cout << "Central Database" << endl;
        cout << "----------------" << endl;
        cout << "1) Go to AdminMode" << endl;
        cout << "2) Go to BankMode" << endl;
        cout << "3) Go to ATMMode" << endl;

        cout << "10) Display all ATMs" << endl;
        cout << "11) Display all Accounts"  << endl;
        cout << "12) Display all Cards" << endl;
        cout << "0) Quit" << endl;
        cout << endl;
        cout << "===>";
        selection = input(inDB);
        return selection;
    }

void displayAdminMode(CentralDB& inDB) {
    int selection;
    cout << endl;
    cout << "Admin Mode" << endl;
    cout << "----------------" << endl;
    cout << "1) Make New ATM" << endl;
    cout << "2) Deposit Cash to ATM" << endl;
    
    cout << "0) Back to ModeSelect" << endl;
    cout << endl;
    cout << "===>";
    selection = input(inDB);
    switch (selection) {
        case 1:
            cout<< endl;
            makeATM(inDB);
            break;
        case 2:
            cout << endl;
            DepositCashinATM(inDB);
            break;
        case 0:
            cout<< endl;
            break;
        default:
            cerr << "Unknown command." << endl;
    }
}

void bankMode(CentralDB& inDB){
    int bankNum = bankSelect(inDB);
    if (bankNum == 0){
        cout << endl;
        return;
    }
    int selection;
    cout << endl;
    cout << inDB.getBank(bankNum).getBankName() << " Account Making Service" << endl;
    cout << "----------------------" << endl;
    cout << "1) Make a Account and Card"<< endl;
    cout << "0) Back to ModeSelect" << endl;
    cout << endl;
    cout << "===>";
    selection = input(inDB);
    switch (selection) {
        case 1:
            cout << endl;
            makeAccountandCard(inDB, bankNum);
            break;
        case 0:
            cout << endl;
            break;
        default:
            cerr << "Unknown command.";
    }
}


void ATMMode(CentralDB& inDB){
    ATMSELECT:
    int SerialNum = ATMSelect(inDB);
    if (SerialNum == 0){
        return;
    }
    string SerialNumber = to_string(SerialNum);
    ATM tempATM;
    try {
        tempATM = inDB.getATM(SerialNumber);
    } catch(exception&){
        cerr << "Enter the correct Serial Number of ATM" << endl;
        goto ATMSELECT;
    }
    ATMSERVICE:

    cout << endl;
    cout << "Hello. This is " << tempATM.getBankName() << "ATM service." <<endl;
    cout << endl;
    cout << "1) Insert debit card" << endl;
    if (tempATM.IsBilingual() == true){
        cout << "2) Change language to Korean(한국어)" << endl;
    }
    cout << "0) back to menu" << endl;
    cout << "===>";

    int menuselection = input(inDB);

    if (menuselection == 0) {
        return;
    }

    if (tempATM.IsBilingual() == true && menuselection == 2){
        KOREAN:
        cout << endl;
        cout << "안녕하십니까 " << tempATM.getBankName() << "자동입출금기 서비스입니다." <<endl;
        cout << endl;
        cout << "1) 신용카드 삽입" << endl;
        if (tempATM.IsBilingual() == true){
            cout << "2) 언어를 영어로 변경(English)" << endl;
        }
        cout << "0) 메뉴로 돌아가기" << endl;
        cout << "===>";

        int KRmenuselection = input(inDB);

        if (KRmenuselection == 0) {
            return;
        }

        if (tempATM.IsBilingual() == true && KRmenuselection == 2){
            goto ATMSERVICE;
        }

        cout << "시작하려면 신용카드를 삽입해주세요. (카드 번호를 입력)" << endl;
        cout << "===>";
        string KRcardnum = input_str(inDB);

        Account KRtempaccount;
        try {
            KRtempaccount = inDB.getAccount(KRcardnum);
        } catch (exception&) {
            cout << "해당하는 카드를 찾을 수 없습니다" << endl;
            cout << "카드번호를 다시 입력해주세요" << endl;
            goto KOREAN;
        }

        cout << endl;
        int KRthreecount = 0;
        KR_VALIDATION:
        cout << "카드(계좌) 비밀번호를 입력해주세요" << endl;
        cout << "===>";

        string KRpassword = input_str(inDB);
        bool KRisAdmin = false;
        try {
            KRisAdmin = inDB.getBank(tempATM.getBankName()).getCard(KRcardnum).isadmin();
        } catch (exception&){

        }

        if (KRisAdmin){
            KR_ATMUI_ADMIN(inDB, inDB.getBank(tempATM.getBankName()), inDB.getATM(SerialNumber));
            return;
        }

        if (!tempATM.IsMulti()){
            try {
                inDB.getBank(tempATM.getBankName()).getCard(KRcardnum);
            } catch (exception&){
                cout << "에러: 허용되지 않은 카드" << endl;
                return;
            }

            if (!inDB.getBank(tempATM.getBankName()).tryLogin(KRcardnum, KRpassword)){
                cout << "에러: 당신의 카드번호 혹은 비밀번호가 다릅니다." << endl;
                cout << "연속으로 세 번 틀릴경우 세션이 종료됩니다. ["<< ++KRthreecount << " 번 틀렸습니다]" << endl;
                if (KRthreecount == 3){
                    cout << "에러: 연속으로 세 번 틀렸습니다. 세션이 종료됩니다." << endl;
                    return;
                }
                goto KR_VALIDATION;
            }
            cout << "성공적으로 ATM에 로그인 했습니다." << endl;
            KR_ATMUI(inDB, inDB.getBank(tempATM.getBankName()), inDB.getATM(SerialNumber), inDB.getBank(tempATM.getBankName()).getAccount(KRcardnum));
            return;

        } else {
            try {
                inDB.getBank(KRtempaccount.getBankName()).getCard(KRcardnum);
            } catch (exception&){
                cout << "에러: 허용되지 않은 카드" << endl;
                return;
            }

            if (!inDB.getBank(KRtempaccount.getBankName()).tryLogin(KRcardnum, KRpassword)){
                cout << "에러: 당신의 카드번호 혹은 비밀번호가 다릅니다." << endl;
                cout << "연속으로 세 번 틀릴경우 세션이 종료됩니다. ["<< ++KRthreecount << " 번 틀렸습니다]" << endl;
                if (KRthreecount == 3){
                    cout << "에러: 연속으로 세 번 틀렸습니다. 세션이 종료됩니다." << endl;
                    return;
                }
                goto KR_VALIDATION;
            }
            cout << "성공적으로 ATM에 로그인 했습니다." << endl;
            KR_ATMUI(inDB, inDB.getBank(KRtempaccount.getBankName()), inDB.getATM(SerialNumber), inDB.getAccount(KRcardnum));
            return;

        }


        cout << "성공적으로 ATM에 로그인 했습니다." << endl;
        KR_ATMUI(inDB, inDB.getBank(tempATM.getBankName()), inDB.getATM(SerialNumber), inDB.getBank(tempATM.getBankName()).getAccount(KRcardnum));
        return;
        }

    cout << "To start, Please insert your debit card. (Input your Card Number)" << endl;
    cout << "===>";
    string cardnum = input_str(inDB);

    Account tempaccount;
    try {
        tempaccount = inDB.getAccount(cardnum);
    } catch (exception&) {
        cout << "please re-enter your account number" << endl;
        goto ATMSERVICE;
    }

    cout << endl;
    int threecount = 0;
    VALIDATION:
    cout << "Enter your account(card) password." << endl;
    cout << "===>";

    string password = input_str(inDB);
    bool isAdmin = false;
    try {
        isAdmin = inDB.getBank(tempATM.getBankName()).getCard(cardnum).isadmin();
    } catch (exception&){

    }

    if (isAdmin){
        ATMUI_ADMIN(inDB, inDB.getBank(tempATM.getBankName()), inDB.getATM(SerialNumber));
        return;
    }

    if (!tempATM.IsMulti()){
        try {
            inDB.getBank(tempATM.getBankName()).getCard(cardnum);
        } catch (exception&){
            cout << "Error: Invalid Card" << endl;
            return;
        }

        if (!inDB.getBank(tempATM.getBankName()).tryLogin(cardnum, password)){
            cout << "Error: You Cannot eccess ATM because your card number or password was wrong." << endl;
            cout << "If you enter wrong password three times in a row, session will shut down. ["<< ++threecount << " times wrong]" << endl;
            if (threecount == 3){
                cout << "Error: You entered wrong password three times. Discharge the card." << endl;
                return;
            }
            goto VALIDATION;
        }
        cout << "You successfully login to ATM" << endl;
        ATMUI(inDB, inDB.getBank(tempATM.getBankName()), inDB.getATM(SerialNumber), inDB.getBank(tempATM.getBankName()).getAccount(cardnum));
        return;

    } else {
        try {
            inDB.getBank(tempaccount.getBankName()).getCard(cardnum);
        } catch (exception&){
            cout << "Error: Invalid Card" << endl;
            return;
        }

        if (!inDB.getBank(tempaccount.getBankName()).tryLogin(cardnum, password)){
            cout << "Error: You Cannot eccess ATM because your card number or password was wrong." << endl;
            cout << "If you enter wrong password three times in a row, session will shut down. ["<< ++threecount << " times wrong]" << endl;
            if (threecount == 3){
                cout << "Error: You entered wrong password three times. Discharge the card." << endl;
                return;
            }
            goto VALIDATION;
        }
        cout << "You successfully login to ATM" << endl;
        ATMUI(inDB, inDB.getBank(tempaccount.getBankName()), inDB.getATM(SerialNumber), inDB.getAccount(cardnum));
        return;

    }


    cout << "You successfully login to ATM" << endl;
    ATMUI(inDB, inDB.getBank(tempATM.getBankName()), inDB.getATM(SerialNumber), inDB.getBank(tempATM.getBankName()).getAccount(cardnum));
    return;

    
}

void ATMUI_ADMIN(CentralDB& inDB, Bank& inBank, ATM& inATM){
    bool done = false;
    while (!done) {
        int selection = ATMADMINMENU(inDB, inBank.getBankName());
        switch(selection){
            case 1:
                cout << endl;
                inATM.displaycurrTransaction();
                break;
            case 0:
                done = true;
                break;
            default:
                cerr << "unknown command" << endl;
        }
    }
}

void KR_ATMUI_ADMIN(CentralDB& inDB, Bank& inBank, ATM& inATM){
    bool done = false;
    while (!done) {
        int selection = ATMADMINMENU(inDB, inBank.getBankName());
        switch(selection){
            case 1:
                cout << endl;
                inATM.displaycurrTransaction();
                break;
            case 0:
                done = true;
                break;
            default:
                cerr << "허용되지 않은 명령" << endl;
        }
    }
}

void ATMUI(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount){
    
    bool done = false;
    while (!done){
        int selection = ATMMenu(inDB, inBank.getBankName());
        switch(selection){
            case 1:
                cout << endl;
                deposit(inDB, inBank, inATM, inAccount);
                break;
            case 2:
                cout << endl;
                withdraw(inDB, inBank, inATM, inAccount);
                break;
            case 3:
                cout << endl;
                transfer(inDB, inBank, inATM, inAccount);
                break;
            case 4:
                cout << endl;
                inAccount.display();
                break;
            case 0:
                inATM.displaylifetimeTransaction();
                inATM.resetWithdrawal();
                done = true;
                break;
            default:
                cerr << "Unknown command." << endl;
        }
    }
}

void KR_ATMUI(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount){
    
    bool done = false;
    while (!done){
        int selection = KR_ATMMenu(inDB, inBank.getBankName());
        switch(selection){
            case 1:
                cout << endl;
                KR_deposit(inDB, inBank, inATM, inAccount);
                break;
            case 2:
                cout << endl;
                KR_withdraw(inDB, inBank, inATM, inAccount);
                break;
            case 3:
                cout << endl;
                KR_transfer(inDB, inBank, inATM, inAccount);
                break;
            case 4:
                cout << endl;
                inAccount.display_KR();
                break;
            case 0:
                inATM.displaylifetimeTransaction_KR();
                done = true;
                break;
            default:
                cerr << "허용되지 않은 명령" << endl;
        }
    }
}

int ATMADMINMENU(CentralDB& inDB, string inBankName){
    int selection;
    cout << endl;
    cout << inBankName << " ATM admin service" << endl;
    cout << "-------------------------" << endl;
    cout << "1) Transaction History" << endl;
    cout << "0) Quit" << endl;
    cout << "===>";
    selection = input(inDB);
    return selection;
}

int KR_ATMADMINMENU(CentralDB& inDB, string inBankName){
    int selection;
    cout << endl;
    cout << inBankName << " 자동입출금기 관리자 서비스" << endl;
    cout << "-------------------------" << endl;
    cout << "1) 모든 거래 출력" << endl;
    cout << "0) 나가기" << endl;
    cout << "===>";
    selection = input(inDB);
    return selection;
}

int ATMMenu(CentralDB& inDB, string inBankName){
    int selection;
    cout << endl;
    cout << inBankName << " ATM service" << endl;
    cout << "-------------------------" << endl;
    cout << "1) Deposit" << endl;
    cout << "2) Withdraw" << endl;
    cout << "3) Send" << endl;
    cout << "4) Show my account info" << endl;
    cout << "0) Quit" << endl;
    cout << "===>";
    selection = input(inDB);
    return selection;
}

int KR_ATMMenu(CentralDB& inDB, string inBankName){
    int selection;
    cout << endl;
    cout << inBankName << " 자동입출금기 서비스" << endl;
    cout << "-------------------------" << endl;
    cout << "1) 입금" << endl;
    cout << "2) 출금" << endl;
    cout << "3) 송금" << endl;
    cout << "4) 계좌 정보" << endl;
    cout << "0) 나가기" << endl;
    cout << "===>";
    selection = input(inDB);
    return selection;
}

void DepositCashinATM(CentralDB& inDB){
    ATMSELECT:
    int SerialNum = ATMSelect(inDB);
    if (SerialNum == 0){
        return;
    }
    string SerialNumber = to_string(SerialNum);
    ATM tempATM;
    try {
        tempATM = inDB.getATM(SerialNumber);
    } catch(exception&){
        cerr << "Enter the correct Serial Number of ATM" << endl;
        goto ATMSELECT;
    }

    cout << "How much cash you want to deposit to atm?" << endl;
    int num50000;
    int num10000;
    int num5000;
    int num1000;

    cout << "Num of 50,000? ";
    num50000 = input(inDB);
    cout << "Num of 10,000? ";
    num10000 = input(inDB);
    cout << "Num of 5,000? ";
    num5000 = input(inDB);
    cout << "Num of 1,000? ";
    num1000 = input(inDB);

    cout << endl;
    cout << "Successfully deposited!" << endl;
    
}

void makeATM(CentralDB& inDB) {
    int banknum;
    inDB.displayBank();
    cout << "Choose number of bank ";
    banknum = input(inDB);
    int serialnum;
    try {
        serialnum = inDB.generateSerialNum(inDB.getBank(banknum).getBankUniqueNum() ,inDB.getBank(banknum).getATMCounter());
    } catch (exception&){
        cout << "return to main..." << endl;
        return;
    }

    string bankname = inDB.getBank(banknum).getBankName();

    int num50000;
    int num10000;
    int num5000;
    int num1000;

    cout << "Num of 50,000? ";
    num50000 = input(inDB);
    cout << "Num of 10,000? ";
    num10000 = input(inDB);
    cout << "Num of 5,000? ";
    num5000 = input(inDB);
    cout << "Num of 1,000? ";
    num1000 = input(inDB);

    CASH cash(num1000, num5000, num10000, num50000);

    int cashamount = cash.getTotalAmountOfMoney();

    int isMul;
    bool isMulti;

    cout << endl;
    cout << "Is this ATM Single Bank ATM or Multi Bank ATM?" << endl;
    cout << "1) Single Bank ATM" << endl;
    cout << "2) Multi Bank ATM" << endl;
    MULTICHECK:
    isMul = input(inDB);
    if (isMul == 1){
        isMulti = false;
    } else if (isMul == 2){
        isMulti = true;
    } else {
        cout << "You entered invaild number. Please enter 1 or 2."<< endl;
        goto MULTICHECK;
    }

    int isBi;
    bool isBilingual;
    cout << endl;
    cout << "Is this ATM Bilingual or Monolingual?" << endl;
    cout << "1) Bilingual" << endl;
    cout << "2) Monolingual" << endl;
    BICHECK:
    isBi = input(inDB);
    if (isBi == 1){
        isBilingual = true;
    } else if (isBi == 2) {
        isBilingual = false;
    } else {
        cout << "You entered invaild number. Please enter 1 or 2." << endl;
        goto BICHECK;
    }

    inDB.addATM(bankname, to_string(serialnum), cash, isMulti, isBilingual);
}

void makeAccountandCard(CentralDB& inDB, int bankNum){
    
    cout << endl;
    cout << "enter your name in english" << endl;
    cout << "===>";
    string username = input_str(inDB);
    
    string password;
    SETPASSWORD:
    cout << "Set your password " << endl;
    cout << "===>";
    password = input_str(inDB);
    
    if (password.length() < 6 || password.length() > 20){
        cout << "Length of Your password should be between 6 and 20." << endl;
        goto SETPASSWORD;
    }
    string repass;
    cout << "Please Rewrite your password " << endl;
    cout << "===>";
    repass = input_str(inDB);

    if (password != repass){
        cout << "Failed to Check your password." <<endl;
        cout << "Password reset." <<endl;
        cout << endl;
        goto SETPASSWORD;
    }
    bool isAdmin = false;

    if(password == "admin99"){
        isAdmin = true;
        cout << "your card set admin card" << endl;
    }

    cout << endl;
    cout << "Password Checked!" << endl;

    int CardNum;
    CardNum = inDB.generateCardNum(inDB.getBank(bankNum).getBankUniqueNum(), inDB.getBank(bankNum).getCardCounter());
    
    inDB.getBank(bankNum).addAccount(username, to_string(CardNum), password, 0);
    inDB.getBank(bankNum).addUserCard(to_string(CardNum), password, isAdmin);

    if (isAdmin){
        inDB.getBank(bankNum).getCard(to_string(CardNum)).setadmin();
    }
    cout << "Your Card and Account successfully generated!" << endl;
    cout << endl;
    cout << "Card Info" << endl;
    cout << "-----------------------------" << endl;
    cout << "Name of Account owner: " << username << endl;
    cout << "Account Num: " << CardNum << endl;
    cout << "Balance: " << 0 << endl;
    cout << "Card Num: " << CardNum << endl;
    cout << "Integrated password: " << password << endl; 
    cout << "Is admin card?: " << inDB.getBank(bankNum).getCard(to_string(CardNum)).isadmin();
}

int bankSelect(CentralDB& inDB) {
    int selection;
    cout << endl;
    cout << "Select the Bank" << endl;
    cout << "----------------" << endl;
    inDB.displayBank();

    cout << "0) Back to mode select" << endl;
    cout << endl;
    cout << "===>";
    selection = input(inDB);
    return selection;
}

int ATMSelect(CentralDB& inDB) {
    int selection;
    cout << endl;
    cout << "Select the ATM (enter the SerialNumber(SN) of ATM)" << endl;
    cout << "----------------" << endl;
    inDB.displayATMforUser();

    cout << "0) Quit" << endl;
    cout << endl;
    cout << "===>";
    selection = input(inDB);
    return selection;
}

void deposit(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount) {

    cout << "Would you like to deposit cash or check?" << endl;
    cout << "1) Cash" << endl;
    cout << "2) Check" << endl;
    cout << endl;
    string transID = to_string(inDB.generateTransNum());
    int selection = input(inDB);

    if (selection == 1){
        int num50000;
        int num10000;
        int num5000;
        int num1000;
        CASHINSERT:
        cout << "Number of 50,000? ";
        num50000 = input(inDB);
        cout << "Number of 10,000? ";
        num10000 = input(inDB);
        cout << "Number of 5,000? ";
        num5000 = input(inDB);
        cout << "Number of 1,000? ";
        num1000 = input(inDB);

        if (num1000 + num5000 + num10000 + num50000 > 50){
            cout << "You can't deposit more than 50 pieces of cash at one time." << endl;
            cout << "Please reinsert cash" << endl;
            goto CASHINSERT;
        }

        CASH inCash(num1000, num5000, num10000, num50000);
        CASH getCash = inATM.getCashPossesion();

        inATM.setCashPossesion(getCash + inCash);

        if (inAccount.getBankName() != inATM.getBankName()){
            cout << "You have to charge deposit fee for non-primary bank." << endl;
            cout << "Deposit fee: KRW " << DEPOSIT_FEE_NONPRIMARY << endl;
            cout << endl;
            DEPOSITFEE1:
            cout << "1) Charge deposit fee" << endl;
            cout << "0) Cancel deposit" << endl;

            int press = input(inDB);
            if (press == 1){
                CASH additionalcash(1, 0, 0, 0);
                inAccount.addMoney(inCash.getTotalAmountOfMoney());
                inATM.setCashPossesion(inATM.getCashPossesion() + additionalcash);
                inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, inCash.getTotalAmountOfMoney()+1000);
                inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, inCash.getTotalAmountOfMoney()+1000);
            } else if (press == 0){
                return;
            } else {
                cout << "invalid command" << endl << endl;
                goto DEPOSITFEE1;
            }
        } else{
            inAccount.addMoney(inCash.getTotalAmountOfMoney());
            inATM.setCashPossesion(inATM.getCashPossesion());
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, inCash.getTotalAmountOfMoney());
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, inCash.getTotalAmountOfMoney());
        }

        cout << "Your cash successfully deposited to your account" << endl;



    } else if (selection == 2){
        CHECKINSERT:
        cout << "How much would you like to put in a check?" <<endl;
        cout << "===>";
        int checkamount = input(inDB);

        if (checkamount < 100000){
            cout << "Error: Invalid Check" << endl;
            cout << "Please reinsert the check" << endl;
            goto CHECKINSERT;
        }

        

        

        
        cout << endl;
        
        if (inAccount.getBankName() != inATM.getBankName()){
            cout << "You have to charge deposit fee for non-primary bank." << endl;
            cout << "Deposit fee: KRW " << DEPOSIT_FEE_NONPRIMARY << endl;
            cout << endl;
            DEPOSITFEE2:
            cout << "1) Charge deposit fee" << endl;
            cout << "0) Cancel deposit" << endl;

            int press = input(inDB);
            if (press == 1){
                inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, checkamount+1000);
                inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, checkamount+1000);
                inAccount.addMoney(checkamount);
            } else if (press == 0){
                return;
            } else {
                cout << "invalid command" << endl << endl;
                goto DEPOSITFEE2;
            }
        }else{
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, checkamount);
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, checkamount);
            inAccount.addMoney(checkamount);
        }
        cout << "Your Check successfully deposited to your account." << endl;
    }

}

void KR_deposit(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount) {

    cout << "현금 혹은 수표중 어떤 것을 입금하시겠습니까?" << endl;
    cout << "1) 현금" << endl;
    cout << "2) 수표" << endl;
    cout << endl;
    string transID = to_string(inDB.generateTransNum());
    int selection = input(inDB);

    if (selection == 1){
        int num50000;
        int num10000;
        int num5000;
        int num1000;
        KR_CASHINSERT:
        cout << "몇 장의 50,000원을 넣으시겠습니까? ";
        num50000 = input(inDB);
        cout << "몇 장의 10,000원을 넣으시겠습니까? ";
        num10000 = input(inDB);
        cout << "몇 장의 5,000원을 넣으시겠습니까? ";
        num5000 = input(inDB);
        cout << "몇 장의 1,000원을 넣으시겠습니까? ";
        num1000 = input(inDB);

        if (num1000 + num5000 + num10000 + num50000 > 50){
            cout << "한 번에 50장 이상의 현금을 입금하실 수 없습니다." << endl;
            cout << "현금을 다시 넣어주세요" << endl;
            goto KR_CASHINSERT;
        }

        CASH inCash(num1000, num5000, num10000, num50000);
        CASH getCash = inATM.getCashPossesion();

        inATM.setCashPossesion(getCash + inCash);

        if (inAccount.getBankName() != inATM.getBankName()){
            cout << "타사 은행 현금 입금의 경우 수수료가 부과됩니다" << endl;
            cout << "수수료: KRW " << DEPOSIT_FEE_NONPRIMARY << endl;
            cout << endl;
            KR_DEPOSITFEE1:
            cout << "1) 입금 수수료를 지불" << endl;
            cout << "0) 입금을 취소" << endl;

            int press = input(inDB);
            if (press == 1){
                CASH additionalcash(1, 0, 0, 0);
                inAccount.addMoney(inCash.getTotalAmountOfMoney());
                inATM.setCashPossesion(inATM.getCashPossesion() + additionalcash);
                inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, inCash.getTotalAmountOfMoney()+1000);
                inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, inCash.getTotalAmountOfMoney()+1000);
            } else if (press == 0){
                return;
            } else {
                cout << "허용되지 않은 명령" << endl << endl;
                goto KR_DEPOSITFEE1;
            }
        } else{
            inAccount.addMoney(inCash.getTotalAmountOfMoney());
            inATM.setCashPossesion(inATM.getCashPossesion());
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, inCash.getTotalAmountOfMoney());
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, inCash.getTotalAmountOfMoney());
        }

        cout << "입금이 성공적으로 계좌에 반영되었습니다." << endl;



    } else if (selection == 2){
        KR_CHECKINSERT:
        cout << "수표의 금액을 입력해주세요" <<endl;
        cout << "===>";
        int checkamount = input(inDB);

        if (checkamount < 100000){
            cout << "에러: 허용되지 않은 수표입니다" << endl;
            cout << "다시 입력해주세요" << endl;
            goto KR_CHECKINSERT;
        }

        

        

        
        cout << endl;
        
        if (inAccount.getBankName() != inATM.getBankName()){
            cout << "타사 은행 수표 입금의 경우 수수료가 부과됩니다" << endl;
            cout << "수수료: KRW " << DEPOSIT_FEE_NONPRIMARY << endl;
            cout << endl;
            KR_DEPOSITFEE2:
            cout << "1) 입금 수수료를 지불" << endl;
            cout << "0) 거래를 취소" << endl;

            int press = input(inDB);
            if (press == 1){
                inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, checkamount+1000);
                inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, checkamount+1000);
                inAccount.addMoney(checkamount);

            } else if (press == 0){
                return;
            } else {
                cout << "허용되지 않은 명령" << endl << endl;
                goto KR_DEPOSITFEE2;
            }
        }else{
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, checkamount);
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, checkamount);
            inAccount.addMoney(checkamount);
        }
        cout << "입금이 성공적으로 계좌에 반영되었습니다." << endl;
    }

}

void withdraw(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount) {
    int selection;
    string transID = to_string(inDB.generateTransNum());

    CASHINPUT:
    cout << "Do you want to withdraw cash in your account?" << endl;
    cout << "1) Yes" << endl;
    cout << "0) No (Quit)" << endl;
    cout << "===>";
    selection = input(inDB);

    if (selection == 1){
        if (inATM.getCashPossesion().getTotalAmountOfMoney() == 0){
            cout << "There are no money in ATM." << endl;
            cout << "Contact administrator" << endl;
            return;
        }
        if (inATM.getWithdrawals() == 3){
            cout << "You reached withdrawal limit in this atm session. withdraw is limited to 3 times in a session" << endl;
            return; 
        }
        cout << "How much cash do you want to withdraw?" << endl;
        CASH tempcash = inATM.getCashPossesion();

        int num50000;
        int num10000;
        int num5000;
        int num1000;
    
        cout << "Number of 50,000? " << "[in ATM remain: " <<tempcash.get50000() << "]" << endl;
        num50000 = input(inDB);
        cout << "Number of 10,000? "<< "[in ATM remain: " <<tempcash.get10000() << "]" << endl;
        num10000 = input(inDB);
        cout << "Number of 5,000? "<< "[in ATM remain: " <<tempcash.get5000() << "]" << endl;
        num5000 = input(inDB);
        cout << "Number of 1,000? "<< "[in ATM remain: " <<tempcash.get1000() << "]" << endl;
        num1000 = input(inDB);

        if (num50000 > tempcash.get50000() || num10000 > tempcash.get10000() || num5000 > tempcash.get5000() || num1000 > tempcash.get1000()){
            cout << "Error: There are not enough cash in atm" << endl;
            cout << "Please re-enter the correct amount" << endl;
            goto CASHINPUT;
        }

        CASH withdrawcash(num1000, num5000, num10000, num50000);
        if (withdrawcash.getTotalAmountOfMoney() > inAccount.getAvailableMoney()){
            cout << "Error: There are not enough money in your account" << endl;
            cout << "Please re-enter the correct amount" << endl;
            cout << endl;
            goto CASHINPUT;
        }
        if (withdrawcash.getTotalAmountOfMoney() > 500000){
            cout << "The maximum amount of cash withdrawal per transaction is KRW 500,000" << endl;
            cout << endl;
            cout << endl;
            goto CASHINPUT;
        }

        if (inAccount.getBankName() != inATM.getBankName()){
            cout << "Withdraw fee is KRW" << WITHDRAWAL_FEE_NONPRIMARY << endl;
            if (withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_NONPRIMARY > inAccount.getAvailableMoney()){
                cout << "You don't have enough mouney in your account including withdraw fee." << endl;
                cout << "please re-enter the correct amount" << endl;
                cout << endl;
                goto CASHINPUT;
            }
            cout << "Automatically paid from your account" << endl;
            inAccount.subtractMoney(withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_NONPRIMARY);
            inATM.setCashPossesion(inATM.getCashPossesion() - withdrawcash);
            inATM.addWithdrawal();
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), WITHDRAW, withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_NONPRIMARY);
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), WITHDRAW, withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_NONPRIMARY);

        } else{
            cout << "Withdraw fee is KRW" << WITHDRAWAL_FEE_PRIMARY << endl;
            if (withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_PRIMARY > inAccount.getAvailableMoney()){
                cout << "You don't have enough mouney in your account including withdraw fee." << endl;
                cout << "please re-enter the correct amount" << endl;
                cout << endl;
                goto CASHINPUT;
            }
            cout << "Automatically paid from your account" << endl;
            inAccount.subtractMoney(withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_PRIMARY);
            inATM.setCashPossesion(inATM.getCashPossesion() - withdrawcash);
            inATM.addWithdrawal();
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), WITHDRAW, withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_NONPRIMARY);
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), WITHDRAW, withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_NONPRIMARY);

        }

    } else if (selection == 0) {
        return;
    } else {
        cout << "Error: invalid command" << endl;
        goto CASHINPUT;
    }

    cout << "You successfully withdraw cash" << endl;

}

void KR_withdraw(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount) {
    int selection;
    string transID = to_string(inDB.generateTransNum());

    CASHINPUT:
    cout << "계좌에서 현금을 출금 하시겠습니까?" << endl;
    cout << "1) 네" << endl;
    cout << "0) 아니오 (나가기)" << endl;
    cout << "===>";
    selection = input(inDB);

    if (selection == 1){
        if (inATM.getCashPossesion().getTotalAmountOfMoney() == 0){
            cout << "ATM에 현금이 없습니다." << endl;
            cout << "관리자에게 문의하세요" << endl;
            return;
        }
        if (inATM.getWithdrawals() == 3){
            cout << "이 세션에서 출금 한도에 도달했습니다. 출금한도: 3회" << endl;
            return; 
        }
        cout << "얼마 만큼의 현금을 출금하시겠습니까?" << endl;
        CASH tempcash = inATM.getCashPossesion();

        int num50000;
        int num10000;
        int num5000;
        int num1000;
    
        cout << "몇 장의 50,000원을 출금하시겠습니까? " << "[ATM 보유량: " <<tempcash.get50000() << "]" << endl;
        num50000 = input(inDB);
        cout << "몇 장의 10,000원을 출금하시겠습니까? "<< "[ATM 보유량: " <<tempcash.get10000() << "]" << endl;
        num10000 = input(inDB);
        cout << "몇 장의 5,000원을 출금하시겠습니까? "<< "[ATM 보유량: " <<tempcash.get5000() << "]" << endl;
        num5000 = input(inDB);
        cout << "몇 장의 1,000원을 출금하시겠습니까? "<< "[ATM 보유량: " <<tempcash.get1000() << "]" << endl;
        num1000 = input(inDB);

        if (num50000 > tempcash.get50000() || num10000 > tempcash.get10000() || num5000 > tempcash.get5000() || num1000 > tempcash.get1000()){
            cout << "ATM의 현금 보유량이 요청하신 것보다 적습니다" << endl;
            cout << "다시 입력해주세요" << endl;
            goto CASHINPUT;
        }

        CASH withdrawcash(num1000, num5000, num10000, num50000);
        if (withdrawcash.getTotalAmountOfMoney() > inAccount.getAvailableMoney()){
            cout << "에러: 계좌에 충분한 양의 돈이 없습니다" << endl;
            cout << "정확한 양을 다시 입력해 주세요" << endl;
            cout << endl;
            goto CASHINPUT;
        }
        if (withdrawcash.getTotalAmountOfMoney() > 500000){
            cout << "출금 당 최대 출금 금액은 500,000원입니다." << endl;
            cout << "올바른 금액을 입력해 주세요."<< endl;
            cout << endl;
            goto CASHINPUT;
        }

        if (inAccount.getBankName() != inATM.getBankName()){
            cout << "출금 수수료: KRW" << WITHDRAWAL_FEE_NONPRIMARY << endl;
            if (withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_NONPRIMARY > inAccount.getAvailableMoney()){
                cout << "계좌에 충분한 양의 돈이 없습니다." << endl;
                cout << "다시 입력해 주세요." << endl;
                cout << endl;
                goto CASHINPUT;
            }
            cout << "자동적으로 계좌에서 출금수수료가 부과되었습니다." << endl;
            inAccount.subtractMoney(withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_NONPRIMARY);
            inATM.setCashPossesion(inATM.getCashPossesion() - withdrawcash);
            inATM.addWithdrawal();
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), WITHDRAW, withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_NONPRIMARY);
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), WITHDRAW, withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_NONPRIMARY);

        } else{
            cout << "출금 수수료: KRW" << WITHDRAWAL_FEE_PRIMARY << endl;
            if (withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_PRIMARY > inAccount.getAvailableMoney()){
                cout << "계좌에 충분한 양의 돈이 없습니다." << endl;
                cout << "다시 입력해 주세요." << endl;
                cout << endl;
                goto CASHINPUT;
            }
            cout << "자동적으로 계좌에서 출금수수료가 부과되었습니다." << endl;
            inAccount.subtractMoney(withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_PRIMARY);
            inATM.setCashPossesion(inATM.getCashPossesion() - withdrawcash);
            inATM.addWithdrawal();
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), WITHDRAW, withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_NONPRIMARY);
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), WITHDRAW, withdrawcash.getTotalAmountOfMoney() + WITHDRAWAL_FEE_NONPRIMARY);

        }

    } else if (selection == 0) {
        return;
    } else {
        cout << "오류: 허용되지 않은 명령" << endl;
        goto CASHINPUT;
    }

    cout << "성공적으로 출금되었습니다" << endl;

}

void transfer(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount) {

    SELECT:
    cout << "Cash transfer of Fund transfer? Select one" << endl;
    cout << "1) Cash transfer" << endl;
    cout << "2) Fund transfer" << endl;
    cout << "0) Quit" << endl;
    cout << "===>";
    int selection = input(inDB);
    if (selection == 0) {
        return;
    }
    if (selection == 1 || selection == 2 || selection == 0){}
    else {
        cout << "Unknown command" << endl;
        goto SELECT;
    }

    TRANSFER_:
    cout << "Enter Account number that you want to transfer money" << endl;
    string accountto = input_str(inDB);

    try {
        inDB.getAccount(accountto);
    } catch (exception&) {
        cout << "Enter correct account number" << endl;
        goto TRANSFER_;
    }
    string tobank = inDB.getAccount(accountto).getBankName();
    string toaccount = inDB.getAccount(accountto).getAccountNumber();
    string atmbank = inATM.getBankName();
    string mybank = inAccount.getBankName();

    if (selection == 1){
        cout << "You selected Cash transfer" << endl;
        cout << "How much money you want to transfer?" << endl;
        
        int num50000;
        int num10000;
        int num5000;
        int num1000;
        cout << "Number of 50,000? ";
        num50000 = input(inDB);
        cout << "Number of 10,000? ";
        num10000 = input(inDB);
        cout << "Number of 5,000? ";
        num5000 = input(inDB);
        cout << "Number of 1,000? ";
        num1000 = input(inDB);

        CASH inCash(num1000, num5000, num10000, num50000);

        cout << "Cash transfer fee is " << CASH_TRANSFER_FEE << endl;
        cout << "Total amount of Cash that you need to insert is " << inCash.getTotalAmountOfMoney() + CASH_TRANSFER_FEE << endl;
        INSERTFEE:
        cout << endl;
        cout << "1) insert fee" << endl;
        cout << "0) Cancel transfer (back to atm menu)" << endl;
        cout << "===>";
        
        int cashselect = input(inDB);
        if (cashselect == 0) {
            cout << "transfer canceled and your cash returned" << endl;
            return; 
        } else if (cashselect == 1){
            CASHPAYMENT:
            cout << endl;
            cout << "1) Pay with 1000 x 5" << endl;
            cout << "2) Pay with 5000 x 1" << endl;
            cout << "===>";
            int payselect = input(inDB);
            if (payselect == 1) {
                CASH fee1000(5, 0, 0, 0);
                inATM.setCashPossesion(inATM.getCashPossesion() + inCash + fee1000);
            }else if ( payselect == 2 ){
                CASH fee5000(0, 1, 0, 0);
                inATM.setCashPossesion(inATM.getCashPossesion() + inCash + fee5000);
            }else {
                cout <<"Unknown command" << endl;
                goto CASHPAYMENT;
            }
            string transID = to_string(inDB.generateTransNum());

            cout << endl;
            inDB.getAccount(accountto).addMoney(inCash.getTotalAmountOfMoney());
            cout << "Your payment reflected to account!" << endl;
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), TRANSFER, inCash.getTotalAmountOfMoney());
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), TRANSFER, inCash.getTotalAmountOfMoney());
            return;

        } else {
            cout << "unknown command" << endl;
            goto INSERTFEE;
        }
        

    }else if (selection == 2){
        cout << "You selected fund transfer" << endl;
        cout << "How much money you want to transfer?" << endl;
        cout << "Your account balance: " << inAccount.getAvailableMoney() << endl;
        cout << endl;
        cout << "===>";
        int transmoney = input(inDB);

        int transfee;

        if (mybank == atmbank && tobank == atmbank){
            transfee = TRANSFER_FEE_BETWEEN_PRIMARY;
        } else if (mybank != atmbank && tobank != atmbank){
            transfee = TRANSFER_FEE_BETWEEN_NONPRIMARY;
        } else {
            transfee = TRANSFER_FEE_BETWEEN_PRIMARY_AND_NONPRIMARY;
        }

        cout << endl;
        cout << "Transfer fee is " << transfee << " and will be automatically paid with your account." << endl;
        cout << "So total amount of payment is " << transmoney + transfee << endl;
        PAYMENTCHECK:
        cout << endl;
        cout << "1) OK" << endl;
        cout << "0) Cancel transfer (back to atm menu)" << endl;
        cout << "===>";
        int transselect = input(inDB);

        if (transselect == 0){
            cout << "Transfer canceled." << endl;
            return;
        } else if (transselect == 1){
            if (inAccount.getAvailableMoney() < transmoney + transfee){
                cout << "There is not enough money in the account." << endl;
                cout << "Transfer canceled." << endl;
                return;
            }

            string transID = to_string(inDB.generateTransNum());

            inAccount.subtractMoney(transmoney + transfee);
            inDB.getAccount(accountto).addMoney(transmoney);
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), TRANSFER, transmoney);
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), TRANSFER, transmoney);
            cout << endl;
            cout << "Successfully reflected to accounts" << endl;
        } else {
            cout << "Unknown command" << endl;
            goto PAYMENTCHECK;
        }

    } 

    


}

void KR_transfer(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount) {

    SELECT:
    cout << "현금 송금, 계좌 이체 중 하나를 골라주십시오." << endl;
    cout << "1) 현금 송금" << endl;
    cout << "2) 계좌 이체" << endl;
    cout << "0) 나가기" << endl;
    cout << "===>";
    int selection = input(inDB);
    if (selection == 0) {
        return;
    }
    if (selection == 1 || selection == 2 || selection == 0){}
    else {
        cout << "에러: 허용되지 않은 명령" << endl;
        goto SELECT;
    }

    TRANSFER_:
    cout << "송금 대상 계좌의 계좌 번호를 입력해주세요" << endl;
    string accountto = input_str(inDB);

    try {
        inDB.getAccount(accountto);
    } catch (exception&) {
        cout << "입력하신 계좌를 찾을 수 없습니다." << endl;
        cout << "정확한 계좌를 입력해주세요." << endl;
        goto SELECT;
    }
    string tobank = inDB.getAccount(accountto).getBankName();
    string toaccount = inDB.getAccount(accountto).getAccountNumber();
    string atmbank = inATM.getBankName();
    string mybank = inAccount.getBankName();

    if (selection == 1){
        cout << "현금 송금을 선택하셨습니다." << endl;
        cout << "얼마 만큼의 현금을 송금하시겠습니까?" << endl;
        
        int num50000;
        int num10000;
        int num5000;
        int num1000;
        cout << "50,000원 몇 장을 송금하시겠습니까? ";
        num50000 = input(inDB);
        cout << "10,000원 몇 장을 송금하시겠습니까? ";
        num10000 = input(inDB);
        cout << "5,000원 몇 장을 송금하시겠습니까? ";
        num5000 = input(inDB);
        cout << "1,000원 몇 장을 송금하시겠습니까? ";
        num1000 = input(inDB);

        CASH inCash(num1000, num5000, num10000, num50000);

        cout << "현금 송금 수수료: " << CASH_TRANSFER_FEE << endl;
        cout << "수수료 포함 총 현금: " << inCash.getTotalAmountOfMoney() + CASH_TRANSFER_FEE << endl;
        INSERTFEE:
        cout << endl;
        cout << "1) 수수료 지불" << endl;
        cout << "0) 거래 취소 (메뉴로 돌아가기)" << endl;
        cout << "===>";
        
        int cashselect = input(inDB);
        if (cashselect == 0) {
            cout << "거래가 취소되었습니다" << endl;
            return; 
        } else if (cashselect == 1){
            CASHPAYMENT:
            cout << endl;
            cout << "1) 1000 x 5로 지불하기" << endl;
            cout << "2) 5000 x 1로 지불하기" << endl;
            cout << "===>";
            int payselect = input(inDB);
            if (payselect == 1) {
                CASH fee1000(5, 0, 0, 0);
                inATM.setCashPossesion(inATM.getCashPossesion() + inCash + fee1000);
            }else if ( payselect == 2 ){
                CASH fee5000(0, 1, 0, 0);
                inATM.setCashPossesion(inATM.getCashPossesion() + inCash + fee5000);
            }else {
                cout <<"허용되지 않은 입력입니다" << endl;
                goto CASHPAYMENT;
            }
            string transID = to_string(inDB.generateTransNum());

            cout << endl;
            inDB.getAccount(accountto).addMoney(inCash.getTotalAmountOfMoney());
            cout << "송금이 계좌에 반영되었습니다." << endl;
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), TRANSFER, inCash.getTotalAmountOfMoney());
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), TRANSFER, inCash.getTotalAmountOfMoney());
            return;

        } else {
            cout << "허용되지 않은 명령" << endl;
            goto INSERTFEE;
        }
        

    }else if (selection == 2){
        cout << "계좌 이체를 선택하셨습니다" << endl;
        cout << "계좌 이체를 원하는 금액을 입력해 주세요" << endl;
        cout << "계좌 금액: " << inAccount.getAvailableMoney() << endl;
        cout << endl;
        cout << "===>";
        int transmoney = input(inDB);

        int transfee;

        if (mybank == atmbank && tobank == atmbank){
            transfee = TRANSFER_FEE_BETWEEN_PRIMARY;
        } else if (mybank != atmbank && tobank != atmbank){
            transfee = TRANSFER_FEE_BETWEEN_NONPRIMARY;
        } else {
            transfee = TRANSFER_FEE_BETWEEN_PRIMARY_AND_NONPRIMARY;
        }

        cout << endl;
        cout << "수수료는 " << transfee << "원 입니다. 자동적으로 계좌에서 부과됩니다." << endl;
        cout << "총 필요 금액: " << transmoney + transfee << endl;
        PAYMENTCHECK:
        cout << endl;
        cout << "1) 확인" << endl;
        cout << "0) 거래 취소 (메뉴로 돌아가기)" << endl;
        cout << "===>";
        int transselect = input(inDB);

        if (transselect == 0){
            cout << "거래가 취소되었습니다" << endl;
            return;
        } else if (transselect == 1){
            if (inAccount.getAvailableMoney() < transmoney + transfee){
                cout << "계좌에 충분한 금액이 없습니다" << endl;
                cout << "거래가 취소되었습니다" << endl;
                return;
            }

            string transID = to_string(inDB.generateTransNum());

            inAccount.subtractMoney(transmoney + transfee);
            inDB.getAccount(accountto).addMoney(transmoney);
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), TRANSFER, transmoney);
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), TRANSFER, transmoney);
            cout << endl;
            cout << "성공적으로 반영되었습니다" << endl;
        } else {
            cout << "허용되지 않은 입력" << endl;
            goto PAYMENTCHECK;
        }

    } 

    
}

int input(CentralDB& inDB) {
    INPUT:
    string selection;
    cin >> selection;

    if (selection == "x") {
        //정보 출력
        inDB.displayATM();
        inDB.displayAccount();
        goto INPUT;
    } else {

        return stoi(selection);
    }
    return 0;
}

string input_str(CentralDB& inDB) {
    INPUT_STR:
    string selection;
    cin >> selection;

    if (selection == "x") {
        //정보 출력
        inDB.displayATM();
        inDB.displayAccount();
        goto INPUT_STR;
    } else {
        return selection;
    }
    return 0;
}

