#include <iostream>
#include <stdexcept>
#include "Bank.h"
using namespace std;

namespace Records{

    Bank::Bank()
    : mBankName("")
    {
    }
    void Bank::makeAccount(){

    }
    void Bank::setBankName(string inBankName){
        mBankName = inBankName;
    }
    string Bank::getBankName(){
        return mBankName;
    }
    void Bank::addUserCard(Card& inNewCard){
        mUserCards.push_back(inNewCard);
    }

    Card& Bank::addUserCard(string inIdentificationNum, string inPassword, bool inIsAdmin){
        Card theCard;
        theCard.setIdenficationNum(inIdentificationNum);
        theCard.setPassword(inPassword);
        theCard.setIssuingBank(mBankName);
        mUserCards.push_back(theCard);
        return mUserCards[mUserCards.size()-1];
    }
    Card& Bank::getCard(string inIdentificationNum){
        for (auto iter = mUserCards.begin();
                iter != mUserCards.end(); ++iter){
                    if (iter->getIdentificationNum() == inIdentificationNum){
                        return *iter;
                    }
                }
        cerr << "No card with that ID" << endl;
        throw exception();
    }
    Account& Bank::addAccount(string inUserName, string inAccountNumber, int inAvailableMoney){
        Account theAccount;
        theAccount.setBankName(mBankName);
        theAccount.setUserName(inUserName);
        theAccount.setAccountNumber(inAccountNumber);
        theAccount.addMoney(inAvailableMoney);
        mAccounts.push_back(theAccount);
        return mAccounts[mAccounts.size()-1];
    }
}