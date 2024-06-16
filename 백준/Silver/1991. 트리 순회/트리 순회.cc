#include <iostream>
#include <vector>
#define MAX 26
using namespace std;

struct node {
	char rLeft;
	char rRight;
};

vector<node>v(MAX);

void preorder(char node) {
	if (node == '.') return;
	cout << node;
	preorder(v[node].rLeft);
	preorder(v[node].rRight);
}

void inorder(char node) {
	if (node == '.') return;
	inorder(v[node].rLeft);
	cout << node;
	inorder(v[node].rRight);
}

void postorder(char node) {
	if (node == '.') return;
	postorder(v[node].rLeft);
	postorder(v[node].rRight);
	cout << node;
}

int main() {

	int N=0;
	char root, left, right;
	
	cin >> N;


	for (int i = 0; i < N; i++) {
		cin >> root >> left >> right;
		v[root].rLeft = left;
		v[root].rRight = right;

	}

	preorder('A');

	cout << "\n";

	inorder('A');

	cout << "\n";

	postorder('A');

	return 0;
}