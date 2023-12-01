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
    void Transaction::printTransaction(){
        std::cout << "Transaction ID: " << transactionID << std::endl;
        std::cout << "Card ID: " << cardID << std::endl;
        switch(transactionType){
            case 1:
                std::cout << "Transaction Type: " << "Deposit" << std::endl;
            case 2:
                std::cout << "Transaction Type: " << "Withdraw" << std::endl;
            case 3:
                std::cout << "Transaction Type: " << "Transfer" << std::endl;
        }
        std::cout << "Transaction Amount: " << transactionAmount << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }

    void Transaction::printTransaction_KR(){
        std::cout << "거래 ID: " << transactionID << std::endl;
        std::cout << "카드 ID: " << cardID << std::endl;
        switch(transactionType){
            case 1:
                std::cout << "거래 유형: " << "입금" << std::endl;
            case 2:
                std::cout << "거래 유형: " << "출금" << std::endl;
            case 3:
                std::cout << "거래 유형: " << "송금" << std::endl;
        }
        std::cout << "거래 금액: " << transactionAmount << std::endl;
        std::cout << "-------------------------------------" << std::endl;
    }
}