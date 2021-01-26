/* etc
 * 1406 에디터
 * 한 줄로 된 간단한 에디터
 * 이 편집기는 영어 소문자만을 기록할 수 있는 편집기
 * 최대 600,000글자까지 입력 가능
 * 이 편집기에는 '커서'라는 것이 있는데 커서는 문장의 맨 앞(첫 번째 문자의 왼쪽),
 * 문장의 맨 뒤(마지막 문자의 오른쪽), 또는 문장 중간 임의의 곳(모든 연속된 두 문자 사이)에 위치
 * 즉 길이가 L인 문자열이 현재 편집기에 입력되어 있으면 커서가 위치할 수 있는 곳은 L+1가지 경우
 * L : 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
 * D : 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
 * B : 커서 왼쪽에 있는 문자 삭제 (커서가 문장의 맨 앞이면 무시됨)
 *     삭제로 인해 커서는 한 칸 왼쪽으로 이동한 것처럼 나타나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로임
 * P $ : $라는 문자를 커서 왼쪽에 추가함
 * 초기에 편집기에 입력되어 있는 문자열이 주어지고, 그 이후 입력한 명령어가 차례로 주어졌을 때,
 * 모든 명령어를 수행하고 난 후 편집기에 입력되어 있는 문자열 구하기
 * 단, 명령어가 수행되기 전에 커서는 문장의 맨 뒤에 위치하고 있다
 */

#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	int n;
	cin >> s >> n;

	list<char> arr(s.begin(), s.end());
	auto cur = arr.end();
	char cmd;

	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == 'L') {
			if (cur != arr.begin())
				cur--;
		}
		if (cmd == 'D') {
			if (cur != arr.end())
				cur++;
		}
		if (cmd == 'B') {
			if (cur != arr.begin())
				cur = arr.erase(--cur);
		}
		if (cmd == 'P') {
			cin >> cmd;
			arr.insert(cur, cmd);
		}
	}

	for (char ch : arr)
		cout << ch;

	return 0;
}