/* etc
 * 11004 K번째 수
 * 수 N개 A1, A2, ..., AN
 * A를 오름차순 정렬했을 때 앞에서부터 K번째 있는 수 출력
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

	int n, k;
	cin >> n >> k;
	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	nth_element(arr.begin(), arr.begin() + k - 1, arr.end());
	cout << arr[k - 1];

	return 0;
}