#include <iostream>
#include <stdexcept>
#include <memory>
#include "CentralDB.h"
using namespace std;

namespace Records{
    
    CentralDB::CentralDB(){}
    ATM& CentralDB::addATM(string inBankName, string inSerialNumber, int inCashAmount, CASH inCashPossesion, bool ismul, bool isBi)
    {
        ATM theATM;
        theATM.setBankName(inBankName);
        theATM.setSerialNumber(inSerialNumber);
        theATM.setCashAmount(inCashAmount);
        theATM.setCashPossesion(inCashPossesion);
        theATM.setIsMulti(ismul);
        theATM.setIsBilingual(isBi);
        mATMs.push_back(theATM);
        return mATMs[mATMs.size()-1];
    }
    void CentralDB::addAccount(Account& inNewAccount)
    {
        mAccounts.push_back(inNewAccount);
    }
    Bank& CentralDB::addBank(string inBankName){
        Bank theBank;
        theBank.setBankName(inBankName);
        mBanks.push_back(theBank);
        return mBanks[mBanks.size()-1];
    }
    void CentralDB::displayATM() const{
        cout << "ATM list" << endl;
        cout << "-------------------" << endl;
        for (auto iter = mATMs.begin(); iter != mATMs.end(); iter++){
            iter->display();
        }
        
    }
    void CentralDB::displayAccount() const{
        cout << "Account list" << endl;
        cout << "-------------------" << endl;
        for (auto iter = mAccounts.begin(); iter != mAccounts.end(); iter++){
            iter->display();
        }
    }
    void CentralDB::displayAll() const{

    }
    bool CentralDB::IsinBank(string inBankName){
        for (auto iter = mBanks.begin(); iter != mBanks.end(); ++iter){
            if (iter->getBankName() == inBankName){
                return true;
            }
        }
        return false;
    }
}