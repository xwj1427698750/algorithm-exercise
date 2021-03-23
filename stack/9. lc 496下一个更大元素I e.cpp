//������ û���ظ�Ԫ�� ������nums1 �� nums2 ������nums1 �� nums2 ���Ӽ���
//
//�����ҳ� nums1 ��ÿ��Ԫ���� nums2 �е���һ��������ֵ��
//
//nums1������ x ����һ������Ԫ����ָ x �� nums2 �ж�Ӧλ�õ��ұߵĵ�һ���� x ���Ԫ�ء���������ڣ���Ӧλ����� -1 ��



#include<stdio.h> 
#include<stack>
#include<string>
#include<vector>
#include<unordered_map> 
using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    int size1 = nums1.size();
    int size2 = nums2.size();
    vector<int> rightMax(size2);
    vector<int> ans(size1);
    stack<int> stk;
    unordered_map<int,int> map;
    for(int i=size2-1;i>=0;i--){
        while(stk.size()&&nums2[i]>=nums2[stk.top()]){
            stk.pop();
        }
        if(stk.empty()){
            rightMax[i] = -1;
        }else{
            rightMax[i] = nums2[stk.top()];
        }
        stk.push(i);
        map[nums2[i]] = rightMax[i];
    }
    for(int i=0;i<size1;i++){
        ans[i] = map[nums1[i]];
    }
    return ans;
}
