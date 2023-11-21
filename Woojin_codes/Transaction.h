#pragma once
#include <string>

namespace Records{
    enum Ttype{CASHIN, CHECKIN, WITHDRAW, CASHTRANSFER, MONEYTRANSFER, TEMP = -1};

    class Transaction{
        public:
            Transaction();
            void setTransactionID(int inTransactionID);
            int getTransactionID();
            void setCardNum(std::string inCardNum);
            std::string getCardNum();
            void setTransType(int inTypeNum);
            int getTransType();
            void setAmountOfMoney(int inMoney);
            int getAmountOfMoney();
        protected:
            int mTransactionID;
            std::string mCardNum;
            enum Ttype mTransType;
            int mAmountOfMoney;
    };
}