//Leetcode---53//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    int n=nums.size();
    int curr_sum=0;
    int max_so_far = INT_MIN;
    for (int i=0;i<n;i++){
        int elem = nums[i];

        curr_sum = curr_sum + elem;
        if(curr_sum>max_so_far){
            max_so_far = curr_sum;

        }
        if(curr_sum<0){
            curr_sum = 0;
        }

    }    
    return max_so_far;
    }
};
