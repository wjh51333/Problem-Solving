/* Dynamic Programming
 * 2193 이친수
 * 0과 1로 이루어진 수를 이진수라함
 * 이진수 중 특별한 성질은 갖는 것들이 이친수(pinary number)
 * 1. 이친수는 0으로 시작하지 않는다
 * 2. 이친수에서는 1이 두 번 연속으로 나타나지 않는다.
 * 즉, 11을 부분 문자열로 갖지 않는다
 * ex) 1, 10, 100, 101, 1000, 1001
 * N자리 이친수의 개수
 */

#include <iostream>

using namespace std;

long long dp[91][2];

long long calc(int n)
{
	// dp[0] = 0;
	// dp[1] = 1;
	for (int i = 0; i < 2; i++) {
		dp[1][i] = i;
	}

	for (int i = 2; i <= n; i++) {
		// 피보나치
		// dp[i] = dp[i-1] + dp[i-2];
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	return dp[n][0] + dp[n][1];
}

int main()
{
	int N;
	cin >> N;
	cout << calc(N) << endl;
	return 0;
}