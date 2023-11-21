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
            void uDepositCash(int inCash);
            void uDepositCheck(int inCheck);
            void uWithdrawCash(int outCash);
            void uCashTransfer(int inAccountNum, int inAmountOfCash);
            void uMoneyTransfer(int inAccountNum, int inAmountOfMoney);

        protected:
            bool isMulti;
            std::string mSerialNumber;
            int mCashAmount;
            CASH mCashPossesion;
            bool isBilingual;
            std::vector<Transaction> mTransactions;
    };
}