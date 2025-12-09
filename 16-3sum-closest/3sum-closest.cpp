class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closestSum = 10000000;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                if (abs(target - sum) < abs(target - closestSum))
                    closestSum = sum;

                if (sum > target)
                    right--;
                else
                    left++;
            }
        }

        return closestSum;
    }
};