#include <iostream>
#include <stdexcept>
#include "Bank.h"
using namespace std;

namespace Records{
    Bank::Bank()
    : mBankName("")
    , mBankUniqueNum(-1)
    , mATMCounter(0)
    , mCardCounter(0)
    {
    }
    void Bank::makeAccount(User user){
		Account newaccount(user);
		mAccounts.push_back(newaccount);
    }
    void Bank::setBankName(string inBankName){
        mBankName = inBankName;
    }
    string Bank::getBankName(){
        return mBankName;
    }
    void Bank::setBankUniqueNum(int inBankUniqueNum){
        mBankUniqueNum = inBankUniqueNum;
    }
    int Bank::getBankUniqueNum(){
        return mBankUniqueNum;
    }
    void Bank::addUserCard(Card& inNewCard){
        mUserCards.push_back(inNewCard);
    }

    Card& Bank::addUserCard(int inIdentificationNum, string inPassword, bool inIsAdmin){
        Card theCard;
        theCard.setIdenficationNum(inIdentificationNum);
        theCard.setPassword(inPassword);
        theCard.setIssuingBank(mBankName);
        mUserCards.push_back(theCard);
        return mUserCards[mUserCards.size()-1];
    }
    Card& Bank::getCard(int inIdentificationNum){
        for (auto iter = mUserCards.begin();
                iter != mUserCards.end(); ++iter){
                    if (iter->getIdentificationNum() == inIdentificationNum){
                        return *iter;
                    }
                }
        cerr << "No card with that ID" << endl;
        throw exception();
    }
    Account& Bank::addAccount(string inUserName, string inAccountNumber, std::string inPassword, int inAvailableMoney){
        Account theAccount;
        theAccount.setBankName(mBankName);
        theAccount.setUserName(inUserName);
        theAccount.setAccountNumber(inAccountNumber);
        theAccount.addMoney(inAvailableMoney);
        mAccounts.push_back(theAccount);
        struct AccountInfo info;
        info.accountID = inAccountNumber;
        info.password = inPassword;
        info.account = theAccount;
        AccountInfoList.push_back(info);
        return mAccounts[mAccounts.size()-1];
    }
    int Bank::getATMCounter(){
        return ++mATMCounter;
    }
    int Bank::getCardCounter(){
        return ++mCardCounter;
    }

    void Bank::display() const{
        cout << mBankUniqueNum << ") " << mBankName << endl;
    }
    void Bank::displayCards() const{
        cout << mBankName << " Card List" << endl;
        cout << "-------------------------" << endl;
        for (auto iter = mUserCards.begin(); iter != mUserCards.end(); iter++){
            iter->display();
        }
    }
    bool Bank::tryLogin(std::string ID, std::string pw) const{
    	for(int i = 0; i< mAccounts.size(), i++):
    		if ID == AccountInfoList[i].accountID:
    			if pw == AccountInfoList[i].password:
    				return true;
    			else:
    				return false;
    		return false;
	}
	Account& Bank::getAccount(std::string accountID):
		for(int i = 0; i < mAccounts.size(),i++):
			if mAccounts[i].mAccountNumber == accountID:
				return Account;
}
