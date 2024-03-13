#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int dy[4] = { -1, 0, 0, 1 };
int dx[4] = { 0, -1, 1, 0 };

struct node {
	int fish;
	bool visited;
};

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int time = 0, count = 0, n, temp, ty, tx, newy, newx, size = 2, exp = 2, fishcount = 0;
	bool found = false;
	cin >> n;
	vector<vector<node>> map(n + 2, vector<node>(n + 2));
	vector<pair<int, int>> bfsQ;
	vector < pair<int, int>> prey;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			map[i][j].visited = false;
			map[i][j].fish = 0;
			cin >> temp;
			if (temp == 9) {
				bfsQ.push_back({ i, j });
			}
			if (temp > 0 && temp < 9) {
				map[i][j].fish = temp;
				fishcount++;
			}
		}
	}

	for (int i = 0; i <= n+1; i++) {//벽 설정
		map[i][0].fish = 100;
		map[i][0].visited = true;
		map[i][n + 1].fish = 100;
		map[i][n + 1].visited = true;
		map[0][i].fish = 100;
		map[0][i].visited = true;
		map[n + 1][i].fish = 100;
		map[n + 1][i].visited = true;
	}

	while (!bfsQ.empty()) {
		if (!fishcount)
			break;
		temp = bfsQ.size();
		count++;
		sort(bfsQ.begin(), bfsQ.end(), comp);
		for (int i = 0; i < temp; i++) {
			if (!fishcount)
				break;
			ty = bfsQ.front().first;
			tx = bfsQ.front().second;
			for (int j = 0; j < 4; j++) {
				if (!fishcount)
					break;
				newy = ty + dy[j];
				newx = tx + dx[j];
				if (!map[newy][newx].visited) {
					if (map[newy][newx].fish == 0 || map[newy][newx].fish == size) {//이동만 할 수 있는 경우
						bfsQ.push_back({ newy, newx });
						map[newy][newx].visited = true;
					}
					else if (map[newy][newx].fish < size) {//먹이가 있는 경우
						prey.push_back({ newy, newx });
						map[newy][newx].visited = true;
					}
				}
			}
			bfsQ.erase(bfsQ.begin());
		}
		//qsize만큼 확인했는데 먹이 후보가 생겼을 경우
		if (!prey.empty()) {
			sort(prey.begin(), prey.end(), comp);

			newy = prey.front().first;
			newx = prey.front().second;

			for (int k = 1; k <= n; k++) {//visited 초기화 
				for (int l = 1; l <= n; l++) {
					map[k][l].visited = false;
				}
			}
			prey.clear();
			bfsQ.clear();
			bfsQ.push_back({ newy, newx }); //visited 초기화 후 큐에 새로 넣기
			map[newy][newx].visited = true;
			map[newy][newx].fish = 0;
			exp--;
			if (!exp) {
				size++;
				exp = size;
			}
			time += count;
			count = 0;
			found = true;
			fishcount--;
		}
	}
	cout << time;
}
