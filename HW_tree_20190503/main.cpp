#include<string>
#include"tree_.h"
using namespace std;

void main() {
	tree_<int, string>tr;
	tr.insert(7, "seven");
	tr.insert(0, "zero");
	tr.insert(50, "fifty");
	tr.insert(8, "eight");
	tr.insert(30, "thirty");
	tr.insert(100, "hundred");
	tr.insert(-3, "minus three");
	/*tr.print();*/

	cout << tr.find(8) << endl;


	system("pause");
}

// метод удаления узла дерева - алгоритм находится в уроке 28.