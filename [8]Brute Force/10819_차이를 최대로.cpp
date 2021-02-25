/* 브루트포스
 * 10819 차이를 최대로
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());

	int ans = 0;
	do {
		int sum = 0;
		for (int i = 1; i < n; i++)
			sum += abs(arr[i] - arr[i - 1]);
		ans = max(ans, sum);
	} while (next_permutation(arr.begin(), arr.end()));
	
	cout << ans;
	return 0;
}