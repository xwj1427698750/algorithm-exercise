//581. �����������������
//����һ���������� nums ������Ҫ�ҳ�һ�� ���������� �����������������������������ô�������鶼���Ϊ��������
//
//�����ҳ���������� ��� �����飬��������ĳ��ȡ�
//ʾ�� 1��
//
//���룺nums = [2,6,4,8,10,9,15]
//�����5
//���ͣ���ֻ��Ҫ�� [6, 4, 8, 10, 9] ��������������ô���������Ϊ��������

#include<stdio.h> 
#include<stack>
#include<string>
#include<vector>
using namespace std;

int main(void) {
  
  return 0;
}


int findUnsortedSubarray(vector<int>& nums) {
    int size = nums.size();
    int begin = size-1, end = 0; 
    stack<int> stk1;
    stack<int> stk2;
    for(int i=0;i<size;i++){
        while(stk1.size()&&nums[i]<nums[stk1.top()]){
            if(begin>stk1.top()){
                begin = stk1.top();
            }
            stk1.pop();
        }
        stk1.push(i);
    }
    if(stk1.size()==size) return 0;//��������
   
    for(int i=size-1;i>=0;i--){
        while(stk2.size()&&nums[i]>nums[stk2.top()]){
            if(end < stk2.top()){
                end = stk2.top();
            }
            stk2.pop();
        }
        stk2.push(i);
    }
    return end - begin + 1;
}
