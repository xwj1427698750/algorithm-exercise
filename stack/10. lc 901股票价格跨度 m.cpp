//��дһ�� StockSpanner �࣬���ռ�ĳЩ��Ʊ��ÿ�ձ��ۣ������ظù�Ʊ���ռ۸�Ŀ�ȡ�
//
//�����Ʊ�۸�Ŀ�ȱ�����Ϊ��Ʊ�۸�С�ڻ���ڽ���۸����������������ӽ��쿪ʼ���������������죩��
//
//���磬���δ��7���Ʊ�ļ۸��� [100, 80, 60, 70, 60, 75, 85]����ô��Ʊ��Ƚ��� [1, 1, 1, 2, 1, 4, 6]��

#include<stdio.h> 
#include<stack>
#include<string>
#include<vector>
using namespace std;

class StockSpanner {
public:
    // typedef struct{
    //     int price;
    //     int num_less;
    // }stock;
    // stack<pair<stock> stk;
    stack<pair<int,int>> stk;
    StockSpanner() {
        
    }
    
    int next(int price) {
        pair<int,int> p(price,1);
        while(stk.size()&&price>=stk.top().first){
            p.second += stk.top().second;
            stk.pop();
        }
        stk.push(p);
        return p.second;
    }
};
