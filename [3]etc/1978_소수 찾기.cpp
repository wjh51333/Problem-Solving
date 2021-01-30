/* etc
 * 1978 소수 찾기
 * 주어진 수 N개 중에서 소수가 몇 개인지 찾아서 출력
 */

#include <iostream>
using namespace std;

bool prime(int n)
{
	if (n == 2)	return true;

	if (n == 1) return false;

	// 2를 제외한 소수는 항상 홀수
	if (n % 2 == 0) return false;

	for (int k = 3; k < n; k += 2) {
		if (n % k == 0)
			return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (prime(k))
			cnt++;
	}
	cout << cnt;

	return 0;
}