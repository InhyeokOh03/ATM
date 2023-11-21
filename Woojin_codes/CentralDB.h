#pragma once
#include "ATM.h"
#include "Account.h"
#include "Bank.h"

namespace Records{
    class CentralDB{
        public:
            CentralDB();
            ATM& addATM(std::string inBankName, std::string inSerialNumber, int inCashAmount, CASH inCashPossesion, bool ismul, bool isBi);
            void addAccount(Account& inNewAccount);
            Bank& addBank(std::string inBankName);
            void displayATM() const;
            void displayAccount() const;
            void displayAll() const;
            bool IsinBank(std::string inBankName);

        protected:
            std::vector<ATM> mATMs;
            std::vector<Account> mAccounts;
            std::vector<Bank> mBanks;
    };
}
