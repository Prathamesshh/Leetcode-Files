class Solution {
public:
    vector<string> res;
    string current;

    void generate(int n, int openN, int closedN) {
        if (openN == n && closedN == n) {
            res.push_back(current);
            return;
        }

        if (openN < n) {
            current.push_back('(');
            generate(n, openN + 1, closedN);
            current.pop_back();
        }

        if (closedN < openN) {
            current.push_back(')');
            generate(n, openN, closedN + 1);
            current.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        res.clear();
        current.clear();
        generate(n, 0, 0);
        return res;
    }
};
