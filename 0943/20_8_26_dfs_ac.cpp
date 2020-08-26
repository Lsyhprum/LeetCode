#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        cost = vector<vector<int>>(A.size(), vector<int>(A.size()));

        for(int i = 0; i < A.size(); i ++){
            for(int j = 0; j < A.size(); j ++){
                cost[i][j] = A[j].length();
                for(int k = 1; k <= min(A[i].length(), A[j].length()); k ++){
                    if(A[i].substr(A[i].size()-k) == A[j].substr(0, k))
                        cost[i][j] = A[j].length() - k;
                }
            }
        } 

        vector<int> path(A.size());
        best_len = INT_MAX;

        dfs(A, 0, 0, 0, path);

        string ans = A[best_path[0]];

        for(int k = 1; k < best_path.size(); k ++){
            int i = best_path[k-1];
            int j = best_path[k];
            ans += A[j].substr(A[j].length() - cost[i][j]);
        }

        return ans;

    }

private:
    vector<vector<int>> cost;
    vector<int> best_path;
    int best_len;

    void dfs(const vector<string> &A, int d, int used, int cur_len, vector<int> &path){
        if(cur_len >= best_len) return;

        if(d == A.size()){
            best_len = cur_len;
            best_path = path;
            return;
        }

        for(int i = 0; i < A.size(); i ++){
            if(used & (1<<i)) continue;

            path[d] = i;

            dfs(A, 
                d + 1, 
                used | (1 << i), 
                d == 0 ? A[i].length() : cur_len + cost[path[d-1]][i], 
                path);
        }
    }
};

int main(){
    vector<string> A = {"catg","ctaagt","gcta","ttca","atgcatc"};

    Solution sol;

    cout << sol.shortestSuperstring(A);

    return 0;
}