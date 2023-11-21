#include <iostream>
#include <stdexcept>
#include "Bank.h"
#include "Card.h"

using namespace std;
namespace Records{
    Bank::Bank(std::string inBankName)
    : mBankName(inBankName)
    {
    }
    void Bank::makeAccount(){

    }
    void Bank::setBankName(std::string inBankName){
        mBankName = inBankName;
    }
    std::string Bank::getBankName(){
        return mBankName;
    }
    Card& Bank::addUserCard(std::string inIdentificationNum, std::string inPassword, bool inIsAdmin){
        Card theCard;
        theCard.setIdenficationNum(inIdentificationNum);
        theCard.setPassword(inPassword);
        theCard.setIssuingBank(mBankName);
        mUserCards.push_back(theCard);
        return mUserCards[mUserCards.size()-1];
    }
    Card& Bank::getCard(std::string inIdentificationNum){
        for (auto iter = mUserCards.begin();
                iter != mUserCards.end(); ++iter){
                    if (iter->getIdentificationNum() == inIdentificationNum)
                        return *iter;
                }
        cerr << "No card with ID " << inIdentificationNum << endl;
        throw exception();
    }
}