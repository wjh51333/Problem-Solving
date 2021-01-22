/* Dynamic Programming
 * 9461 파도반 수열
 * 삼각형이 나선 모양으로 놓여져 있다
 * 첫 삼각형은 정삼각형으로 변의 길이 1
 * 나선에서 가장 긴 변의 길이를 k라 했을 때, 그 변에 길이가 k인 정삼각형 추가
 * 파도반 수열 P(N)은 나선에 있는 정삼각형의 변의 길이
 * N이 주어졌을 때 P(N) 구하기
 */

#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T, n;
	long long dp[101];
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++) {
		cin >> n;

		dp[0] = 0;
		dp[1] = dp[2] = 1;
		for (int i = 3; i <= n; i++) {
			dp[i] = dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << "\n";
	}

	return 0;
}