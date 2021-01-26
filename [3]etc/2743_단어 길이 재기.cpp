/* etc
 * 2743 단어 길이 재기
 * 알파벳으로만 이루어진 단어를 입력받아, 그 길이 출력
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
	cout << s.size();

	return 0;
}