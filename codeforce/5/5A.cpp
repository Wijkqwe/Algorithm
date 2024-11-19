/*cf_5A
int main()
{
	int l = 0, a = 0;
	string q;
	while (getline(cin, q), q != "\0")
	{
		if (q[0] == '+')
		{
			a++;
			continue;
		}
		else if (q[0] == '-')
		{
			a--;
			continue;
		}
		int s = 0;
		for (auto i : q)
		{
			s++;
			if (i == ':')
			{
				s = 0;
			}
		}
		l += a * s;
	}
	cout << l;


	return 0;
}
//*/
