class Solution {
private:
    string str = "";
    int res = 0;
    
    bool is_unique(){
        bool flag[26] = {0};
        for(auto &c: str){
            if(flag[c - 'a']) return false;
            flag[c - 'a'] = true;
        }
        return true;
    }
    
    void solve(vector<string> &arr, int index){
        for(int i = index; i < arr.size(); i++){
            str += arr[i];
            if(is_unique()){
                res = max(res, (int) str.length());
                solve(arr, i + 1);
            }
            str.erase(str.length() - arr[i].length());
        }
    }
    
public:
    int maxLength(vector<string>& arr) {
        solve(arr, 0);
        return res;
    }
};