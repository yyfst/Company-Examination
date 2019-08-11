#include <iostream>

using namespace std;

int main()
{
	/*
	5
	10 2 1 5 2 5
	10 2 10 5 2 5
	10 2 3 5 2 5
	100 100 3 4 4 3
	10000 1000 10 5 5 3
	*/
	long long m;//最大容量
	long long t;//经过t分钟
	int m1;//每分钟给水管注入量
	int t1;//每经过t1分钟给水管状态改变
	int m2;//每分钟排水管排出量
	int t2;//排水管状态改变时间

	int T;//数组组数
	cin >> T;
	while (T--)
	{
		bool in = true;
		bool out = true;
		long pre = 0;//当前容量

		cin >> m >> t >> m1 >> t1 >> m2 >> t2;

		for (long i = 1; i <= t; i++)
		{
			if (in == true && out == false)
			{
				pre += m1;
				if (pre > m)
					pre = m;
			}
			if (in == false && out == true)
			{
				pre -= m2;
				if (pre < 0)
					pre = 0;
			}

			if (in == true && out == true)
			{
				pre += (m1 - m2);
				if (pre < 0)
					pre = 0;
				if (pre > m)
					pre = m;
			}				
			if ((i/t1)%2 == 0)
				in = true;				
			else
				in = false;
			if ((i/t2)%2 == 0)
				out = true;
			else
				out = false;
		}

		cout << pre << endl;

	}

	std::system("pause");

	return 0;
}
