class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        vector<int> dp(s.length() + 1, 0);
        for (int i = 1; i <= s.length(); ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = 0; j < i; ++j) {
                if (find(dictionary.begin(), dictionary.end(), s.substr(j, i - j)) != dictionary.end()) {
                    dp[i] = min(dp[i], dp[j]);
                }
            }
        }

        return dp[s.length()];
    }
};