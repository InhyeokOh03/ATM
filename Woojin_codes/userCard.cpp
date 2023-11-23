#include "userCard.h"

namespace Records {
    // userCard 클래스의 생성자 정의
    userCard::userCard(const std::string& cardID, const std::string& bankName)
        : Card(cardID), bankName(bankName) {
        // 추가적인 초기화가 필요하다면 여기에 작성하세요.
    }
}