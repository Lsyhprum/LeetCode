#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

// time complexity : O(2^N), 6.66%
// memory complexity : 5.24%

class Solution {
public: 
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end(), [](vector<string> v1, vector<string> v2){return v1[1] < v2[1];});

        map<string, vector<pair<string, bool>>> iti;

        for(auto v : tickets)
            iti[v[0]].push_back({v[1], true});

        vector<string> ans{"JFK"};

        dfs(tickets, iti, ans);

        return ans;
    }

private:

    bool dfs(const vector<vector<string>> &tickets, map<string, vector<pair<string, bool>>> &iti, vector<string> &ans){
        if(ans.size() - 1 == tickets.size()){
            return true;
        }

        vector<pair<string, bool>> candidate = iti[ans[ans.size() -1]];    
        
        for(int i = 0; i < candidate.size(); i ++){
            if(candidate[i].second){
                string s ;
                // cout << i << " " << candidate.size() <<endl;
                // cout << iti[ans[ans.size() - 1]].size() <<endl;
                iti[ans[ans.size() - 1]][i].second = false;
                s = iti[ans[ans.size() - 1]][i].first;

                ans.push_back(s);

                if(dfs(tickets, iti, ans)){
                    return true;
                }

                ans.pop_back();

                iti[ans[ans.size() - 1]][i].second = true;
            }

            // cout << "wtf" << endl;
            // cout << i << " " << candidate.size() <<endl;
        }

        return false;
    }   
};

int main(){
    Solution sol;
    //[["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
    vector<vector<string>> tickets = {{"JFK","SFO"}, {"JFK","ATL"}, {"SFO","ATL"}, {"SFO","JFK"}, {"ATL","SFO"}};
    //vector<vector<string>> tickets = {{"JFK","KUL"}, {"JFK","NRT"}, {"NRT","JFK"}};
    for(string s : sol.findItinerary(tickets))
        cout << s << endl;
    return 0;
}