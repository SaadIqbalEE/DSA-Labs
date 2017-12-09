/*
* Name:Saad Iqbal
* Student # 32903
* Date: 29/10/2015
*/

/*
* lab 6
* 
*/
#include<iostream>
#include<string>

using namespace std;

void PRINT_STRING(string a){
	if (a.size() == 0)// base case
		return ;
	cout << a[0];// do some work
	PRINT_STRING(a.substr(1, a.size() + 1)); // recursive call on simpler problem
	cout << a[0];// do some work
}

int main(){
	PRINT_STRING("Alas");
	cout << endl;
	PRINT_STRING("Saad");
	cout << endl;
	PRINT_STRING("Cartoon");
	cout << endl;
	PRINT_STRING("CS250");
	cout << endl;
	PRINT_STRING("Nothing");
	cout << endl;
	PRINT_STRING("Gamer");
	cout << endl;
	PRINT_STRING("Hello");
	cout << endl;
	system("pause");
	return 0;
}