/* etc
 * 10866 덱
 * 정수를 저장하는 덱를 구현한 다음
 * 입력으로 주어지는 명령을 처리하는 프로그램 작성
 * push_front X : 정수 X를 덱의 앞에 넣는 연산
 * push_back X : 정수 X를 덱의 뒤에 넣는 연산
 * pop_front : 덱의 가장 앞에 있는 정수를 빼고 그 수 출력
 *             만약 덱에 들어있는 정수가 없는 경우에는 -1 출력
 * pop_back : 덱의 가장 뒤에 있는 정수를 빼고 그 수 출력
 *            만약 덱에 들어있는 정수가 없는 경우에는 -1 출력
 * size : 덱에 들어있는 정수의 개수 출력
 * empty : 덱이 비어있으면 1, 아니면 0 출력
 * front : 덱의 가장 앞에 있는 정수 출력
 *         만약 덱에 들어있는 정수가 없는 경우에는 -1 출력
 * back : 덱의 가장 뒤에 있는 정수 출력
 *        만약 덱에 들어있는 정수가 없는 경우에는 -1 출력
 */

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string cmd;
	deque<int> d;
	int n, x;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd == "push_front") {
			cin >> x;
			d.push_front(x);
		}
		else if (cmd == "push_back") {
			cin >> x;
			d.push_back(x);
		}
		else if (cmd == "pop_front") {
			if (!d.empty()) {
				cout << d.front() << "\n";
				d.pop_front();
			}
			else
				cout << -1 << "\n";
		}
		else if (cmd == "pop_back") {
			if (!d.empty()) {
				cout << d.back() << "\n";
				d.pop_back();
			}
			else
				cout << -1 << "\n";
		}
		else if (cmd == "size") {
			cout << d.size() << "\n";
		}
		else if (cmd == "empty") {
			if (d.empty())
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (cmd == "front") {
			if (!d.empty())
				cout << d.front() << "\n";
			else
				cout << -1 << "\n";
		}
		else { // back
			if (!d.empty())
				cout << d.back() << "\n";
			else
				cout << -1 << "\n";
		}
	}

	return 0;
}