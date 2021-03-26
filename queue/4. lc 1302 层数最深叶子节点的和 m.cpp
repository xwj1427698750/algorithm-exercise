/*
1302. ��������Ҷ�ӽڵ�ĺ�
����һ�ö������ĸ��ڵ� root �����㷵�� ���������Ҷ�ӽڵ�ĺ� ��
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

int deepestLeavesSum(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> q;
        if(root != nullptr){
            q.push(root);
        }
        while(q.size()>0){
            int size = q.size();
            vector<int> row;
            bool isDeepest = true;
            while(size>0){
                TreeNode* node = q.front();
                q.pop();
                size--;
                row.push_back(node->val);
                if(node->left != nullptr){
                    q.push(node->left);
                    isDeepest = false;
                } 
                if(node->right != nullptr){
                    q.push(node->right);
                    isDeepest = false;
                } 
            }
            if(isDeepest == true){
                for(int i=0;i<row.size();i++) ans += row[i];
            }
        }
        return ans;
    }
