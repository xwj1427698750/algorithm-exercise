/*
103. 二叉树的锯齿形层序遍历
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
*/
#include<stdio.h> 
#include<stack>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
 using namespace std;
 
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
 int main(void) {
   
   return 0;
 }

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<TreeNode*> q;
    int level = 0;
    if(root != nullptr){
        q.push(root);
    }
    while(q.size()>0){
        level++;
        int size = q.size();
        vector<int> row;
        while(size>0){
            TreeNode* node = q.front();
            q.pop();
            size--;
            row.push_back(node->val);
            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        if(level %2 == 0) reverse(row.begin(),row.end());
        ans.push_back(row);
    }
    return ans;
}
