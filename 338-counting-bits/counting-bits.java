class Solution {
    public int[] countBits(int n) {
        int[] a = new int[n+1];

        a[0] = 0;

        for(int i=1;i<=n;i++){
            if(i == 2){
                a[i] = 1;
            }


            else if(i % 2 == 0){
                a[i] = a[i/2];
            }

            else{
                a[i] = a[i/2] + 1;
            }
        }


        return a;
    }
}