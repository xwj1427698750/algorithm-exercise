
//����һ�����ַ�����ʾ�ķǸ����� num���Ƴ�������е� k λ���֣�ʹ��ʣ�µ�������С��
//
//ע��:
//
//num �ĳ���С�� 10002 �ҡ� k��
//num ��������κ�ǰ���㡣
//ʾ�� 1 :
//
//����: num = "1432219", k = 3
//���: "1219"
//����: �Ƴ����������� 4, 3, �� 2 �γ�һ���µ���С������ 1219��

#include<stdio.h> 
#include<stack>
#include<string>
#include<vector>
using namespace std;

int main(void) {
  
  return 0;
}

string removeKdigits(string num, int k) {
    string ans;//����һ����������ջ
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
