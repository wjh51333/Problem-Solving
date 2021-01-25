/* Dynamic Programming
 * 2011 암호코드
 * A는 1, B는 2, ..., Z는 26
 * BEAN을 암호화하면 25114
 * 하지만 25114를 영어로 바꾸면 BEAAD, YAAD, YAN, YKD, BEKD 6가지로 해석
 * 어떤 암호가 주어졌을 때, 나올 수 있는 해석의 가짓수를 1000000으로 나눈 나머지 출력
 * 암호가 잘못되어 암호를 해석할 수 없는 경우에는 0 출력
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int pw[5001], dp[5001];
	const int Moduler = 1000000;

	cin >> s;
	int n = s.size();
	for (int i = 1; i <= n; i++)
		pw[i] = s[i - 1] - '0';

	// 0으로 시작하는 경우 암호를 해석할 수 없음
	if (pw[1] == 0) {
		cout << 0;
		exit(0);
	}
	
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i] = 0;
		// i-1번째 경우에 i번째 암호(A~I / 1~9)를 붙여서 나올 수 있는 암호의 해석
		if (pw[i] > 0 && pw[i] < 10)
			dp[i] += dp[i - 1] % Moduler;

		// i-2번째 경우에 ((i-1)*10+i)번째(J~Z / 10~26)를 붙여서 나올 수 있는 암호의 해석
		int num = pw[i - 1] * 10 + pw[i];
		if (num >= 10 && num <= 26)
			dp[i] += dp[i - 2] % Moduler;
	}
	cout << dp[n] % Moduler;

	return 0;
}