/* 그리디
 * 1931 회의실 배정
 * 각 회의 I에 대해 시작시간과 끝나는 시간이 주어져 있고,
 * 각 회의가 겹치지 않게 하면서 회의실을 사용할 수 있는 회의의 최대 개수 출력
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return a.first < b.first;
	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s, e;
	cin >> n;

	vector<pair<int, int>> time;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		time.push_back(make_pair(s, e));
	}

	// 회의가 끝나는 시간을 기준으로 오름차순 정렬
	sort(time.begin(), time.end(), cmp);

	int t = time[0].second;
	int ans = 1;
	for (int i = 1; i < n; i++) {
		// 회의 시작시간이 이전 회의의 끝나는 시간 이후일 경우 회의실 사용 가능
		if (t <= time[i].first) {
			t = time[i].second;
			ans++;
		}
	}
	cout << ans;

	return 0;
}