#include <iostream>
#include <vector>

using namespace std;

// Time complexity : O(n^2)
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        for(int i = 0; i < T.size(); i ++){
            for(int j = i + 1; j < T.size(); j ++){
                if(T[j] <= T[i]){

                }else{
                    
                }
            }
        }
    }
};

int main(){

}