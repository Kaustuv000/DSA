#include <bits/stdc++.h>
#include  <deque>
#include <iostream>
using namespace std;

// struct TreeNode{
//     int data;
//     TreeNode* left;
//     TreeNode* right;

//     TreeNode(int val){
//         data = val;
//         left = NULL;
//         right = NULL;

//     }
// };

// vector<vector<int>> LevelOrder(TreeNode* root) {
//     vector<vector<int>> ans;
//     if (!root) return ans;

//     queue<TreeNode*> q;
//     q.push(root);

//     while (!q.empty()) {
//         int size = q.size();
//         vector<int> level;

//         for (int i = 0; i < size; ++i) {
//             TreeNode* node = q.front();
//             q.pop();

//             level.push_back(node->val);

//             if (node->left) q.push(node->left);
//             if (node->right) q.push(node->right);
//         }

//         ans.push_back(level);
//     }
//     return ans;
// }


// int main(){
//     // Example tree construction
//     //      1
//     //     / \
//     //    2   3
//     //   / \
//     //  4   5

//     TreeNode* root = new TreeNode(1);
//     root->left = new TreeNode(2);
//     root->right = new TreeNode(3);
//     root->left->left = new TreeNode(4);
//     root->left->right = new TreeNode(5);

//         vector<vector<int>> levels = LevelOrder(root);

//         for (const auto& level : levels) {
//             for (int val : level) {
//                 cout << val << " ";
//             }
//             cout << endl; // new line after each level
//         } 
//         return 0;
// }       

// building a tree from array input
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Step 2: Build tree from level order vector
TreeNode* buildTreeLevelOrder(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        // Left child
        if (nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;

        if (i >= nodes.size()) break;

        // Right child
        if (nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}

// Step 3: Level order traversal
vector<vector<int>> LevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();

            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        ans.push_back(level);
    }
    return ans;
}

// Step 4: Main
int main() {
    vector<int> nodes = {1, 2, 3, 4, 5, -1, -1, 1};
    TreeNode* root = buildTreeLevelOrder(nodes);

    vector<vector<int>> levels = LevelOrder(root);

    for (const auto& level : levels) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
