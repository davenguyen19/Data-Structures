
#ifndef AVLTREE_H
#define AVLTREE_H
#include <iostream>


using namespace std;


class AVLTree {
private:
	struct listNode {
		int value;
		listNode *left, *right;
	};
	listNode *root;
	int height(listNode *r);
	void rotateRight(listNode *&r);
	void rotateLeft(listNode *&r);
	void rotateLeftRight(listNode *&r);
	void rotateRightLeft(listNode *&r);
	int difference(listNode *r);
	void balance(listNode *&r);
	void append(listNode *&r, int v);
	void clear(listNode *&r);
	void remove(listNode *&r, int v);
	bool find(listNode *r, int v);
	void print(listNode *r);
public:
	AVLTree();
	~AVLTree();
	void clear();
	void append(int v);
	void remove(int v);
	bool find(int v);
	void print();
	bool isEmpty();
	bool isFull();
};


AVLTree::AVLTree() {
	root = nullptr;
}





AVLTree::~AVLTree() {
	clear();
}





void AVLTree::append(listNode *&r, int v) {
	if (r == nullptr) {
		r = new listNode;
		r->value = v;
		r->left = nullptr;
		r->right = nullptr;
	}
	else if (v < r->value) {
		append(r->left, v);
		balance(r);
	}
	else {
		append(r->right, v);
		balance(r);
	}
}






void AVLTree::append(int v) {
	append(root, v);
}






bool AVLTree::find(listNode *r, int v) {
	if (r == nullptr) {
		return false;
	}
	else if (r->value == v) {
		return true;
	}
	else if (v < r->value) {
		return find(r->left, v);
	}
	else
		return find(r->right, v);
}







bool AVLTree::find(int v) {
	return find(root, v);
}






void AVLTree::clear(listNode *&r) {
	if (r != nullptr) {
		clear(r->left);
		clear(r->right);
		delete r;
		r = nullptr;
	}
}





void AVLTree::clear() {
	clear(root);
}






void AVLTree::print(listNode *r) {
	if (r == nullptr) {
		return;
	}
	else {
		print(r->left);
		cout << r->value << " ";
		print(r->right);
	}
}






void AVLTree::print() {
	print(root);
	cout << endl;
	cout << height(root) << endl;
}







bool AVLTree::isEmpty() {
	if (root == nullptr) {
		return true;
	}
	else return false;
}







bool AVLTree::isFull() {
	bool full = true;
	listNode *d = new listNode;
	if (d) {
		delete d;
		full = false;
	}
	return full;
}






void AVLTree::remove(listNode *&r, int v) {
	if (r == nullptr) {
		return;
	}
	else if (v < r->value) {
		remove(r->left, v);
		balance(r);
	}
	else if (r->value < v) {
		remove(r->right, v);
		balance(r);
	}
	else {
		if ((r->left == nullptr) && (r->right == nullptr)) {
			delete r;
			r = nullptr;
		}
		else if ((r->left != nullptr) && (r->right == nullptr)) {
			listNode *p = r;
			r = r->left;
			delete p;
		}
		else if ((r->left == nullptr) && (r->right != nullptr)) {
			listNode *p = r;
			r = r->right;
			delete p;
		}
		else {
			listNode *p = r->right;
			while (p->left != nullptr) {
				p = p->left;
			}
			p->left = r->left;
			p = r;
			r = r->right;
			delete p;
		}
	}
}







void AVLTree::remove(int v) {
	remove(root, v);
}







int AVLTree::height(listNode *r) {
	int LH = 0;
	int RH = 0;
	if (r == nullptr) {
		return 0;
	}
	else {
		LH = height(r->left);
		RH = height(r->right);
		if (LH > RH) {
			return (LH + 1);
		}
		else {
			return (RH + 1);
		}
	}
}






void AVLTree::rotateRight(listNode *&r) {
	listNode *p = r->left;
	r->left = p->left;
	p->right = r;
	r = p;
}






void AVLTree::rotateLeft(listNode *&r) {
	listNode *p = r->right;
	r->right = p->left;
	p->left = r;
	r = p;
}






void AVLTree::rotateRightLeft(listNode *&r) {
	rotateRight(r->right);
	rotateLeft(r);
}






void AVLTree::rotateLeftRight(listNode *&r) {
	rotateLeft(r->left);
	rotateRight(r);
}





int AVLTree::difference(listNode *r) {
	int bf = 0;
	bf = height(r->right) - height(r->left);
	return bf;
}






void AVLTree::balance(listNode *&r) {
	if (difference(r) == -2) {
		if (difference(r->left) == -1) {
			rotateRight(r);
		}
		else {
			rotateLeftRight(r);
		}
	}
	else if (difference(r) == 2) {
		if (difference(r->right) == 1) {
			rotateLeft(r);
		}
		else {
			rotateRightLeft(r);
		}
	}
}

#endif
