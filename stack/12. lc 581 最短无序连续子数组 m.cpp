//581. 最短无序连续子数组
//给你一个整数数组 nums ，你需要找出一个 连续子数组 ，如果对这个子数组进行升序排序，那么整个数组都会变为升序排序。
//
//请你找出符合题意的 最短 子数组，并输出它的长度。
//示例 1：
//
//输入：nums = [2,6,4,8,10,9,15]
//输出：5
//解释：你只需要对 [6, 4, 8, 10, 9] 进行升序排序，那么整个表都会变为升序排序。

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
    if(stk1.size()==size) return 0;//单调序列
   
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
