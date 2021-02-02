/* 그래프
 * 10451 순열 사이클
 * 1부터 N까지 정수 N개로 이루어진 순열을 나타내는 방법으 ㄴ여러 가지가 있다
 * 순열을 배열을 이용해 표현하면 방향 그래프로 나타낼 수도 있다
 * ( 1 ... i ... n 
 *  ㅠ1...ㅠi...ㅠn )으로 나타냈다면 i에서 ㅠi로 간선을 이어 그래프로 만들 수 있다
 * 순열 그래프 (3, 2, 7, 8, 1, 4, 5, 6)에는 총 3개의 사이클이 있다
 * 이런 사이클을 순열 사이클이라고 한다
 * N개의 정수로 이루어진 순열이 주어졌을 때, 순열 사이클의 개수 출력
 */

#include <iostream>
#include <cstring>
using namespace std;

int n;
int edge[1001];
bool visited[1001];
bool cycle[1001];
int ans;

void dfs(int v)
{
	visited[v] = true;

	int next = edge[v];

	if (!visited[next])
		dfs(next);
	else if (!cycle[next])
		ans++;

	cycle[v] = true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;
		memset(visited, false, sizeof(visited));
		memset(cycle, false, sizeof(cycle));

		for (int i = 1; i <= n; i++)
			cin >> edge[i];

		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i])
				dfs(i);
		}
		cout << ans << "\n";
	}

	return 0;
}