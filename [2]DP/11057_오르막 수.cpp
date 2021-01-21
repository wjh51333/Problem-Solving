/* Dynamic Programming
 * 11057 오르막 수
 * 오르막 수는 수의 자리가 오름차순을 이루는 수
 * 인접한 수가 같아도 오름차순으로 친다
 * ex) 2234, 11119
 * 수의 길이가 N일 때 오르막 수의 개수
 * 0으로 시작할 수 있다
 * 길이가 N인 오르막 수의 개수를 10007로 나눈 나머지 출력
 */

#include <iostream>

using namespace std;

int dp[1001][10];
const int mod = 10007;

int calc(int n)
{
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}

	// i는 숫자의 길이, j는 어떤 수의 끝 숫자
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			// j라는 숫자 앞에 올 수 있는 수는 0~j
			for (int k = 0; k <= j; k++)
				dp[i][j] += dp[i - 1][k] % mod;
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += dp[n][i];
	}

	return sum % mod;
}

int main()
{
	int N;
	cin >> N;
	cout << calc(N) << endl;
	return 0;
}