#include <iostream>
#include <string>

using namespace std;

template <class T>
	struct node
	{
		int key;
		T code;
		node *left;
		node *right;
		node(T _code, int _key)
		{
			key=_key; // num
			code=_code; // string 
			left=nullptr;
			right=nullptr;
		}
	};

template <class T>	// T is string
class btree
{
private:
	void destroy_tree(node<T> *leaf);
	void insert(T codeVal, node<T> *leaf,int keyVal);
	node<T> *search(T codeVal, node<T> *leaf);
	node<T> *findMax(node<T> *leaf);
	int keyVal(T codeVal,node<T> *leaf);

	node<T> *root;

public:
	btree();
	~btree();

	void destroy_tree();
	void insert(T codeVal,int keyVal);
	node<T> *search(T codeVal);
	node<T> *findMax();
	int keyVal(T codeVal);


};

template <class T>	// T is string and T is int
btree<T>::btree()
{
	root=NULL;
}

template <class T>	// T is string and T is int
btree<T>::~btree(){
	destroy_tree();
}


template <class T>	// T is string and T is int
void btree<T>::destroy_tree(node<T> *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

template <class T>	// T is string and T is int
void btree<T>::insert(T codeVal, node<T> *leaf, int keyVal)
{
	if(codeVal< leaf->code)
	{
		if(leaf->left!=NULL)
			insert(codeVal, leaf->left,keyVal);
		else
		{
			leaf->left=new node<T>(codeVal,keyVal);
		}  
	}
	else if(codeVal>=leaf->code)
	{
		if(leaf->right!=NULL)
			insert(codeVal, leaf->right,keyVal);
		else
		{
			leaf->right=new node<T>(codeVal,keyVal);
		}
	}
}

template <class T>	// T is string and T is int
void btree<T>::insert(T codeVal,int keyVal)
{
	if(root!=NULL)
		insert(codeVal, root,keyVal);
	else
	{
		root=new node<T>(codeVal,keyVal);
	}
}


template <class T>	// T is string and T is int
node<T>* btree<T>::search(T codeVal, node<T> *leaf)
{
	if(leaf != NULL)
	{
		if(codeVal == leaf->code)
		{
			return leaf;
		}
		if(codeVal < leaf->code)
		{
			return search(codeVal, leaf->left);
		}
		else
		{
			return search(codeVal, leaf->right);
		}
	}
	else
	{
		return NULL;
	}
}


template <class T>	// T is string and T is int
node<T> *btree<T>::search(T codeVal)
{
	return search(codeVal,root);
}


template <class T>	// T is string and T is int
node<T> *btree<T>::findMax(node<T> *leaf)
{
	if( leaf != NULL )
		while( leaf->right != NULL )
			leaf = leaf->right;
	return leaf;
}

template <class T>	// T is string and T is int
node<T> *btree<T>::findMax()
{
	return findMax(root);
}

template <class T>	// T is string and T is int
void btree<T>::destroy_tree()
{
	destroy_tree(root);
}

template <class T>
int btree<T>::keyVal(T codeVal,node<T> *leaf)
{
	if(leaf != NULL)
	{
		if(codeVal == leaf->code)
		{
			return leaf->key;
		}
		if(codeVal < leaf->code)
		{
			return keyVal(codeVal, leaf->left);
		}
		else
		{
			return keyVal(codeVal, leaf->right);
		}
	}
	else
	{
		return -1;
	}
}

template <class T>
int btree<T>::keyVal(T codeVal)
{
	return keyVal(codeVal,root);
}

