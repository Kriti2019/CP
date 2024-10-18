class Solution {\r
public:\r
    long long wonderfulSubstrings(string word) {\r
        vector<long long> count(1024, 0); // 2^10 to store XOR values\r
        long long result = 0;\r
        int prefixXor = 0;\r
        count[prefixXor] = 1;\r
\r
        for (char ch : word) {\r
            int charIndex = ch - 'a';\r
            prefixXor ^= 1 << charIndex;\r
            result += count[prefixXor];\r
            for (int i = 0; i < 10; i++) {\r
                result += count[prefixXor ^ (1 << i)];\r
            }\r
            count[prefixXor]++;\r
        }\r
\r
        return result;\r
    }\r
};