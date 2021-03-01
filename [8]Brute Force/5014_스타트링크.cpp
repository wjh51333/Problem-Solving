/* 브루트포스
 * 5014 스타트링크
 * BFS
 */

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 1000001
using namespace std;

int dist[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;

	// 강호가 있는 곳과 스타트링트가 있는 곳이 같으면 엘리베이터 X
	if (S == G) {
		cout << 0;
		return 0;
	}

	queue<int> q;
	int move[] = { U, -D };
	
	q.push(S);
	fill(dist, dist + MAX, -1);
	dist[S] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < 2; i++) {
			int next = cur + move[i];

			if (next < 1 || next > F) continue;
			if (dist[next] != -1) continue;

			q.push(next);
			dist[next] = dist[cur] + 1;
			
			if (next == G) {
				cout << dist[next];
				return 0;
			}
		}
	}

	cout << "use the stairs";
	return 0;
}