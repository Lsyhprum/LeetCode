#include <iostream>
#include <queue>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        trips_.clear();
        route_.clear();

        for(const auto& t : tickets) {
            trips_[t[0]].push_back(t[1]);
        }

        for(auto& t : trips_){
            auto& dests = t.second;

            sort(dests.begin(), dests.end());
        }

        const string kStart = "JFK";

        visit(kStart);

        return vector<string>(route_.crbegin(), route_.crend());
    }

private:
    map<string, deque<string>> trips_;
    vector<string> route_;

    void visit(const string& src){
        auto& dests = trips_[src];

        while(!dests.empty()){
            const string dest = dests.front();

            dests.pop_front();

            visit(dest);
        }

        route_.push_back(src);
    }
};

int main(){
    Solution sol;
    //[["JFK","KUL"],["JFK","NRT"],["NRT","JFK"]]
    //vector<vector<string>> tickets = {{"JFK","SFO"}, {"JFK","ATL"}, {"SFO","ATL"}, {"SFO","JFK"}, {"ATL","SFO"}};
    vector<vector<string>> tickets = {{"JFK","KUL"}, {"JFK","NRT"}, {"NRT","JFK"}};
    for(string s : sol.findItinerary(tickets))
        cout << s << endl;
    return 0;
}