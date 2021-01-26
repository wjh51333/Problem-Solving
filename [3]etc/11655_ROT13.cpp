/* etc
 * 11655 ROT13
 * ROT13은 카이사르 암호의 일종으로 영어 알파벳을 13글자씩 밀어서 만든다
 * Baekjoon Online Judge를 ROT13으로 암호화하면 Onrxwbba Bayvar Whqtr
 * ROT13으로 암호화한 내용을 원래 내용으로 바꾸려면 암호화한 문자열을 다시 ROT13
 * ROT13은 알파벳 대문자와 소문자에만 적용
 * 알파벳이 아닌 글자는 원래 글자 그대로 남아 있어야 한다
 * ex) One is 1 -> Bar vf 1
 * 문자열이 주어졌을 때, "ROT13"으로 암호화한 다음 출력
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
	getline(cin, s);
	int n = s.size();

	for (int i = 0; i < n; i++) {
		if (s[i] >= 'A' && s[i] <= 'Z')
			s[i] = 'A' + (s[i] - 'A' + 13) % 26;

		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] = 'a' + (s[i] - 'a' + 13) % 26;
	}
	cout << s;

	return 0;
}