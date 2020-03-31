# include <iostream>
# include <algorithm>
# include <vector>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size() == 0) return 0;
        
        sort(points.begin(), points.end(), 
        [](vector<int> a, vector<int> b){ return a[1] < b[1];});

        int res = 1;
        int x_end = points[0][1];
        for(int i = 0; i < points.size(); i ++){
            int start = points[i][0];

            if(start >= x_end){
                res ++;
                x_end = points[i][1];
            }
        }

        return res;
    }
};

int main(){
    Solution sol;
    vector<vector<int>> v = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    cout << sol.findMinArrowShots(v);
    return 0;
}