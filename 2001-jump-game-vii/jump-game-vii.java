class Solution {
    public boolean canReach(String s, int minJump, int maxJump) {
        int n = s.length();
        boolean[] vis = new boolean[n];
        Queue<Integer> q = new LinkedList<>();
        
        q.add(0);
        vis[0] = true;
        int farthest = 0;

        while (!q.isEmpty()) {
            int i = q.poll();
            if (i == n - 1) return true;

            int left = Math.max(i + minJump, farthest + 1);
            int right = Math.min(i + maxJump, n - 1);

            for (int j = left; j <= right; j++) {
                if (s.charAt(j) == '0' && !vis[j]) {
                    q.add(j);
                    vis[j] = true;
                }
            }

            farthest = right; 
        }

        return false;
    }
}
