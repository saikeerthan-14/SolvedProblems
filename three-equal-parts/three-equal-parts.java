class Solution {
    public int[] threeEqualParts(int[] arr) {
        ArrayList<Integer> id = new ArrayList<>();
        for(int i=0;i<arr.length;i++) {
            if(arr[i] == 1)
                id.add(i);
        }
        int[] ans = new int[]{-1, -1};
        int n = id.size();
        if(n==0) return new int[]{0, 2};
        if(n%3 !=0) return ans;
        int a = id.get(0), b = id.get(n/3), c = id.get(2*n/3);
        int i;
        for(i=0; c+i<arr.length;i++) {
            if(arr[i+a] !=arr[i+b] || arr[i+b]!=arr[i+c]) {
                return ans;
            }   
        }
        if(c+i==arr.length) {
                ans[0] = a+i-1;
                ans[1] = b+i;
        }
        return ans;
    }
}