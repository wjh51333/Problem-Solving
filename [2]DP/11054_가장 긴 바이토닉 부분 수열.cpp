/* Dynamic Programming
 * 11054 가장 긴 바이토닉 부분 수열
 * 수열 S가 어떤 수 Sk를 기준으로
 * S1 < S2 < ... < Sk-1 < Sk > Sk+1 > ...> Sn을 만족하면 바이토닉 수열
 * ex) { 10, 20, 30, 25, 20 }, { 10, 20, 30, 40 }, { 50, 40, 25, 10 }
 * 수열 A가 주어졌을 때, 그 수열의 부분 수열 중 바이토닉 수열이면서 가장 긴 수열의 길이 출력
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	vector<int> dp(n); // 앞에서부터 찾는 최장수열
	vector<int> dp_r(n); // 뒤에서부터 찾는 최장수열

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	// 가장 긴 증가하는 부분 수열
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			// 마지막 원소에서 증가하는 부분 수열의 원소를 추가해주어야 해서 dp[j] + 1
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	// 가장 긴 감소하는 부분 수열
	for (int i = n - 1; i >= 0; i--) {
		dp_r[i] = 1;
		for (int j = n - 1; j > i; j--) {
			// 마지막 원소에서 증가하는 부분 수열의 원소를 추가해주어야 해서 dp[j] + 1
			if (arr[j] < arr[i] && dp_r[i] < dp_r[j] + 1)
				dp_r[i] = dp_r[j] + 1;
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		// -1 해주는 이유는 i번째 원소가 중복되기 때문
		if (ans < dp[i] + dp_r[i] - 1)
			ans = dp[i] + dp_r[i] - 1;
	}
	cout << ans;

	return 0;
}