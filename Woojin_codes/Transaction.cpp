#include "Transaction.h"
#include <iostream>

namespace Records {
    Transaction::Transaction() : transactionID(""), cardID(""), transactionType(0), transactionAmount(0) {}
    Transaction::Transaction(std::string id, std::string cardID, int type, int amount)
            : transactionID(id), cardID(cardID), transactionType(type), transactionAmount(amount) {}

    void Transaction::setTransactionID(std::string inID){
        this->transactionID = inID;
    }

    void Transaction::setCardNum(std::string cardID) {
        this->cardID = cardID;
    }

    // setTransType 함수의 구현
    void Transaction::setTransType(int type) {
        this->transactionType = type;
    }

    // setAmountOfMoney 함수의 구현
    void Transaction::setAmountOfMoney(int amount) {
        this->transactionAmount = amount;
    }

    std::string Transaction::getTransactionID(){
        return transactionID;
    }
    std::string Transaction::getCardID(){
        return cardID;
    }
    std::string Transaction::getTransactionType(){
        switch(transactionType){
            case 1:
                return "Deposit";
            case 2:
                return "Withdraw";
            case 3:
                return "Transfer";
        }
        return "";
    }
    int Transaction::getTransactionAmount(){
        return transactionAmount;
    }

    // 트랜잭션 정보를 출력하는 메서드 구현
    void Transaction::printTransaction() const {
        std::cout << "Transaction ID: " << transactionID << std::endl;
        std::cout << "Card ID: " << cardID << std::endl;
        std::cout << "Transaction Type: " << transactionType << std::endl;
        std::cout << "Transaction Amount: " << transactionAmount << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }
}