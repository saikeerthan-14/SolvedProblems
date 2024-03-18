class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<pair<int,int>> hp(points.size());
        for(auto i{0}; i < points.size(); ++i){
            hp[i] = {points[i][1],points[i][0]};
        }
        sort(hp.begin(),hp.end());
        int& arrows = hp[0].second;
        arrows=1;
        int& last = hp[0].first;
        for(auto i{1}; i < hp.size(); ++i)
        {
            auto& p{hp[i]};
            if(p.second > last){
                ++arrows;
                last = p.first;
            }
        }
        return arrows;
    }
};