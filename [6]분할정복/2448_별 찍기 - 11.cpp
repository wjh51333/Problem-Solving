/* 분할정복
 * 2448 별 찍기 - 11
 */

#include <iostream>
#define MAX 3072
using namespace std;

bool map[MAX][2 * MAX - 1];

// Divide & Conquer
void star(int x, int y, int size)
{
	if (size == 3) {
		map[x][y] = true;
		for (int i = 1; i < 3; i++) {
			for (int j = -i; j <= i; j++) {
				if (!(i == 1 && j == 0))
					map[x + i][y + j] = true;
			}
		}
		return;
	}

	size /= 2;
	star(x, y, size);
	for (int i = 1, j = 0; j < 2 * i + 1; j++) {
		if (!(i == 1 && j == 1))
			star(x + i * size, y + (j - 1) * size, size);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	star(0, (2 * n - 1) / 2, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n - 1; j++)
			cout << (map[i][j] ? "*" : " ");
		cout << "\n";
	}
	return 0;
}