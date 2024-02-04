// leetcode ques
#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> letters;
        for (auto c : t)
            letters[c]++;

        int count = 0;
        int low = 0;
        int min_length = INT_MAX, min_start = 0;

        for (int high = 0; high < s.length(); high++)
        {
            if (letters[s[high]] > 0)
                count++;
            letters[s[high]]--;
            if (count == t.length())
            {
                while (low < high && letters[s[low]] < 0)
                {
                    letters[s[low]]++;
                    low++;
                }
                if (min_length > (high - low + 1))
                {
                    min_start = low;
                    min_length = high - low + 1;
                }
            }
        }
        if (min_length == INT_MAX)
            return "";
        return s.substr(min_start, min_length);
    }
};
int main() {

return 0;
}