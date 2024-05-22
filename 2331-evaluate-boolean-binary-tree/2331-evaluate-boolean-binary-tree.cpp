#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    static bool evaluateTree(TreeNode* root) { 
        vector<TreeNode*> stack={root};
        while(!stack.empty()){
            auto Node=stack.back();
            if (!Node->left && !Node->right){
                stack.pop_back();
                continue;
            }
            int l, r;
            //children are computed already
            if ((l=Node->left->val)<=1 && (r=Node->right->val)<=1){
                stack.pop_back();
                Node->val=(Node->val==3)?l&r:l|r;
            }
            else{// children are not yet computed
                stack.push_back(Node->right);
                stack.push_back(Node->left);
            }
        }
        return root->val;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();