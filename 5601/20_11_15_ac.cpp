#include <iostream>
#include <vector>

using namespace std;

class OrderedStream {
public:
    OrderedStream(int n) {
        for(int i = 0; i < n + 1; i ++) {
            container.push_back("");
            flags.push_back(false);
        }
    }
    
    vector<string> insert(int id, string value) {
        vector<string> res;

        container[id] = value;
        flags[id] = false;

        while(ptr < container.size() && flags[ptr] == false && container[ptr] != "") {
            res.push_back(container[ptr]);
            flags[ptr] = true;
            ptr ++;
        }

        return res;
    }

private:

    std::vector<string> container;
    std::vector<bool> flags;
    int ptr = 1;
};
int main() {

    
    OrderedStream* obj = new OrderedStream(5);
    vector<string> param_1 = obj->insert(3, "ccccc");
    vector<string> param_2 = obj->insert(1, "aaaaa");
        vector<string> param_3 = obj->insert(2, "bbbbb");

    for(string s : param_3) {
        std::cout << s << std::endl;
    }


    return 0;
}