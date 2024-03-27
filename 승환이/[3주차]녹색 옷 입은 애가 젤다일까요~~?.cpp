#include <iostream>
#include <vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include <cstring>
#include<climits>
#include<queue>
#include<tuple>
#include<cstring>
int arr[130][130];
//가장 위쪽
int dx[4] = { -1, 0, 0, 1 };
int dy[4] = { 0, -1, 1, 0 };
bool visitied[130][130] = { false, };
int val[130][130];
using namespace std;
typedef tuple<int, int, int> t;
int n;

int dixytra(int s1, int s2,int count)
{
	memset(visitied, false, sizeof(visitied));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			visitied[i][j] = false;
			val[i][j] = INT_MAX;
		}
	}
	val[s1][s2] = arr[s1][s2];
	priority_queue<t, vector<t>, greater<t>> myq;
	//visitied[s1][s2] = true;
	myq.push(t(0, s1, s2));
	while (!myq.empty())
	{
		t now = myq.top();
//		int now_val = get<0>(now);
		int x = get<1>(now);
		int y = get<2>(now);
		myq.pop();
		if (visitied[x][y] == true)
			continue;
		visitied[x][y] = true;
		for (int i = 0; i < 4; i++)
		{
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if (nx >= 0 && ny >= 0 && nx < n && ny < n&&visitied[nx][ny]==false)
			{
				if (val[x][y] + arr[nx][ny] < val[nx][ny])
				{
					val[nx][ny] = arr[nx][ny] + val[x][y];
					myq.push(t(val[nx][ny], nx, ny));
				}
			}
		}
	}
	/*for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << val[i][j] << " ";
		}
		cout << "\n";
	}*/
	cout <<"Problem "<< count<<": "<< val[n - 1][n - 1] << "\n";
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//memset(visitied, false, sizeof(visitied));
	//memset(val, 20, sizeof(val));
	
	int cnt = 1;
	while (cin >> n)
	{
		if (n == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		dixytra(0, 0, cnt);
		cnt++;
	}
	return 0;
}
