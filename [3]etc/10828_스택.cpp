/* etc
 * 10828 스택
 * 정수를 저장하는 스택을 구현한 다음
 * 입력으로 주어지는 명령을 처리하는 프로그램 작성
 * push X : 정수 X를 스택에 넣는 연산
 * pop : 스택에서 가장 위에 있는 정수를 빼고 그 수 출력
 *       만약 스택에 들어있는 정수가 없는 경우에는 -1 출력
 * size : 스택에 들어있는 정수의 개수 출력
 * empty : 스택이 비어있으면 1, 아니면 0 출력
 * top : 스택의 가장 위에 있는 정수 출력
 *       만약 스택에 들어있는 정수가 없는 경우에는 -1 출력
 */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string cmd;
	stack<int> st;
	int n, x;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd == "push") {
			cin >> x;
			st.push(x);
		}
		else if (cmd == "pop") {
			if (st.size()) {
				cout << st.top() << "\n";
				st.pop();
			}
			else
				cout << -1 << "\n";

			
		}
		else if (cmd == "size") {
			cout << st.size() << "\n";
		}
		else if (cmd == "empty") {
			if (st.size())
				cout << 0 << "\n";
			else
				cout << 1 << "\n";
		}
		else {
			if (st.size())
				cout << st.top() << "\n";
			else
				cout << -1 << "\n";
		}
	}

	return 0;
}