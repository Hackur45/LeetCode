class Solution {
    public boolean canReach(int[] arr, int start) {
        int n = arr.length;
        int[] vis = new int[n];
        Arrays.fill(vis,0);
        if(arr[start] == 0) return true;
        Queue<Integer> q = new LinkedList<Integer>();

        if(arr[start] + start < n){
            q.add(arr[start] + start);
            vis[arr[start] + start] = 1;
        }

        if(start - arr[start] >= 0){
            q.add(start - arr[start]);
            vis[start-arr[start]] = 1;
        }


        while(!q.isEmpty()){
            int index = q.poll();
            if(arr[index] == 0) return true;
            vis[index] = 1;
            int a = index - arr[index];
            int b = index + arr[index];

            if(a >= 0 && vis[a] == 0) q.add(a);
            if(b < n && vis[b] == 0) q.add(b);
        }

        return false;
    }
}