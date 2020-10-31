#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <random>

using namespace std;

class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> idx;
    vector<int> nums;

    /** Initialize your data structure here. */
    RandomizedCollection() {

    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        nums.push_back(val);
        idx[val].insert(nums.size() - 1);
        return idx[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (idx.find(val) == idx.end()) {
            return false;
        }
        int i = *(idx[val].begin());
        nums[i] = nums.back();
        idx[val].erase(i);
        idx[nums[i]].erase(nums.size() - 1);
        if (i < nums.size() - 1) {
            idx[nums[i]].insert(i);
        }
        if (idx[val].size() == 0) {
            idx.erase(val);
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:

 */

int main() {
    RandomizedCollection* obj = new RandomizedCollection();
    std::cout << obj->insert(0) << std::endl;
    std::cout << obj->remove(0) << std::endl;
    std::cout << obj->insert(-1) << std::endl;
    std::cout << obj->remove(0) << std::endl;
    std::cout << obj->getRandom() << std::endl;
    std::cout << obj->getRandom() << std::endl;
    std::cout << obj->getRandom() << std::endl;
    std::cout << obj->getRandom() << std::endl;
    std::cout << obj->getRandom() << std::endl;
    std::cout << obj->getRandom() << std::endl;
    std::cout << obj->getRandom() << std::endl;

    return 0;
}