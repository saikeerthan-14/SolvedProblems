class Solution {
public:
   bool isValid(string s) {
       stack<char> s1;
       for(char c : s) {
           if(c=='(' || c=='{' || c=='[') {
               s1.push(c);
           } else {
               if((s1.size()>0) && ((s1.top()=='(' && c==')') ||
                  (s1.top()=='{' && c=='}') ||
                  (s1.top()=='[' && c==']')))
                   s1.pop();
               else return false;
           }
       }
       if(s1.size()){
           return false;
       }
       return true;
   }
};