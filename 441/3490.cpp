class Solution {
public:
    map<uint64_t, int> cache;
    int dp(string& upper_s, int index, int mul, int sum, bool is_limit, bool is_num) {
        int n = upper_s.size();
        if (index == n) {
            if (sum && mul % sum == 0)
                return 1;
            return 0;
        }

        
        int ret = 0;

        if (is_limit == false) {
            uint64_t mask = ((uint64_t)mul << 32) + (sum << 16) + n - index;
            if (is_num) {
                if (cache.count(mask)) return cache[mask];
                for (int i = 0; i < 10; i++) {
                    ret += dp(upper_s, index + 1, mul * i, sum + i, 0, 1);
                }
                cache[mask] = ret;

            } else {
                ret = dp(upper_s, index + 1, mul, sum, 0, 0);            
                for (int i = 1; i < 10; i++) {
                    ret += dp(upper_s, index + 1, mul * i, sum + i, 0, 1);
                }

            }
        }

        if (is_limit) {
            int dig = upper_s[index] - '0';
            for (int i = 0; i < dig; i++) {
                ret += dp(upper_s, index + 1, mul * i, sum + i, 0, 1);
            }
            ret += dp(upper_s, index + 1, mul * dig, sum + dig, 1, 1);
        }

        return ret;
    }
    int cal(int upper) {
        string upper_s = to_string(upper);
        int ret = 0;
        int dig = upper_s[0] - '0';
        // curr is 0，前导 0， 后续可以 0-9 的统计
        ret += dp(upper_s, 1, 1, 0,  /* is_limit*/false, /* is_num */ false); 
        for (int i = 1; i < dig; i++) { 
            // curr 1 ~ dig， 后续可以 0-9 的统计
            ret += dp(upper_s, 1, i, i,  /* is_limit*/false, /* is_num */ true);
        }
        // curr dig， 后续需要考虑 upper
        ret += dp(upper_s, 1, dig, dig,  /* is_limit*/true, /* is_num */  true); 
        return ret;
    }
    int beautifulNumbers(int l, int r) { return cal(r) - cal(l - 1); }
};

