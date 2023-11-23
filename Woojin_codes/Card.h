#pragma once
#include <string>

namespace Records{
    
    class Card{
        public:
            Card();
            void setIssuingBank(std::string inIssuingBank);
            std::string getIssuingBank();
            void setIdenficationNum(int inIdentificationNum);
            int getIdentificationNum();
            void setPassword(std::string inPassword);
            std::string getPassword();
            void setAdmin();
            void display() const;
        protected:
            std::string mIssuingBank;
            int mIdentificationNum;
            std::string mPassword;
            bool isAdmin;
    };
}