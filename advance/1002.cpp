#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct term {
	int times;
	double num;
};

bool cmp(term a, term b) { return a.times > b.times; }

unordered_map<int, int> mapp;
vector<term> poly;

int main()
{
	int a, b, exp;
	double coe;
	scanf("%d", &a);
	for (int i = 0; i < a; i++)
	{
		scanf("%d %lf", &exp, &coe);
		auto it = mapp.find(exp);
		if (it != mapp.end())
		{
			//在map中找到
			poly[it->second].num += coe;
		}
		else
		{
			//没找到
			int count = poly.size();
			mapp[exp] = count;		//map中存入该键值对
			term temp = { exp,coe };
			poly.push_back(temp);
		}
	}
	scanf("%d", &b);
	for (int i = 0; i < b; i++)
	{
		scanf("%d %lf", &exp, &coe);
		auto it = mapp.find(exp);
		if (it != mapp.end())
		{
			//在map中找到
			poly[it->second].num += coe;
		}
		else
		{
			//没找到
			int count = poly.size();
			mapp[exp] = count;		//map中存入该键值对
			term temp = { exp,coe };
			poly.push_back(temp);
		}
	}
	sort(poly.begin(), poly.end(), cmp);
	int count=0;
	for (auto it = poly.begin(); it != poly.end(); it++)
	{
		if (it->num != 0)	count++;
	}
	cout << count;
	for (auto it = poly.begin(); it != poly.end(); it++)
	{
		if(it->num!=0)
			printf(" %d %.1lf", it->times, it->num);
	}
	return 0;
}
