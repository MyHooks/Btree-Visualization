#include "btree.h"

using namespace std;

btree::btree() {
	root = NULL;
}

btree::~btree() {
	destroy_tree();
}

void btree::destroy_tree(node* leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void btree::insert(const char* key, node* leaf) {

	stringstream keyVal;
	stringstream leafVal;

	keyVal << key;
	leafVal << leaf->value;

	int iKey;
	int iLeaf;

	keyVal >> iKey;
	leafVal >> iLeaf;

	if (iKey < iLeaf) {
		if (leaf->left != NULL) {
			insert(key, leaf->left);
		}
		else {
			//create node to left of parent node and draw connecting line
			leaf->left = new node;
			leaf->left->value = key;
			leaf->left->left = NULL;
			leaf->left->right = NULL;
			leaf->left->xpos = leaf->xpos - (200/root->leftSpacing);
			leaf->left->ypos = leaf->ypos + 100;
			{ Fl_Group* o = new Fl_Group(leaf->left->xpos, leaf->left->ypos, 35, 25);
			o->box(FL_ROUNDED_BOX);
			o->color((Fl_Color)131);
			o->labelcolor((Fl_Color)131);
			{ new Fl_Input(leaf->left->xpos + 25, leaf->left->ypos + 10, 0, 0, leaf->left->value);
			} // Fl_Input* o
			o->end();
			fl_begin_line();
			fl_vertex(leaf->xpos + 20, leaf->ypos + 25);
			fl_vertex(leaf->left->xpos + 20, leaf->left->ypos);
			fl_end_line();
			root->leftSpacing++;
			} // Fl_Group* o
		}
	}
	else if (iKey >= iLeaf) {
		if (leaf->right != NULL) {
			insert(key, leaf->right);
		}
		else {
			//create node to right of parent node and draw connecting line
			leaf->right = new node;
			leaf->right->value = key;
			leaf->right->right = NULL;
			leaf->right->left = NULL;
			leaf->right->xpos = leaf->xpos + (200/root->rightSpacing);
			leaf->right->ypos = leaf->ypos + 100;
			{ Fl_Group* o = new Fl_Group(leaf->right->xpos, leaf->right->ypos, 35, 25);
			o->box(FL_ROUNDED_BOX);
			o->color((Fl_Color)131);
			o->labelcolor((Fl_Color)131);
			{ new Fl_Input(leaf->right->xpos + 25, leaf->right->ypos + 10, 0, 0, leaf->right->value);
			} // Fl_Input* o
			o->end();
			fl_begin_line();
			fl_vertex(leaf->xpos + 20, leaf->ypos + 25);
			fl_vertex(leaf->right->xpos + 20, leaf->right->ypos);
			fl_end_line();
			root->rightSpacing++;
			} // Fl_Group* o
		}
	}

}

void btree::insert(const char* key) {
	if (root != NULL) {
		insert(key, root);
	}
	else {
		//draw base node
		root = new node;
		root->value = key;
		root->left = NULL;
		root->right = NULL;
		root->xpos = 900;
		root->ypos = 35;
		{ Fl_Group* o = new Fl_Group(root->xpos, root->ypos, 35, 25);
		o->box(FL_ROUNDED_BOX);
		o->color((Fl_Color)131);
		o->labelcolor((Fl_Color)131);
		{ new Fl_Input(root->xpos + 25, root->ypos + 10, 0, 0, root->value);
		} // Fl_Input* o
		o->end();
		} // Fl_Group* o
	}
}

void btree::destroy_tree() {
	destroy_tree(root);
}

void btree::inorder_print() {
	inorder_print(root);
	cout << "\n";
}

void btree::inorder_print(node* leaf) {
	if (leaf != NULL) {
		inorder_print(leaf->left);
		cout << leaf->value << ",";
		inorder_print(leaf->right);
	}
}

void btree::postorder_print() {
	postorder_print(root);
	cout << "\n";
}

void btree::postorder_print(node* leaf) {
	if (leaf != NULL) {
		inorder_print(leaf->left);
		inorder_print(leaf->right);
		cout << leaf->value << ",";
	}
}

void btree::preorder_print() {
	preorder_print(root);
	cout << "\n";
}

void btree::preorder_print(node* leaf) {
	if (leaf != NULL) {
		cout << leaf->value << ",";
		inorder_print(leaf->left);
		inorder_print(leaf->right);
	}
}