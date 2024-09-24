class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<string> prefixes;
        for (int num : arr1) {
            string strNum = to_string(num);
            for (size_t i = 1; i <= strNum.length(); ++i) {
                prefixes.insert(strNum.substr(0, i));
            }
        }
        int maxLength = 0;
        for (int num : arr2) {
            string strNum = to_string(num);
            for (size_t i = 1; i <= strNum.length(); ++i) {
                string currentPrefix = strNum.substr(0, i);
                if (prefixes.count(currentPrefix)) {
                    maxLength = max(maxLength, static_cast<int>(currentPrefix.length()));
                }
            }
        }

        return maxLength;
    }
};
