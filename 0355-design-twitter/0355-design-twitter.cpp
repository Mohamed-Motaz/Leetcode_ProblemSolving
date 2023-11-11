class Twitter {
public:
    unordered_map<int, unordered_set<int>> following;
    vector<pair<int, int>> tweets; //uid, tid
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        unordered_set<int>& s = following[userId];
        for (int i = tweets.size() - 1; i >= 0 && res.size() < 10; i--){
            
            if (tweets[i].first == userId || //I posted a message
                s.find(tweets[i].first) != s.end()) //someone I follow posted a message
                res.push_back(tweets[i].second);
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */