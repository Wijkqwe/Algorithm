/*cf_2b
char s[1005][1005];
void qwe(int i, int j)
{
				if (i == 0 && j == 0)
				{return;}
				else if (s[i][j] == 'D')
								qwe(i - 1, j);
				else if (s[i][j] == 'R')
								qwe(i, j - 1);
				cout << s[i][j];
}

int main()
{
				int n, i, j;
				cin >> n;
				int a[1005][1005];

				vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(3, 0)));

				for (i = 0; i < n; i++)
				{
								for (j = 0; j < n; j++)
								{
												cin >> a[i][j];
												if (a[i][j] == 0)
																a[i][j] = 10;
								}
				}
				for (i = 0; i < n; i++)
				{
								for (j = 0; j < n; j++)
								{
												while (a[i][j] % 2 == 0 || a[i][j] % 5 == 0)
												{
																if (a[i][j] % 2 == 0)
																{
																				dp[i][j][0]++;
																				a[i][j] /= 2;
																}
																if (a[i][j] % 5 == 0)
																{
																				dp[i][j][1]++;
																				a[i][j] /=5;
																}
												}
								}
				}

				for (i = 1; i < n; i++)
				{
								dp[i][0][0] += dp[i - 1][0][0];
								dp[i][0][1] += dp[i - 1][0][1];
								s[i][0] = 'D';
				}
				for (j = 1; j < n; j++)
				{
								dp[0][j][0] += dp[0][j - 1][0];
								dp[0][j][1] += dp[0][j - 1][1];
								s[0][j] = 'R';
				}

				for (i = 1; i < n; i++)
				{
								for (j = 1; j < n; j++)
								{
												if (min(dp[i - 1][j][0], dp[i - 1][j][1]) < min(dp[i][j - 1][0], dp[i][j - 1][1]))
												{
																dp[i][j][0] += dp[i - 1][j][0];
																dp[i][j][1] += dp[i - 1][j][1];
																s[i][j] = 'D';
												}
												else if (min(dp[i - 1][j][0], dp[i - 1][j][1]) > min(dp[i][j - 1][0], dp[i][j - 1][1]))
												{
																dp[i][j][0] += dp[i][j - 1][0];
																dp[i][j][1] += dp[i][j - 1][1];
																s[i][j] = 'R';
												}
												else if (max(dp[i - 1][j][0], dp[i - 1][j][1]) < max(dp[i][j - 1][0], dp[i][j - 1][1]))
												{
																dp[i][j][0] += dp[i - 1][j][0];
																dp[i][j][1] += dp[i - 1][j][1];
																s[i][j] = 'D';
												}
												else if (max(dp[i - 1][j][0], dp[i - 1][j][1]) > max(dp[i][j - 1][0], dp[i][j - 1][1]))
												{
																dp[i][j][0] += dp[i][j - 1][0];
																dp[i][j][1] += dp[i][j - 1][1];
																s[i][j] = 'R';
												}
												else
												{
																dp[i][j][0] += dp[i - 1][j][0];
																dp[i][j][1] += dp[i - 1][j][1];
																s[i][j] = 'D';
												}
								}
				}

				cout << min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) << endl;
				qwe (i - 1, j - 1);

				return 0;
}
*/