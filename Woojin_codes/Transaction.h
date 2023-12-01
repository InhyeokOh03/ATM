#pragma once
#include <string>

namespace Records {
    class Transaction {
    public:
        // 생성자
        Transaction();
        Transaction(std::string id, std::string cardID, int type, int amount);
           
        // 멤버 함수
        void printTransaction();
        void printTransaction_KR();
        void setTransactionID(std::string inID);
        void setCardNum(std::string cardID);
        void setTransType(int type);
        void setAmountOfMoney(int amout);
        std::string getTransactionID();
        std::string getCardID();
        std::string getTransactionType();
        int getTransactionAmount();

    protected:
        std::string transactionID; // 트랜잭션 ID
        std::string cardID; // 카드 ID
        int transactionType; // 트랜잭션 타입
        int transactionAmount; // 트랜잭션 금액
    };
}