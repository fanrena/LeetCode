class Solution 
{
public:
    int romanToInt(string s) 
    {
        int result = 0;
        int mark = 0;
        for (int i = s.length()-1; i >= 0; i--)
        {
            switch (s[i])
            {
            case 'I':if (mark != 1) { result += 1; mark = 0; }
                    else if (mark == 1) { result -= mark; mark = 0; }break;
            case 'V':mark = 1; result += 5; break;
            case 'X':if (mark != 10) { result += 10; mark = 1; }
                    else if (mark == 10) { result -= mark; mark = 1; }break;
            case 'L':mark = 10; result += 50; break;
            case 'C':if (mark != 100) { result += 100; mark = 10; }
                    else if (mark == 100) { result -= mark; mark = 10; }break;
            case 'D':mark = 100; result += 500; break;
            case 'M':result += 1000; mark = 100; break;
            }
            cout << "result: " << result << endl;
        }
        return result;
    }
};