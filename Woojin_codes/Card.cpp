#include "Card.h"
using namespace std;

namespace Records {
    // 생성자 정의
    Card::Card()
    : mCardID("")
    , mPassword("")
    , mIssuingBank("")
    , isAdmin(false)
    {
    }
    Card::Card(string cardID, bool isAdmin = false) 
    : mCardID(cardID)
    , isAdmin(isAdmin) 
    {
    }

    void Card::setCardId(string inID){
        mCardID = inID;
    }
    void Card::setPassword(string inPassword){
        mPassword = inPassword;
    }
    void Card::setIssuingBank(string bankName){
        mIssuingBank = bankName;
    }

    std::string Card::getCardID() const{
        return mCardID;
    }

    // std::string Card::getIdentificationNum() const {
    //     return identificationNum;
    // }

    std::string Card::getPassword() const{
        return mPassword;
    }

    std::string Card::getIssuingBank() const{
        return mIssuingBank;
    }

    void Card::display() const{
        cout << "Card ID: " << getCardID() << endl;
        // cout << "Identification Number: " << getCardID() << endl;
        cout << "Issuing Bank: " << getIssuingBank() << endl;
    }
}
