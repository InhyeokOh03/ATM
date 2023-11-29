#include "Card.h"

namespace Records {
    // 생성자 정의
    Card::Card() : cardID(""), isAdmin(false) {
    // 추가적인 초기화나 작업이 필요하다면 여기에 작성하세요.
    }
    Card::Card(const std::string& cardID, bool isAdmin) : cardID(cardID), isAdmin(isAdmin) {
        // 생성자에서 추가적인 초기화나 작업이 필요하다면 여기에 작성하세요.
    }

    std::string Card::getCardID() const {
        return cardID;
    }

    std::string Card::getIdentificationNum() const {
        return identificationNum;
    }

    std::string Card::getPassword() const {
        return password;
    }

    std::string Card::getIssuingBank() const {
        return issuingBank;
    }

    void Card::display() const {
        std::cout << "Card ID: " << getCardID() << std::endl;
        std::cout << "Identification Number: " << getIdentificationNum() << std::endl;
        std::cout << "Issuing Bank: " << getIssuingBank() << std::endl;
    }
}
