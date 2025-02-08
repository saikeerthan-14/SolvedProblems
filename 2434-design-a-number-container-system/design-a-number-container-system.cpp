class NumberContainers {
public:
    unordered_map<int, int> u;
    unordered_map<int, set<int>>s;
    NumberContainers() {

    }
    
    void change(int index, int number) {
        if(u.find(index)!=u.end()) {
            s[u[index]].erase(index);
            if(s[u[index]].size()==0) s.erase(u[index]);
        }
        u[index] = number;
        s[number].insert(index);
    }
    
    int find(int number) {
        if(s.find(number)==s.end()) return -1;
        return *s[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */