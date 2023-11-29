#pragma once
#include <string>
#include <iostream>

namespace Records {
    class Card {
        public:
            // 생성자 선언
            Card();
            Card(const std::string& cardID, bool isAdmin = false);
            // 추가된 멤버 함수들
            void setIdentificationNum(const std::string& inIdentificationNum);
            void setPassword(const std::string& inPassword);
            void setIssuingBank(const std::string& bankName);
            std::string getCardID() const;
            std::string getIdentificationNum() const;
            std::string getPassword() const;
            std::string getIssuingBank() const;
            void display() const;

        protected:
            std::string cardID; // 카드 ID
            std::string identificationNum; // 식별 번호 추가
            std::string password; // 비밀번호 추가
            std::string issuingBank; // 발급 은행 추가
            bool isAdmin; // 관리자 여부
    };
}
