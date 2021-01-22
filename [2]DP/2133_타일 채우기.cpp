/* Dynamic Programming
 * 2133 타일 채우기
 * 3xN 크기의 벽을 2x1, 1x2 크기의 타일로 채우는 경우의 수
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, dp[31];
	cin >> n;

	dp[0] = 1;
	dp[2] = 3;
	for (int i = 4; i <= n; i++) {
		// 3x(i-2) 타일 뒤에 1x2 타일 3개 붙이는 경우 1가지
		// 3x(i-2) 타일 뒤에 1x2 타일 1개, 2x1 타일 2개 붙이는 경우 2가지
		dp[i] = 3 * dp[i - 2];
		for (int j = 4; j <= i; j += 2)
			// 특수 경우 2가지 붙이는 경우
			dp[i] += 2 * dp[i - j];
	}
	cout << dp[n];

	return 0;
}