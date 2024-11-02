class Solution {
    public boolean isCircularSentence(String sentence) {
        String[] words = sentence.split(" ");
        int i;
        for(i=0;i<words.length-1;i++) {
            int n = words[i].length();
            if(words[i].charAt(n-1)!=words[i+1].charAt(0)) return false;
        }
        return words[0].charAt(0)==words[i].charAt(words[i].length()-1);
    }
}