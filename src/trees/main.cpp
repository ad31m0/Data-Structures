#include <iostream>
#include "BST.h"
using namespace std;

int main(int argc, const char * argv[]) {
	BST<int> tree;

	cout << tree.insert(1) << endl;
	cout << tree.insert(1) << endl;
	cout << tree.insert(3) << endl;
	cout << tree.insert(5) << endl;
	cout << tree.insert(2) << endl;

	cout << tree.remove(2) << endl;
	cout << tree.remove(1) << endl;
	cout << tree.remove(1) << endl;
	cout << tree.remove(3) << endl;
	cout << tree.remove(5) << endl;
	return 0;
}
