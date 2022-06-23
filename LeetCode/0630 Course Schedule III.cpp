class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>a, vector<int>b){return a[1] < b[1];});
        priority_queue<int> q;
        int sum = 0;
        for(auto &c: courses){
            q.push(c[0]);
            sum += c[0];
            if(sum > c[1])
                sum -= q.top(), q.pop();
            
        }
        return q.size();
    }
};