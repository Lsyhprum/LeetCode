#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        unordered_map<char, int> mp;

        for(int i = 0; i < S.size(); i ++ ) {
            mp[S[i]] = i;
        }

        int left = 0, right;
        while(left < S.size()) {
            right = mp[S[left]];

            //std::cout << left << " " << right << std::endl;
            int tmp_left = left, tmp_right = right;
            
            while(tmp_left <= tmp_right) {
                //std::cout << tmp_left << "|" << tmp_right << std::endl;
                int new_left = -1, new_right = -1;
                for(int i = tmp_left; i <= tmp_right; i ++) {
                    if((new_right != -1 && mp[S[i]] > new_right) || (new_right == -1 && mp[S[i]] > tmp_right)) {
                        new_left = tmp_right + 1;
                        new_right = mp[S[i]];
                    }
                }

                tmp_left = tmp_right + 1;

                if(new_left != -1) {
                    tmp_left = new_left;
                    tmp_right = new_right;
                }
            }
            //std::cout << left << "\/" << tmp_right + 1 << std::endl;
            res.push_back(tmp_right + 1 - left);
            left = tmp_right + 1;
        }

        return res;
    }
};

int main() {
    Solution sol;
    // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    // e a e d c a a a d e  d  a  a  c  b
 
    vector<int> v = sol.partitionLabels("bceacbacdbbadea");

    for(int i = 0; i < v.size(); i ++) {
        std::cout << v[i] << std::endl;
    }

    return 0;
}