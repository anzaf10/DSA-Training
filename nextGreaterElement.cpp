//NEXT GREATER ELEMENT//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n);

        stack<int> st;

        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }

            if (st.empty())
                ans[i] = -1;
            else
                ans[i] = st.top();

            st.push(arr[i]);
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {4, 5, 2, 10, 8};

    vector<int> result = sol.nextGreaterElement(arr);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
