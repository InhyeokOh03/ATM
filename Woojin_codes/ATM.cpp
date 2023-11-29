#include <string>
#include "ATM.h"

using namespace std;

namespace Records{
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



}