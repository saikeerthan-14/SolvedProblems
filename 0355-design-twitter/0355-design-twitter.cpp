class Twitter {
public:
    int t;
    priority_queue<vector<int>> tweets;
    unordered_map<int, unordered_set<int>> follows;
    Twitter() {
        t=0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets.push({this->t, tweetId, userId});
        this->t ++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<vector<int>>pq = tweets;
        // for(auto it: tweets[userId]) {
        //     cout<<it.first<<" "<<it.second<<endl;
        //     pq.push(it);
        //     if(pq.size()>10) pq.pop();
        // }
        // for(auto it: follows[userId]) {
        //     for(auto j: tweets[it]) {
        //         cout<<j.first<<" "<<j.second<<endl;
        //         pq.push(j);
        //         if(pq.size()>10) pq.pop();
        //     }
        // }
        vector<int> ans;
        int n = 0;
        while(!pq.empty() && n<10) {
            vector<int> top = pq.top();
            pq.pop();
            if(top[2]==userId || follows[userId].count(top[2])) {
                ans.push_back(top[1]);
                n++;
            }
                
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
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