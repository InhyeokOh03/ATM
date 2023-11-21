#include <string>
#include <vector>
#include "Card.h"

namespace Records{

    class Bank{
        public:
            Bank(std::string inBankName);
            void makeAccount();
            void setBankName(std::string inBankName);
            std::string getBankName();
            Card& addUserCard(std::string inIdentificationNum, std::string inPassword, bool inIsAdmin);
            Card& getCard(std::string inIdentificationNum);


        protected:
            std::string mBankName;
            std::vector<Card> mUserCards;
    };
}