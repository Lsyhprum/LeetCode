# include <iostream>
# include <unordered_map>
# include <list>

using namespace std;

class LRUCache {
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        auto it = m.find(key);
        if(it == m.end()){
            return -1;
        }else{
            pair<int, int> kv = *m[key];
            l.erase(m[key]);
            l.push_front(kv);
            m[key] = l.begin();

            return kv.second;
        }
    }
    
    void put(int key, int value) {
        // 未存在
        auto it = m.find(key);
        if(it == m.end()){
            l.push_front(make_pair(key, value));
            m[key] = l.begin();
            if(l.size() > cap){
                auto it_end = l.back();
                m.erase(it_end.first);
                l.pop_back();
            }
        }else{
            l.erase(m[key]);
            l.push_front(make_pair(key, value));
            m[key] = l.begin();
        }
        return ;
    }

private:
    int cap;
    list<pair<int,int> > l;
    unordered_map<int, list<pair<int, int> >::iterator > m;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){

    return 0;
}