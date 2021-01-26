/* etc
 * 10809 알파벳 찾기
 * 알파벳 소문자로만 이루어진 단어 S
 * 각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를,
 * 포함되어 있지 않은 경우에는 -1 출력
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;

	for (int i = 0; i < 26; i++) {
		auto it = s.find('a' + i); // 찾는 문자열이 없는 경우에 string::npos 반환
		if (it != string::npos)
			cout << it << " ";
		else
			cout << -1 << " ";
	}

	return 0;
}