//你两个 没有重复元素 的数组nums1 和 nums2 ，其中nums1 是 nums2 的子集。
//
//请你找出 nums1 中每个元素在 nums2 中的下一个比其大的值。
//
//nums1中数字 x 的下一个更大元素是指 x 在 nums2 中对应位置的右边的第一个比 x 大的元素。如果不存在，对应位置输出 -1 。



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
