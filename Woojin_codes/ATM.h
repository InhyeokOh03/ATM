#pragma once
#include <string>
#include <vector>
#include "Cash.h"
#include "Transaction.h"

namespace Records{
    class ATM{
        public:
            ATM();
            ATM(std::string inBankName, std::string inSerialNum, CASH inCash, bool isMulti, bool isBi);
            void printCurrTransaction() const;
            void printLifetimeTransaction() const;
            void makeTXTFile();
            Transaction& addCurrTransaction(std::string inId, std::string inCardID, int inType, int inAmount);
            Transaction& addLifetimeTransaction(std::string inId, std::string inCardID, int inType, int inAmount);
            
            void setBankName(std::string inBankName);
            std::string getBankName();
            void setSerialNumber(std::string inSerialNumber);
            std::string getSerialNumber();
            void setCashPossesion(CASH inCash);
            CASH getCashPossesion();
            void setToMulti(bool inIsMulti);
            bool IsMulti();
            void setToBilingual(bool inIsBilingual);
            bool IsBilingual();
            void addWithdrawal();
            void resetWithdrawal();
            int getWithdrawals();


            void display();
            void displayforuser();
        protected:
            std::string mBankName;
            std::string mSerialNum;
            CASH mCurrCash;
            std::vector<Transaction> currTransaction;
            std::vector<Transaction> lifetimeTransaction;
            bool isMulti;
            bool isBilingual;
            int CASHINPUTMAX;
            int CHECKINPUTMAX;
            int NumofWithdrawals;
    };
}