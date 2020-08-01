#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// Time complexity : O(2*N)
// Space complexity : O(2*N)
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        
        stack<int> s;
        unordered_map<int, int> map;
        
        for(int i = 0; i < nums.size() * 2; i ++){
            while(!s.empty() && nums[s.top() % nums.size()] < nums[i % nums.size()]){
                map[s.top()] = nums[i % nums.size()];
                s.pop();
            }
            s.push(i);
        }

        for(int i = 0; i < nums.size(); i ++){
            if(map.find(i) == map.end())
                res[i] = -1;
            else
                res[i] = map[i];
        }

        return res;
    }
};

int main(){

    Solution sol;

    vector<int> v = {3, 2, 1};

    for(int val : sol.nextGreaterElements(v)){
        cout << val << endl;
    }

    return 0;

}