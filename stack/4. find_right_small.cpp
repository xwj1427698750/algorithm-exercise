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

vector<int> findRightSmall(vector<int> &A) {
	if(A.empty()){
		return {};
	}
	const int size = A.size();
   	vector<int> ans(size);
   	stack<int> st;
   	for(int i=0;i<size;i++){
	   	while(!st.empty()&&A[st.top()]>A[i]){
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
  auto C = findRightSmall(B);
  assert(A == C);
}

int main(void) {
  ASSERT_EQ({1, -1}, {5, 2});
  ASSERT_EQ({5, 5, 5, 4, 5, -1, -1}, {1, 2, 4, 9, 4, 0, 5});
  return 0;
}
