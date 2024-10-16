// https://leetcode.com/problems/number-of-wonderful-substrings/
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        vector<long long> count(1024, 0); // 2^10 to store XOR values
        long long result = 0;
        int prefixXor = 0;
        count[prefixXor] = 1;

        for (char ch : word)
        {
            int charIndex = ch - 'a';
            prefixXor ^= 1 << charIndex;
            result += count[prefixXor]; // for all character even time
            for (int i = 0; i < 10; i++)
            {
                result += count[prefixXor ^ (1 << i)];  // for one character odd time
            }
            count[prefixXor]++;
        }

        return result;
    }
};
int main()
{

    return 0;
}