#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.size() == 0) return 0;

        int time = duration;

        int end = 0;
        for(int i = 0; i < timeSeries.size() - 1; i ++) {
            end = timeSeries[i] + duration;
            if(end < timeSeries[i + 1]) {   // 未重叠
                time += duration;
            }else {
                time += (timeSeries[i + 1] - timeSeries[i]);
            }
        }

        return time;
    }
};

int main() {
    Solution sol;
    vector<int> timeSeries = {1, 2, 3, 4, 5};
    std::cout << sol.findPoisonedDuration(timeSeries, 2);

    return 0;
}