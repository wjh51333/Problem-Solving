/* etc
 * 2751 수 정렬하기 2
 * N개의 수가 주어졌을 때, 이를 오름차순으로 정렬
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
	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";

	return 0;
}