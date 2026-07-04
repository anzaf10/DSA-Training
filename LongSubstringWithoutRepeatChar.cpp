//leetcode---3//

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        vector<int> freq(256, 0);

        int i = 0, j = 0;
        int max_len = 0;

        while (j < n) {
            freq[s[j]]++;

            if (freq[s[j]] == 1) {
                max_len = max(max_len, j - i + 1);
                j++;
            }
            else if (freq[s[j]] > 1) {
                while (freq[s[j]] > 1) {
                    freq[s[i]]--;
                    i++;
                }

                max_len = max(max_len, j - i + 1);
                j++;
            }
        }

        return max_len;
    }
};
