/* 그래프
 * 2331 반복수열
 * 다음과 같이 정의된 수열이 있다
 * D[1] = A
 * D[n] = D[n-1]의 각 자리의 숫자를 P번 곱한 수들의 합
 * ex) A = 57, P = 2일 때, {57, 74(=5^2 + 7^2), 65, 61, ... }
 * 이와 같은 수열을 계속 구하다 보면 언젠가 이와 같은 반복수열이 된다
 * 이때, 반복되는 부분을 제외했을 때, 수열에 남게 되는 수들의 개수 출력
 */

#include <iostream>
#include <cmath>
#include <cstring>
#define MAX 300001
using namespace std;

int a, p;
int visited[MAX];

void dfs(int n)
{
	visited[n]++;

	// 반복구간이 한 번 반복되었다는 것을 의미
	// 2일 때 return 하면 반복되는 수들까지 개수에 포함됨 
	if (visited[n] == 3)
		return;

	int sum = 0;
	while (n) {
		sum += (int)pow(n % 10, p);
		n /= 10;
	}
	dfs(sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> a >> p;
	memset(visited, 0, MAX);
	dfs(a);

	int ans = 0;
	for (int i = 0; i < MAX; i++) {
		if (visited[i] == 1)
			ans++;
	}
	cout << ans;

	return 0;
}