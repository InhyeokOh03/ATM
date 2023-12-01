#ifndef USERCARD_H
#define USERCARD_H
#include "Card.h"

namespace Records {
    // adminCard 클래스 선언 (Card 클래스를 상속받음)
    class userCard : public Card {
    public:
        // 생성자
        userCard(std::string cardID, std::string bankName);

    protected:
        // 관리자 카드는 isAdmin이 항상 true
        std::string cardID;
        std::string bankName;
    };
}
#endif // USERCARD_H