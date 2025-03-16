class Solution {
public:
    int maxSum(vector<int>& nums) {
        
        int ans = nums[0];
        bool mark = false;
        for (auto num : nums) {
            if (num > 0) { mark = true; break; }
            ans = max(ans, num);
        }
    
        if (mark == false) {
            return ans;
        }
        
        set<int> s;
        ans = 0;
        for (auto num : nums) {
            if (num <= 0) continue;
            if (s.count(num)) continue;
            ans += num;
            s.insert(num);
        }
        return ans;
        
    }
};
