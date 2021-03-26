/**
 * 102. ¶þ²æÊ÷µÄ²ãÐò±éÀú
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
#include<stdio.h> 
#include<stack>
#include<string>
#include<vector>
#include<queue>
 using namespace std;
 
 int main(void) {
   
   return 0;
 }
 struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode() : val(0), left(nullptr), right(nullptr) {}
       TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
       TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    if(root != nullptr){
        q.push(root);
    }
    while(q.size()>0){
        int size  = q.size();
        vector<int> row;
        while(size>0){
            TreeNode* node = q.front();
            row.push_back(node->val);
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr) q.push(node->right);
            q.pop();
            size--;
        }
        ans.push_back(row);
    }
    return ans;
}
