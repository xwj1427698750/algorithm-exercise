  
/*
 * 题目：给定一个数组，要找到这个数组里面每个元素右边比我大的元素的位置
 * - 注意：是右边第一个比我大的，如果有多个的话
 * - 如果没有，那么用-1表示。
 * 返回：一个数组，表示右边比我大的数的下标位置
 *
 * 输入：[5, 6]
 * 输出：[1, -1]
 * 解释：A[0] = 5，右边比我大的是A[1] = 6, 所以记录为 = 1
 *       A[1] = 6, 右边比我大的元素没有，所以记录为   = -1
 *       所以返回值是[1, -1]
 */

#include <assert.h>
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <numeric>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

vector<int> findRightlarger(vector<int> &A) {
	if(A.empty()){
		return {};
	}
	const int size = A.size();
   	vector<int> ans(size);
   	stack<int> st;
   	for(int i=0;i<size;i++){
	   	while(!st.empty()&&A[st.top()]<A[i]){
	   		ans[st.top()] = i;
	   		st.pop();
		}
		st.push(i);//压入栈的是索引 
	}
	while(!st.empty()){
		ans[st.top()] = -1;
		st.pop();
	}
	return ans;
}

// 测试代码
void ASSERT_EQ(vector<int> A, vector<int> B) {
  auto C = findRightlarger(B);
  assert(A == C);
}

int main(void) {
  ASSERT_EQ({1, -1}, {2, 5});
  ASSERT_EQ({1, 2, 3, -1, 6, 6, -1}, {1, 2, 4, 9, 4, 0, 5});
  ASSERT_EQ({-1, -1, -1, 4, -1, -1, -1},{5, 5, 5, 4, 5, -1, -1});
  return 0;
}
