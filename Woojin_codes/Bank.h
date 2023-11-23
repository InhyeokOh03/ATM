#pragma once
#include <string>
#include <vector>
#include "Card.h"
#include "Account.h"

namespace Records{

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
            Account& addAccount(std::string inUserName, std::string inAccountNumber, int inAvailableMoney);
            int getATMCounter();
            int getCardCounter();

            void display() const;
            void displayCards() const;


        protected:
            std::string mBankName;
            int mBankUniqueNum;
            std::vector<Card> mUserCards;
            std::vector<Account> mAccounts;
            int mATMCounter;
            int mCardCounter;
    };
}