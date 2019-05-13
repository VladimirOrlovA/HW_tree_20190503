#pragma once
#include<iostream>
using namespace std;

template<class T1, class T2>
struct node
{
	T1 key;
	T2 value;
	node<T1, T2> *parent = nullptr;
	node<T1, T2> *left = nullptr;
	node<T1, T2> *right = nullptr;
};

template<class T1, class T2>
class tree_
{
	node<T1, T2> *root;
	size_t size_;
public:
	tree_() {
		root = nullptr;
		size_ = 0;
	}

	void insert(const T1& key, const T2& value) {
		// создаем новый узел
		node<T1, T2>*newNode = new node<T1, T2>;
		// присваиваем значение ключа узла
		newNode->key = key;
		// присваиваем данные в узел
		newNode->value = value;
		// если дерева нет, то назначаем корнем созданный узел
		if (root == nullptr) {
			root = newNode;
			size_ = 1;
			return;
		}
		// значит есть хотя бы 1 элемент
		//создаем два указателя, которые будут идти друг за другом
		node<T1, T2> *tmp = root;
		node<T1, T2> *y = nullptr;
		// цикл пока не дойдем до указателя на левого или правого потомка равного нулю
		// место куда будем добавлять новый узел.
		while (tmp != nullptr) {
			y = tmp;
			if (key < tmp->key)
				tmp = tmp->left; // вставлять новый узел будем слева, выходим из цикла
			else
				tmp = tmp->right; // вставлять новый узел будем справа, выходим из цикла
		}
		// в новом узле, указателю на родитель, присваиваем значение указателя предстоящего перед ним узла
		newNode->parent = y;
		// в родительском узле, в  указатель на потомка справа или слева присваиваем указатель нового узла
		if (key < y->key)
			y->left = newNode;
		else
			y->right = newNode;
		size_++;
	}

	void printNode(node<T1, T2>*nd) const {
		if (nd != nullptr) {
			printNode(nd->left);
			cout << nd->key << " " << nd->value << endl;
			printNode(nd->right);
		}
	}
	void print() const {
		printNode(root);
	}
	const T2 find(const T1& key) const {
		node<T1, T2> *tmp = root;
		// делаем обход дерева
		while (tmp->key != key && tmp != nullptr) {
			if (key < tmp->key)
				tmp = tmp->left;
			else
				tmp = tmp->right;

		}
		return tmp->value;
	}

	//////////////////////////////////////////////////////////////////////////


	//void deleteNode(int key)
	//{
	//	node<T1, T2> *tmp = root;

	//	// делаем обход дерева
	//	while (tmp->key != key && tmp != nullptr) {
	//		if (key < tmp->key)
	//			tmp = tmp->left;
	//		else
	//			tmp = tmp->right;

	//	}
	//	cout << tmp->key << endl;

	//	//1) У узла нет наследников(удаляем лист).Тогда он просто удаляется, а его родитель обнуляет указатель на него.

	//	if (tmp->left == nullptr && tmp->right == nullptr) {
	//		if (tmp->parent == nullptr) {
	//			delete tmp;
	//			root = nullptr;
	//			size_ = --;
	//		}
	//		else {
	//			node<T1, T2> *y = tmp;
	//			tmp = tmp->parent;
	//			tmp->left = nullptr;

	//			delete y;
	//			size_--;
	//		}


	//	}

	//	//2) У узла один наследник. В этом случае узел подменяется своим наследником.

	//	//if (tmp->left != nullptr) {
	//	//	node<T1, T2> *y = tmp;
	//	//	tmp->left->parent = tmp->parent;
	//	//	tmp = tmp->left;
	//	//	//delete y;
	//	//	size_--;
	//	//}

	//	//3) У узла оба наследника. В этом случае узел не удаляем, а заменяем его значение на максимум левого поддерева. После этого удаляем максимум левого поддерева.
	//}

	node<T1, T2> getRoot() {
		return root;
	}

	tree_* deleteNode(tree_* node, int key) {
		if (node == nullptr)
			return node;

		if (key == node->key) {

			tree_* tmp;
			if (node->right == nullptr)
				tmp = node->left;
			else {

				tree_*ptr = node->right;
				if (ptr->left == nullptr) {
					ptr->left = node->left;
					tmp = ptr;
				}
				else {

					tree_* pmin = ptr->left;
					while (pmin->left != nullptr) {
						ptr = pmin;
						pmin = ptr->left;
					}
					ptr->left = pmin->right;
					pmin->left = node->left;
					pmin->right = node->right;
					tmp = pmin;
				}
			}

			delete node;
			return tmp;
		}
		else if (key < node->key)
			node->left = deleteNode(node->left, key);
		else
			node->right = deleteNode(node->right, key);
		return node;
	}

};