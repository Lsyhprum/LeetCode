# include <iostream>
# include <sstream>
# include <string>
# include <vector>
# include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dirs;

        stringstream ss(path);
        string dir;
        while(getline(ss, dir, '/')){
            if(dir.empty() || dir == "."){
                continue;
            }else if(dir == ".."){
                if(!dirs.empty())
                    dirs.pop();
            }else{
                dirs.push(dir);
            }
        }

        string res;

        while(!dirs.empty()){
            res = "/" + dirs.top() + res;
            dirs.pop();
        }

        return res.empty() ? "/" : res;
    }
};

int main(){
    Solution sol;

    cout << sol.simplifyPath("///");
    return 0;
}