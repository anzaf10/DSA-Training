//leetcode---17//

class Solution {
    vector<string> mappings = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };

    void getAllCombination(string &digits, int idx, string output, vector<string> &finalOutput) {
        if (idx == digits.length()) {
            finalOutput.push_back(output);
            return;
        }

        string letters = mappings[digits[idx] - '0'];

        for (int i = 0; i < letters.length(); i++) {
            char curr = letters[i];
            getAllCombination(digits, idx + 1, output + curr, finalOutput);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> finalOutput;

        if (digits.empty())
            return finalOutput;

        string output = "";
        getAllCombination(digits, 0, output, finalOutput);

        return finalOutput;
    }
};
