/* etc
 * 10814 나이순 정렬
 * 온라인 저지에 가입한 사람들의 나이와 이름이 가입한 순서대로 주어진다
 * 이때, 회원들을 나이가 증가하는 순으로,
 * 나이가 같으면 먼저 가입한 사람이 앞에 오는 순서로 정렬
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const pair<int, string>& a, const pair<int, string>& b)
{
	// 첫 번째 수가 더 작은 게 앞으로 -> 오름차순
	// 첫 번째 수가 같으면 가입한 순서대로
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, string>> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i].first >> arr[i].second;

	// sort (시작주소, 종료주소, [비교함수])
	stable_sort(arr.begin(), arr.end(), compare);
	for (int i = 0; i < n; i++)
		cout << arr[i].first << " " << arr[i].second << "\n";

	return 0;
}