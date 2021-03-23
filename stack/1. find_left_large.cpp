/*
 * ��Ŀ������һ�����飬Ҫ�ҵ������������ÿ��Ԫ����߱���С��Ԫ�ص�λ��
 * - ע�⣺����ߵ�һ������С�ģ�����ж���Ļ�
 * - ���û�У���ô��-1��ʾ��
 *
 * ���أ�һ�����飬��ʾ��߱���С�������±�λ��
 *
 * ���룺[5, 6]
 * �����[-1, 0]
 * ���ͣ�A[0] = 5����߱���С��Ԫ��û��, ���Լ�¼Ϊ = -1
 *       A[1] = 6, ��߱���С��Ԫ��ΪA[0] = 5�����Լ�¼Ϊ   = 0
 *       ���Է���ֵ��[-1, 0]
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

// ���Դ���
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
