#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include "CentralDB.h"
using namespace std;
using namespace Records;
int displayDBMenu();
void makeATM(CentralDB& inDB);

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
            cout << "This will be added. Comming Soon" << endl;
            break;
        case 10:
            DB.displayATM();
            break;
        case 11:
            DB.displayAccount();
            break;
        case 0:
            done = true;
            break;
        default:
            cerr << "Unknown command." <<endl;
        }
    }
}

int displayDBMenu(){
    int selection;
    cout << endl;
    cout << "Central Database" << endl;
    cout << "----------------" << endl;
    cout << "1) Make New ATM" << endl;
    cout << "2) Coming soon" << endl;
    cout << "10) Display all ATMs" << endl;
    cout << "11) Display all Accounts"  << endl;
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

}