#pragma once
#include "ATM.h"
#include "Account.h"
#include "Bank.h"

namespace Records{
    class CentralDB{
        public:
            CentralDB();
            ATM& addATM(std::string inBankName, int inSerialNumber, int inCashAmount, CASH inCashPossesion, bool ismul, bool isBi);
            void addAccount(Account& inNewAccount);
            Bank& addBank(std::string inBankName);
            int generateSerialNum(int inBanknum, int inATMnum);
            void displayATM() const;
            void displayAccount() const;
            void displayBank() const;
            void displayAll() const;
            bool IsinBank(std::string inBankName);
            Bank& getBank(std::string inBankName);
            Bank& getBank(int inBankNum);

        protected:
            std::vector<ATM> mATMs;
            std::vector<Account> mAccounts;
            std::vector<Bank> mBanks;
            static int static_bank_counter;
    };
}
