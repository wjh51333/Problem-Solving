/* etc
 * 10820 문자열 분석
 * 문자열 N개
 * 이때, 문자열에 포함되어 있는 소문자, 대문자, 숫자, 공백의 개수를 구하는 프로그램 작성
 * 각 문자열은 알파벳 소문자, 대문자, 숫자, 공백으로만 이루어져 있다.
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
	int n = 0;
	
	while (getline(cin, s)) {
		int cnt[4] = { 0, }; // 알파벳 소문자, 대문자, 숫자, 공백 개수
		for (char ch : s) {
			if (ch >= 'a' && ch <= 'z')
				cnt[0]++;
			if (ch >= 'A' && ch <= 'Z')
				cnt[1]++;
			if (ch >= '0' && ch <= '9')
				cnt[2]++;
			if (ch == ' ')
				cnt[3]++;
		}

		for (int j = 0; j < 4; j++)
			cout << cnt[j] << " ";
		cout << "\n";
	}

	return 0;
}