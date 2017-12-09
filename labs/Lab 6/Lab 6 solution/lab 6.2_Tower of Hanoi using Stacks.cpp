/*
* Name:Saad Iqbal
* Student # 32903
* Date: 29/10/2015
*/

/*
* PROBLEM
* Tower of Hanoi using Stacks
* EXECUTE the program without making any changes
*/

#include <iostream>

#include "myNode.hpp"
#include "myStack.hpp"

using namespace std;

unsigned int moves = 0;

/*
* Function moves a disk from source tower to destination tower
*/
void MoveDisk(Stack<int>& source, Stack<int>& destination) {
	if (destination.IsEmpty() || (destination.Top())->Data() > (source.Top())->Data()) {
		cout << "\tMoving Disk #\t" << (source.Top())->Data() << "\t(" << &source << " -> " << &destination << ")" << endl;
		destination.Push(source.Pop());
	}
}

/*
* Function recursively solves the tower of Hanoi puzzle
*/
void MoveTowerofHanoi(int disks, Stack<int>& source, Stack<int>& destination, Stack<int>& spare) {
	moves ++;
	if (disks == 1)
		MoveDisk(source, destination);
	else{
		MoveTowerofHanoi(disks - 1, source, spare, destination);
		MoveDisk(source, destination);
		MoveTowerofHanoi(disks - 1, spare, destination, source);
	}
}

int main() {
	Stack<int> source, destination, spare;

	cout << endl
		<< "\n\tEnter the number of disks: ";

	unsigned int dnum;
	cin >> dnum; cin.ignore();
	for (unsigned int i = dnum; i >= 1; i--) {
		source.Push(i);
	}

	cout << endl
		<< "\tTowers:" << endl
		<< "\t\tTower 1:\t" << &source << endl
		<< "\t\tTower 2:\t" << &destination << endl
		<< "\t\tTower 3:\t" << &spare << endl
		<< endl;

	MoveTowerofHanoi(dnum, source, destination, spare);

	cout << endl
		<< "\n\tNumber of moves:\t" << moves;

	cin.get();
	return 0;
}