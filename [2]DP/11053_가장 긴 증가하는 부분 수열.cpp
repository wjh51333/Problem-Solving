/* Dynamic Programming
 * 11053 가장 긴 증가하는 부분 수열
 * 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열 길이 출력
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
	vector<int> dp(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			// 마지막 원소에서 증가하는 부분 수열의 원소를 추가해주어야 해서 dp[j] + 1
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}