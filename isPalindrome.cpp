class Solution 
{
public:
    bool isPalindrome1(int x) {
        string a = to_string(x);
        for (int i = 0; i < a.length(); i++)
        {
            cout << a[i] << " " << a[a.length() - i - 1] << endl;
            if (a[i] != a[a.length() - i-1])
                return false;
        }
        return true;
    }
    bool isPalindrome2(int x) {
        if (x >= 0) {
            int x_c = x;
            int revInt = 0;
            while (x != 0)
            {
                int temp = x % 10;
                //std::cout << "temp is "<<temp <<"revInt:"<<revInt<< std::endl;
                if (revInt > 214748364 || (revInt == 21478364 && temp > 7)) return 0;
                if (revInt < -214748364 || (revInt == -21478364 && temp < -8)) return 0;
                revInt = revInt * 10 + temp;
                x = x / 10;
            }
            if (revInt == x_c)
                return true;
        }
        else return false;
        return false;
    }
};