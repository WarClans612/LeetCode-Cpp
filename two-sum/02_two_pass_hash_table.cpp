class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            hashMap[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hashMap.find(complement) != hashMap.end() && hashMap.find(complement)->second != i) {
                vector<int> answer = {i , hashMap.find(complement)->second};
                return answer;
            }
        }
        throw std::invalid_argument("No Valid Value");
    }
};
