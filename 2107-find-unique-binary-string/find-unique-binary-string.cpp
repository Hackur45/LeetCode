class Solution {
public:
    int binaryToDecimal(const string& s) {
        int dec_value = 0;
        int base = 1; 

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '1') {
                dec_value += base;
            }
            base *= 2;
        }

        return dec_value;
    }

    string decToBinary(int n, int length) {
        string bin = "";
        while (n > 0) {
            bin.push_back('0' + (n % 2));
            n /= 2;
        }
        while (bin.size() < length) { 
            bin.push_back('0');
        }
        reverse(bin.begin(), bin.end());
        return bin;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        set<int> st;

        for (auto& num : nums) {
            st.insert(binaryToDecimal(num));
        }

        for (int i = 0; i < (1 << n); i++) { 
            if (st.find(i) == st.end()) {
                return decToBinary(i, n);
            }
        }

        return "";
    }
};
