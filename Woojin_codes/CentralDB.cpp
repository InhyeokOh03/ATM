#include <iostream>
#include <stdexcept>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "CentralDB.h"
using namespace std;

namespace Records{

    int CentralDB::static_bank_counter = 0;
    
    CentralDB::CentralDB(){}
    ATM& CentralDB::addATM(string inBankName, int inSerialNumber, int inCashAmount, CASH inCashPossesion, bool ismul, bool isBi)
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
        theBank.setBankUniqueNum(++static_bank_counter);
        mBanks.push_back(theBank);
        return mBanks[mBanks.size()-1];
    }

    int CentralDB::generateSerialNum(int inBanknum, int inATMnum){
        return (100000*inBanknum + inATMnum);
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
    void CentralDB::displayBank() const{
        cout << "Bank list" << endl;
        cout << "-------------------" << endl;
        for (auto iter = mBanks.begin(); iter != mBanks.end(); iter++){
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

    Bank& CentralDB::getBank(string inBankName){
        for (auto iter = mBanks.begin(); iter != mBanks.end(); ++iter){
            if (iter->getBankName() == inBankName){
                return *iter;
            }
        }
        cerr << "No Bank with name " << inBankName << endl;
        throw exception();
    }
    Bank& CentralDB::getBank(int inBankNum){
        for (auto iter = mBanks.begin(); iter != mBanks.end(); ++iter){
            if (iter->getBankUniqueNum() == inBankNum){
                return *iter;
            }
        }
        cerr << "No Bank with number " << inBankNum << endl;
        throw exception();
    }

}