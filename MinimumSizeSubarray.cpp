//LEETCODE---209//

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_len = INT_MAX;

        int i = 0, j = 0;
        int sum = 0;

        while (j < n) {
            sum += nums[j];
            if (sum < target) {
                j++;
            }
            else {

            while (sum >= target) {
                min_len = min(min_len, j - i + 1);
                sum -= nums[i];
                i++;
            }

            j++;
        }
        }
        return (min_len == INT_MAX) ? 0 : min_len;
    }
    
};
