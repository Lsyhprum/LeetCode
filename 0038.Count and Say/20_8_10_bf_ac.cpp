#include <iostream>
#include <string>

using namespace std;

// time complexity : 88.14%
// memory complexity : 74.40%
class Solution{
public:
    string countAndSay(int n){
        //1
        //11
        //21
        //1211
        //111221
        //312211
        //13112221
        //1113213211
        //31131311131221
        //貌似没什么规律
        
        string origin = "1";
        for(int i = 1; i < n; i ++){ // count and say 次数
            string tmp = "";

            int left = 0;
            int right = 0;
            while(right < origin.size()){
                if(origin[left] == origin[right]){
                    right ++;
                }else{
                    tmp.append(to_string(right - left));
                    tmp += origin[left];
                    // cout << "tmp : " << tmp << endl;
                    left = right;
                }
            }
            tmp.append(to_string(right-left));
            tmp += origin[left];
            // cout << tmp << endl;
            origin = tmp;
        }

        return origin;
    }
};

int main(){
    Solution sol;
    cout << sol.countAndSay(6);
    return 0;
}