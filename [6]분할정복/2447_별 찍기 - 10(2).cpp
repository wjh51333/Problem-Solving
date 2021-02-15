/* 분할정복
 * 2447 별 찍기 - 10
 */

#include <iostream>
#define MAX 2187
using namespace std;

bool map[MAX][MAX];

// Divide & Conquer
void star(int x, int y, int size)
{
	if (size == 1) {
		map[x][y] = true;
		return;
	}

	size /= 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!(i == 1 && j == 1))
				star(x + i * size, y + j * size, size);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	star(0, 0, n);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << (map[i][j] ? "*" : " ");
		cout << "\n";
	}
	return 0;
}