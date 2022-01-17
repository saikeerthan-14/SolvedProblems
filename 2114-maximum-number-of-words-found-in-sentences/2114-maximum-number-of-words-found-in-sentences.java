class Solution {
    public int mostWordsFound(String[] s) {
        int ans = 0;
        for(int i=0;i<s.length;i++) {
            int di = s[i].split(" ").length;
            if(di>ans) ans = di;
        }
        return ans;
    }
}