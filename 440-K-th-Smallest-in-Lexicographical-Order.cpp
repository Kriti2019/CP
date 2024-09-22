class Solution {
public:
    int findKthNumber(int n, int k) {
        auto countSteps = [&](long long prefix, long long n) -> int {
        long long cur = prefix;
        long long next = cur + 1;
        int steps = 0;
        while (cur <= n) {
            steps += min(n + 1, next) - cur;
            cur *= 10;
            next *= 10;
        }
        return steps;
    };
    
    int current = 1;
    k--;  // We already consider 1 as the first number.
    
    while (k > 0) {
        int steps = countSteps(current, n);
        if (steps <= k) {
            // Move to the next prefix
            current += 1;
            k -= steps;
        } else {
            // Move to the next level (deeper into the current prefix)
            current *= 10;
            k -= 1;  // We counted this prefix itself as one step.
        }
    }
    
    return current;
        
    }
};