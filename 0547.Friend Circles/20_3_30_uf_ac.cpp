# include <iostream>
# include <vector>

using namespace std;

// 42.11%
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        init();

        for(int i = 0; i < M.size(); i ++){
            for(int j = i + 1; j < M[i].size(); j ++){
                if(M[i][j]){
                    Union(i, j);
                }
            }
        }

        int res = 0;
        for(int i = 0; i < M.size(); i ++){
            if(father[i] == i)
                res ++;
        }
        return res;
    }

private:
    int father[210];

    void init(){
        for(int i = 0; i < 210; i ++){
            father[i] = i;
        }
    }

    int find(int a){
        int x = a;
        while(father[x] != x){
            x = father[x];
        }
        return x;
    }

    void Union(int a, int b){
        int faA = find(a);
        int faB = find(b);

        if(faA != faB)
            father[faA] = faB;
    }

};

int main(){
    Solution sol;
    vector<vector<int>> v = {{1, 1}, {1, 1}};
    cout << sol.findCircleNum(v) << endl;

    return 0;
}