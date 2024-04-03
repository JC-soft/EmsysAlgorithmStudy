#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comp(pair<int, int>a, pair<int, int>b){
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else
		return a.first < b.first;
}



int n, e=101, ts=0,te=301, cnt=0;
bool fail = 1;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> ts >> te;
		a[i].first = ts * 100 + te;
		cin >> ts >> te;
		a[i].second = ts * 100 + te;
	}

	sort(a.begin(), a.end(), comp);
	//만약 현재 종료시간 이전에 시작하는 애들이 남아있으면
	//종료시간이 가장 마지막인 애가 나올때마다 ts te 갱신
	//더이상 없으면 ts te가 0인지 확인. 
	//둘다 0이면 fail, 아니면 s e 갱신하며 ts,te 0 0 초기화 후 continue
	te = 0;
	e = 301;
	for (int i = 0; i < n; i++) {
		if (a[i].first <= e) { //다음에 피울 수 있는 꽃이 아직 남아있을 때
			if (a[i].second > te) {//te갱신
                if(a[i].second > 1130){
                    cnt++;
                    fail = false;
                    break;
                }
				te = a[i].second;
			}
		}
		
		else {//더이상 꽃이 없을때
			if (te==0) {//추가된 꽃도 없을때는 실패
				break;
			}
            //추가된 꽃이 있으면 갱신
			cnt++;
			e = te;
			te = 0;
			if (e > 1130) {
				fail = false;
                break;
			}
            i--;
        }
	}
	if(fail)
	    cout << "0";
    else   
        cout << cnt;
}
