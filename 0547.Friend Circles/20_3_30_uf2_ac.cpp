# include <iostream>
# include <vector>

using namespace std;

// 添加平衡性优化

// 42.11% -> 84.44%
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
    int size[210];

    void init(){
        for(int i = 0; i < 210; i ++){
            father[i] = i;
            size[i] = 1;
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

        if(faA != faB){
            if(size[faA] > size[faB]){
                father[faB] = faA;
                size[faA] += size[faB];
            }else{
                father[faA] = faB;
                size[faB] += size[faA];
            }
        }
            
    }

};

int main(){
    Solution sol;
    vector<vector<int>> v = {{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    cout << sol.findCircleNum(v) << endl;

    return 0;
}