class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if(a[1]<b[1]) return true;
        if(a[1]==b[1] && a[2]<b[2]) return true;
        return false;
    }
    
    bool carPooling(vector<vector<int>>& trips, int capacity)
    {
        int n = trips.size() ;
		
        sort(trips.begin(),trips.end(),comp) ;
        
        int curr = 0 ;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i=0;i<n;i++)
        {
            while(!pq.empty() && pq.top().first<=trips[i][1])
            {
                curr-=pq.top().second ;
                pq.pop() ;
            }
         
            pq.push({trips[i][2],trips[i][0]}) ;
            curr+=trips[i][0] ;
			
			if(curr>capacity)
                return false ;
        }
		
        return true ;  
    }

};