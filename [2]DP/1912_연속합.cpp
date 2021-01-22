/* Dynamic Programming
 * 1912 연속합
 * 연속된 몇 개의 수를 선택해서 구할 수 있는 가장 큰 합 출력
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int arr[100001];
	int dp[100001];

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1] = arr[1];
	int ans = dp[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;

	return 0;
}