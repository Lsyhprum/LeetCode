# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

// Runtime 7.41%
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return 0;

        int res = intervals.size();

        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){return a[1] < b[1];});

        int x_end = intervals[0][1], start;

        // 至少一个不相交
        int num = 1;
        for(int i = 0; i < intervals.size(); i ++){
            start = intervals[i][0];
            if(start >= x_end){ // 重叠
                x_end = intervals[i][1];
                num ++;
            }
        }

        return res - num;
    }

// 坑：不知道为何出错
// private:
//     bool cmp(const vector<int> &a, const vector<int> &b){
//         return a[1] < b[1];
//     }
};

int main(){
    Solution sol;
    vector<vector<int>> v = {{1, 2}, {1, 2}, {1, 2}};
    cout << sol.eraseOverlapIntervals(v) << endl;
    return 0;
}