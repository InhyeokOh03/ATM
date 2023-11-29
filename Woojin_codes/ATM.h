#include <string>
#include <vector>

namespace Records{
    class ATM{
        public:
            void printCurrTransaction() const;
            void printLifetimeTransaction() const;
            void makeTXTFile();

        protected:
            std::string mBankName;
            std::string mSerialNum;
            //CASH mCurrCash;
            //std::vector<Transaction> currTransaction;
            //std::vector<Transaction> lifetimeTransaction;
            bool isMulti;
            bool isBilingual;
            int CASHINPUTMAX;
            int CHECKINPUTMAX;
    };
}