#include <iostream>
#include <algorithm>

using namespace std;

int map[400];
bool visit[400];
int x[400];
int temp[400];
int r, h,eat,n;
int sizeofshark = 2;

void set0() {
	for (int i = 0; i < 400; i++) {
		visit[i] = 0;
	}
}

void printmap() {
	for (int i = 0; i < n * n; i++) {
		if (i % n == 0) cout << '\n';
		cout << map[i];
	}
	cout << ' ' << sizeofshark << ' '<< r << '\n';
}

bool bfs() {
	set0();
	int j,q=1,ans=0,t=0;
	int arr[400];
	bool flag = 0;
	x[0] = h;
	while (q > 0 && !flag) {
		j = q;
		q = 0;
		for (int i = 0; i < j; i++) {
			if ((map[x[i]]!=9 && map[x[i]] >= 1) && map[x[i]]<sizeofshark) {
				flag = 1;
				arr[ans++] = x[i];
			}
			if ((x[i] + 1) % n != 0 && x[i] + 1 < n * n) {
				if (!visit[x[i] + 1] && map[x[i]+1]<=sizeofshark) {
					visit[x[i] + 1] = 1;
					temp[q++] = x[i] + 1;
				}
			}
			if ((x[i] - 1) >= 0 && (x[i] - 1) % n != n - 1) {
				if (!visit[x[i] - 1] && map[x[i]-1] <= sizeofshark) {
					visit[x[i] - 1] = 1;
					temp[q++] = x[i] - 1;
				}
			}
			if ((x[i] - n) >= 0) {
				if (!visit[x[i] - n] && map[x[i]-n] <= sizeofshark) {
					visit[x[i] - n] = 1;
					temp[q++] = x[i] - n;
				}
			}
			if ((x[i] + n) < n * n) {
				if (!visit[x[i] + n] && map[x[i]+n] <= sizeofshark) {
					visit[x[i] + n] = 1;
					temp[q++] = x[i] + n;
				}
			}
		}
		for (int i = 0; i < q; i++) {
			x[i] = temp[i];
		}
		t++;
	}
	if (!flag)
		return 0;
	else {
		sort(arr, arr + ans);
		int qwer = arr[0];
		map[qwer] = 9;
		map[h] = 0;
		h = qwer;
		r += t-1;
		if (++eat >= sizeofshark) {
			sizeofshark++;
			eat = 0;
		}
		return 1;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> map[i];
		if (map[i] == 9)
			h = i;
	}
	while (bfs());
	cout << r;
	return 0;
}
