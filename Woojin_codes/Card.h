#include <string>

namespace Records{
    
    class Card{
        public:
            Card(std::string inIssuingBank, std::string inPassword, bool inIsAdmin);
            void setIssuingBank(std::string inIssuingBank);
            std::string getIssuingBank();
            void setPassword(std::string inPassword);
            std::string getPassword();
            void setAdmin();
        protected:
            std::string mIssuingBank;
            std::string mPassword;
            bool isAdmin;
    };
}