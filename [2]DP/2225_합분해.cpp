/* Dynamic Programming
 * 2225 합분해
 * 0부터 N까지의 정수 k개를 더해서 그 합이 N이 되는 경우의 수
 * 덧셈의 순서가 바뀐 경우는 다른 경우로 센다
 * 한 개의 수를 여러 번 쓸 수도 있다
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, k;
	long long dp[201][201]; // dp[a][b] = a개 더해서 그 합이 b가 되는 경우의 수
	const int Moduler = 1000000000;

	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= k; i++) {
		/*dp[i][0] = 1;
		for (int j = 1; j <= n; j++)
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % mod;
			*/
		for (int j = 0; j <= n; j++) {
			dp[i][j] = dp[i - 1][0];
			for (int l = 1; l <= j; l++)
				dp[i][j] += dp[i - 1][l];
			dp[i][j] %= Moduler;
		}
	}

	cout << dp[k][n];

	return 0;
}