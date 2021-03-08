/* 브루트포스
 * 2003 수들의 합 2
 */

#include <iostream>
#define MAX 10000
using namespace std;

int a[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> a[i];

	int answer = 0;
	int left = 0, right = 0;
	int sum = 0;
	
	// 투 포인터 알고리즘 O(1)
	while (right <= N && left <= right) {
		if (sum >= M) {
			if (sum == M)
				answer++;

			sum -= a[left++];
		}
		else {
			if (right == N)
				break;

			sum += a[right++];
		}
	}
	cout << answer;

	return 0;
}