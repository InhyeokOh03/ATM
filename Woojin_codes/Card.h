#pragma once
#include <string>

namespace Records {
    class Card {
    public:
        // 생성자 선언
        Card(const std::string& cardID, bool isAdmin = false);

    protected:
        std::string cardID; // 카드 ID
        bool isAdmin; // 관리자 여부
    };
}
