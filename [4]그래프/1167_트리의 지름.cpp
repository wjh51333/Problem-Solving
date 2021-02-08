/* 그래프
 * 1167 트리의 지름
 * 트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것
 * 트리의 지름 출력
 */

#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;

int n, pivot;
vector<pair<int, int>> tree[MAX];
bool visited[MAX];
long long ans = 0;

void dfs(int v, long long dist = 0)
{
	visited[v] = true;

	for (pair<int, int> next : tree[v]) {
		if (!visited[next.first])
			dfs(next.first, dist + next.second);
	}

	if (dist > ans) {
		ans = dist;
		pivot = v;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int u, v, w;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> u;

		while (cin >> v) {
			if (v == -1)
				break;

			cin >> w;
			tree[u].push_back({ v, w });
		}
	}
	dfs(1);

	memset(visited, false, sizeof(visited));
	ans = 0;
	dfs(pivot);
	cout << ans;

	return 0;
}