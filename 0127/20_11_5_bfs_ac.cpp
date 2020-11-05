#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(string &word : wordList) {
            addEdge(word);
        }

        addEdge(beginWord);
        if(!wordId.count(endWord)) return 0;

        vector<int> dis(nodeNum, INT_MAX);
        int beginId = wordId[beginWord], endId = wordId[endWord];
        dis[beginId] = 0;

        queue<int> que;
        que.push(beginId);
        while (!que.empty()) {
            int x = que.front();
            que.pop();
            if (x == endId) {
                return dis[endId] / 2 + 1;
            }
            for (int& it : edge[x]) {
                if (dis[it] == INT_MAX) {
                    dis[it] = dis[x] + 1;
                    que.push(it);
                }
            }
        }
        return 0;
    }

private:
    unordered_map<string, int> wordId;
    vector<vector<int>> edge;
    int nodeNum = 0;

    void addWord(string& word) {
        if(!wordId.count(word)) {
            wordId[word] = nodeNum ++;
            edge.emplace_back();
        }
    }

    void addEdge(string& word) {
        addWord(word);
        int id1 = wordId[word];
        for(char &it : word) {
            char tmp = it;
            it = '*';
            addWord(word);
            int id2 = wordId[word];
            edge[id1].push_back(id2);
            edge[id2].push_back(id1);
            it = tmp;
        }
    }

    int diff(string s1, string s2) {
        int num = 0;
        for(int i = 0; i < s1.size(); i ++) {
            if(s1[i] != s2[i]) num ++;
        }
        return num;
    }
};

int main() {
    Solution sol;
    vector<string> v = {"hot","dot","dog","lot","log", "cog"};
    std::cout << sol.ladderLength("hit", "cog", v);
    return 0;
}