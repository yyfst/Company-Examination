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
	long long m;//�������
	long long t;//����t����
	int m1;//ÿ���Ӹ�ˮ��ע����
	int t1;//ÿ����t1���Ӹ�ˮ��״̬�ı�
	int m2;//ÿ������ˮ���ų���
	int t2;//��ˮ��״̬�ı�ʱ��

	int T;//��������
	cin >> T;
	while (T--)
	{
		bool in = true;
		bool out = true;
		long pre = 0;//��ǰ����

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
