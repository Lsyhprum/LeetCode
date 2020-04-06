# include <iostream>
# include <algorithm>

using namespace std;

// Runtime 5.01%
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size(), len2 = word2.size();

        int memo[512][512];
        for(int i = 0; i < len1; i ++){
            for(int j = 0; j < len2; j ++){
                memo[i][j] = -1;
            }
        }

        int val = recursion(word1, word2, len1 - 1, len2 - 1, memo);

        // for(int a = 0; a < len1; a ++){
        //     for(int b = 0; b < len2; b ++){
        //         cout << memo[a][b];
        //     }
        //     cout << endl;
        // }

        return val;
    }

private:
    int recursion(string word1, string word2, int i, int j, int memo[512][512]){
        if(i == -1) return j + 1;
        if(j == -1) return i + 1;

        if(memo[i][j] == -1){
            // skip
            if(word1[i] == word2[j]){
                memo[i][j] = recursion(word1, word2, i - 1, j - 1, memo);
            }else{
                // insert delete replace
                memo[i][j] = MIN(recursion(word1, word2, i, j - 1, memo), 
                            recursion(word1, word2, i - 1, j, memo), 
                            recursion(word1, word2, i - 1, j - 1, memo)) + 1;
            }
        }

        return memo[i][j];
    }

    int MIN(int a, int b, int c){
        int d = min(a, b);
        return min(d, c);
    }
};


int main(){
    Solution sol;
    cout << sol.minDistance("dinitrophenylhydrazine", "benzalphenylhydrazone");
    return 0;
}