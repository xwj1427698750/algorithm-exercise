// lc 42. 接雨水
//给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
//本题存在多种解法， 单调栈只是其中一种
//最优的是双指针 
#include<stdio.h> 
#include<stack>
#include<string>
#include<vector>
using namespace std;

//栈的解法 
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
//双指针解法 
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
