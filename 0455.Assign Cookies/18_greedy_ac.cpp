# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(), [](const int &a, const int &b) -> int{ return a > b;});
        sort(s.begin(), s.end(), [](const int &a, const int &b) -> int{ return a > b;});

        int index = -1;
        int num = 0;

        for(int i = 0; i < s.size();i ++){
            while(index < ((int)(g.size())) - 1){
                index ++;
                if(s[i] >= g[index]){
                    num ++;
                    break;
                }
            }
        }

        return num;
    }
};