class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (hashMap.find(complement) != hashMap.end()) {
                vector<int> answer = {hashMap.find(complement)->second, i};
                return answer;
            }
            hashMap[nums[i]] = i;
        }
    throw std::invalid_argument("No Valid Value");
    }
};
