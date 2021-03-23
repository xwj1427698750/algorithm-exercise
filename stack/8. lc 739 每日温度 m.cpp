//739. 每日温度
//请根据每日 气温 列表，重新生成一个列表。
//对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。
//如果气温在这之后都不会升高，请在该位置用 0 来代替。

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
