#include "adminCard.h"

namespace Records {
    // adminCard 클래스의 생성자 정의
    adminCard::adminCard(const std::string& cardID) : Card(cardID, isAdmin) {
        // 추가적인 초기화가 필요하다면 여기에 작성하세요.
    }
}