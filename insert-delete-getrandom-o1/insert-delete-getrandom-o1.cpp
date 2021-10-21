class RandomizedSet {
public:
    unordered_map<int, int>u;
    vector<int>v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(u.find(val)!=u.end()) return false;
        u[val] = v.size();
        v.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(u.find(val)==u.end()) return false;
        int idx = u[val];
        if(idx<v.size()-1) {
            swap(v[idx], v[v.size()-1]);
            u[v[idx]] = idx;
        }
        u.erase(val);
        v.pop_back();
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */