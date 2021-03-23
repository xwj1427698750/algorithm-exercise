/*
leetcode 316. 去除重复字母
给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次。
需保证 返回结果的字典序最小（要求不能打乱其他字符的相对位置）。
这里需要特别注意num数组的意义,
在循环中，num[stk.top()-'a']表示在当前元素s[i]之后还有多少个stk.top()字符 
*/


#include<stdio.h> 
#include<stack>
#include<string>
using namespace std;

string removeDuplicateLetters(string s) {
    int num[26] = {0};
    int inStack[26] = {0};
    int len = s.length();
    stack<char> stk;
    for(int i=0;i<len;i++){
        num[s[i]-'a']++;
    }
    for(int i=0;i<len;i++){
        printf("%c \n",s[i]);
        if(inStack[s[i]-'a'] ==0){
        	if(stk.size())
        		printf("num[%c] is %d \n",stk.top(), num[stk.top()-'a']);
            while(stk.size()&&s[i]<stk.top()&&num[stk.top()-'a']>=1){
            	printf("top is %c \n",stk.top());
//            	printf("num[%d] is %d \n",stk.top()-'a', num[stk.top()-'a']);
                // if(num[stk.top()-'a']>1){
                    num[stk.top()-'a']--;
                    inStack[stk.top()-'a'] = 0;
                    stk.pop();
                    
                // }
            }
            stk.push(s[i]);
            inStack[s[i]-'a'] = 1;
            num[stk.top()-'a']--;//当前数字已经入栈
        }else{
            num[stk.top()-'a']--;//当前数字已经入栈，直接丢弃不使用
        }
    }

    string ans;
    while(!stk.empty()){
        ans = stk.top() + ans;
        stk.pop();
    }
    return ans;
}
int main(){
	string s = "bddbccd";
	string ans = removeDuplicateLetters(s);
	printf("%s",ans.c_str());
	return 0;
} 
    
