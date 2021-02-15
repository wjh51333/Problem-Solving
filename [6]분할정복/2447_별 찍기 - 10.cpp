/* 분할정복
 * 2447 별 찍기 - 10
 */

#include <iostream>
#define MAX 3000
using namespace std;

int n;
char map[MAX][MAX];

void stars(int x, int y)
{
	int cnt = 0;

	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			cnt++;
			if (cnt == 5)
				map[i][j] = ' ';
			else
				map[i][j] = '*';
		}
	}
}

void space(int x, int y, int size)
{
	for (int i = x; i < x + size; i++) {
		for (int j = y; j < y + size; j++) {
			map[i][j] = ' ';
		}
	}
}

// Divide & Conquer
void divConq(int x, int y, int size)
{
	if (size > 3) {
		int cnt = 0;

		for (int i = x; i < x + size; i += size / 3) {
			for (int j = y; j < y + size; j += size / 3) {
				cnt++;
				if (cnt == 5)
					space(i, j, size / 3);
				else
					divConq(i, j, size / 3);
			}
		}
	}
	else
		stars(x, y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	divConq(0, 0, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << map[i][j];
		cout << "\n";
	}
	return 0;
}