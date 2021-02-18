/* 분할정복
 * 1517 버블 소트
 * 버블 소트는 시간 복잡도가 O(n^2)이므로 버블 소트로는 해결 X
 */

#include <iostream>
#define MAX 500001
using namespace std;

int n;
int arr[MAX];
int res[MAX];
long long ans = 0;

void merge(int s, int m, int e)
{
	int i = s, j = m, idx = s;
	while (i < m && j < e) {
		if (arr[i] > arr[j]) {
			res[idx++] = arr[j++];
			// 오른쪽 배열에서 가져오는데 왼쪽배열에서 가져오지 않은 부분이 있다면 그 개수만큼 더해준다
			ans += (m - i);
		}
		else {
			res[idx++] = arr[i++];
		}
	}

	if (i < m) {
		for (int k = i; k < m; k++)
			res[idx++] = arr[k];
	}
	else {
		for (int k = j; k < e; k++)
			res[idx++] = arr[k];
	}

	for (int k = s; k < e; k++)
		arr[k] = res[k];
}

void mergesort(int s, int e)
{
	if (e - s > 1) {
		int m = (e + s) / 2;
		mergesort(s, m);
		mergesort(m, e);
		merge(s, m, e);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int k;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	mergesort(0, n);
	cout << ans;

	return 0;
}