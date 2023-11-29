#pragma once
#include "Card.h"

namespace Records {
    // adminCard 클래스 선언 (Card 클래스를 상속받음)
    class adminCard : public Card {
    public:
        // 생성자
        adminCard(const std::string& cardID);

    protected:
        // 관리자 카드는 isAdmin이 항상 true
        static const bool isAdmin = true;
    };
}