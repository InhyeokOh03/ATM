#include <iostream>
#include "ATM.h"
using namespace std;

namespace Records {
    ATM::ATM()
    : mBankName("")
    , isMulti(true)
    , mSerialNumber(-1)
    , mCashAmount(0)
    , isBilingual(false)
    {
    }
    void ATM::userAuthorization(Card& inCard){

    }
    void ATM::passwordCheck(){

    }
    void ATM::uDepositCash(int inCash){

    }
    void ATM::uDepositCheck(int inCheck){
        
    }
    void ATM::uWithdrawCash(int outCash){
        
    }
    void ATM::uCashTransfer(int inAccountNum, int inAmountOfCash){
        
    }
    void ATM::uMoneyTransfer(int inAccountNum, int inAmountOfMoney){

    }

    Transaction& ATM::addTransaction(string inBankName, string inCardNum, int inTransType, int inAmountOfMoney){
        Transaction theTransaction;
        theTransaction.setCardNum(inCardNum);
        theTransaction.setTransType(inTransType);
        theTransaction.setAmountOfMoney(inAmountOfMoney);
        mTransactions.push_back(theTransaction);
        return mTransactions[mTransactions.size()-1];
    }

    void ATM::setBankName(string inBankName){
        mBankName = inBankName;
    }
    string ATM::getBankName(){
        return mBankName;
    }
    void ATM::setIsMulti(bool inIsMulti){
        isMulti = inIsMulti;
    }
    bool ATM::IsMulti(){
        return isMulti;
    }
    void ATM::setSerialNumber(int inSerialNumber){
        mSerialNumber = inSerialNumber;
    }
    int ATM::getSerialNumber(){
        return mSerialNumber;
    }
    void ATM::setCashAmount(int inCashAmount){
        mCashAmount = inCashAmount;
    }
    int ATM::getCashAmount(){
        return mCashAmount;
    }
    void ATM::setCashPossesion(CASH inCash){
        mCashPossesion = inCash;
    }
    CASH ATM::getCashPossesion(){
        return mCashPossesion;
    }
    void ATM::setIsBilingual(bool inIsBilingual){
        isBilingual = inIsBilingual;
    }
    bool ATM::IsBilingual(){
        return isBilingual;
    }

    void ATM::display() const{
        cout << "ATM [SN: " << mSerialNumber << "] 남은 현금: " <<  mCashAmount << endl;
    }

}