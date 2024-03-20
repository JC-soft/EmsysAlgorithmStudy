#include<iostream>
#include<vector>
using namespace std;

struct yx {
	int y;
	int x;
};

vector<vector<yx>> tetro(19);
int yRange[19] = {0, 3, 1, 2, 2, 2, 2, 2, 1, 1, 2, 1, 1, 1, 1, 2, 1, 2, 1};
int xRange[19] = {3, 0, 1, 1, 1, 1, 1, 1, 2, 2, 1, 2, 2, 2, 2, 1, 2, 1, 2};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	tetro[0] = { {0, 0}, {0, 1}, {0, 2}, {0, 3} };//ㅡ
	tetro[1] = { {0, 0}, {1, 0}, {2, 0}, {3, 0} };//ㅣ
	tetro[2] = { {0, 0}, {0, 1}, {1, 0}, {1, 1} };//사각형
	tetro[3] = { {0, 0}, {1, 0}, {2, 0}, {2, 1} };//ㄴ
	tetro[4] = { {0, 0}, {0, 1}, {1, 0}, {2, 0} };//r
	tetro[5] = { {0, 0}, {0, 1}, {1, 1}, {2, 1} };//ㄱ
	tetro[6] = { {0, 1}, {1, 1}, {2, 1}, {2, 0} };//ㅢ
	tetro[7] = { {0, 0}, {1, 0}, {1, 1}, {2, 1} };//ㄴ,
	tetro[8] = { {1, 0}, {1, 1}, {0, 1}, {0, 2} };//,r
	tetro[9] = { {0, 0}, {0, 1}, {1, 1}, {1, 2} };//ㄱㄴ
	tetro[10] = { {0, 1}, {1, 1}, {1, 0}, {2, 0} };// r'
	tetro[11] = { {0, 0}, {0, 1}, {0, 2}, {1, 2} };//옆으로긴ㄱ
	tetro[12] = { {0, 0}, {0, 1}, {0, 2}, {1, 0} };//옆으로긴r
	tetro[13] = { {0, 0}, {1, 0}, {1, 1}, {1, 2} };//옆으로긴ㄴ
	tetro[14] = { {1, 0}, {1, 1}, {1, 2}, {0, 2} };//옆으로긴ㅢ
	tetro[15] = { {0, 1}, {1, 1}, {2, 1}, {1, 0} };//ㅓ
	tetro[16] = { {0, 1}, {1, 0}, {1, 1}, {1, 2} };//ㅗ
	tetro[17] = { {0, 0}, {1, 0}, {2, 0}, {1, 1} };//ㅏ
	tetro[18] = { {0, 0}, {0, 1}, {0, 2}, {1, 1} };//ㅜ

	int n, m, maxnum = 0, y, x, temp;
	cin >> n >> m;
	vector <vector<int>> map(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < 19; i++) {
		y = n - yRange[i];
		x = m - xRange[i];
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < x; k++) {
				temp = 0;
				for (int l = 0; l < 4; l++) {
					temp += map[j + tetro[i][l].y][k + tetro[i][l].x];
				}
				if (temp > maxnum)
					maxnum = temp;
			}
		}
	}
	cout << maxnum;
}
