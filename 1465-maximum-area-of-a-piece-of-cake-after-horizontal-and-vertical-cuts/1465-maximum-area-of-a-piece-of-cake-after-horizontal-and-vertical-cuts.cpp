class Solution {
public:
    int maxArea(int h, int v, vector<int>& hc, vector<int>& vc) {
        int mm = 1e9+7;
        sort(hc.begin(), hc.end());
        sort(vc.begin(), vc.end());
        int h_max = hc[0], v_max = vc[0];
        
        for(int i=1;i<hc.size();i++){
            if(h_max<hc[i]-hc[i-1]) h_max = hc[i]-hc[i-1];
        }
        if(h_max<h-hc[hc.size()-1]) h_max = h-hc[hc.size()-1];
        for(int i=1;i<vc.size();i++){
            if(v_max<vc[i]-vc[i-1]) v_max = vc[i]-vc[i-1];
        }
        if(v_max<v-vc[vc.size()-1]) v_max = v-vc[vc.size()-1];
        
        
        return (1ll*h_max*v_max)%1000000007;
    }
};