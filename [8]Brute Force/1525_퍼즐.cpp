/* 브루트포스
 * 1525 퍼즐
 * BFS
 */

#include <iostream>
#include <queue>
#include <string>
#include <map>
#define TARGET "123456780"
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string start;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int n; cin >> n;
			char ch = n + '0';
			start = start + ch;
		}
	}

	queue<string> q;
	map<string, int> visited;
	q.push(start);
	visited[start] = 0;

	int dx[] = { -1, 1, 0, 0 }; // 상하좌우
	int dy[] = { 0, 0, -1, 1 };

	while (!q.empty()) {
		string cur = q.front(); q.pop();

		if (cur == TARGET)
			break;

		int z = cur.find('0');
		int x = z / 3;
		int y = z % 3;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= 3 || ny < 0 || ny >= 3) continue;

			string next = cur;
			swap(next[x * 3 + y], next[nx * 3 + ny]);

			if (!visited.count(next)) {
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}

	if (!visited.count(TARGET))
		cout << -1;
	else
		cout << visited[TARGET];

	return 0;
}