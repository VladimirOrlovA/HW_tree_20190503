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
		newNode->key = key;
		newNode->value = value;
		// если ничего нет
		if (root == nullptr) {
			root = newNode;
			size_ = 1;
			return;
		}
		// значит есть хотя бы 1 элемент
		//создаем два указателя, которые будут идти друг за другом
		node<T1, T2> *tmp = root;
		node<T1, T2> *y = nullptr;
		while (tmp != nullptr) {
			y = tmp;
			if (key < tmp->key)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		}
		newNode->parent = y;
		if (key < y->key)
			y->left = newNode;
		else
			y->right = newNode;
		size_++;
	}

	void printNode(node<T1, T2>*nd) const {
		if (nd != nullptr) {
			printNode(nd->left);
			cout << nd->key << " "
				<< nd->value << endl;
			printNode(nd->right);
		}
	}
	void print() const {
		printNode(root);
	}
	const T2 find(const T1& key) const {
		node<T1, T2> *tmp = root;
		while (tmp->key != key && tmp != nullptr) {
			if (key < tmp->key)
				tmp = tmp->left;
			else
				tmp = tmp->right;
		
		}
		return tmp->value;
	}
};