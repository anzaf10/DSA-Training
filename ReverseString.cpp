//REVERSE STRING USING STACK//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    string reverseString(string& s) {
        stack<char> st;

        for (char ch : s) {
            st.push(ch);
        }

        string ans = "";

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string s = "hello";

    cout << "Original: " << s << endl;
    cout << "Reversed: " << sol.reverseString(s) << endl;

    return 0;
}
