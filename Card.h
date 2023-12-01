#pragma once
#include <string>
#include <iostream>

namespace Records {
    class Card {
        public:
            // 생성자 선언
            Card();
            Card(std::string cardID, bool isAdmin);
            // 추가된 멤버 함수들
            void setCardId(std::string inID);
            void setPassword(std::string inPassword);
            void setIssuingBank(std::string bankName);
            void setadmin();
            bool isadmin();
            std::string getCardID() const;
            // std::string getIdentificationNum() const;
            std::string getPassword() const;
            std::string getIssuingBank() const;
            void display() const;

        protected:
            std::string mCardID; // 카드 ID
            // std::string mIdentificationNum; // 식별 번호 추가
            std::string mPassword; // 비밀번호 추가
            std::string mIssuingBank; // 발급 은행 추가
            bool isAdmin; // 관리자 여부
    };
}
