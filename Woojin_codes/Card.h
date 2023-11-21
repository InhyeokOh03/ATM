#include <string>

namespace Records{
    
    class Card{
        public:
            Card();
            void setIssuingBank(std::string inIssuingBank);
            std::string getIssuingBank();
            void setIdenficationNum(std::string inIdentificationNum);
            std::string getIdentificationNum();
            void setPassword(std::string inPassword);
            std::string getPassword();
            void setAdmin();
        protected:
            std::string mIssuingBank;
            std::string mIdentificationNum;
            std::string mPassword;

            bool isAdmin;
    };
}