#include <bits/stdc++.h>
#include <deque>
#include <iostream>

using namespace std;


 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      
      //default constructor
      TreeNode() : val(0), left(nullptr), right(nullptr) {}

      // constructor with value
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

      // constructor with value and left/right children
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> iterativePreorder(TreeNode* root) {
    vector<int> preorder;
    if (!root) return preorder;

    stack<TreeNode*> s;
    s.push(root);

    while (!s.empty()) {
        TreeNode* node = s.top();
        s.pop();
        preorder.push_back(node->val);

        // Push right child first so that left child is processed first
        if (node->right) s.push(node->right);
        if (node->left) s.push(node->left);
    }

    return preorder;
}

TreeNode* buildTree(const vector<int>& nodes){
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root  = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while(!q.empty() && i < nodes.size()){
        TreeNode* current= q.front();
        q.pop();


        if (nodes[i] != -1){
            current -> left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i >= nodes.size()) break;

        if (nodes[i] != -1){
            current -> right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}


int main() {
    vector<int> nodes = {1, 2, 3, 4, 5, -1, -1, 1};
    TreeNode* root = buildTree(nodes);

    vector<int> preorder = iterativePreorder(root);
    cout << "Iterative Preorder Traversal: ";
    for (int val : preorder) {      
        cout << val << " ";
    }
    cout << endl;
    return 0;
}