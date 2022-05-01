class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans, tmp;
        unordered_map<string, int> map;
        for(auto &str: words)
            map[str]++;
        
        multimap<int, string, greater<>> mmap;
        set<int, greater<>> fset;
        for(auto &it: map){
            mmap.insert({it.second, it.first});
            fset.insert(it.second);
        }
        
        int count = 0;
        for(auto &i: fset){
            tmp = {};
            for (auto itr = mmap.find(i); itr != mmap.end() && itr->first == i; itr++)
                tmp.push_back(itr->second);
            
            sort(tmp.begin(), tmp.end());
            for(int i = 0; i < tmp.size() and count++ < k; i++){
                ans.push_back(tmp[i]);
            }
        }
        return ans;
    }
};