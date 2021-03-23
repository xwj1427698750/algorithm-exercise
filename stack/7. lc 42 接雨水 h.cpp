// lc 42. ����ˮ
//���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ��
//������ڶ��ֽⷨ�� ����ջֻ������һ��
//���ŵ���˫ָ�� 
#include<stdio.h> 
#include<stack>
#include<string>
#include<vector>
using namespace std;

//ջ�Ľⷨ 
int trapByStack(vector<int>& height) {
    int size = height.size(), ans =0;
    if(size==0) return 0;
    stack<int> stk;
    for(int i=0;i<size;i++){
        while(stk.size()&&height[i]>height[stk.top()]){
            int buttom = stk.top();
            stk.pop();
            if(stk.empty()) break;
            int h = (min(height[i],height[stk.top()]) - height[buttom])*(i-stk.top()-1);
            if(h>0) ans += h;
        }
        stk.push(i);
    }
    return ans;
}
//˫ָ��ⷨ 
int trap(vector<int>& height) {
    int size = height.size(), ans =0;
    if(size==0) return 0;
    int left = 0,right = size-1, left_max = 0, right_max = 0;
    while(left<right){
        if(height[left]<=height[right]){
            if(left_max < height[left]) left_max = height[left];
            else ans += (left_max-height[left]);
            left++;
        }else{
            if(right_max < height[right]) right_max = height[right];
            else ans += (right_max-height[right]);
            right--;
        }
    }
    return ans;
}
int main(){
	
	return 0;
} 
