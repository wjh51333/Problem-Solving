/* 그리디
 * 2875 대회 or 인턴
 * 2명의 여학생과 1명의 남학생이 팀을 결성해서 나가는 것이 원칙이다
 * K명은 반드시 인턴십 프로그램에 참여해야 하므로 대회에 참여하지 못한다
 * 여학생 수 N, 남학생 수 M, 인턴십에 참가해야하는 인원 K가 주어질 때 만들 수 있는 최대의 팀 수
 */

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	int ans = 0;
	int total = n + m - k;

	while (n > 1 && m > 0 && total > 2) {
		ans++;
		n -= 2;
		m--;
		total -= 3;
	}
	// ans = min(min(n/2, m), (n + m - k) / 3);
	cout << ans;

	return 0;
}