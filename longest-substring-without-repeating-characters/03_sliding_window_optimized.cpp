#include<algorithm>
#include<map>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        std::map<char, int> hashMap;
        for (int i = 0, j = 0; j < n; ++j) {
            if (hashMap.find(s[j]) != hashMap.end()) {
                i = std::max(hashMap.find(s[j])->second, i) ;
            }
            ans = std::max(ans, j - i + 1);
            hashMap[s[j]] = j + 1;
        }
        return ans;
    }
};
