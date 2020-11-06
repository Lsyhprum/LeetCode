#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> res;
        map<int, priority_queue<int, vector<int>, greater<int>>> mp;
        set<int> s;
        for(int i = 0; i < arr.size(); i ++) {
            int num = arr[i];
            int one_num = 0;
            while(num) {
                if(num & 1) 
                   one_num ++;
                num = num >> 1; 
            }
            
            if(!mp.count(one_num)) {
                s.insert(one_num);
                priority_queue<int, vector<int>, greater<int>> q;
                mp[one_num] = q;
            }
            mp[one_num].push(arr[i]);
        }

        for(auto iter : mp) {
            while(!iter.second.empty()){
                res.push_back(iter.second.top());
                iter.second.pop();
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {10,100,1000,10000};

    for(int i : sol.sortByBits(arr))
        std::cout << i << std::endl;

    return 0;
}