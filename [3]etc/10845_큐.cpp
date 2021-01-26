/* etc
 * 10845 큐
 * 정수를 저장하는 큐를 구현한 다음
 * 입력으로 주어지는 명령을 처리하는 프로그램 작성
 * push X : 정수 X를 큐에 넣는 연산
 * pop : 큐에서 가장 앞에 있는 정수를 빼고 그 수 출력
 *       만약 큐에 들어있는 정수가 없는 경우에는 -1 출력
 * size : 큐에 들어있는 정수의 개수 출력
 * empty : 큐가 비어있으면 1, 아니면 0 출력
 * front : 큐의 가장 앞에 있는 정수 출력
 *         만약 큐에 들어있는 정수가 없는 경우에는 -1 출력
 * back : 큐의 가장 뒤에 있는 정수 출력
 *        만약 큐에 들어있는 정수가 없는 경우에는 -1 출력
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string cmd;
	queue<int> q;
	int n, x;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> x;
			q.push(x);
		}
		else if (cmd == "pop") {
			if (!q.empty()) {
				cout << q.front() << "\n";
				q.pop();
			}
			else
				cout << -1 << "\n";
		}
		else if (cmd == "size") {
			cout << q.size() << "\n";
		}
		else if (cmd == "empty") {
			if (q.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (cmd == "front") {
			if (!q.empty())
				cout << q.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else { // back
			if (!q.empty())
				cout << q.back() << "\n";
			else
				cout << -1 << "\n";
		}
	}

	return 0;
}