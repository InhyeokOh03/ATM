#include <iostream>

#include "ATM.h"
#include "Bank.h"

namespace Records {
    ATM::ATM() {
        isMulti = false;
        mCashAmount = 0;
        mCashPossesion = {0, 0, 0, 0};
        isBilingual = false;
    }

    // 인자 확인 필요
    void ATM::userAuthorization(Card& Card) {
        /*
            ATM안에서 실행되는 함수,
            단일인지 다중인지 확인,
            단일이면 -> 특정 은행 클래스에다가 요청을 보내어 
            (getCard()는 아이디를 넣으면 카드를 가져옴)
            가져온 카드 클래스변수에서 getIssuingBank가져오면 어디서 만들었는지 확인가능
            여기서 일치하는지 확인하고 터지면 에러출력
        */
        if (isMulti) {
            std::cout << "다중 ATM입니다." << std::endl;
        }
        else {
            std::cout << "단일 ATM입니다." << std::endl;

        int cardID = Bank::getCard(Card);
        Card userCard = Bank::getCard(cardID);

        std::string issuingBank = userCard.getIssuingBank();

        std::string atmBank = Bank::mBankName;
            if (issuingBank != atmBank) {
                std::cout << "에러: 발급 은행과 ATM 소속 은행이 일치하지 않습니다." << std::endl;
            } else {
                std::cout << "발급 은행과 ATM 소속 은행이 일치합니다." << std::endl;
            }
        }
    }




    void ATM::uDepositCash(int inCash) {
        // 현금 입금 로직 구현
        // 예: 입금한 현금을 처리하는 코드
    }

    void ATM::uDepositCheck(int inCheck) {
        // 수표 입금 로직 구현
        // 예: 수표 정보를 처리하는 코드
    }

    void ATM::uWithdrawCash(int outCash) {
        // 현금 출금 로직 구현
        // 예: 출금 처리 코드
    }

    void ATM::uCashTransfer(int inAccountNum, int inAmountOfCash) {
        // 현금 이체 로직 구현
        // 예: 계좌번호와 금액을 받아 처리하는 코드
    }

    void ATM::uMoneyTransfer(int inAccountNum, int inAmountOfMoney) {
        // 금액 이체 로직 구현
        // 예: 계좌번호와 금액을 받아 처리하는 코드
    }
}
