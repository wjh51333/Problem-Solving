/* 그래프
 * 1967 트리의 지름
 * 트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것
 * 트리의 지름 출력
 */

#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10001
using namespace std;

int n;
vector<pair<int, int>> tree[MAX];
bool visited[MAX];
int pivot, ans = 0;

void dfs(int v, int dist = 0)
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

	for (int i = 1; i < n; i++) {
		cin >> u >> v >> w;
		tree[u].push_back(make_pair(v, w));
		tree[v].push_back(make_pair(u, w));
	}

	// 임의의 정점에서 가장 먼 정점을 찾는다
	memset(visited, false, sizeof(visited));
	dfs(1);

	// 그 정점에서 가장 먼 정점을 찾으면 그게 트리의 지름
	memset(visited, false, sizeof(visited));
	dfs(pivot);
	cout << ans;

	return 0;
}