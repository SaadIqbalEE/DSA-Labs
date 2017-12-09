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

class que{//queue class with static array of 100 size
	node* ss[100];//private member
public:
	int H_position, T_position;//member variable of node
	void enque(int a){//enqueue function
		if (T_position < 100){
			ss[T_position] = new node(a);
			T_position++;
		}
		else
			cout << "List is overflow" << endl;
	}
	void deque(){//dequeue function
		if (H_position < T_position){
			ss[H_position] = NULL;
			H_position++;
		}
		else
		{
			cout << "Underflow" << endl;
		}
	}
	int front(){//getting from front
		if (H_position < T_position)
			return ss[H_position]->value;
		else{
			cout << "underflow" << endl;
			return -1;
		}
	}
	int back(){//getting from back
		if (H_position < T_position)
			return ss[T_position - 1]->value;
		else{
			cout << "underflow" << endl;
			return -1;
		}
	}
	que(){//consturctor 
		H_position = T_position = 0;
		ss[H_position] = NULL;
	}
	~que(){}//destructor

};

int main(){
	que x;//stack defining
	for (int i = 100; i <= 500;){//for loop to enqueue data
		x.enque(i);
		i += 100;
	}
	cout << "values: ";
	while (x.H_position <x.T_position){//display +dequeue
		cout << x.front() << " ";
		x.deque();
	}
	cout << endl;
	system("pause");
	return 0;
}