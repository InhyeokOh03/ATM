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
            void addUserCard(Card& inNewCard);
            Card& addUserCard(std::string inIdentificationNum, std::string inPassword, bool inIsAdmin);
            Card& getCard(std::string inIdentificationNum);
            Account& addAccount(std::string inUserName, std::string inAccountNumber, int inAvailableMoney);


        protected:
            std::string mBankName;
            std::vector<Card> mUserCards;
            std::vector<Account> mAccounts;
    };
}