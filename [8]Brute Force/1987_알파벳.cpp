/* 브루트포스
 * 1987 알파벳
 */

#include <iostream>
#include <string>
using namespace std;

int R, C;
string map[20];
bool visited[26];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int dfs(int x, int y, int cnt)
{
	// 해당 알파벳이 적힌 칸을 지났다고 표시
	visited[map[x][y] - 'A'] = true;

	int ret = cnt;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
		
		// 새로 이동할 칸에 적혀 있는 알파벳이 지금까지 지나온 모든 칸에 적혀 있는 알파벳이 아니라면 이동
		if (!visited[map[nx][ny] - 'A']) {
			ret = max(ret, dfs(nx, ny, cnt + 1));
			visited[map[nx][ny] - 'A'] = false;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> map[i];
	}

	// 처음 말이 놓여있던 칸도 지나는 칸에 포함해야 하므로 cnt = 1
	cout << dfs(0, 0, 1);
	return 0;
}