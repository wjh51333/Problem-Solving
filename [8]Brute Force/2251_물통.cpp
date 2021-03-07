/* 브루트포스
 * 2251 물통
 * BFS
 */

#include <iostream>
#include <set>
#include <queue>
#define MAX 201
using namespace std;

bool visited[MAX][MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	// set은 key 유형의 고유한 객체 집합을 포함하는 연관 컨테이너
	// 중복된 요소를 허용하지 않고 삽입되는 key들은 자동으로 오름차순 정렬된다
	// 중복저장하고 싶으면 multiset 사용 -> <set>
	set<int> answer;
	answer.insert(C);

	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(0, 0), C));

	while (!q.empty()) {




		int a = q.front().first.first;
		int b = q.front().first.second;
		int c = q.front().second;
		q.pop();

		if (visited[a][b][c]) continue;
		visited[a][b][c] = true;

		if (a == 0) answer.insert(c);

		// A -> B
		if (a + b > B) q.push(make_pair(make_pair(a + b - B, B), c));
		else q.push(make_pair(make_pair(0, a + b), c));

		// A -> C
		if (a + c > C) q.push(make_pair(make_pair(a + c - C, b), C));
		else q.push(make_pair(make_pair(0, b), a + c));

		// B -> A
		if (b + a > A) q.push(make_pair(make_pair(A, b + a - A), c));
		else q.push(make_pair(make_pair(b + a, 0), c));

		// B -> C
		if (b + c > C) q.push(make_pair(make_pair(a, b + c - C), C));
		else q.push(make_pair(make_pair(a, 0), b + c));

		// C -> A
		if (c + a > A) q.push(make_pair(make_pair(A, b), c + a - A));
		else q.push(make_pair(make_pair(c + a, b), 0));

		// C -> B
		if (c + b > B) q.push(make_pair(make_pair(a, B), c + b - B));
		else q.push(make_pair(make_pair(a, c + b), 0));
	}

	for (int k : answer) {
		cout << k << " ";
	}

	return 0;
}