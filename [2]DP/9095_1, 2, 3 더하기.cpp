/* Dynamic Programming
 * 9095 1, 2, 3 더하기
 * 정수 n을 1, 2, 3의 합으로 나타내는 방법의 수
 */

#include <iostream>

using namespace std;

int dp[11] = { 0, };

int calc(int n)
{
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		// i-1에 1 더하는 경우 + i-2에 2 더하는 경우 + i-3에 3 더하는 경우
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}

	return dp[n];
}

int main()
{
	int T, n;
	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << calc(n) << endl;
	}
	return 0;
}