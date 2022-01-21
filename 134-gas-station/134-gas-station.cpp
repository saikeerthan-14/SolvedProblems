class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ag = 0, s = 0, id = 0;
        for(int i=0;i<gas.size();i++) {
            s += gas[i]-cost[i];
            ag += gas[i] - cost[i];
            if(s<0) {
                s = 0;
                id = i+1;
            }
        }
        return ag<0?-1:id;
    }
};