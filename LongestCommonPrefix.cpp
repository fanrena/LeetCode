class Solution 
{
public:
    string longestCommonPrefix(vector<string>& strs) 
    {
        string result = string();
        int longest = 1000000000;
        if (strs.size() == 0) goto label;
        else if (strs.size() == 1) return strs[0];
        for (int j = 0; j < longest; j++)
        {
            int mark = 1;
            for (int i = 1; i < strs.size(); i++)
            {
                if (strs[i].size() < longest) longest = strs[i].size();
                if (strs[i][j] != strs[i - 1][j])
                {
                    mark = 0; break;
                }
                
                //cout << result[j];
            }
            if (mark == 1)result += strs[1][j];
            else goto label;
            cout << result[j];
        }

        label:return result;
    }
};