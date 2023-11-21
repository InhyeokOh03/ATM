#pragma once
#include <string>
#include <vector>
#include "Transaction.h"
#include "Bank.h"
#include "Card.h"

namespace Records{
    typedef struct Cash{
        int numOf1000 = 0;
        int numOf5000 = 0;
        int numOf10000 = 0;
        int numOf50000 = 0;
    }CASH;

    class ATM{
        public:
            ATM();
            void userAuthorization(Card& inCard);
            void passwordCheck();
            void uDepositCash(int inCash);
            void uDepositCheck(int inCheck);
            void uWithdrawCash(int outCash);
            void uCashTransfer(int inAccountNum, int inAmountOfCash);
            void uMoneyTransfer(int inAccountNum, int inAmountOfMoney);

            Transaction& addTransaction(std::string inBankName, std::string inCardNum, int inTransType, int inAmountOfMoney);

            void setBankName(std::string inBankName);
            std::string getBankName();
            void setIsMulti(bool inIsMulti);
            bool IsMulti();
            void setSerialNumber(std::string inSerialNumber);
            std::string getSerialNumber();
            void setCashAmount(int inCashAmount);
            int getCashAmount();
            void setCashPossesion(CASH inCash);
            CASH getCashPossesion();
            void setIsBilingual(bool inIsBilingual);
            bool IsBilingual();

            void display() const;


        protected:
            std::string mBankName;
            bool isMulti;
            std::string mSerialNumber;
            int mCashAmount;
            CASH mCashPossesion;
            bool isBilingual;
            std::vector<Transaction> mTransactions;
    };
}