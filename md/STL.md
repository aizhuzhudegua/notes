# STL

## 容器：数组、链表、树、栈、队列、集合、映射表

### vector

为了获得连续的空间，vector在容量不够时会找一片新的连续空间（似乎是原来空间的两倍），然后将原有的数据和新的数据拷贝到新的空间。

```c++
#include<vector>
//构造函数
vector<T>() //默认
vector<int> v2(v1.begin(),v1.end()) //区间复制
vector<T>(n,elem) //n个elem方式
vector(const vector &vec) //拷贝构造
vector<int> vec6 = {10, 20, 30, 40};
vector<int> abc(10);    //初始化了10个默认值为0的元素

//插入元素
vector<int> v;  //初始化容器
v.push_bask(e); //插入元素e

//遍历
//方法一
vector<int>::iterator itBegin = v.begin(); //起始迭代器
vector<int>::iterator itEnd = v.end(); //结束迭代器，指向最后一个元素的下一个位置

while(itBegin!=itEnd){
    cout<< *itBegin <<endl;
    itBegin++;
}

//方法二
for(vector<int>::iterator it = v.begin();v.begin()!=v.end();it++){
     cout<< *it <<endl;
}

//方法三，用算法for_each

void myPrint(int val){
    cout<<val<<endl;
}


#include<algorithm>
for_each(v.begin(),v.end(),myPrint); #用到了回调的技术
```

### string

```c++
#include <string> 
using namespace std;

//默认构造
string();
//用char *
string(const char *);
//拷贝构造
string(const string& str);
//用n个c初始化
string(int n,char c);
    
//赋值操作
string & operator=(const char* str);
string & operator=(const string &s);
string & operator=(char c);
string & assign(const char *s);
str.assign("hello C++");
string & assign(const char *s,int n); //把字符串s的前n个赋值
string & assign(const string &s);
string & assign(int n,char c);//用n个字符c赋给当前字符串

//追加字符串
string & operator+=(const char* str);
string & operator+=(const string &str);
string & operator+=(char c);
string & append(const char *s);
string & append(const char *s,int n); //把字符串s的前n个追加
string & append(const string &s);
string & append(const string &s,int pos,int n);//字符串pos开始的n个字符串

//查找字符串
//npos=-1
int find(const string& str,int pos = 0) const; //从pos开始查找字符串str第一次出现的位置
int find(const char * s,int pos = 0) const; //从pos开始查找字符串s第一次出现的位置
int find(const char * s,int pos,int n) const; //从pos查找字符串s的前n个字符第一次出现的位置
int find(const char c,int pos = 0) const; //查找字符c第一次出现的位置
int rfind(const string& str,int pos = npos) const; //从pos开始查找字符串str最后一次出现的位置
int rfind(const char * s,int pos = npos) const; //从pos开始查找字符串s最后一次出现的位置
int rfind(const char * s,int pos,int n) const; //从pos查找字符串s的前n个字符最后一次出现的位置
int rfind(const char c,int pos = 0) const; //查找字符c最后一次出现的位置
//find从左往右找，rfind从右往左找，返回值不一定相同
string& replace(int pos,int n,const string& str); //替换从pos开始的n个字符为str
string& replace(int pos,int n,const char* str); //替换从pos开始的n个字符为str
string str1 = "abcdefg";
str1.replace(1,3,"1111");
//a1111efg

//比较字符串
int compare(const string &s) const;
int compare(const char *s) const;

//字符存取
char& operator[](int n);
char& at(int n);

//插入删除
string & insert(int pos,const char *s);
string & insert(int pos,const string& str);
string & insert(int pos,int n,char c);
string & erase(int pos,int n=npos); //从pos开始删除n个字符
string str = "hello";
str.erase(1,3);

//子串
string substr(int pos = 0,int n = npos) const;
```

 

## 算法

## 迭代器：算法要通过迭代器访问容器