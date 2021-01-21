/* Dynamic Programming
 * 2156 포도주 시식
 * 1. 포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 
 *    마신 후에는 원래 위치에 다시 놓아야 한다
 * 2. 연속으로 놓여 있는 3잔을 모두 마실 수는 없다
 * 최대로 마실 수 있는 포도주의 양 출력
 */

#include <iostream>
#include <algorithm>

using namespace std;

int wine[10001];
int dp[10001];

int calc(int n)
{
	dp[0] = wine[0] = 0;
	dp[1] = wine[1];
	dp[2] = wine[1] + wine[2];

	for (int i = 3; i <= n; i++) {
		// (n-3)잔까지의 최댓값 + (n-1)잔 + n잔
		// (n-2)잔까지의 최댓값 + n잔
		// (n-1)잔까지의 최댓값
		dp[i] = max(dp[i-3] + wine[i-1] + wine[i], max(dp[i - 2] + wine[i], dp[i - 1]));
	}

	return dp[n];
}

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> wine[i];
	
	cout << calc(n);

	return 0;
}