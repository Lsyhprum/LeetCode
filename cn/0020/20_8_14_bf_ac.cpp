#include <iostream>
#include <stack>

using namespace std;

// time complexity : O(N), 46.75%
// memory complexity : O(N), 74.75%
class Solution {
public:
    bool isValid(string s) {
        stack<char> container;

        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                container.push(c);
            }else{
                if(container.empty())
                    return false;

                if((c == ')' && container.top() != '(') ||
                    (c == '}' && container.top() != '{') ||
                    (c == ']' && container.top() != '[')){
                        return false;
                }else{
                    container.pop();
                }
            }
        }

        return container.empty();
    }
};

int main(){
    Solution sol;
    cout << sol.isValid("([)]") <<endl;

    return 0;
}