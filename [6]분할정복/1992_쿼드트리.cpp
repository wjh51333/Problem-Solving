/* 분할정복
 * 1992 쿼드트리
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<string> arr;
string ans;

void quadTree(int x, int y, int size)
{
	char ch = arr[x][y];
	bool check = true;

	// 모두 같은 숫자로 되어있는지 확인
	for (int i = x; check && i < x + size; i++) {
		for (int j = y; check && j < y + size; j++) {
			if (arr[i][j] != ch) {
				check = false;
				break;
			}
		}
	}

	// 0과 1이 섞여있으면 왼쪽 위, 오른쪽 위, 왼쪽 아래, 오른쪽 아래 4개로 나누어 압축
	if (!check) {
		size /= 2;
		ans.append("(");
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				quadTree(x + i * size, y + j * size, size);
		ans.append(")");
	}
	else // 모두 같은 숫자일 경우 압축 결과 출력
		ans += ch;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		arr.push_back(s);
	}

	quadTree(0, 0, n);
	cout << ans;

	return 0;
}