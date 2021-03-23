/*
 * 题目：给定一个数组，要找到这个数组里面每个元素左边比我小的元素的位置
 * - 注意：是左边第一个比我小的，如果有多个的话
 * - 如果没有，那么用-1表示。
 *
 * 返回：一个数组，表示左边比我小的数的下标位置
 *
 * 输入：[5, 6]
 * 输出：[-1, 0]
 * 解释：A[0] = 5，左边比我小的元素没有, 所以记录为 = -1
 *       A[1] = 6, 左边比我小的元素为A[0] = 5，所以记录为   = 0
 *       所以返回值是[-1, 0]
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

vector<int> findLeftLarger(vector<int> &A) {
	const int size = A.size();
	if(size==0){
		return {};
	}
	vector<int> ans(size);
	stack<int> st;
	for(int i=size-1;i>=0;i--){
		while(!st.empty()&&A[i]>A[st.top()]){
			ans[st.top()] = i;
			st.pop();
		}
		st.push(i);
	}
	while(!st.empty()){
		ans[st.top()] = -1;
		st.pop();
	}
	return ans;
}

// 测试代码
void ASSERT_EQ(int i, vector<int> A, vector<int> B) {
	auto C = findLeftLarger(B);
	assert(A == C);
	printf("test case %d is passed\n",i);
}

int main(void) {
	ASSERT_EQ(0, {-1, -1}, {2, 5});
	ASSERT_EQ(1, {-1, -1, -1, -1, 3, 4, 3}, {1, 2, 4, 9, 4, 0, 5});
	ASSERT_EQ(2, {-1, -1, -1, 2, -1, 4, 4}, {5, 5, 5, 4, 5, -1, -1});
	printf("All test cases are passed\n");
	return 0;
}
