/* Binary Search, Ternary Seacrh
 * 10815 숫자 카드
 * 상근이는 숫자 카드 N개를 가지고 있다
 * 정수 M개가 주어졌을 때, 이 수가 적혀있는 숫자 카드를 상근이가 가지고 있으면 1, 아니면 0 출력
 */

#include <iostream>
#include <algorithm>
#define MAX 500001
using namespace std;

int arr[MAX];

bool binarySearch(int left, int right, int x)
{
	if (left > right)
		return false;
	else {
		int mid = (left + right) / 2;

		if (x == arr[mid])
			return true;
		else if (x > arr[mid])
			return binarySearch(mid + 1, right, x);
		else
			return binarySearch(left, mid - 1, x);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> k;
		if (binarySearch(0, n - 1, k))
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}

	return 0;
}