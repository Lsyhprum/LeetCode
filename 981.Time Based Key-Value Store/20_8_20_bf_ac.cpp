#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

//
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[move(key)].emplace(timestamp, move(value));
    }
    
    string get(string key, int timestamp) {
        auto m = mp.find(key);
        if(m == mp.end()) return "";

        auto it = m->second.upper_bound(timestamp);

        if(it == begin(m->second)) return "";
        return prev(it)->second;
    }

private:
    unordered_map<string, map<int, string>> mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

int main(){
    TimeMap* obj = new TimeMap();
    obj->set("foo", "bar", 1);
    cout << obj->get("foo", 3);


    return 0;
}