
//给定一个以字符串表示的非负整数 num，移除这个数中的 k 位数字，使得剩下的数字最小。
//
//注意:
//
//num 的长度小于 10002 且≥ k。
//num 不会包含任何前导零。
//示例 1 :
//
//输入: num = "1432219", k = 3
//输出: "1219"
//解释: 移除掉三个数字 4, 3, 和 2 形成一个新的最小的数字 1219。

#include<stdio.h> 
#include<stack>
#include<string>
#include<vector>
using namespace std;

int main(void) {
  
  return 0;
}

string removeKdigits(string num, int k) {
    string ans;//构建一个单调递增栈
    int len = num.size();
    for(int i=0;i<len;i++){
        while(ans.size()&&num[i]<ans.back()&&k>0){
            ans.pop_back();
            k--;
        }
        ans.push_back(num[i]);
    }
    while(k>0&&ans.size()){
        ans.pop_back();
        k--;
    } 
    while(ans.size()&&ans[0]=='0'){
        ans.erase(0,1);
    }
    if(ans.size()==0){
        ans = "0";
    }
    return ans;
}
