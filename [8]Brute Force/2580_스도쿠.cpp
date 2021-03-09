/* 브루트포스
 * 2580 스도쿠
 * 백트래킹
 */

#include <iostream>
using namespace std;

int n = 9;
int board[10][10];
bool c[10][10]; // 행 확인
bool c2[10][10]; // 열 확인
bool c3[10][10]; // 3x3칸 확인

int square(int x, int y)
{
	return (x / 3) * 3 + (y / 3);
}

bool go(int z)
{
	if (z == 81) {
		// 정답이니까 출력
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cout << board[i][j] << ' ';
			cout << '\n';
		}
		return true;
	}

	int x = z / n;
	int y = z % n;

	if (board[x][y] != 0) {
		// 이미 채워져있으므로 다음 칸 호출
		return go(z + 1);
	}
	else {
		// 채워넣기
		for (int i = 1; i <= 9; i++) {
			// 행, 열, 정사각형을 검사했을 때 해당 숫자가 없으면 채워준다
			if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0) {
				c[x][i] = c2[y][i] = c3[square(x, y)][i] = true;
				board[x][y] = i;

				// 다음 칸 호출
				if (go(z + 1))
					return true;

				board[x][y] = 0;
				c[x][i] = c2[y][i] = c3[square(x, y)][i] = false;
			}
		}
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) {
				c[i][board[i][j]] = true; // i행에 숫자 board[i][j]가 있다
				c2[j][board[i][j]] = true; // j열에 숫자 board[i][j]가 있다
				c3[square(i, j)][board[i][j]] = true; // square(i, j)번째 작은 정사각형에 숫자 board[i][j]가 있다
			}
		}
	}
	go(0);
	return 0;
}