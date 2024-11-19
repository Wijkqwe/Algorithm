/*cd_5b
int main()
{
	vector<string> q(1005);
	int a = 0, i, s, d = 0;
	for (i = 1; getline(cin, q[i]), (q[i] != "\0" || q[i - 1] != "\0"); ++i)
	{
		if (q[i].size() > a)
		{
			a = q[i].size();
		}
	}
	cout << setw(a + 2) << setfill('*') << "*" << endl;
	for (int j = 1; j < i - 1; j++)
	{
		int aa;
		if (a % 2)
		{
			aa = 0;
		}
		else
		{
			if (q[j].size() % 2)
			{
				if (d)
				{
					aa = 1;
					d = 0;
				}
				else
				{
					aa = 0;
					d = 1;
				}
			}
			else
			{
				aa = 0;
			}
		}
		s = (a - q[j].size()) / 2 + aa;
		cout << "*" << setw(s + q[j].size()) << setfill(' ') << q[j] << setw(a - s - q[j].size() + 1) << "*" << endl;
	}
	cout << setw(a + 2) << setfill('*') << "*" << endl;

	return 0;
}
//*/
