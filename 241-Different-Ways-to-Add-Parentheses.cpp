class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        // Memoization dictionary to store the results of sub-expressions
    unordered_map<string, vector<int>> memo;
         if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }

        vector<int> results;
        // Iterate over each character in the expression
        for (int i = 0; i < expression.size(); i++) {
            char c = expression[i];
            // If the character is an operator, split the expression
            if (c == '+' || c == '-' || c == '*') {
                // Recursively compute the results for the left and right sub-expressions
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1));

                // Combine the results from left and right sub-expressions using the operator
                for (int l : left) {
                    for (int r : right) {
                        if (c == '+') {
                            results.push_back(l + r);
                        } else if (c == '-') {
                            results.push_back(l - r);
                        } else if (c == '*') {
                            results.push_back(l * r);
                        }
                    }
                }
            }
        }

        // If there are no operators, the expression is a single number
        if (results.empty()) {
            results.push_back(stoi(expression));
        }

        // Store the computed results in the memoization map
        memo[expression] = results;
        return results;
        
    }
};