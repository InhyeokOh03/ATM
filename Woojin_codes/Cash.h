namespace Records{
    class CASH{
        protected:
            int numOf1000;
            int numOf5000;
            int numOf10000;
            int numOf50000;
        public:
            CASH(int num1000, int num5000, int num10000, int num50000);
            CASH operator+(CASH &ref);
            int getTotalAmountOfMoney();
        
    };
}