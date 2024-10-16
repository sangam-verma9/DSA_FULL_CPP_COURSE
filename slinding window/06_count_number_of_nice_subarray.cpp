class Solution
{
    bool isvavel(char &ch)
    {
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            return true;
        return false;
    }

public:
    long long atmost(string &word, int k)
    {
        int n = word.size();
        unordered_map<char, int> mp;
        long long ans = 0;
        int conso = 0;
        int i = 0, j = 0;
        while (j < n)
        {
            if (isvavel(word[j]))
            {
                mp[word[j]]++;
            }
            else
            {
                conso++;
            }
            if (mp['a'] < 0 || mp['e'] < 0 || mp['i'] < 0 || mp['o'] < 0 || mp['u'] < 0)
            {
                j++;
                continue;
            }
            while (conso > k)
            {
                if (isvavel(word[i]))
                {
                    mp[word[i]]--;
                }
                else
                {
                    conso--;
                }
                i++;
            }
            if (mp['a'] > 0 && mp['e'] > 0 && mp['i'] > 0 && mp['o'] > 0 && mp['u'] > 0)
            {
                ans += j - i + 1 - 4 - k;
            }
            j++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k)
    {
        return atmost(word, k) - (k > 0 ? atmost(word, k - 1) : 0);
    }
};