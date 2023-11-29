#include <string>
#include <vector>
#include "Cash.h"
#include "Transaction.h"

namespace Records{
    class ATM{
        public:
            ATM(std::string inBankName, std::string inSerialNum, CASH inCash, bool isMulti, bool isBi);
            void printCurrTransaction() const;
            void printLifetimeTransaction() const;
            void makeTXTFile();
            Transaction& addCurrTransaction(int inId, const std::string& inCardID, int inType, int inAmount);
            Transaction& addLifetimeTransaction(int inId, const std::string& inCardID, int inType, int inAmount);

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