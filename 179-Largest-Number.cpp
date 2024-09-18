class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> str_nums;
        for (int num : nums) {
            str_nums.push_back(to_string(num));
        }

        // Sort the strings with custom comparator
        sort(str_nums.begin(), str_nums.end(), [](const string &a, const string &b) {
            return a + b > b + a;
        });

        // Edge case: If the largest number is \0\, return \0\
        if (str_nums[0] == \0\) {
            return \0\;
        }

        // Concatenate sorted strings
        string result;
        for (const string &num : str_nums) {
            result += num;
        }

        return result;
        
    }
};