/* etc
 * 11652 카드
 * 숫자 카드 N장
 * 숫자 카드에는 정수가 하나 적혀있는데, 
 * 적혀있는 수는 -2^62보다 크거나 같고 2^62보다 작거나 같다
 * 준규가 가지고 있는 카드가 주어졌을 때, 가장 많이 가지고 있는 정수 출력
 * 만약, 가장 많이 가지고 있는 정수가 여러 가지라면, 작은 것 출력
 */

#include <iostream>
#include <algorithm>
#define MAX 100000

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, cnt, max;
	long long ans, arr[MAX];
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	sort(arr, arr + n);
	cnt = max = 0; ans = arr[0];
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] == arr[i + 1])
			cnt++;
		else
			cnt = 0;

		if (cnt > max) {
			ans = arr[i];
			max = cnt;
		}
	}
	cout << ans;

	return 0;
}