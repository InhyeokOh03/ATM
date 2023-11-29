#include <string>
#include <iostream>
#include "ATM.h"

using namespace std;

namespace Records{
    ATM::ATM()
    : mBankName("")
    , mSerialNum("")
    , isMulti(false)
    , isBilingual(false)
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

    Transaction& ATM::addCurrTransaction(int inId, const std::string& inCardID, int inType, int inAmount){
        Transaction theTransaction;
        theTransaction.setCardNum(inCardID);
        theTransaction.setTransType(inType);
        theTransaction.setAmountOfMoney(inAmount);
        currTransaction.push_back(theTransaction);
        return currTransaction[currTransaction.size()-1];
    }

    Transaction& ATM::addLifetimeTransaction(int inId, const std::string& inCardID, int inType, int inAmount){
        Transaction theTransaction;
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

    void ATM::display(){
        cout << "ATM [SN: " << mSerialNum << "] 남은 현금: " <<  mCurrCash.getTotalAmountOfMoney() << endl;
    }

}