#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        int res = 0;
        ring = ring + ring + ring;
        dfs(ring, key, ring.size() / 3, 0, 0, res);
        return res;
    }

private:
    void dfs(string ring, string key, int ring_pos, int key_pos, int op, int &res) {
        std::cout 
        // 查找失败终止条件
        if(ring_pos == 0 || ring_pos == ring.size() - 1) return;

        if(ring[ring_pos] == key[key_pos]){
            op ++;
            key_pos ++;
            if(ring_pos >= (ring.size() / 3 * 2)) {
                ring_pos -= ring.size() / 3;
            } else if(ring_pos < (ring.size() / 3)) {
                ring_pos += ring.size() / 3;
            }
        }

        // 查找成功终止条件
        if(key_pos == key.size()) {
            res = min(res, op);
            return;
        }

        // 不旋转
        dfs(ring, key, ring_pos, key_pos, op, res);

        // 逆时针旋转
        dfs(ring, key, ring_pos - 1, key_pos, op + 1, res); 

        // 顺时针旋转
        dfs(ring, key, ring_pos + 1, key_pos, op + 1, res);

    }
};

int main() {
    Solution sol;
    std::cout << sol.findRotateSteps("godding", "gd");
    return 0;
}