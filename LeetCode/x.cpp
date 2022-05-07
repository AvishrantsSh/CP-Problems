#include <iostream>
#include <string>
#include<stack>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        st.push({s[0], 1});
        string ans = "";
        for(int i = 1; i < s.length(); i++){
            if(!st.empty() && st.top().first == s[i]){
                if(st.top().second == k - 1) st.pop();
                else st.top().second++;
            }
            
            else st.push({s[i], 1});
        }
        // for(;!st.empty(); st.pop()) ans = st.top().first + ans;
        while(!st.empty()){
            ans = st.top().first + ans;
            st.pop();
        }
        return ans;
    }
};

int main(){
    Solution s;
    cout << s.removeDuplicates("deeedbbcccbdaa", 3) << endl;
}