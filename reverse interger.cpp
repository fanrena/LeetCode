class Solution 
{
public:
    int reverse(int x) 
    {
            std::cout << x << std::endl;
            int revInt = 0;
            while (x!=0)
            {
                int temp = x % 10;
                //std::cout << "temp is "<<temp <<"revInt:"<<revInt<< std::endl;
                if (revInt > 214748364 || (revInt == 21478364 && temp > 7)) return 0;
                if (revInt < -214748364 || (revInt == -21478364 && temp <-8)) return 0;
                revInt = revInt * 10 + temp;
                x = x / 10;
            }
            //std::cout << "rev is "<<revInt << std::endl;
            return revInt;
    }
};