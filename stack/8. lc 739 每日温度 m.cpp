//739. ÿ���¶�
//�����ÿ�� ���� �б���������һ���б�
//��Ӧλ�õ����Ϊ��Ҫ��۲⵽���ߵ����£�������Ҫ�ȴ���������
//�����������֮�󶼲������ߣ����ڸ�λ���� 0 �����档

#include<stdio.h> 
#include<stack>
#include<string>
#include<vector>
using namespace std;

vector<int> dailyTemperatures(vector<int>& T) {
    stack<int> stk;
    int N = T.size();
    vector<int> ans(N);
    for(int i=N-1; i>=0; i--){
        while(stk.size()&&T[i]>=T[stk.top()]){
            stk.pop();
        }
        if(!stk.empty())  ans[i] = stk.top() - i;
        stk.push(i);
       
    }

    return ans;
}

int main(void) {
  
  return 0;
}
