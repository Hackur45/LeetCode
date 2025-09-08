class Solution {
    public static Boolean safe(int a){
        while(a > 0){
            int r = a % 10;
            if(r == 0) return false;
            a /= 10;
        }

        return true;
    }
    public int[] getNoZeroIntegers(int n) {
        int[] ans = new int[2];

        for(int i=1;i<n;i++){
            int a = n - i;
            int b = i;

            if(safe(a) && safe(b)){
                ans[0] = a;
                ans[1] = b;
                break;
            }
        }

        return ans;
    }
}