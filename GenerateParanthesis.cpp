class Solution {
public:
    vector<string> Sol;
    void generateParenthesisUtil(int N, int o, int c, string S) {

        if (o == N && c == N) {
            Sol.push_back(S);
            return;
        }
        
        if (o < N) {
            generateParenthesisUtil(N, o + 1, c, S + '(');
        }
        if (o > c && c < N) {
            generateParenthesisUtil(N, o, c + 1, S + ')');
        }

    }

    vector<string> generateParenthesis(int n) {
        generateParenthesisUtil(n, 0, 0, "");
        return Sol;
    }

};