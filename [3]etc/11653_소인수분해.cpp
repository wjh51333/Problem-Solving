/* etc
 * 11653 소인수분해
 * 정수 N이 주어졌을 때, 소인수분해
 */

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			cout << i << "\n";
			n /= i;
		}
	}

	if (n > 1)
		cout << n;

	return 0;
}