// https://leetcode.com/problems/design-twitter/
#include<bits/stdc++.h>
using namespace std;
class Twitter
{
public:
    unordered_map<int, unordered_set<int>> users;
    vector<pair<int, int>> tweets;
    Twitter()
    {
    }
    void postTweet(int userId, int tweetId)
    {
        tweets.push_back({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> ans;
        vector<int> user;
        for (auto it : users[userId])
        {
            user.push_back(it);
        }
        user.push_back(userId);
        int cnt = 0;
        for (int i = tweets.size() - 1; i >= 0 && cnt < 10; i--)
        {
            if (find(user.begin(), user.end(), tweets[i].first) != user.end())
            {
                ans.push_back(tweets[i].second);
                cnt++;
            }
        }
        return ans;
    }

    void follow(int followerId, int followeeId)
    {
        users[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        users[followerId].erase(followeeId);
    }
};
int main(){

return 0;
}