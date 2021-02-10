/* Binary Search, Ternary Seacrh
 * 2110 공유기 설치
 * C개의 공유기를 N개의 집에 적당히 설치해서, 가장 인접한 두 공유기 사이의 최대 거리 출력
 */

#include <iostream>
#include <algorithm>
#define MAX 200001
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c;
	int arr[MAX];
	cin >> n >> c;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	// Binary Search를 이용하여 존재할 수 있는 간격의 값을 찾는다
	// 두 공유기 사이의 최대값은 좌표의 시작점과 끝점의 차이이다
	// 거리의 최소값은 시작점의 좌표값이 아니라 1이다
	// 최대간격이 시작점의 좌표값보다 작을수도 있기 때문이다
	int left = 1, right = arr[n - 1];
	int ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int now = 0;
		int cnt = 1;

		// 하나하나 건너뛰면서 두 공유기 사이의 거리가 현재 mid 이상인 경우에만 설치 가능
		for (int i = 1; i < n; i++) {
			if (arr[i] - arr[now] >= mid) {
				now = i;
				cnt++;
			}
		}

		// 모든 인덱스를 확인한 후 입력받은 c보다 개수가 큰지 확인
		// c보다 크면 현재의 최대값이 되고, left를 변경하여 더 큰 값 탐색
		if (cnt >= c) {
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else { // c보다 작으면 right를 변경
			right = mid - 1;
		}
	}
	cout << ans;

	return 0;
}