#include "User.h"

namespace Records {

    User::User(const std::string& name) : username(name) {}

    // 카드를 추가하는 메서드 구현
    void User::addCard(Card* newCard) {
        cardlist.push_back(newCard);
    }

    // 유저 이름 설정하는 메서드 구현
    void User::setUsername(const std::string& name) {
        username = name;
    }

    // 유저 이름 반환하는 메서드 구현
    const std::string& User::getUsername() const {
        return username;
    }

    // 카드 리스트 반환하는 메서드 구현
    const std::vector<Card*>& User::getCardList() const {
        return cardlist;
    }
}
