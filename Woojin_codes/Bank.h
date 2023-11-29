#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Account.h"
#include "Atm.h"
#include "User.h"
namespace Records{
	struct AccountInfo{
		std::string accountID;
		std::string password;
		Account& account;
	}; 
    class Bank{
        public:
            Bank();
            void makeAccount();
            void setBankName(std::string inBankName);
            std::string getBankName();
            void setBankUniqueNum(int inBankUniqueNum);
            int getBankUniqueNum();
            void addUserCard(Card& inNewCard);
            Card& addUserCard(int inIdentificationNum, std::string inPassword, bool inIsAdmin);
            Card& getCard(int inIdentificationNum);
            Account& addAccount(std::string inUserName, std::string inAccountNumber, std::string inPassword, int inAvailableMoney);
            int getATMCounter();
            int getCardCounter();
            bool tryLogin(std::string ID, std::string pw) const;
            Account& getAccount(std::string accountID);
            void display() const;
            void displayCards() const;


        protected:
        	static int mStaticBankCounter 
            std::string mBankName;
            int mBankID
            int mBankUniqueNum;
            std::vector<Atm> mAtmList;
            std::vector<Card> mUserCards;
            std::vector<Account> mAccounts;
            int mATMCounter;
            int mCardCounter;
            std::vector<AccountInfo> AccountInfoList;
    };
}
