#include<iostream>//libraries
#include<forward_list>
#include<algorithm>

using namespace std;//defining std

class node{//class node
public:
	int cofficient;//member variable of node
	int exponent;

	node(){};//constructor of node
	~node(){};//destructor of node
	node(int x, int y){//constructor overloading
		cofficient = x;
		exponent = y;
	}

	bool operator < (const node& x) const//operater overloading
	{
		return (exponent > x.exponent);
	}
};

void display(forward_list<node> x){//displaying list
	x.sort();
	forward_list<node>::iterator a = x.begin();
	cout << "Polynomial is: " << endl;
	for (; a != x.end(); a++)
		cout << a->cofficient << "x^" << a->exponent << " --> ";
	cout << "NULL"<<endl;
}

forward_list<node> addition(forward_list<node> l1, forward_list<node> l2){//to add two list
	
	l1.sort();
	l2.sort();
	
	forward_list<node> l3;
	forward_list<node>::iterator a=l1.begin(),b=l2.begin();
	if (l1.empty() || l2.empty()){//if polynomials are empty
		if (l1.empty() && !l2.empty())
			return l3 = l2;
		if (l2.empty() && !l1.empty())
			return l3 = l1;
		if (l1.empty() && l2.empty())
			return l3;
	}
	else{//if not empty
		while (a != l1.end() || b != l2.end()){
			if (a->exponent == b->exponent){
				l3.push_front(*new node(a->cofficient + b->cofficient, a->exponent));
				a++;
				b++;
			}
			else{
				if (a->exponent > b->exponent){
					l3.push_front(*new node(a->cofficient, a->exponent));
					a++;
				}
				else{
					l3.push_front(*new node(b->cofficient, b->exponent));
					b++;
				}
			}
			while (a == l1.end() || b == l2.end()){
				if (a == l1.end() && b != l2.end())
				{
					l3.push_front(*new node(b->cofficient, b->exponent));
					b++;
				}
				if (a != l1.end() && b == l2.end())
				{
					l3.push_front(*new node(a->cofficient, a->exponent));
					a++;
				}
				if (a == l1.end() && b == l2.end())
					break;
			}
		}
	}
	l3.sort();//sorting result of addition
	return l3;//returning polynomials
}

void test_cases(){//test cases
	forward_list<node> alpha1, alpha2,result,check;	
	alpha1.push_front(*new node(1, 0));//first polynomial
	alpha1.push_front(*new node(6, 1));
	alpha1.push_front(*new node(5, 2));
	alpha1.push_front(*new node(3, 3));
	alpha1.push_front(*new node(4, 4));

	alpha2.push_front(*new node(3, 0));//second polynomial
	alpha2.push_front(*new node(4, 1));
	alpha2.push_front(*new node(6, 4));
	alpha2.push_front(*new node(9, 5));
	
	result.push_front(*new node(4, 0));//result polynomial
	result.push_front(*new node(10, 1));
	result.push_front(*new node(5, 2));
	result.push_front(*new node(3, 3));
	result.push_front(*new node(10, 4));
	result.push_front(*new node(9, 5));
	
	check = addition(alpha1, alpha2);//result of function
	forward_list<node>::iterator x = result.begin(), y=check.begin();
	for (; y != check.end(); y++){
		if (y->cofficient == x->cofficient&&y->exponent == x->exponent)
			x++;
		else{
			cout << "test failed";//test failed
			break;
		}
	}
	if (check.end() == y &&x == result.end()){
		cout << "test passed"<<endl;//test passed
	}
}



int main(){
	test_cases();//test case
	cout << endl;
	forward_list<node> l1;//defining list1 and list 2
	forward_list<node> l2;
	l1.push_front(*new node(5,12));//data entering
	l1.push_front(*new node(2,9));
	l1.push_front(*new node(4,7));
	l1.push_front(*new node(6,6));
	l1.push_front(*new node(1,3));

	l2.push_front(*new node(7,8));
	l2.push_front(*new node(2,7));
	l2.push_front(*new node(8,6));
	l2.push_front(*new node(6,4));
	l2.push_front(*new node(2,2));
	l2.push_front(*new node(3,1));
	l2.push_front(*new node(40,0));

	display(l1);//display l1
	display(l2);//display l2
	cout << "Addition of Two polynomial is:" << endl << "Result:" << endl;
	display(addition(l1,l2));//display addition of polynomial 1 and 2


	system("pause");
	return 0;
}