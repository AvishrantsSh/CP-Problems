class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto &q : queries){
            int count = 0;
            for(auto &p: points)
                if (pow(p[0]-q[0],2) + pow(p[1]-q[1],2) <= pow(q[2],2))
                    count++;
            
            ans.push_back(count);
        }
        return ans;
    }
};