#include<iostream>/*libraries*/
#include<time.h>
#include<stdlib.h>

int rolling_dice(){/*rolling dice function*/
	return (rand() % 6 + 1);/*generating random number from 1 to 6*/
}
int main()
{
	srand(time(NULL));/*seed as time function*/
	std::cout << "The dice rolls for six times and outputs are: ";
	for (int i = 0; i < 6; i++){/*for loop*/
		std::cout<<rolling_dice()<< " ";
	}
	std::cout << std::endl;
	system("pause");/*hold the system*/
	return 0;
}