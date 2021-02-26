/* 브루트포스
 * 1697 숨바꼭질
 * BFS
 */

#include <iostream>
#include <queue>
#include <algorithm>
#define MAX 100001
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	if (n == k) {
		cout << 0;
		return 0;
	}

	int ans = 0;
	int move[] = { -1, 1, 2 };
	int dist[MAX];
	fill(dist, dist + MAX, -1);

	queue<int> q;
	q.push(n);
	dist[n] = 0;

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int i = 0; i < 3; i++) {
			int next = i == 2 ? cur * move[i] : cur + move[i];

			if (next < 0 || next > 100000) continue;
			if (dist[next] >= 0) continue;

			q.push(next);
			dist[next] = dist[cur] + 1;

			if (next == k) {
				cout << dist[next];
				return 0;
			}
		}
	}

	return 0;
}