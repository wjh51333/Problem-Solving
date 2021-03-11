/* 브루트포스
 * 1806 부분합
 */

#include <iostream>
#include <vector>
#define INF 10000000
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s;
	cin >> n >> s;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int answer = INF;
	int left = 0, right = 0;
	int sum = 0;

	// 투 포인터 알고리즘 O(1)
	while (right <= n && left <= right) {
		if (sum >= s) {
			answer = min(answer, right - left);
			sum -= arr[left++];
		}
		else {
			if (right == n)
				break;

			sum += arr[right++];
		}
	}

	if (answer == INF)
		answer = 0;

	cout << answer;


	return 0;
}