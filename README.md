# ATM
OOP term project

## 개발 진척 상황
### 오인혁
**ATM.cpp**
- method
  - userAuthorization

### 김우진
**Transaction 클래스**
- 변수
  - 거래ID
  - 카드 번호
  - 거래 유형 (가능한 유형들 enum으로 선언해놓음)
  - 거래 금액
- method
  - set, get 함수
 
**Card 클래스**
- 변수
  - 발급 은행 이름
  - 식별 번호
  - 카드 비밀번호
  - 어드민 여부
- method
  - set, get 함수

**Account 클래스**
- 변수
  - 발급 은행 이름
  - 사용자 이름
  - 계좌 번호
  - 가용 금액
  - 거래 목록
- method
  - 거래 목록에 거래 추가
  - set, get 함수
  - 가용 금액 조정 함수

**Bank 클래스**
- 변수
  - 은행 이름
  - 자사 카드 목록
  - 자사 계좌 목록
- method
  - 계좌 제작
  - set, get 함수
  - 카드 목록에 카드 추가
  - 계좌 목록에 계좌 추가
 
**ATM 클래스**
- 변수
  - 다중 여부
  - 시리얼 넘버
  - 보유 현금 총 금액
  - 보유 현금 장 수
  - 양언어 여부
  - 이 ATM으로 진행된 거래 목록
