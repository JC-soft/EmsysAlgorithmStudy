#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
#include<queue>
#include <climits>
using namespace std;
typedef pair<int, int> edge;
static int v, e, k;
static vector<int> mdistance;
static vector < bool > visitied;
static vector<vector<edge>> mlist;
static priority_queue <edge, vector<edge>, greater<edge>> q;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin.tie(NULL);

	cin >> v >> e >> k;
	mdistance.resize(v + 1);
	visitied.resize(v + 1);
	mlist.resize(v + 1);
	fill(mdistance.begin(), mdistance.end() ,INT_MAX);
	fill(visitied.begin(), visitied.end() ,false);

	for (int i = 1; i <= e; i++)
	{
		int u, v, w;
		cin >> u>>v>>w;
		//u에서 v가는거에 w웨이트;
		//w에서 v가는게 w 웨이트 마지막에 매달아 놈
		mlist[u].push_back(edge(v, w));
	}
	//k에서 시작
	q.push(make_pair(0, k));
	mdistance[k] = 0;
	while (!q.empty())
	{

		int cur_edg = q.top().second;
		q.pop();
		if (visitied[cur_edg] == true)
		{
			continue;
		}
		visitied[cur_edg] = true;

		for (auto i : mlist[cur_edg])
		{
			int next_val = i.second;
			int next_node = i.first;
			if (mdistance[next_node] > mdistance[cur_edg] + next_val)
			{
				mdistance[next_node] = mdistance[cur_edg] + next_val;
				q.push(make_pair(mdistance[next_node], next_node));
			}
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (mdistance[i] == INT_MAX)
		{
			cout << "INF" << "\n";
		}
		else
		{
			cout << mdistance[i] << "\n";
		}
	}
}
