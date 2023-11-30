#include "Cash.h"

namespace Records{
    CASH::CASH()
    : numOf1000(0)
    , numOf5000(0)
    , numOf10000(0)
    , numOf50000(0)
    {

    }
    CASH::CASH(int num1000, int num5000, int num10000, int num50000)
    : numOf1000(num1000)
    , numOf5000(num5000)
    , numOf10000(num10000)
    , numOf50000(num50000)
    {
    }
    int CASH::get1000(){
        return numOf1000;
    }
    int CASH::get5000(){
        return numOf5000;
    }
    int CASH::get10000(){  
        return numOf10000;
    }
    int CASH::get50000(){
        return numOf50000;
    }

    CASH CASH::operator+(CASH& ref){
        CASH cash(numOf1000 + ref.get1000(), numOf5000 + ref.get5000(), numOf10000 + ref.get10000(), numOf50000 + ref.get50000());
        return cash;
    }
    CASH CASH::operator-(CASH& ref){
        CASH cash(numOf1000 - ref.get1000(), numOf5000 - ref.get5000(), numOf10000 - ref.get10000(), numOf50000 - ref.get50000());
        return cash;
    }

    int CASH::getTotalAmountOfMoney(){
        return 1000*numOf1000 + 5000*numOf5000 + 10000*numOf10000 + 50000*numOf50000;
    }

}