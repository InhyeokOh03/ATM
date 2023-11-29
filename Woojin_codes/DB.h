#pragma once
#include <string>
#include <vector>
#include "Bank.h"
#include "User.h"
namespace Records{
    class DB{
        public:
			void addBank(Bank newbank);
			void addUser(User newuser);
			Bank& getBank(std::string inBankName);
			User& getUser(std::string inUserID);
		private:
			std::vector<Bank> mBankList;
			std::vector<User> mUserList;
    };
}
