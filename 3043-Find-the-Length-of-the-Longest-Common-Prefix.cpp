class Solution {
public:
    int commonPrefixLength(const string& s1, const string& s2) {
       int i = 0;
        while (i < s1.size() && i < s2.size() && s1[i] == s2[i]) {
            i++;
        }
        return i;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
          vector<string> strArr1, strArr2;
        for (int num : arr1) {
            strArr1.push_back(to_string(num));
        }
        for (int num : arr2) {
            strArr2.push_back(to_string(num));
        }
        
        // Sort both arrays as strings
        sort(strArr1.begin(), strArr1.end());
        sort(strArr2.begin(), strArr2.end());
        
        int maxLength = 0;
        int i = 0, j = 0;
        
        // Use two pointers to compare adjacent elements
        while (i < strArr1.size() && j < strArr2.size()) {
            int prefixLength = commonPrefixLength(strArr1[i], strArr2[j]);
            maxLength = max(maxLength, prefixLength);
            
            // Move the pointer for the smaller string lexicographically
            if (strArr1[i] < strArr2[j]) {
                i++;
            } else {
                j++;
            }
        }
        
        return maxLength;
    }
};