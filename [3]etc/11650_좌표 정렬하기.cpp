/* etc
 * 11650 좌표 정렬하기
 * 2차원 평면 위의 점 N개
 * 좌표를 x좌표가 증가하는 순으로,
 * x좌표가 같으면 y좌표가 증가하는 순서로 정렬한 다음 출력
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

	vector<pair<int, int>> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++)
		cout << arr[i].first << " " << arr[i].second << "\n";

	return 0;
}