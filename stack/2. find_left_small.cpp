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

//�ⷨ1����ջΪ���� 
vector<int> findLeftSmall(vector<int> &A) {
	if (A.empty()) {
		return {};
	}
	const int size = A.size();
	vector<int> ans(size);
	stack<int> st;
	for (int i = size - 1; i >= 0; i--) {
		while (!st.empty() && A[i] < A[st.top()]) {
			ans[st.top()] = i;
			st.pop();
		}
		st.push(i);//ѹ��ջ��������
	}
	while (!st.empty()) {
		ans[st.top()] = -1;
		st.pop();
	}
	return ans;
	
	//�ⷨ2����left����Ϊ���� 
//	int n = A.size();
//    vector<int> left(n);
//    stack<int> stk;
//
//    for (int i = 0; i < n; i ++ ) {
//        while (stk.size() && A[stk.top()] >= A[i]) stk.pop();
//        if (stk.empty()) left[i] = -1;
//        else left[i] = stk.top();
//        stk.push(i);
//    }
	
	
	//���ӣ�https://www.acwing.com/activity/content/code/content/375419/

}

// ���Դ���
void ASSERT_EQ(vector<int> A, vector<int> B) {
	auto C = findLeftSmall(B);
	assert(A == C);
}

int main(void) {
	ASSERT_EQ({-1, 0}, {2, 5});
	ASSERT_EQ({-1, 0, 1, 2, 1, -1, 5}, {1, 2, 4, 9, 4, 0, 5});
	ASSERT_EQ({-1, -1, -1, -1, 3, -1, -1}, {5, 5, 5, 4, 5, -1, -1});
	return 0;
}
