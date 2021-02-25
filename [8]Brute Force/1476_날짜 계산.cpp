/* 브루트포스
 * 1476 날짜 계산
 */

#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int e, s, m;
	cin >> e >> s >> m;

	int year = 0;
	
	while (1) {
		year++;
		if ((year - e) % 15 == 0 && (year - s) % 28 == 0 && (year - m) % 19 == 0)
			break;
	}
	cout << year;

	return 0;
}