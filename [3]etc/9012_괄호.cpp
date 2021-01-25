/* etc
 * 9012 괄호
 * 괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 (와 )만으로 구성되어 있는 문자열
 * 그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)라고 부른다
 * 입력으로 주어진 괄호 문자열이 VPS인지 아닌지 판단해서 YES, NO로 출력
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

	int n;
	string s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s;

		stack<char> vps;
		int res = 1;
		for (char ch : s) {
			if (ch == '(')
				vps.push(ch);
			else { // ch == ')'
				if (vps.size())
					vps.pop();
				else {
					res = 0;
					break;
				}
			}
		}

		if (res && vps.size() == 0)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}