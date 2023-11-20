#include "Card.h"
using namespace std;

namespace Records{
    Card::Card(string inIssuingBank, string inPassword, bool inIsAdmin = false)
    : mIssuingBank(inIssuingBank)
    , mPassword(inPassword)
    {
        if (inIsAdmin) { setAdmin(); }
    }
    void Card::setIssuingBank(string inIssuingBank){
        mIssuingBank = inIssuingBank;
    }
    string Card::getIssuingBank(){
        return mIssuingBank;
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