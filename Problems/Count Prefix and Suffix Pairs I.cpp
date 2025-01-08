class Solution
{
public:
    bool isPrefixandSuffix(string strA, string strB)
    {
        int n = strA.length();
        int m = strB.length();
        if (n > m)
        {
            return false;
        }
        if (strA == strB.substr(0, n) &&
            strA == strB.substr(strB.size() - n, n))
        {
            return true;
        }
        return false;
    }

    int countPrefixSuffixPairs(vector<string> &words)
    {
        int count = 0;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = i; j < words.size(); j++)
            {
                if (j != i && isPrefixandSuffix(words[i], words[j]))
                {
                    count++;
                }
            }
        }
        return count;
    }
};