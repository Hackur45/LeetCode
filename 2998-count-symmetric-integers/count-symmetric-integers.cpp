class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i = low; i <= high; i++) {
            string s = to_string(i);
            int n = s.length();
            if (n % 2 == 0) {
                string fh = s.substr(0, n / 2);
                string sh = s.substr(n / 2, n / 2);

                int fhs = 0;
                int shs = 0;

                for (auto& a : fh)
                    fhs += a - '0';
                for (auto& a : sh)
                    shs += a - '0';

                if (fhs == shs) {
                    ans++;
                }
            }
        }

        return ans;
    }
};