class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int dis[100100];
        map<int, int> mp;
        map<int, int> mp_m;
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (mp.count(num) == 0) {
                dis[i] = -1;
                mp[num] = i;
                mp_m[num] = i;
                continue;
            }
            dis[i] = min(i - mp[num], n - i + mp_m[num]);
            mp[num] = i;
        }
        
        mp.clear();
        mp_m.clear();
        
        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            if (mp.count(num) == 0) {
                mp[num] = i;
                mp_m[num] = i;
                continue;
            }
            
            int tmp = min(mp[num] - i, i + n -  mp_m[num]);
            if (dis[i] == -1) {
                dis[i] = tmp;
            } else {
                dis[i] = min(dis[i], tmp);
            }
            mp[num] = i;
        }
        
        vector<int> ans;
        for (auto query : queries) {
            ans.push_back(dis[query]);
        }
        return ans;
        
    }
};
