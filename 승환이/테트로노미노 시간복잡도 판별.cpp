#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<climits>
#include<queue>
int arr[501][501];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
using namespace std;
int n, m;
vector<pair<int, int>> list;
bool visitied[501][501] = { false, };
int tmep_res = 0;
int MAX_VAL(int cnt, int depth, vector<pair<int, int>> lis)
{
	if (depth == 4)
	{
		tmep_res = max(cnt, tmep_res);
		return 0;
	}
	for (pair<int, int> k : list)
	{
		int x = k.first;
		int y = k.second;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m&&visitied[nx][ny]==false)
			{
				visitied[nx][ny] = true;
				list.push_back(make_pair(nx, ny));
				MAX_VAL(cnt + arr[nx][ny], depth + 1, lis);
				list.pop_back();
				visitied[nx][ny] = false;
			}
		}

	}

	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			tmep_res = 0;
			list.clear();
			list.push_back(make_pair(i, j));
			//memset(visitied, false, sizeof(visitied));
			visitied[i][j] = true;
			MAX_VAL(arr[i][j], 1, list);
			res = max(res, tmep_res);
		}
	}
	cout << res;
}
