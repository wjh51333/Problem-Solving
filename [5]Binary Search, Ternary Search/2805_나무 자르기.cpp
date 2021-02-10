/* Binary Search, Ternary Seacrh
 * 2805 나무 자르기
 * 목재절단기는 다음과 같이 동작한다
 * 먼저, 절단기에 높이 H를 지정해야 한다
 * 높이를 지정하면 톱날이 땅으로부터 H미터 위로 올라간다
 * 그 다음, 한 줄에 연속해있는 나무를 모두 절단해버린다
 * 따라서, 높이가 H보다 큰 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않을 것이다
 * 적어도 M미터의 나무를 집에 가져가기 위해서 절단기에 설정할 수 있는 높이의 최댓값
 */

#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int arr[MAX];
	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	// Binary Search
	int left = 1, right = arr[n - 1];
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		long long sum = 0;

		// 절단된 나무의 길이의 합을 구한다
		for (int i = 0; i < n; i++)
			if (arr[i] - mid > 0)
				sum += arr[i] - mid;

		// 합이 구하는 나무의 길이보다 긴 경우
		// 필요한 길이보다 더 많이 절단되므로 높이를 더 높여야 한다
		if (sum >= m) {
			// 절단기에 설정할 수 있는 높이를 늘려본다
			left = mid + 1;

			if (ans < mid)
				ans = mid;
		}
		else {
			// 절단기에 설정할 수 있는 높이를 줄여본다
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}