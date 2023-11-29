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
            Transaction& addCurrTransaction(int inId, const std::string& inCardID, int inType, int inAmount);
            Transaction& addLifetimeTransaction(int inId, const std::string& inCardID, int inType, int inAmount);
            
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

            void display();
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
    };
}