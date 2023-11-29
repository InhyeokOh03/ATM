#include "Transaction.h"
#include <iostream>

namespace Records {
    Transaction::Transaction() : transactionID(0), cardID(""), transactionType(0), transactionAmount(0) {}
    Transaction::Transaction(int id, const std::string& cardID, int type, int amount)
            : transactionID(id), cardID(cardID), transactionType(type), transactionAmount(amount) {}

    void Transaction::setCardNum(const std::string& cardID) {
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

    // 트랜잭션 정보를 출력하는 메서드 구현
    void Transaction::printTransaction() const {
        std::cout << "Transaction ID: " << transactionID << std::endl;
        std::cout << "Card ID: " << cardID << std::endl;
        std::cout << "Transaction Type: " << transactionType << std::endl;
        std::cout << "Transaction Amount: " << transactionAmount << std::endl;
    }
}
