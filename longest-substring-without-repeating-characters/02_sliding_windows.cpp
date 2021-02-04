#include<algorithm>
#include<set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        std::set<char> ss;
        int ans = 0, i = 0, j = 0;
        while(i < n && j < n) {
            if (ss.find(s[j]) == ss.end()) {
                ss.insert(s[j]);
                ++j;
                ans = std::max(ans, j - i);
            }
            else {
                ss.erase(ss.find(s[i]));
                ++i;
            }
        }
        return ans;
    }
};
