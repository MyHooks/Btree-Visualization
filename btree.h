#include <iostream>
#include <sstream>
#include <FL/Fl.H>
#include <FL/Fl_Double_Window.H>
#include <FL/fl_draw.H>
#include "btreegui.h"
#include <algorithm>

using namespace std;


struct node {
	const char* value;
	int leftSpacing = 1;
	int rightSpacing = 1;
	int xpos;
	int ypos;
	node* left;
	node* right;
};

class btree {
public:
	btree();
	~btree();

	void insert(const char* key);
	void destroy_tree();
	void inorder_print();
	void postorder_print();
	void preorder_print();

private:
	void destroy_tree(node* leaf);
	void insert(const char*, node* leaf);
	void inorder_print(node* leaf);
	void postorder_print(node* leaf);
	void preorder_print(node* leaf);

	node* root;
};