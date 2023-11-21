#include "Card.h"
using namespace std;

namespace Records{
    Card::Card()
    : mIssuingBank("")
    , mIdentificationNum("")
    , mPassword("")
    , isAdmin(false)
    {
    }
    void Card::setIssuingBank(string inIssuingBank){
        mIssuingBank = inIssuingBank;
    }
    string Card::getIssuingBank(){
        return mIssuingBank;
    }
    void Card::setIdenficationNum(std::string inIdentificationNum){
        mIdentificationNum = inIdentificationNum;
    }
    std::string Card::getIdentificationNum(){
        return mIdentificationNum;
    }
    void Card::setPassword(string inPassword){
        mPassword = inPassword;
    }
    string Card::getPassword(){
        return mPassword;
    }
    void Card::setAdmin(){
        isAdmin = true;
    }
}