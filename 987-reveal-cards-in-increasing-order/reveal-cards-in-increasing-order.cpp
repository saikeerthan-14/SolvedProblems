class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      sort(deck.begin(),deck.end());
      vector<int> ans(deck.size());

      queue<int> q;
      for(int i=0;i<deck.size();i++)
      {
        q.push(i);
      }

      int index=0;
      while(q.size()>0)
    {
        int x=q.front();
        q.pop();
        ans[x]=deck[index++];
        int y=q.front();
        q.pop();
        q.push(y);
    }
       return ans;
    }
};