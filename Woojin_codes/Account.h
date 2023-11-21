#pragma once
#include <string>
#include <vector>
#include "Transaction.h"

namespace Records{

    class Account{
        public:
            Account();
            Transaction& addTransaction(std::string inBankName, std::string inCardNum, int inTransType, int inAmountOfMoney);
            void setBankName(std::string inBankName);
            std::string getBankName();
            void setUserName(std::string inUserName);
            std::string getUserName();
            void setAccountNumber(std::string inAccountNumber);
            std::string getAccountNumber();
            void addMoney(int inMoney);
            void subtractMoney(int outMoney);
            int getAvailableMoney();
            void display() const;


        protected:
            std::string mBankName;
            std::string mUserName;
            std::string mAccountNumber;
            int mAvailableMoney;
            std::vector<Transaction> mTransactions;
    };
}