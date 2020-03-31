# include <iostream>
# include <vector>

using namespace std;

//Runtime 98.71%
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        init();
        
        for(int i = 0; i < grid.size(); i ++){
            for(int j = 0; j < grid.size(); j ++){
                int block = i * grid.size() + j;
                if(grid[i][j] == '/'){
                    Union(block * 4, block * 4 + 3);
                    Union(block * 4 + 1, block * 4 + 2);
                }else if(grid[i][j] == '\\'){
                    Union(block * 4, block * 4 + 1);
                    Union(block * 4 + 2, block * 4 + 3);
                }else{
                    Union(block * 4, block * 4 + 1);
                    Union(block * 4 + 1, block * 4 + 2);
                    Union(block * 4 + 2, block * 4 + 3);
                }
            }
        } 

        // int num = 0;
        // for(int i = 0; i < grid.size() * grid.size() * 4; i ++){
        //     if(father[i] == i)
        //         num ++;
        // }
        // cout << num << endl;

        int block, up, down, left, right;
        int up_limit = 0, down_limit = grid.size() * grid.size() * 4, right_limit, left_limit;
        for(int i = 0; i < grid.size(); i ++){
            for(int j = 0; j < grid.size(); j ++){
                left_limit = i * grid.size() * 4;
                right_limit = (i + 1) * grid.size() * 4;

                block = (i * grid.size() + j) * 4;
                up = block - grid.size() * 4 + 2;
                if(up >= up_limit){
                    Union(block, up);
                }

                block ++;
                right = block + 6;
                if(right < right_limit) {
                    Union(block, right);
                }

                block ++;
                down = block + grid.size() * 4 - 2;
                if(down < down_limit){
                    Union(block, down);
                }

                block ++;
                left = block - 6;
                if(left >= left_limit){
                    Union(block, left);
                }
            }
        }

        int res = 0;
        for(int i = 0; i < grid.size() * grid.size() * 4; i ++){
            if(father[i] == i)
                res ++;
        }

        return res;
    }

private:
    int father[30*30*4];

    void init(){
        for(int i = 0; i < 30*30*4; i ++)
            father[i] = i;
    }

    void Union(int a, int b){
        int faA = find(a);
        int faB = find(b);

        if(faA != faB){
            father[faA] = faB;
        }
            
    }

    int find(int a){
        int x = a;
        while(x != father[x]){
            father[x] = father[father[x]];
            x = father[x];
        }
        return x;
    }

    bool is_legel(int block, int col, int grid_size){
        if(block >= 0 && block < grid_size * grid_size * 4 && block >= col * 4 * grid_size + 3 && block < (col + 1) * 4 * grid_size){
            return true;       
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<string> v = {"\\/\\", "\\/\\","\\/\\"};
    cout << sol.regionsBySlashes(v) << endl;
    return 0;
}