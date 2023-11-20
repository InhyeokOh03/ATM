#include "Transaction.h"
using namespace std;

namespace Records{

    Transaction::Transaction()
    : mTransactionID(-1)
    , mCardNum("")
    , mTransType(TEMP)
    , mAmountOfMoney(-1)
    {
        //transactionID임의로부여
    }

    void Transaction::setTransactionID(int inTransactionID){
        mTransactionID = inTransactionID;
        // 임의로 부여하는 기능 추가
    }
    int Transaction::getTransactionID(){
        return mTransactionID;
    }
    void Transaction::setCardNum(std::string inCardNum){
        mCardNum = inCardNum;
    }
    std::string Transaction::getCardNum(){
        return mCardNum;
    }
    void Transaction::setTransType(int inTypeNum){
        mTransType = static_cast<Ttype>(inTypeNum);
    }
    int Transaction::getTransType(){
        return mTransType;
    }
    void Transaction::setAmountOfMoney(int inMoney){
        mAmountOfMoney = inMoney;
    }
    int Transaction::getAmountOfMoney(){
        return mAmountOfMoney;
    }
}