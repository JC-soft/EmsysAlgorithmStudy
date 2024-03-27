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
using namespace std;
int arr[31][31][31];
typedef tuple<int, int, int > t;
int visitied[31][31][31];
//동,서,남,북,상,하

int dx[6] = { 0,0,0,0,1,-1 };
int dy[6] = { 0,0,1,-1,0,0 };
int dc[6] = { 1,-1,0,0,0,0 };
int c, n, m;
queue<t>myq;
void bfs()
{

	while (!myq.empty())
	{
		t now = myq.front();
		int fc = get<0>(now);
		int x = get<1>(now);
		int y = get<2>(now);
		myq.pop();
		//cout << fc << " " << x << " " << y << "\n";
		if (arr[fc][x][y] == 9)
		{
			cout << "Escaped in "<<visitied[fc][x][y]<<" minute(s).\n";
			return;
		}
		for (int i = 0; i < 6; i++)
		{
			int nc = fc + dc[i];
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nc >= 0 && nx >= 0 && ny >= 0 && nc < c && nx < n && ny < m)
			{
				//cout << arr[nc][nx][ny];
				if (visitied[nc][nx][ny] == 0 && (arr[nc][nx][ny] == 0 || arr[nc][nx][ny] == 9))
				{
					//cout << "들어옴1";
					visitied[nc][nx][ny] = visitied[fc][x][y] + 1;
					myq.push(t(nc, nx, ny));
				}
			}
		}
			
	}
	cout << "Trapped!\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	while (cin >> c >> n >> m)
	{
		if (c == 0 && n == 0 && m == 0)
			return 0;
		for (int k = 0; k < c; k++)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					visitied[k][i][j] = 0;
				}
			}
		}
		while (!myq.empty())
		{
			myq.pop();
		}
		for (int k = 0; k < c; k++)
		{
			for (int i = 0; i < n; i++)
			{
				string s;
				cin >> s;
				for (int j = 0; j < m; j++)
				{
					if (s[j] == '#')
					{
						arr[k][i][j] = 1;
					}
					else if (s[j] == '.')
					{
						arr[k][i][j] = 0;
					}
					else if (s[j] == 'S')
					{
						//다시 출발점 오든 말든 상관 없음
						visitied[k][i][j] = 0;
						arr[k][i][j] = 0;
						myq.push(t(k, i, j));
					}
					else if (s[j] == 'E')
					{
						arr[k][i][j] = 9;
					}
				}
			}
		}
		bfs();

	}
}
