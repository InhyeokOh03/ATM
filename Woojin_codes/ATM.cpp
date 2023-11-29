#include <string>
#include "ATM.h"

using namespace std;

namespace Records{
    ATM::ATM(string inBankName, string inSerialNum, bool isMul, bool isBi)
    : mBankName(inBankName)
    , mSerialNum(inSerialNum)
    , isMulti(isMul)
    , isBilingual(isBi)
    {
    }

    
}