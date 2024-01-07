// ConsoleApplication2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//
/*map<int, int> m;
	int n;
	cin >> n;
	int i;

	for (i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		if (m.count(e) == 0)
		{
			m.insert(pair<int, int>(e, 1));
		}
		else
		{
			m[e]++;
		}

	}


	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}*/


/*double dis(pair<int, int> A, pair<int, int> B) {
	return sqrt(((A.first- B.first)* (A.first - B.first) + (A.second - B.second) * (A.second - B.second)));
}

double fn(vector < pair<int, int>> &v, vector < int> &d,int k) {

	double min = 9999999999999999;
	int index = -1;
	//标记访问过了
	d[k] = 1;
	for (int i = 0; i < v.size(); i++)
	{

		if (d[i] == 0)
		{
			double m = dis(v[k], v[i]);
			if (m < min)
			{
				min = m;
				index = i;
			}
		}

	}
	if (index==-1)
	{
		return 0;
	}
	else {
		//cout << v[k].first << "," << v[k].second << "->" << v[index].first << "," << v[index].second << endl;
		return min + fn(v, d, index);
	}

}


int main()
{
	
	int n;
	cin >> n;
	vector < pair<int, int>> v;
	

	for (int i = 0; i < n; i++)
	{
		pair<int, int> e;
		cin >> e.first >> e.second;
		v.push_back(e);
	}

	vector < int> d(n, 0);
	
	double l = fn(v, d, 0);
	printf("%.2f", l);
	
}*/
/*string s = "Under the moonlight, Ania saw a grim-faced figure holding a sharp knife and approaching Kung. The figure began to scream wildly and kept getting closer  to Kung. Next to them, Boji was  terrified and desperately trying  to escape. However, the figure  seemed to be everywhere,  relentlessly pursuing them.";
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i]=='e') {
			continue;
		}
		if (s[i] == 'a')
		{
			cout << "/" << endl;
			cout << s[i] << endl;
			cout << "/" << endl;
		}
		else
		{
			cout << s[i] << endl;
		}
	}
	map<int, int> m;
	int n;
	cin >> n;
	int i;

	for (i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		if (m.count(e) == 0)
		{
			m.insert(pair<int, int>(e, 1));
		}
		else
		{
			m[e]++;
		}

	}*/

/*int main() {

	map<int, int> m;
	int n,s;
	cin >> n >> s;
	int i;

	for (i = 0; i < n; i++)
	{
		int e;
		cin >> e;
		if (m.count(e) == 0)
		{
			m.insert(pair<int, int>(e, 1));
		}
		else
		{
			m[e]++;
		}

	}
	for (i = 0; i < s; i++)
	{
		int e;
		cin >> e;
		if (m.count(e) == 0)
		{
			m.insert(pair<int, int>(e, 1));
		}
		else
		{
			m[e]++;
		}

	}

	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		if (it->second==2)
		{
			cout << it->first << " ";
		}
		
	}
}*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


int dfs(vector<pair<int, int>> &v, vector<int> &mark,int index,pair<int,int> pre) {

	int min = 1000000;
	
	mark[index] = 1;
	int find = -1;

	for (int i = 0; i < v.size(); i++)
	{
		int m;
	
		if (mark[i]==0) {
			m = abs(v[i].first - pre.first) + abs(v[i].second - pre.second);
			//cout << "m:" << abs(v[i].second - pre.second) << endl;
			if (m < min)
			{
				find = i;
				min = m;
			}
		}
	}
	//cout << "min:" << min << endl;
	if (find != -1)
	{
		//cout << "->" << "(" << pre.first << "," << pre.second << ")" << "->" << "(" << v[find].first << "," << v[find].second << ")";
		return min + dfs(v, mark, min, v[index]);
	}
	else {
		return 0;
	}

	
}

int main() {

	int t;
	cin >> t;

	for (int i = 0; i < t; i++)
	{
		int n;
		cin >> n;
		vector<pair<int,int>> v;
		vector<int> mark(n,0);
		for (int j = 0; j < n; j++)
		{
			pair<int, int> e;
			cin >> e.first >> e.second;
			v.push_back(e);

		}
		int min = dfs(v, mark,0,pair<int,int>(0,0));
		cout << min <<endl;
		
	}


}