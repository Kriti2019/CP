class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int contentChildren = 0;
        int gIndex = 0;
        int sIndex = 0;

        while (gIndex < g.size() && sIndex < s.size()) {
            if (s[sIndex] >= g[gIndex]) {
                ++contentChildren;
                ++gIndex;
            }
            ++sIndex;
        }

        return contentChildren;
        
    }
};