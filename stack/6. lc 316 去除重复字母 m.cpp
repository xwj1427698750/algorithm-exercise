/*
leetcode 316. ȥ���ظ���ĸ
����һ���ַ��� s ������ȥ���ַ������ظ�����ĸ��ʹ��ÿ����ĸֻ����һ�Ρ�
�豣֤ ���ؽ�����ֵ�����С��Ҫ���ܴ��������ַ������λ�ã���
������Ҫ�ر�ע��num���������,
��ѭ���У�num[stk.top()-'a']��ʾ�ڵ�ǰԪ��s[i]֮���ж��ٸ�stk.top()�ַ� 
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
            num[stk.top()-'a']--;//��ǰ�����Ѿ���ջ
        }else{
            num[stk.top()-'a']--;//��ǰ�����Ѿ���ջ��ֱ�Ӷ�����ʹ��
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
    
