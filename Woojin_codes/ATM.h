#include <string>
#include <vector>
#include "Transaction.h"

namespace Records{
    typedef struct Cash{
        int numOf1000;
        int numOf5000;
        int numOf10000;
        int numOf50000;
    }CASH;

    class ATM{
        public:
            ATM();
            void userAuthorization();
            void depositCash(int inCash);
            void depositCheck(int inCheck);
            void withdrawCash(int outCash);
            

        protected:
            bool isMulti;
            std::string mSerialNumber;
            int mCashAmount;
            CASH mCashPossesion;
            bool isBilingual;
            std::vector<Transaction> mTransactions;
    };
}