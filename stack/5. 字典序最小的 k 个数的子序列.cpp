//�� 4���ֵ�����С�� k ������������
//����Ŀ������һ������������� k��Ҫ������ȡ�� k ������������������һ�������У���Ҫ���㣺1. ����Ϊ k��2.�ֵ�����С��
//
//���룺nums = [3,5,2,6], k = 2
//�����[2,6]
//
//���ͣ������п��ܵĽ⣺{[3,5], [3,2], [3,6], [5,2], [5,6], [2,6]} �У�[2,6] �ֵ�����С��
//
//��ν�ֵ�����ǣ������������飺x = [x1,x2,x3,x4]��y = [y1,y2,y3,y4]����� 0 �� p < i��xp == yp �� xi < yi����ô������Ϊ x ���ֵ���С�� y��

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

vector<int> findSmallSeq(vector<int> &nums, int k) {
  if (nums.empty()) {
    return {};	
  }
  vector<int> ans(k);
  stack<int> s;

  // �������ɵ���ջ
  for (size_t i = 0; i < nums.size(); i++) {
    const int x = nums[i];
    const int left = nums.size() - i;
    // ע��������Ҫ��ȡ��k����������ע������ӵ������ĸ���
    while (!s.empty() && (s.size() + left > k) && s.top() > x) {
      s.pop();
    }
    s.push(x);
  }

  // �������ջ�������̫�࣬��ô����ֻ��Ҫȡ��ǰk���Ϳ����ˡ�
  // �����ջ�е�Ԫ����Ҫ�ӵ���
  while (s.size() > k) {
    s.pop();
  }

  // ��k��Ԫ��ȡ������ע������ȡ��˳��!
  for (int i = k - 1; i >= 0; i--) {
    ans[i] = s.top();
    s.pop();
  }

  return ans;
}

// ���Դ���
void ASSERT_EQ(vector<int> A, vector<int> B, int k) {
  auto C = findSmallSeq(B, k);
  for(int i=0;i<C.size();i++){
  	printf("%d ",C[i]);
  }
  printf("\n");
  assert(A == C);
}

int main(void) {
  ASSERT_EQ({1, 2, 3}, {9, 2, 4, 5, 1, 2, 6, 3, 100, 4}, 3);
  ASSERT_EQ({1, 2}, {9, 2, 4, 5, 1, 2, 6, 3, 100, 4}, 2);
  ASSERT_EQ({1}, {9, 2, 4, 5, 1, 2, 6, 3, 100, 4}, 1);
  ASSERT_EQ({1}, {1, 1, 1, 1}, 1);
  ASSERT_EQ({1, 1}, {1, 1, 1, 1}, 2);
  ASSERT_EQ({1, 1, 1}, {1, 1, 1}, 3);
  return 0;
}
