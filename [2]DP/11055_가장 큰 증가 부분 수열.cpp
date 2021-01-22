/* Dynamic Programming
 * 11055 가장 큰 증가 부분 수열
 * 수열 A가 주어졌을 때, 합이 가장 큰 증가 부분 수열의 합 출력
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> arr(n);
	vector<int> dp(n); // 증가 부분 수열의 합 저장

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		dp[i] = arr[i];
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}