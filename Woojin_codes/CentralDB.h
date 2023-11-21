#include "ATM.h"
#include "Account.h"

namespace Records{
    class CentralDB{
        public:
            ATM& addATM();
            Account& addAccount(std::string inBankName, std::string inUserName, std::string inAccountNumber, int inAvailableMoney);
            void displayATM() const;
            void displayAccount() const;
            void displayAll() const;

        protected:
            std::vector<ATM> mATMs;
            std::vector<Account> mAccounts;
    };
}
