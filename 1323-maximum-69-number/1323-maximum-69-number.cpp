class Solution {
public:
    int maximum69Number (int num) {
        string ns = to_string(num);
        size_t six_occ = ns.find('6');
        if(six_occ==string::npos) return num;
        ns[six_occ] = '9';
        return stoi(ns);
    }
};