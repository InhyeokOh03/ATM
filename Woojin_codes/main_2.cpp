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
            selection = bankSelect();
            break;
        // case 10:
        //     DB.displayATM();
        //     break;
        // case 11:
        //     DB.displayAccount();
        //     break;
        // case 12:
        //     DB.displayCard();
        //     break;
        // case 0:
        //     done = true;
        //     break;
        // default:
        //     cerr << "Unknown command." << endl;
        }
    }
}

int displayDBMenu() {
        int selection;
        cout << endl;
        cout << "Central Database" << endl;
        cout << "----------------" << endl;
        cout << "1) Go to AdminMode" << endl;
        cout << "2) Go to BankSelect" << endl;
        cout << "3) Go to ATMSelect" << endl;

        cout << "10) Display all ATMs" << endl;
        cout << "11) Display all Accounts"  << endl;
        cout << "12) Display all Cards" << endl;
        cout << "0) Quit" << endl;
        cout << endl;
        cout << "===>";
        cin >> selection;
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
    cin >> selection;
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

void makeATM(CentralDB& inDB) {
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

    int num50000;
    int num10000;
    int num5000;
    int num1000;


    cout << "Num of 50,000? ";
    cin >> num50000;
    cout << "Num of 10,000? ";
    cin >> num10000;
    cout << "Num of 5,000? ";
    cin >> num5000;
    cout << "Num of 1,000? ";
    cin >> num1000;

    CASH cash(num1000, num5000, num10000, num50000);

    int cashamount = cash.getTotalAmountOfMoney();

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

    inDB.addATM(bankname, to_string(serialnum), cash, isMulti, isBilingual);
}

int bankSelect() {
    // 은행 추가 기능 구현 필요
    int selection;
    cout << endl;
    cout << "Select the mode" << endl;
    cout << "----------------" << endl;
    cout << "1) KakaoBank" << endl;
    cout << "2) ShinhanBank" << endl;
    cout << "3) TossBank" << endl;

    cout << "0) Back to mode select" << endl;
    cout << endl;
    cout << "===>";
    cin >> selection;
    return selection;
}

int ATMSelect() {
    // DB에서 ATM에 대한 정보를 만들어야 함
    int selection;
    cout << endl;
    cout << "Central Database" << endl;
    cout << "----------------" << endl;
    cout << "1) Go to AdminMode" << endl;
    cout << "2) Go to BankSelect" << endl;
    cout << "3) Go to ATMSelect" << endl;

    cout << "0) Quit" << endl;
    cout << endl;
    cout << "===>";
    cin >> selection;
    return selection;
}

int input() {
    string selection;
    cout << endl;
    cout << "===>";
    cin >> selection;

    if (selection == "x") {
        //정보 출력
    } else {
        return stoi(selection);
    }
}