# include <iostream>
# include <algorithm>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int i = word1.size() - 1, j = word2.size() - 1;

        return recursion(word1, word2, i, j);
    }

private:
    int recursion(string word1, string word2, int i, int j){
        if(i == -1) return j + 1;
        if(j == -1) return i + 1;

        // skip
        if(word1[i] == word2[j]){
            return recursion(word1, word2, i - 1, j - 1);
        }

        // insert delete replace
        return MIN(recursion(word1, word2, i, j - 1), 
                    recursion(word1, word2, i - 1, j), 
                    recursion(word1, word2, i - 1, j - 1)) + 1;
    }

    int MIN(int a, int b, int c){
        int d = min(a, b);
        return min(d, c);
    }
};

int main(){
    Solution sol;
    cout << sol.minDistance("ophenylhydrazine", "phenylhydrazone");
    return 0;
}