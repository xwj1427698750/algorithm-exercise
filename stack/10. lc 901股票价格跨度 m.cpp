//编写一个 StockSpanner 类，它收集某些股票的每日报价，并返回该股票当日价格的跨度。
//
//今天股票价格的跨度被定义为股票价格小于或等于今天价格的最大连续日数（从今天开始往回数，包括今天）。
//
//例如，如果未来7天股票的价格是 [100, 80, 60, 70, 60, 75, 85]，那么股票跨度将是 [1, 1, 1, 2, 1, 4, 6]。

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
