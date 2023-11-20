#include "Account.h"
using namespace std;
namespace Records{
    Account::Account(string BankName, string UserName, string AccountNumber, int AvailableMoney)
        : mBankName(BankName)
        , mUserName(UserName)
        , mAccountNumber(AccountNumber)
        , mAvailableMoney(AvailableMoney)
    {
    }
    Account::~Account()
    {
    }

    Transaction& Account::addTransaction(string inCardNum, int inTransType, int inAmountOfMoney)
    {
        Transaction theTransaction;
        theTransaction.setCardNum(inCardNum);
        theTransaction.setTransType(inTransType);
        theTransaction.setAmountOfMoney(inAmountOfMoney);
        mTransactions.push_back(theTransaction);
        return mTransactions[mTransactions.size()-1];
    }
    void Account::setBankName(string inBankName){
        mBankName = inBankName;
    }
    string Account::getBankName(){
        return mBankName;
    }
    void Account::setUserName(string inUserName){
        mUserName = inUserName;
    }
    string Account::getUserName(){
        return mUserName;
    }
    void Account::setAccountNumber(string inAccountNumber){
        mAccountNumber = inAccountNumber;
    }
    string Account::getAccountNumber(){
        return mAccountNumber;
    }
    void Account::addMoney(int inMoney){
        mAvailableMoney += inMoney;
    }
    void Account::subtractMoney(int outMoney){
        mAvailableMoney -= outMoney;
        //돈이 -일 경우 문제 발생. 차후 고려
    }
    int Account::getAvailableMoney(){
        return mAvailableMoney;
    }
}