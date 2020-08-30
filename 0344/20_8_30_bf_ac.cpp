#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0, right = s.size()-1;

        while(left < right){
            swap(s[left], s[right]);

            left ++;
            right --;
        }
    }
};

int main(){
    Solution sol;

    vector<char> c = {'H', 'a', 'n', 'n', 'a', 'h'};
    sol.reverseString(c);

    for(char c1 : c){
        cout << c1;
    }
}