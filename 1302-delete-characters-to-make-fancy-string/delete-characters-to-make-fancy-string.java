class Solution {
    public String makeFancyString(String s) {
        if(s.length()<3) return s;
        StringBuilder sb = new StringBuilder(s);
        int j = 2;
        
        for (int i = 2; i < s.length(); i++) {
            if (s.charAt(i) != sb.charAt(j - 1) || s.charAt(i) != sb.charAt(j - 2)) {
                sb.setCharAt(j, s.charAt(i));
                j++;
            }
        }
        
        return sb.substring(0, j);
    }
}