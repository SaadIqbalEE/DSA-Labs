#include<iostream>//libraries

using namespace std;//defining std

class node{//class node
public:
	node(){};
	~node(){};
	int value;
	node* next;

};


class list{//class list
public:
	node* head;//head pointer
	node* iterator;//node tranverse pointer
	list(){//constructor
		head = NULL;
		iterator = NULL;
	}
	~list(){}//destructor
	void insert_at_beginning(int new_value){//function to insert node at beginning
		node* lnew = new node;
		lnew->value = new_value;
		lnew->next = head;
		head = lnew;
	}
	void insert_at_loc(int location, int new_value){//function to insert node at desired location
		iterator = head;
		int i;
		for (i = 1; i <= location && iterator != NULL; i++){
			if (location == i + 1){
				node* lnew = new node;
				lnew->value = new_value;
				node* temp;
				temp = iterator->next;
				iterator->next = lnew;
				lnew->next = temp;
			}
			else
				insert_at_beginning(new_value);
			iterator = iterator->next;
		}
		if (i != location)//out of range exception
			cout << "List is short than ur imagination" << endl;
	}
	void display(){//display list
		iterator = head;
		while (iterator != NULL)
		{
			cout << iterator->value << "  ";
			iterator = iterator->next;
		}
		cout << endl;
	}
	void del(int del_value){//delete node
		iterator = head;
		node* remember_last = NULL;
		if (iterator == NULL)
			cout << "List is empty" << endl;
		else{
			while (iterator->value != del_value){
				remember_last = iterator;
				iterator = iterator->next;
				if (iterator == NULL)
					break;
				else
					continue;
			}
			if (iterator == NULL){
				cout << "Number not found" << endl;
			}
			else{
				if (remember_last== NULL){
					head = iterator->next;
					node* temp;
					temp = iterator;
					delete temp;
				}
				else{
					node* temp;
					remember_last->next = iterator->next;
					temp = iterator;
					delete temp;
				}
			}
		}
	}

	void count(){//counter of nodes
		iterator = head;
		int count = 0;
		while (iterator != NULL)
		{
			count++;
			iterator = iterator->next;
		}
		cout << count << endl;;
	}
};
int main(){
	list l1;
	while (1){
		cout << "Press 1 to insert at beginning" << endl;//menu
		cout << "Press 2 to insert at desired location" << endl;
		cout << "Press 3 to delete the value" << endl;
		cout << "Press 4 to count nodes" << endl;
		cout << "Press 5 to display list" << endl;
		cout << "********************************************" << endl;
		int Q, A, B;
		cin >> Q;
		switch (Q){
		case 1:
			cout << "Enter the value" << endl;
			cin >> A;
			l1.insert_at_beginning(A);
			cout << "********************************************" << endl;
			break;
		case 2:
			cout << "Enter the value and location" << endl;
			cin >> A >> B;
			l1.insert_at_loc(B, A);
			cout << "********************************************" << endl;
			break;
		case 3:
			cout << "Enter the value to be delete" << endl;
			cin >> A;
			l1.del(A);
			cout << "********************************************" << endl;
			break;
		case 4:
			l1.count();
			cout << "********************************************" << endl;
			break;
		case 5:
			l1.display();
			cout << "********************************************" << endl;
			break;
		default:
			cout << "out of case" << endl;
			cout << "********************************************" << endl;
		}
		system("pause");
		system("CLS");
	}
	return 0;
}