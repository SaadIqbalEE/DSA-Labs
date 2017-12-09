#include<iostream>//libraries
using namespace std;//defining std

class node{//class node
public:
	int value;//member variable of node
	node(){//constructor of node
		value = -1;
	}
	node(int x){//constructor overloading
		value = x;
	}
	~node(){}//destructor of node
};

class stack{//stack class with static array of 100 size
	node* ss[100];//private member
public:
	int position;//member variable of node
	stack(){//consturctor 
		position = 0;
		ss[position] = NULL;
	}
	~stack(){}//destructor

	void push(int a){//push function
		if (position < 100 && position >= 0){
			ss[position] = new node(a);
			position++;
			ss[position] == NULL;
		}
		else
			cout << "Overflow" << endl;
	}
	void pop(){//pop function
		if (position > 0){
			position--;
			ss[position] = NULL;
		}
		else
			cout << " Now list is empty";
	}
	int peek(){//peek function
		if (position > 0 && position < 101)
			return ss[position - 1]->value;
		else{
			cout << "Underflow" << endl;
			return -1;
		}
	}
};



int main(){
	stack x;//stack defining
	for (int i = 100; i <= 500;){//for loop to push data
		x.push(i);
		i += 100;
	}
	cout << "values: " << endl;
	while (x.position > 0){//display +poping
		cout << x.peek() << endl;
		x.pop();
	}
	cout << endl;
	system("pause");
	return 0;
}