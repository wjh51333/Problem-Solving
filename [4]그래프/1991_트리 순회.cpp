/* 그래프
 * 1991 트리 순회
 * 이진 트리를 입력 받아 전위 순회(preorder traversal), 중위 순회(inorder traversal),
 * 후위 순회(postorder traversal)한 결과 출력
 */

#include <iostream>
using namespace std;

int n;
char tree[27][2];

// VLR
void preorder(char k)
{
	if (k != '.') {
		int index = k - 'A' + 1;
		cout << k;
		preorder(tree[index][0]);
		preorder(tree[index][1]);
	}
}

// LVR
void inorder(char k)
{
	if (k != '.') {
		int index = k - 'A' + 1;
		inorder(tree[index][0]);
		cout << k;
		inorder(tree[index][1]);
	}
}

// LRV
void postorder(char k)
{
	if (k != '.') {
		int index = k - 'A' + 1;
		postorder(tree[index][0]);
		postorder(tree[index][1]);
		cout << k;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	char ch, left, right;

	for (int i = 1; i <= n; i++) {
		cin >> ch >> left >> right;

		int index = ch - 'A' + 1;
		tree[index][0] = left;
		tree[index][1] = right;
	}

	preorder('A');
	cout << "\n";
	inorder('A');
	cout << "\n";
	postorder('A');
	cout << "\n";

	return 0;
}