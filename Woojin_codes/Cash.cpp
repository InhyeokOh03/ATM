#include "Cash.h"

namespace Records{
    CASH::CASH(int num1000, int num5000, int num10000, int num50000)
    : numOf1000(num1000)
    , numOf5000(num5000)
    , numOf10000(num10000)
    , numOf50000(num50000)
    {
    }

    CASH CASH::operator+(CASH &ref){
        return CASH::CASH(numOf1000 + ref.numOf1000, numOf5000 + ref.numOf5000, numOf10000 + ref.numOf10000, numOf50000 + ref.numOf50000);
    }

    int CASH::getTotalAmountOfMoney(){
        return 1000*numOf1000 + 5000*numOf5000 + 10000*numOf10000 + 50000*numOf50000;
    }
}