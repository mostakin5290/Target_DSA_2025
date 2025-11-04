class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n - k + 1; i++) {
            unordered_map<int, int> freq;
            for (int j = i; j < i + k; j++) {
                freq[nums[j]]++;
            }
            vector<pair<int, int>> arr;
            for (auto& p : freq) {
                arr.push_back({p.second, p.first});
            }
            sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
                if (a.first != b.first) return a.first > b.first;
                return a.second > b.second;
            });
            int sum = 0;
            for (int idx = 0; idx < min(x, (int)arr.size()); idx++) {
                sum += arr[idx].first * arr[idx].second;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};