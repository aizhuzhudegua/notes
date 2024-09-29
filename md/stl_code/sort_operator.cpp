#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct custom
{
    int a;
    int b;
    int c;
    bool operator < (const custom& c){
        return b > c.b;
    }

};

int main() {

    vector<custom> v;
    v.push_back(custom{3,2,7});
    v.push_back(custom{4,1,3});
    v.push_back(custom{2,3,1});
    v.push_back(custom{5,6,9});


    sort(v.begin(),v.end());

    for(auto it = v.begin();it < v.end(); it ++)
    {   
        cout << it->a << it->b << it->c << " ";
    }
    cout << endl;
    return 0;
}