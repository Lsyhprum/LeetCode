#include <iostream>
#include <unordered_map>

using namespace std;


class Solution {
public:
    string reorganizeString(string S) {
        // aba
        // cccaa -> cacac
        // cccaaa -> caccaca
        unordered_map<char, int> mp;

        for(char c : S) {
            mp[c] ++;
        }

        

    }
};

int main() {
    return 0;
}