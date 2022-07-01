class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        set<int,greater<int>> s;
        map<int,int> hmap;
        int result=0;
        int count=0;
        
        for(int i=0;i<boxTypes.size();i++){
            hmap[boxTypes[i][1]] += boxTypes[i][0];
            s.insert(boxTypes[i][1]);
        }
        set<int,greater<int>>::iterator itr;
        for (itr = s.begin(); itr != s.end(); itr++) {
            if(count+hmap[*itr]<truckSize){
                result+=hmap[*itr]* (*itr);
                count+=hmap[*itr];
            }
            else{
                result+= (*itr) * (truckSize-count);
                count=truckSize;
            }
        }
        return result; 
    }
};