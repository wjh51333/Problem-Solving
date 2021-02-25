/* 브루트포스
 * 9095 1, 2, 3 더하기
 */

#include <iostream>
using namespace std;

int ans = 0;

void solution(int n, int sum)
{
	if (sum == n) {
		ans++;
		return;
	}

	if (sum < n) {
		for (int i = 1; i <= 3; i++)
			solution(n, sum + i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;
		ans = 0;
		solution(n, 0);
		cout << ans << "\n";
	}

	return 0;
}