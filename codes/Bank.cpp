#include <iostream>
#include <vector>

using namespace std;

struct Account {
    string bankName;
    string userName;
    string accountNumber;
    double availableFunds;
};

class Bank {
    private:
        vector<Account> accounts;

    public:
        Bank(const string name);
        Bank(string name, const string con);
        ~Bank();
        void createAccount(const string& bankName, const string& userName, const string& accountNumber, double initialFunds);
        void displayAccountInfo();
        Account* findAccount(const string& accountNumber);
        void deposit(const string& accountNumber, double amount);
        void withdraw(const string& accountNumber, double amount);
};  

    void createAccount(const string& bankName, const string& userName, const string& accountNumber, double initialFunds) {
        // 계정 생성 후 벡터에 추가
        Account newAccount {bankName, userName, accountNumber, initialFunds};
        accounts.push_back(newAccount);
        cout << "새 계정이 생성되었습니다!" << endl;
    }

    // 계정 정보 표시
    void displayAccountInfo() {
        for (const auto& account : accounts) {
            cout << "은행: " << account.bankName << ", 소유자: " << account.userName
                      << ", 계좌번호: " << account.accountNumber << ", 잔액: " << account.availableFunds << endl;
        }
    }

    // 특정 계정 정보 검색
    Account* findAccount(const string& accountNumber) {
        for (auto& account : accounts) {
            if (account.accountNumber == accountNumber) {
                return &account; // 해당 계정 반환
            }
        }
        return nullptr; // 계정이 없을 경우 nullptr 반환
    }

    // 입금 기능
    void deposit(const string& accountNumber, double amount) {
        Account* account = findAccount(accountNumber);
        if (account != nullptr) {
            account->availableFunds += amount; // 입금 처리
            cout << amount << "원이 입금되었습니다." << endl;
        } else {
            cout << "계좌를 찾을 수 없습니다." << endl;
        }
    }

    // 출금 기능
    void withdraw(const string& accountNumber, double amount) {
        Account* account = findAccount(accountNumber);
        if (account != nullptr) {
            if (account->availableFunds >= amount) {
                account->availableFunds -= amount; // 출금 처리
                cout << amount << "원이 출금되었습니다." << endl;
            } else {
                cout << "잔액이 부족합니다." << endl;
            }
        } else {
            cout << "계좌를 찾을 수 없습니다." << endl;
        }
    }