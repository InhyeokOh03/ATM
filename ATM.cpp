#include <string>
#include <iostream>
#include <fstream>
#include "ATM.h"

using namespace std;

namespace Records{
    ATM::ATM()
    : mBankName("")
    , mSerialNum("")
    , isMulti(false)
    , isBilingual(false)
    , NumofWithdrawals(0)
    {
        CASH nocash;
        setCashPossesion(nocash);
    }
    ATM::ATM(string inBankName, string inSerialNum, CASH inCash, bool isMul, bool isBi)
    : mBankName(inBankName)
    , mSerialNum(inSerialNum)
    , mCurrCash(inCash)
    , isMulti(isMul)
    , isBilingual(isBi)
    {
    }

    Transaction& ATM::addCurrTransaction(string inId, string inCardID, int inType, int inAmount){
        Transaction theTransaction;
        theTransaction.setTransactionID(inId);
        theTransaction.setCardNum(inCardID);
        theTransaction.setTransType(inType);
        theTransaction.setAmountOfMoney(inAmount);
        currTransaction.push_back(theTransaction);
        return currTransaction[currTransaction.size()-1];
    }

    Transaction& ATM::addLifetimeTransaction(string inId, string inCardID, int inType, int inAmount){
        Transaction theTransaction;
        theTransaction.setTransactionID(inId);
        theTransaction.setCardNum(inCardID);
        theTransaction.setTransType(inType);
        theTransaction.setAmountOfMoney(inAmount);
        lifetimeTransaction.push_back(theTransaction);
        return lifetimeTransaction[lifetimeTransaction.size()-1];
    }

    void ATM::setBankName(std::string inBankName){
        mBankName = inBankName;
    }
    std::string ATM::getBankName(){
        return mBankName;
    }
    void ATM::setSerialNumber(std::string inSerialNumber){
        mSerialNum = inSerialNumber;
    }
    std::string ATM::getSerialNumber(){
        return mSerialNum;
    }
    void ATM::setCashPossesion(CASH inCash){
        mCurrCash = inCash;
    }
    CASH ATM::getCashPossesion(){
        return mCurrCash;
    }
    void ATM::setToMulti(bool inIsMulti){
        isMulti = inIsMulti;
    }
    bool ATM::IsMulti(){
        return isMulti;
    }
    void ATM::setToBilingual(bool inIsBilingual){
        isBilingual = inIsBilingual;
    }
    bool ATM::IsBilingual(){
        return isBilingual;
    }
    void ATM::addWithdrawal(){
        NumofWithdrawals++;
    }
    void ATM::resetWithdrawal(){
        NumofWithdrawals = 0;
    }
    int ATM::getWithdrawals(){
        return NumofWithdrawals;
    }

    void ATM::display(){
        cout << "ATM [SN: " << mSerialNum << "] 남은 현금: " <<  mCurrCash.getTotalAmountOfMoney() << endl;
    }

    void ATM::displayforuser(){
        cout << "[ATM] [SN: " << mSerialNum << "] 관리 은행: " << mBankName << endl;
    }

    void ATM::displaylifetimeTransaction(){
        cout << "Your transaction in this atm session" << endl;
        cout << "-------------------------------------" << endl;
        for (auto iter = lifetimeTransaction.begin(); iter != lifetimeTransaction.end(); iter++){
            iter->printTransaction();
        }
        lifetimeTransaction.clear();
    }

    void ATM::displaylifetimeTransaction_KR(){
        cout << "현재 세션에서의 거래 목록" << endl;
        cout << "-------------------------------------" << endl;
        for (auto iter = lifetimeTransaction.begin(); iter != lifetimeTransaction.end(); iter++){
            iter->printTransaction();
        }
        lifetimeTransaction.clear();
    }

    void ATM::displaycurrTransaction(){
        cout << "Transaction History" << endl;
        cout << "-------------------" << endl;
        for (auto iter = currTransaction.begin(); iter != currTransaction.end(); iter++){
            iter->printTransaction();
        }

        string line;
        ofstream file("Transaction_History.txt");
        if(file.is_open()){
            file << "Transaction History\n";
            file << "-------------------\n";
            for (int i = 0; i<currTransaction.size(); i++){
                file << "Transaction ID: " << currTransaction[i].getTransactionID() << "\n";
                file << "Card ID: " << currTransaction[i].getCardID() << "\n";
                file << "Transaction Type: " << currTransaction[i].getTransactionType() << "\n";
                file << "Transaction Amount: " << currTransaction[i].getTransactionAmount() << "\n";
                file << "-------------------------------------\n"; 
            }
            file.close();
        } else {
            cout <<"error" << endl;
        }
    }

}