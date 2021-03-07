/* 브루트포스
 * 1759 암호 만들기
 */

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int L, C;
char letters[15];
set<string> code;

bool check(string pw)
{
	int c = 0; // 자음
	int v = 0; // 모음 aeiou

	for (char ch : pw) {
		if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
			v++;
		else
			c++;
	}

	if (c >= 2 && v >= 1)
		return true;
	return false;
}

void comb(string pw, int idx)
{
	if (pw.size() == L && check(pw)) {
		code.insert(pw);
		return;
	}

	if (idx < C && pw.size() < L) {
		// idx번째 알파벳 선택
		comb(pw + letters[idx], idx + 1);
		//idx번째 알파벳 선택 X
		comb(pw, idx + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		cin >> letters[i];
	}
	sort(letters, letters + C);

	comb("", 0);

	for (string s : code) {
		cout << s << "\n";
	}

	return 0;
}