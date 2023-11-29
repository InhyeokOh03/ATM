#pragma once
#include <string>

namespace Records {
    class Transaction {
    public:
        // 생성자
        Transaction();
        Transaction(int id, const std::string& cardID, int type, int amount);
           
        // 멤버 함수
        void printTransaction() const;
        void setTransactionID(int inID);
        void setCardNum(const std::string& cardID);
        void setTransType(int type);
        void setAmountOfMoney(int amout);

    protected:
        int transactionID; // 트랜잭션 ID
        std::string cardID; // 카드 ID
        int transactionType; // 트랜잭션 타입
        int transactionAmount; // 트랜잭션 금액
    };
}