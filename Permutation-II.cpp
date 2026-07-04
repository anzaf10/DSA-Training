//leetcode---47//

class Solution {
public:
    void solve(int index, vector<int>& nums, vector<vector<int>>& ans) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> used;

        for (int i = index; i < nums.size(); i++) {
            if (used.count(nums[i]))
                continue;

            used.insert(nums[i]);

            swap(nums[index], nums[i]);
            solve(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }    
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        solve(0, nums, ans);

        return ans;
    }
};
