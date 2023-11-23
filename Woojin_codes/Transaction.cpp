#include "Transaction.h"
#include <iostream>

namespace Records {
    Transaction(int id, const std::string& cardID, int type, int amount)
            : transactionID(id), cardID(cardID), transactionType(type), transactionAmount(amount) {}

    // 트랜잭션 정보를 출력하는 메서드 구현
    void Transaction::printTransaction() const {
        std::cout << "Transaction ID: " << transactionID << std::endl;
        std::cout << "Card ID: " << cardID << std::endl;
        std::cout << "Transaction Type: " << transactionType << std::endl;
        std::cout << "Transaction Amount: " << transactionAmount << std::endl;
    }
}
