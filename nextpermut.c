class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int pivot = n - 2;

        while (pivot >= 0 && nums[pivot] >= nums[pivot + 1])
            --pivot;

        if (pivot >= 0) {
            int successor = n - 1;
            while (nums[successor] <= nums[pivot])
                --successor;

            swap(nums[pivot], nums[successor]);
        }

        reverse(nums.begin() + pivot + 1, nums.end());
    }
};  
