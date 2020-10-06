#include <iostream>
#include <sstream>
using namespace std;


int main()
{
	int a, b;
	cin >> a >> b;
	int sum = a + b;
	bool minusflag = false;
	if (sum < 0)
	{
		sum = -sum;
		minusflag = true;
	}
	stringstream ss;
	ss << sum;
	string out;
	ss >> out;
	auto it = out.end();
	int count = 0;
	while(it != out.begin())
	{
		if (count != 3)
		{
			count++;
			it--;
		}
		if (count == 3)
		{
			if (it == out.begin())	break;
			count = 0;
			out.insert(it, ',');
		}
	}
	if (minusflag == true)	cout << "-";
	cout << out;
	return 0;
}
