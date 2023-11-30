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

using namespace std;
using namespace Records;
int displayDBMenu();
void makeATM(CentralDB& inDB);
void makeAccountandCard(CentralDB& inDB, int bankNum);
void displayAdminMode(CentralDB& inDB);
void bankMode(CentralDB& inDB);
void ATMMode(CentralDB& inDB);
void ATMUI(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount);
int ATMMenu(string inBankName);
int bankSelect(CentralDB& inDB);
int ATMSelect(CentralDB& inDB);
void deposit(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount);
void withdraw(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount);
void transfer(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount);
int input();
string input_str();

int main() {
    CentralDB DB;
    Bank KakaoBank = DB.addBank("KakaoBank");
    Bank ShinhanBank = DB.addBank("ShinhanBank");
    Bank TossBank = DB.addBank("TossBank");

    bool done = false;

    while(!done) {
        int selection = displayDBMenu();
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

int displayDBMenu() {
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
        selection = input();
        return selection;
    }

void displayAdminMode(CentralDB& inDB) {
    int selection;
    cout << endl;
    cout << "Admin Mode" << endl;
    cout << "----------------" << endl;
    cout << "1) Make New ATM" << endl;
    cout << "0) Back to ModeSelect" << endl;
    cout << endl;
    cout << "===>";
    selection = input();
    switch (selection) {
        case 1:
            cout<< endl;
            makeATM(inDB);
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
    int selection;
    cout << endl;
    cout << inDB.getBank(bankNum).getBankName() << " Account Making Service" << endl;
    cout << "----------------------" << endl;
    cout << "1) Make a Account and Card"<< endl;
    cout << "0) Back to ModeSelect" << endl;
    cout << endl;
    cout << "===>";
    selection = input();
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
    int SerialNum = ATMSelect(inDB);
    string SerialNumber = to_string(SerialNum);
    ATM tempATM = inDB.getATM(SerialNumber);
    cout << endl;
    cout << "Hello. This is " << tempATM.getBankName() << "ATM service." <<endl;
    cout << endl;
    cout << "To start, Please insert your debit card. (Input your Card Number)" << endl;
    cout << "===>";
    string cardnum = input_str();

    cout << endl;
    VALIDATION:
    cout << "Enter your account(card) password." << endl;
    cout << "===>";

    string password = input_str();

    int threecount = 0;
    
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
    }
    cout << "You successfully login to ATM" << endl;
    ATMUI(inDB, inDB.getBank(tempATM.getBankName()), inDB.getATM(SerialNumber), inDB.getBank(tempATM.getBankName()).getAccount(cardnum));

}

void ATMUI(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount){
    
    bool done = false;
    while (!done){
        int selection = ATMMenu(inBank.getBankName());
        switch(selection){
            case 1:
                cout << endl;
                // deposit
                break;
            case 2:
                cout << endl;
                // withdraw
                break;
            case 3:
                cout << endl;
                // send
                break;
            case 0:
                // lifetimetransaction 출력
                done = true;
                break;
            default:
                cerr << "Unknown command." << endl;
        }
    }
}

int ATMMenu(string inBankName){
    int selection;
    cout << endl;
    cout << inBankName << " ATM service" << endl;
    cout << "-------------------------" << endl;
    cout << "1) Deposit" << endl;
    cout << "2) Withdraw" << endl;
    cout << "3) Send" << endl;
    cout << "0) Quit" << endl;
    cout << "===>";
    selection = input();
    return selection;
}

void makeATM(CentralDB& inDB) {
    int banknum;
    inDB.displayBank();
    cout << "Choose number of bank ";
    banknum = input();
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
    num50000 = input();
    cout << "Num of 10,000? ";
    num10000 = input();
    cout << "Num of 5,000? ";
    num5000 = input();
    cout << "Num of 1,000? ";
    num1000 = input();

    CASH cash(num1000, num5000, num10000, num50000);

    int cashamount = cash.getTotalAmountOfMoney();

    int isMul;
    bool isMulti;

    cout << endl;
    cout << "Is this ATM Single Bank ATM or Multi Bank ATM?" << endl;
    cout << "1) Single Bank ATM" << endl;
    cout << "2) Multi Bank ATM" << endl;
    MULTICHECK:
    isMul = input();
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
    isBi = input();
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
    string username = input_str();
    
    string password;
    SETPASSWORD:
    cout << "Set your password " << endl;
    cout << "===>";
    password = input_str();
    
    if (password.length() < 6 || password.length() > 20){
        cout << "Length of Your password should be between 6 and 20." << endl;
        goto SETPASSWORD;
    }
    string repass;
    cout << "Please Rewrite your password " << endl;
    cout << "===>";
    repass = input_str();

    if (password != repass){
        cout << "Failed to Check your password." <<endl;
        cout << "Password reset." <<endl;
        cout << endl;
        goto SETPASSWORD;
    }
    bool isAdmin = false;

    if(password == "admin99"){
        isAdmin = true;
    }

    cout << endl;
    cout << "Password Checked!" << endl;

    int CardNum;
    CardNum = inDB.generateCardNum(inDB.getBank(bankNum).getBankUniqueNum(), inDB.getBank(bankNum).getCardCounter());
    
    inDB.getBank(bankNum).addAccount(username, to_string(CardNum), password, 0);
    inDB.getBank(bankNum).addUserCard(to_string(CardNum), password, isAdmin);
    cout << "Your Card and Account successfully generated!" << endl;
    cout << endl;
    cout << "Card Info" << endl;
    cout << "-----------------------------" << endl;
    cout << "Name of Account owner: " << username << endl;
    cout << "Account Num: " << CardNum << endl;
    cout << "Balance: " << 0 << endl;
    cout << "Card Num: " << CardNum << endl;
    cout << "Integrated password: " << password << endl; 
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
    selection = input();
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
    selection = input();
    return selection;
}

void deposit(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount) {

    cout << "Would you like to deposit cash or check?" << endl;
    cout << "1) Cash" << endl;
    cout << "2) Check" << endl;
    cout << endl;
    string transID = to_string(inDB.generateTransNum());
    int selection = input();

    if (selection == 1){
        int num50000;
        int num10000;
        int num5000;
        int num1000;
        CASHINSERT:
        cout << "Num of 50,000? ";
        num50000 = input();
        cout << "Num of 10,000? ";
        num10000 = input();
        cout << "Num of 5,000? ";
        num5000 = input();
        cout << "Num of 1,000? ";
        num1000 = input();

        if (num1000 + num5000 + num10000 + num50000 > 50){
            cout << "You can't deposit more than 50 pieces of cash at one time." << endl;
            cout << "Please reinsert cash" << endl;
            goto CASHINSERT;
        }

        CASH inCash(num1000, num5000, num10000, num50000);

        inATM.setCashPossesion(inATM.getCashPossesion() + inCash);

        if (inAccount.getBankName() != inATM.getBankName()){
            cout << "You have to charge deposit fee for non-primary bank." << endl;
            cout << "Deposit fee: KRW " << DEPOSIT_FEE_NONPRIMARY << endl;
            cout << endl;
            DEPOSITFEE1:
            cout << "1) Charge deposit fee" << endl;
            cout << "0) Cancel deposit" << endl;

            int press = input();
            if (press == 1){
                inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, inCash.getTotalAmountOfMoney()+1000);
                inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, inCash.getTotalAmountOfMoney()+1000);
            } else if (press == 0){
                return;
            } else {
                cout << "invalid command" << endl << endl;
                goto DEPOSITFEE1;
            }
        } else{
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, inCash.getTotalAmountOfMoney());
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, inCash.getTotalAmountOfMoney());
        }

        cout << "Your cash successfully deposited to your account" << endl;



    } else if (selection == 2){
        CHECKINSERT:
        cout << "How much would you like to put in a check?" <<endl;
        cout << "===>";
        int checkamount = input();

        if (checkamount < 100000){
            cout << "Error: Invalid Check" << endl;
            cout << "Please reinsert the check" << endl;
            goto CHECKINSERT;
        }

        inAccount.addMoney(checkamount);

        

        
        cout << endl;
        
        if (inAccount.getBankName() != inATM.getBankName()){
            cout << "You have to charge deposit fee for non-primary bank." << endl;
            cout << "Deposit fee: KRW " << DEPOSIT_FEE_NONPRIMARY << endl;
            cout << endl;
            DEPOSITFEE2:
            cout << "1) Charge deposit fee" << endl;
            cout << "0) Cancel deposit" << endl;

            int press = input();
            if (press == 1){
                inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, checkamount+1000);
                inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, checkamount+1000);
            } else if (press == 0){
                return;
            } else {
                cout << "invalid command" << endl << endl;
                goto DEPOSITFEE2;
            }
        }else{
            inATM.addCurrTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, checkamount);
            inATM.addLifetimeTransaction(transID, inAccount.getAccountNumber(), DEPOSIT, checkamount);
        }


        cout << "Your Check successfully deposited to your account." << endl;
    }

    

}

void withdraw(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount) {

}

void transfer(CentralDB& inDB, Bank& inBank, ATM& inATM, Account& inAccount) {

}

int input() {
    INPUT:
    string selection;
    cin >> selection;

    if (selection == "x") {
        //정보 출력
        cout << "You pressed x" << endl;
        goto INPUT;
    } else {

        return stoi(selection);
    }
    return 0;
}

string input_str() {
    INPUT_STR:
    string selection;
    cin >> selection;

    if (selection == "x") {
        //정보 출력
        cout << "You pressed x" << endl;
        goto INPUT_STR;
    } else {
        return selection;
    }
    return 0;
}

