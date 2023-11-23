#include <iostream>
#include "Card.h"
using namespace std;

namespace Records{
    Card::Card()
    : mIssuingBank("")
    , mIdentificationNum(-1)
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
    void Card::setIdenficationNum(int inIdentificationNum){
        mIdentificationNum = inIdentificationNum;
    }
    int Card::getIdentificationNum(){
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
    void Card::display() const{
        cout << "Bank Name: " << mIssuingBank << endl;
        cout << "Card ID: " << mIdentificationNum << endl;
        cout << "Card PW: " << mPassword << endl;
    }
}