#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<unsigned, vector<vector<int>>> mp;

        for(int i = 0; i < pieces.size(); i ++) {
            if(mp.find(pieces[i][0]) == mp.end()) {
                mp[pieces[i][0]].push_back(pieces[i]);
            }else{
                mp[pieces[i][0]].push_back(pieces[i]);
            }
        }

        for(int i = 0; i < arr.size(); i ++) {
            if(mp.find(arr[i]) == mp.end()) return false;
            vector<vector<int>> v = mp[arr[i]];

            bool flag = false;
            int num = 0;
            for(auto tmp : v) {
                int j = 0;
                num = 0;
                for(; j < tmp.size(); j ++) {
                    if(tmp[j] == arr[i]) {
                        continue;
                    }else{
                        break;
                    }
                }

                if(j == tmp.size()) {
                    flag = true;
                    num = tmp.size();
                    break;
                }
            }

            if(flag) {
                i += (num - 1);
            }else {
                return false;
            }
        }

        return true;
    }
};

int main() {
    return 0;
}