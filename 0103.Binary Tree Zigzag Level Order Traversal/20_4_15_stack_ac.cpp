# include <iostream>
# include <vector>
# include <queue>
# include <stack>

using namespace std;

// Runtime 84.03%
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL) return res;

        stack<TreeNode*> s;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            vector<int> v;
            res.emplace_back(v);

            while(!q.empty()){
                res.back().emplace_back(q.front()->val);

                if(res.size() % 2 == 1){
                    if(q.front()->left){
                        s.push(q.front()->left);
                    }
                    if(q.front()->right){
                        s.push(q.front()->right);
                    }
                }else{
                    if(q.front()->right){
                        s.push(q.front()->right);
                    }
                    if(q.front()->left){
                        s.push(q.front()->left);
                    }
                }
                q.pop();
            }    
            
            while(!s.empty()){
                q.push(s.top());
                s.pop();
            }
        }

        return res;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root -> left = new TreeNode(9);
    root -> right = new TreeNode(20);
    
    root -> left -> left = new TreeNode(3);
    root -> left -> right = new TreeNode(4);

    root -> right -> left = new TreeNode(15);
    root -> right -> right = new TreeNode(7);

    root -> left -> left ->left = new TreeNode(30);
    root -> right -> right -> right = new TreeNode(70);

    Solution sol;

    vector<vector<int>> res = sol.zigzagLevelOrder(root);
    for(int i = 0; i < res.size(); i ++){
        for(int j = 0; j < res[i].size(); j ++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}