/* Dynamic Programming
 * 11726 2xn 타일링
 * 2xn 크기의 직사각형을 1x2, 2x1 타일로 채우는 방법의 수
 * 2xn 크기의 직사각형을 채우는 방법의 수를 10007로 나눈 나머지 출력
 */

#include <iostream>

using namespace std;

int dp[1001] = { 0, };

int calc(int n)
{
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		// 2*(i-1) 타일의 뒤에 2*1 한 개 붙이는 경우 + 2*(i-2) 타일 뒤에 1*2 두 개 붙이는 경우
		// d[i]에는 1007 미만의 수만 들어가게 된다
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;
	}

	return dp[n];
}

int main()
{
	int N;
	cin >> N;
	cout << calc(N) << endl;
	return 0;
}