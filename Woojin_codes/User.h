#pragma once
#include "Card.h"

#include <string>
#include <vector>

namespace Records { 
    class User {
        public:
            User(const std::string& name);

            // 멤버 함수
            void addCard(Card* newCard);

            // Getter 및 Setter
            const std::vector<Card*>& getCardList() const;
            void setUsername(const std::string& name);
            const std::string& getUsername() const;

        protected:
            std::vector<Card*> cardlist; 
            std::string username;
    };
}