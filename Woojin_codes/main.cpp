#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include "CentralDB.h"
using namespace std;
using namespace Records;
int displayDBMenu();
void makeATM(CentralDB& inDB);
void makeCard(CentralDB& inDB);

int main(){
    CentralDB DB;
    Bank KakaoBank = DB.addBank("KakaoBank");
    Bank ShinhanBank = DB.addBank("ShinhanBank");
    Bank TossBank = DB.addBank("TossBank");

    bool done = false;
    while(!done){
        int selection = displayDBMenu();
        switch(selection){
        case 1:
            cout << endl;
            makeATM(DB);
            break;
        case 2:
            cout << endl;
            makeCard(DB);
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
            cerr << "Unknown command." <<endl;
        }
    }
}

int modeSelect() {
    int selection;
    cout << endl;
    cout << "Select the mode" << endl;
    cout << "----------------" << endl;
    cout << "1) KakaoBank" << endl;
    cout << "2) ATM select" << endl;
    cout << "3) Bank select" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "===>";
    cin >> selection;
    return selection;
}

int ATMSelect() {
    return 0;
}

int bankSelect() {
    int selection;
    cout << endl;
    cout << "Select the mode" << endl;
    cout << "----------------" << endl;
    cout << "1) Admin Mode" << endl;
    cout << "2) ShinhanBank" << endl;
    cout << "3) TossBank" << endl;
    cout << "0) Back to mode select" << endl;
    cout << endl;
    cout << "===>";
    cin >> selection;
    return selection;
}

int displayDBMenu(){
    int selection;
    cout << endl;
    cout << "Central Database" << endl;
    cout << "----------------" << endl;
    cout << "1) Make New ATM" << endl;
    cout << "2) Make New Card" << endl;
    cout << "3) Coming soon" << endl;
    cout << "10) Display all ATMs" << endl;
    cout << "11) Display all Accounts"  << endl;
    cout << "12) Display all Cards" << endl;
    cout << "0) Quit" << endl;
    cout << endl;
    cout << "===>";
    cin >> selection;
    return selection;
}

void makeATM(CentralDB& inDB){

    int banknum;
    inDB.displayBank();
    cout << "Choose number of bank ";
    cin >> banknum;
    int serialnum;
    try {
        serialnum = inDB.generateSerialNum(inDB.getBank(banknum).getBankUniqueNum() ,inDB.getBank(banknum).getATMCounter());
    } catch (exception&){
        cout << "return to main..." << endl;
        return;
    }

    string bankname = inDB.getBank(banknum).getBankName();
   
    CASH cash;
    cout << "Num of 50,000? ";
    cin >> cash.numOf50000;
    cout << "Num of 10,000? ";
    cin >> cash.numOf10000;
    cout << "Num of 5,000? ";
    cin >> cash.numOf5000;
    cout << "Num of 1,000? ";
    cin >> cash.numOf1000;

    int cashamount = cash.numOf50000 * 50000 + cash.numOf10000 * 10000 + cash.numOf5000 * 5000 + cash.numOf1000 * 1000;

    int isMul;
    bool isMulti;

    cout << "Is this ATM Single Bank ATM or Multi Bank ATM?" << endl;
    cout << "1) Single Bank ATM" << endl;
    cout << "2) Multi Bank ATM" << endl;
    MULTICHECK:
    cin >> isMul;
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
    cout << "Is this ATM Bilingual or Monolingual?" << endl;
    cout << "1) Bilingual" << endl;
    cout << "2) Monolingual" << endl;
    BICHECK:
    cin >> isBi;
    if (isBi == 1){
        isBilingual = true;
    } else if (isBi == 2) {
        isBilingual = false;
    } else {
        cout << "You entered invaild number. Please enter 1 or 2." << endl;
        goto BICHECK;
    }

    inDB.addATM(bankname, serialnum, cashamount, cash, isMulti, isBilingual);
}

void makeCard(CentralDB& inDB){
    int banknum;
    inDB.displayBank();
    cout << "Choose number of bank ";
    cin >> banknum;
    int cardnum;
    try {
        cardnum = inDB.generateCardNum(inDB.getBank(banknum).getBankUniqueNum() ,inDB.getBank(banknum).getCardCounter());
    } catch (exception&){
        cout << "return to main..." << endl;
        return;
    }

    string bankname = inDB.getBank(banknum).getBankName();

    string password;
    SETPASSWORD:
    cout << "Set your password ";
    cin >> password;
    
    if (password.length() < 6 || password.length() > 20){
        cout << "Length of Your password should be between 6 and 20." << endl;
        goto SETPASSWORD;
    }
    string repass;
    cout << "Please Rewrite your password ";
    cin >> repass;

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

    cout << "Password Checked!" << endl;

    inDB.getBank(banknum).addUserCard(cardnum, password, isAdmin);
    //user가 카드를 소유하게 하려면, user 클래스에 카드 벡터를 만들고 거기에 추가할 수 있음.

    cout << endl;
    cout << "Your card successfully issued!" << endl;
    cout << endl;
    cout << "Information of Your card" << endl;
    cout << "------------------------" << endl;
    inDB.getBank(banknum).getCard(cardnum).display();
    cout << endl;
    cout << "Return to main..." << endl;
}