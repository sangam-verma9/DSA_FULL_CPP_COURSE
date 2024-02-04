#include<bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, bool> mp;
        for (auto i : wordList)
        {
            mp[i] = true;
        }
        if (mp.find(endWord) == mp.end())
            return 0;
        int strl = beginWord.length();
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        mp[beginWord] = false;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            if (front.first == endWord)
            {
                return front.second;
            }
            for (int i = 0; i < strl; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    char ch = 'a' + j;
                    string newWord = front.first;
                    newWord[i] = ch;
                    if (mp.find(newWord) != mp.end() && mp[newWord])
                    {
                        mp[newWord] = false;
                        q.push({newWord, front.second + 1});
                    }
                }
            }
        }
        return 0;
    }
};
int main() {

return 0;
}