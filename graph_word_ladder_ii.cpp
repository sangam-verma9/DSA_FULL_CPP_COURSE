class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, bool> mp;
        for (auto i : wordList)
        {
            mp[i] = true;
        }
        if (mp.find(endWord) == mp.end())
            return {};
        vector<vector<string>> ans;
        int minl = INT_MAX;
        int strl = beginWord.length();
        queue<vector<string>> q;
        q.push({beginWord});
        vector<string> used;
        used.push_back(beginWord);
        int level = 0;
        while (!q.empty())
        {
            auto front = q.front();
            q.pop();
            if (front.size() > level)
            {
                level++;
                for (auto it : used)
                {
                    mp[it] = false;
                }
                used.clear();
            }
            if (front.back() == endWord)
            {
                if (front.size() <= minl)
                {
                    ans.push_back(front);
                    minl = front.size();
                }
            }
            for (int i = 0; i < strl; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    char ch = 'a' + j;
                    string newWord = front.back();
                    newWord[i] = ch;
                    if (mp[newWord])
                    {
                        front.push_back(newWord);
                        q.push(front);
                        used.push_back(newWord);
                        front.pop_back();
                    }
                }
            }
        }
        return ans;
    }
};