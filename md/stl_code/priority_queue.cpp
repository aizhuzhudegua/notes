#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct custom
{
    int a;
    int b;
    int c;
    bool operator < (const custom& cust) const{
        if (a == cust.a) {
            if (b == cust.b) {
                return c < cust.c; 
            } else {
                return b < cust.b; 
            }
        } else {
            return a < cust.a; 
        }
    }
};

int main() {
    priority_queue<custom> que;
    que.push(custom{4, 2, 7});
    que.push(custom{4, 2, 3});
    que.push(custom{2, 3, 1});
    que.push(custom{5, 6, 9});

    while (!que.empty()) {
        custom top = que.top();
        cout << top.a <<  top.b <<  top.c << " ";  // 增加空格以提高可读性
        que.pop();
    }

    cout << endl;
    return 0;
}
