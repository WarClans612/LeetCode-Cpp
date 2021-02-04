#include<algorithm>
#include<set>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j <= n; ++j)
                if (allUnique(s, i, j)) ans = std::max(ans, j - i);
        return ans;
    }
    
    bool allUnique(string s, int start, int end) {
        std::set<char> ss;
        for (int i = start; i < end; ++i) {
            char c = s[i];
            if (ss.find(c) != ss.end()) return false;
            ss.insert(c);
        }
        return true;
    }
};
