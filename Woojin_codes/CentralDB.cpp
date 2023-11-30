#include <iostream>
#include <stdexcept>
#include <memory>
#include <cstdlib>
#include <ctime>
#include "CentralDB.h"
using namespace std;

namespace Records{

    int CentralDB::static_bank_counter = 0;
    int CentralDB::static_trans_counter = 0;
    
    CentralDB::CentralDB(){}
    ATM& CentralDB::addATM(string inBankName, string inSerialNumber, CASH inCashPossesion, bool ismul, bool isBi)
    {
        ATM theATM;
        theATM.setBankName(inBankName);
        theATM.setSerialNumber(inSerialNumber);
        theATM.setCashPossesion(inCashPossesion);
        theATM.setToMulti(ismul);
        theATM.setToBilingual(isBi);
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
    int CentralDB::generateCardNum(int inBanknum, int inCardnum){
        return (10000000*inBanknum + inCardnum);
    }
    int CentralDB::generateTransNum(){
        return ++static_trans_counter;
    }
    
    void CentralDB::displayATM(){
        cout << "ATM list" << endl;
        cout << "-------------------" << endl;
        for (auto iter = mATMs.begin(); iter != mATMs.end(); iter++){
            iter->display();
        }
    }
    void CentralDB::displayATMforUser(){
        cout << "ATM list" << endl;
        cout << "-------------------" << endl;
        for (auto iter = mATMs.begin(); iter != mATMs.end(); iter++){
            iter->displayforuser();
        }
    }
    void CentralDB::displayAccount() const{
        cout << "Account list" << endl;
        cout << "-------------------" << endl;
        for (auto iter = mBanks.begin(); iter != mBanks.end(); iter++){
            iter->displayAccounts();
        }
    }
    void CentralDB::displayBank() const{
        cout << "Bank list" << endl;
        cout << "-------------------" << endl;
        for (auto iter = mBanks.begin(); iter != mBanks.end(); iter++){
            iter->display();
        }
    }
    void CentralDB::displayCard() const{
        cout << "Card list" << endl;

        for (auto iter = mBanks.begin(); iter != mBanks.end(); iter++){
            cout << "-------------------" << endl;
            iter->displayCards();
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
    ATM& CentralDB::getATM(std::string inSerialNum){
        for (auto iter = mATMs.begin(); iter != mATMs.end(); ++iter){
            if (iter->getSerialNumber() == inSerialNum){
                return *iter;
            }
        }
        cerr << "No ATM with serial number " << inSerialNum << endl;
        throw exception();
    }

    Account& CentralDB::getAccount(std::string inID){
        for (int i = 0; i < mBanks.size(); i++){
            try {
                mBanks[i].getAccount(inID);
                } catch (exception&) {
                    continue;
                }
            return mBanks[i].getAccount(inID);
        }
        cerr << "No account with ID " << inID << endl;
        throw exception();
    }

}