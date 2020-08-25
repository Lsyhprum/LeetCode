#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

// time complexity : 5.21%
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res {{}};

        sort(nums.begin(), nums.end());

        unordered_map<int, vector<vector<int>>> mp;
        vector<int> tmp;
        dfs(nums, 0, tmp, mp);

        for(auto entry : mp){
            for(vector<int> v : entry.second){
                res.push_back(v);
            }
        }

        return res;
    }

private:
    void dfs(const vector<int> &nums, int index, vector<int> &tmp, 
                            unordered_map<int, vector<vector<int>>> &mp){

        if(!tmp.empty()) {
            auto iter = mp.find(tmp[0]);
            if(iter != mp.end()){
                vector<vector<int>> container = iter->second;

                bool flag = true;
                for(vector<int> v : container){
                    int i = 0;
                    for( ; v.size() == tmp.size() && i < v.size(); i ++){
                        if(tmp[i] != v[i])
                            break;
                    }
                    if(i == v.size()){
                        flag = false;
                        break;
                    }
                }

                if(flag) {
                    mp[iter->first].push_back(tmp);
                }
            }else{
                vector<vector<int>> v;
                v.push_back(tmp);

                mp[tmp[0]] = v;
            }
        }

        for(int i = index; i < nums.size(); i ++){
            tmp.push_back(nums[i]);

            dfs(nums, i + 1, tmp, mp);

            tmp.pop_back();
        }
    }
};

int main(){
    Solution sol;

    vector<int> nums = {4, 4, 4, 1, 4};
    for(vector<int> v : sol.subsetsWithDup(nums)){
        for(int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}