  
/*
 * ��Ŀ������һ�����飬Ҫ�ҵ������������ÿ��Ԫ���ұ߱��Ҵ��Ԫ�ص�λ��
 * - ע�⣺���ұߵ�һ�����Ҵ�ģ�����ж���Ļ�
 * - ���û�У���ô��-1��ʾ��
 * ���أ�һ�����飬��ʾ�ұ߱��Ҵ�������±�λ��
 *
 * ���룺[5, 6]
 * �����[1, -1]
 * ���ͣ�A[0] = 5���ұ߱��Ҵ����A[1] = 6, ���Լ�¼Ϊ = 1
 *       A[1] = 6, �ұ߱��Ҵ��Ԫ��û�У����Լ�¼Ϊ   = -1
 *       ���Է���ֵ��[1, -1]
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
		st.push(i);//ѹ��ջ�������� 
	}
	while(!st.empty()){
		ans[st.top()] = -1;
		st.pop();
	}
	return ans;
}

// ���Դ���
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
