class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num == 0) continue;
            bool f[1010];
            memset(f, 0, sizeof f);
            f[0] = true;
            
            int k = -1;
            for (int j = 0; j < queries.size(); j++) {
                int l = queries[j][0];
                int r = queries[j][1];
                int val = queries[j][2];
                if (l > i || r < i) continue;

                for (int sum = num; sum >= val; sum--) {
                    if (f[sum - val]) f[sum] = true;
                }
                if (f[num]) {
                    k = j + 1;
                    break;
                }
            }

            if (k == -1) return -1;
            ans = max(ans, k);
        }
        return ans;

    }
};
