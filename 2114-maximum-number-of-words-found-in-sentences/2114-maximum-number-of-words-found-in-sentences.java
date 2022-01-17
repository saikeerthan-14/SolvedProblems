class Solution {
    public int mostWordsFound(String[] s) {
        int ans = 0;
        for(int i=0;i<s.length;i++) {
            // int di = s[i].split(" ").length;
            // if(di>ans) ans = di;
            ans = Math.max(ans, s[i].split(" ").length);
        }
        return ans;
    }
}