#include <iostream>
using namespace std;
struct Tree
{
	int value;
	Tree* right;
	Tree* left;
	Tree()
	{
		value = -1;
		right = NULL;
		left = NULL;
	}
};
struct ListElement
{
	int value;
	ListElement* pointer;
	ListElement()
	{
		value = -1;
		pointer = NULL;
	}
};
void Input(Tree*& e, int x)
{
	if (e == NULL)
	{
		e = new Tree();
		e->value = x;
	}
	else
		if (e->value > x)
		{
			Input(e->left, x);
		}
		else
			if (e->value < x)
			{
				Input(e->right, x);
			}
}
void Output(Tree* e)
{
	if (e != NULL)
	{
		Output(e->left);
		cout << e->value << " ";
		Output(e->right);
	}

}
void Detach(Tree* root, Tree* e)
{
	if (root == NULL || e == NULL) { return; }
	else if (root->left == e) { root->left = NULL; }
	else if (root->right == e) { root->right = NULL; }
	{
		Detach(root->left, e);
		Detach(root->right, e);
	}
}
void Remove(Tree* e)
{
	if (e != NULL)
	{
		Remove(e->left);
		Remove(e->right);
		delete e;
	}
}
Tree* Find(Tree* e, int x)
{
	Tree* result = NULL;
	if (e == NULL) { result = NULL; }
	else if (e->value == x) { result = e; }
	else
	{
		result = Find(e->left, x);
		if (result == NULL) { result = Find(e->right, x); }
	}
	return result;
}
void List(ListElement*& first, Tree* e, ListElement*& elem)
{
	if (e)
	{
		List(first, e->left, elem);
		ListElement* p = new ListElement();
		p->value = e->value;
		if (elem == NULL)
		{
			first = p;
			elem = p;
		}
		else
		{
			elem->pointer = p;
			elem = p;
		}
		List(first, e->right, elem);
	}
}

void OutputList(ListElement* m) {
	while (m != NULL) {
		cout << m->value << " ";
		m = m->pointer;
	}
	cout << endl;
}
int main() {
	setlocale(LC_ALL, "Russian");
	Tree* root = NULL;
	ListElement* number = NULL;
	int N = 0, el;
	cout << "Введите количество чисел " << endl;
	cin >> N;
	cout << "Введите числа " << endl;
	for (int i = 0; i < N; i++) {
		cin >> el;
		Input(root, el);
	}
	Output(root);
	cout << endl;
	int n;
	cout << "Введите число для удаления поддерева" << endl;
	cin >> n;
	Tree* e = Find(root, n);
	Detach(root, e);
	Remove(e);
	Output(root);
	cout << endl;
	cout << "Список ";
	ListElement* Nch = NULL;
	List(number, root, Nch);
	OutputList(number);
	return 0;


}
