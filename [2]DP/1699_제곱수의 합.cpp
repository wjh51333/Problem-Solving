/* Dynamic Programming
 * 1699 제곱수의 합
 * 어떤 자연수 N은 그보다 작거나 같은 제곱수들의 합으로 나타낼 수 있다
 * ex) 11 = 3^2 + 1^2 + 1^2 (3개 항) / 11 = 2^2 + 2^2 + 1^2 + 1^2 + 1^2 (5개 항)
 * 11은 그보다 적은 항의 제곱수 합으로 표현할 수 없으므로 제곱수 항의 최소 개수는 3
 * 주어진 자연수 N을 표현할 수 있는 제곱수 항의 최소개수 출력
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, dp[100001];
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;

		for (int j = 2; j * j <= i; j++) {
			if (i - j * j >= 0)
				dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}
	cout << dp[n];

	return 0;
}