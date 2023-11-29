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

//=====================================================================================
    ENDATM:
        cout << "Close ATM, Good Bye!!!" << endl;
        return 0;
//=====================================================================================
    MODESELECT:
        int selection = 0; // If selection is zero, the ATM goes out. 
        
        if (selection == 0) {
            goto ENDATM;
        }
//=====================================================================================
    ADMINMODE:
        // 앞으로 매번 selection입력을 받아야 함!!!!!
        if (selection == 0) {
            cout << "Back to MODESELECT" << endl;
            goto MODESELECT;
        }
    
    MAKEATM:

        if (selection == 0) {
            cout << "Back to ADMINMODE" << endl;
            goto ADMINMODE;
        }
//=====================================================================================
    BANKSELECT:
        if (selection == 0) {
            cout << "Back to MODESELECT" << endl;
            goto MODESELECT;
        }

    BANK:
        if (selection == 0) {
            cout << "Back to BANKSELECT" << endl;
            goto BANKSELECT;
        }
    // makeaccount부터는 추가로 만들다가 나갈시, 데이터를 삭제하는 작업도 필요할 듯. 아님 랄로
    MAKEACCOUNT:
        if (selection == 0) {
            cout << "Back to BANK" << endl;
            goto BANK;
        }
    
    MAKECARD:
        if (selection == 0) {
            cout << "Back to BANK" << endl;
            goto BANK;
        }

//=====================================================================================
    ATMSELECT:
        // If selection is zero, MODESELECT scene will appear.
        if (selection == 0) {
            cout << "Back to MODESELECT" << endl;
            goto MODESELECT;
        }

    ATMUI:
        if (selection == 0) {
            cout << "Back to ATMSELECT" << endl;
            goto ATMSELECT;
        }

    LANGUAGECHANGE:
        if (selection == 0) {
            cout << "Back to ATMUI" << endl;
            goto ATMUI;
        }
    
    CARDINPUT:
        // If the Card is not valid or something, MODESELECT will appear
        if (selection == 0) {
            cout << "Back to ATMUI" << endl;
            goto ATMUI;
        }
    
    ISADMIN:
        if (selection == 0) {
            cout << "Back to CARDINPUT" << endl;
            goto CARDINPUT;
        }
    
    USER:
        // 유저는 딱히 뒤로 돌아가지 않음.
        // if (selection == 0) {
        //     cout << "Back to ..." << endl;
        //     goto CARDINPUT;
        // }
    
    ASKTRANSACTIONTYPE:
        //아래 3개 종류중 골라야 함.
        if (selection == 0) {
            cout << "Back to USER" << endl;
            goto USER;
        }
    
    DEPOSIT:
        if (selection == 0) {
            cout << "Back to ASKTRANSACTIONTYPE" << endl;
            goto ASKTRANSACTIONTYPE;
        }
    
    WITHDRAWL:
        //SHOWTRANSACTION으로 갈수 있어야 함. 만약 돈이 없을 떄,
        if (selection == 0) {
            cout << "Back to ASKTRANSACTIONTYPE" << endl;
            goto ASKTRANSACTIONTYPE;
        }
    
    SEND:
        // 계좌를 물어야 한다네요.
        if (selection == 0) {
            cout << "Back to ASKTRANSACTIONTYPE" << endl;
            goto ASKTRANSACTIONTYPE;
        }
    
    CASH:
        // CASH와 check는 USER로 이동하능함.
        if (selection == 0) {
            cout << "Back to DEPOSIT" << endl;
            goto DEPOSIT;
        }
    
    CHECK:
        if (selection == 0) {
            cout << "Back to DEPOSIT" << endl;
            goto DEPOSIT;
        }
    
    CARD:
        //마찬가지로 User로 이동해야함. 끝나고 말하는 거임. 어카운트도 동일
        if (selection == 0) {
            cout << "Back to SEND" << endl;
            goto SEND;
        }
    
    ACCOUNT:
        if (selection == 0) {
            cout << "Back to SEND" << endl;
            goto SEND;
        } 
    
    SHOWTRANSACTION:
        // 선택할 필요 없음. 임무 수행 후, 바로 ATMUI로 이동.
        // if (selection == 0) {
        //     cout << "Back to SEND" << endl;
        //     goto SEND;
        // }
        goto ATMUI;
    //=====================================================================================
}