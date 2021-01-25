/* etc
 * 11651 좌표 정렬하기 2
 * 2차원 평면 위의 점 N개
 * 좌표를 y좌표가 증가하는 순으로,
 * y좌표가 같으면 x좌표가 증가하는 순서로 정렬한 다음 출력
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)
{
	// 두 번째 수가 같다면
	if (a.second == b.second)
		return a.first < b.first; // 첫 번째 수로 오름차순
	return a.second < b.second; // 두 번째 수가 더 작은 게 앞으로 -> 오름차순
}

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

	// sort (시작주소, 종료주소, [비교함수])
	sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < n; i++)
		cout << arr[i].first << " " << arr[i].second << "\n";

	return 0;
}