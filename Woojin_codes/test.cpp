// #include <iostream>
// #include <string>
// #include <vector>

// #include "ATM.h"
// #include "Bank.h"
// #include "Account.h"
// #include "Card.h"
// #include "Transaction.h"

// using namespace std;

// int main() {
//     Bank Kakao = Bank("Kakao");
//     Bank Daegu = Bank("Daegu");

//     //Initial Conditions
//     bankmap.insert(pair<string, Bank*>("Kakao", &Kakao));
//     bankmap.insert(pair<string, Bank*>("Daegu", &Daegu));

//     Account* Account1 = bankmap.at("Kakao")->initAccount("Kakao", "David", "111-111-111111", "cooldavid", 5000, false);
//     Account* Account2 = bankmap.at("Daegu")->initAccount("Daegu", "Jane", "222-222-222222", "cooljane", 5000, false);
//     Account* Account3 = bankmap.at("Kakao")->initAccount("Kakao", "Kate", "333-333-333333", "coolkate", 5000, false);

//     ATM* ATM1 = new ATM("Kakao", "111111", true, true, 5000);
//     ATM* ATM2 = new ATM("Daegu", "222222", false, false, 5000);
//     ATM* ATM3 = new ATM("Daegu", "333333", false, false, 5000);

//     //Test Case : Action1
//     ATM2->execute();

//     //Test Case : Action2


//     //Test Case : Action3
//     return 0;    
// }