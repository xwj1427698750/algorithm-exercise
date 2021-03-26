/*
117. ���ÿ���ڵ����һ���Ҳ�ڵ�ָ�� II
�������ÿ�� next ָ�룬�����ָ��ָ������һ���Ҳ�ڵ㡣����Ҳ�����һ���Ҳ�ڵ㣬�� next ָ������Ϊ NULL��

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
 
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        if(root != nullptr){
            q.push(root);
        }
        while(q.size()>0){
            int size = q.size();
            while(size>0){
                Node * node = q.front();
                q.pop();
                size--;
                if(size==0) node->next = nullptr;
                else node->next = q.front();
                if(node->left!=nullptr) q.push(node->left);
                if(node->right!=nullptr) q.push(node->right);
            }
        }
        return root;
    }
};
