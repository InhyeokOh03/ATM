#pragma once
#include "ATM.h"
#include "Account.h"
#include "Bank.h"

namespace Records{
    class CentralDB{
        public:
            CentralDB();
            ATM& addATM(std::string inBankName, std::string inSerialNumber, CASH inCashPossesion, bool ismul, bool isBi);
            void addAccount(Account& inNewAccount);
            Bank& addBank(std::string inBankName);
            int generateSerialNum(int inBanknum, int inATMnum);
            int generateCardNum(int inBanknum, int inCardnum);
            int generateTransNum();
            void displayATM();
            void displayATMforUser();
            void displayAccount() const;
            void displayBank() const;
            void displayCard() const;
            void displayAll() const;
            bool IsinBank(std::string inBankName);
            Bank& getBank(std::string inBankName);
            Bank& getBank(int inBankNum);
            ATM& getATM(std::string inSerialNum);


        protected:
            std::vector<ATM> mATMs;
            std::vector<Account> mAccounts;
            std::vector<Bank> mBanks;
            static int static_bank_counter;
            static int static_trans_counter;
    };
}
