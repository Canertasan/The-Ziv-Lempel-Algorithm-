#include <iostream>
#include <string>

using namespace std;

template <class T,class T1> // T is int T1 is string
	struct node
	{
		T1 key;
		T code;
		node *left;
		node *right;
		node(T _code, T1 _key)
		{
			key=_key; // num
			code=_code; // string 
			left=nullptr;
			right=nullptr;
		}
	};

template <class T,class T1>	// T is int T1 is string
class btree
{
private:
	void destroy_tree(node<T,T1> *leaf);
	void insert(T codeVal, node<T,T1> *leaf,T1 keyVal);
	node<T,T1> *search(T codeVal, node<T,T1> *leaf);
	node<T,T1> *findMax(node<T,T1> *leaf);
	T1 keyVal(T codeVal,node<T,T1> *leaf);

	node<T,T1> *root;

public:
	btree();
	~btree();

	void destroy_tree();
	void insert(T codeVal,T1 keyVal);
	node<T,T1> *search(T codeVal);
	node<T,T1> *findMax();
	T1 keyVal(T codeVal);


};

template <class T,class T1>	// T is string and T is T1
btree<T,T1>::btree()
{
	root=NULL;
}

template <class T,class T1>	// T is string and T is T1
btree<T,T1>::~btree(){
	destroy_tree();
}


template <class T,class T1>	// T is string and T is T1
void btree<T,T1>::destroy_tree(node<T,T1> *leaf){
	if(leaf != NULL){
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

template <class T,class T1>	// T is string and T is T1
void btree<T,T1>::insert(T codeVal, node<T,T1> *leaf, T1 keyVal)
{
	if(codeVal< leaf->code)
	{
		if(leaf->left!=NULL)
			insert(codeVal, leaf->left,keyVal);
		else
		{
			leaf->left=new node<T,T1>(codeVal,keyVal);
		}  
	}
	else if(codeVal>=leaf->code)
	{
		if(leaf->right!=NULL)
			insert(codeVal, leaf->right,keyVal);
		else
		{
			leaf->right=new node<T,T1>(codeVal,keyVal);
		}
	}
}

template <class T,class T1>	// T is string and T is T1
void btree<T,T1>::insert(T codeVal,T1 keyVal)
{
	if(root!=NULL)
		insert(codeVal, root,keyVal);
	else
	{
		root=new node<T,T1>(codeVal,keyVal);
	}
}


template <class T,class T1>	// T is string and T is T1
node<T,T1>* btree<T,T1>::search(T codeVal, node<T,T1> *leaf)
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


template <class T,class T1>	// T is string and T is T1
node<T,T1> *btree<T,T1>::search(T codeVal)
{
	return search(codeVal,root);
}


template <class T,class T1>	// T is string and T is T1
node<T,T1> *btree<T,T1>::findMax(node<T,T1> *leaf)
{
	if( leaf != NULL )
		while( leaf->right != NULL )
			leaf = leaf->right;
	return leaf;
}

template <class T,class T1>	// T is string and T is T1
node<T,T1> *btree<T,T1>::findMax()
{
	return findMax(root);
}

template <class T,class T1>	// T is string and T is T1
void btree<T,T1>::destroy_tree()
{
	destroy_tree(root);
}

template <class T,class T1>
T1 btree<T,T1>::keyVal(T codeVal,node<T,T1> *leaf)
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
		return "";
	}
}

template <class T,class T1>
T1 btree<T,T1>::keyVal(T codeVal)
{
	return keyVal(codeVal,root);
}

