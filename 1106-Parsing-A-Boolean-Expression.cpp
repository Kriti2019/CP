

class Solution {
public:
    bool parseBoolExpr(string expression) {
        int index = 0;
        return parse(index, expression);
    }
    
private:
    bool parse(int& index, const string& expression) {
        if (expression[index] == 't') {
            index++;
            return true;
        } else if (expression[index] == 'f') {
            index++;
            return false;
        } else if (expression[index] == '!') {
            index += 2; // Skip over '!' and '('
            bool res = !parse(index, expression);
            index++; // Skip over ')'
            return res;
        } else if (expression[index] == '&' || expression[index] == '|') {
            char op = expression[index];
            index += 2; // Skip over operator and '('
            bool res = (op == '&') ? true : false;
            while (expression[index] != ')') {
                bool subRes = parse(index, expression);
                if (op == '&') {
                    res = res && subRes;
                } else {
                    res = res || subRes;
                }
                if (expression[index] == ',') {
                    index++; // Skip over ','
                }
            }
            index++; // Skip over ')'
            return res;
        }
        // Should not reach here for valid expressions
        return false;
    }
};
