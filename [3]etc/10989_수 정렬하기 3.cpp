/* etc
 * 10989 수 정렬하기 3
 * counting sort
 * N개의 수가 주어졌을 때, 이를 오름차순으로 정렬
 */

#include <iostream>
#define MAX 10000
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp;
	int arr[MAX + 1] = { 0, };
	cin >> n;

	// 각 숫자가 몇 번 등장하는지 카운트
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		arr[tmp]++;
	}

	for (int i = 1; i < MAX + 1; i++) {
		// 숫자가 등장하는 만큼 출력
		for (int j = 0; j < arr[i]; j++)
			cout << i << "\n";
	}

	return 0;
}