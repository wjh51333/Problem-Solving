/* etc
 * 10808 알파벳 개수
 * 알파벳 소문자로만 이루어진 단어 S
 * 각 알파벳이 단어에 몇 개가 포함되어 있는지 구하는 프로그램 작성
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
	int alphabet[26] = { 0, };
	cin >> s;

	for (char ch : s)
		alphabet[ch - 'a']++;

	for (int i = 0; i < 26; i++)
		cout << alphabet[i] << " ";

	return 0;
}