#include<iostream>/*libraries*/
#include<vector>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<algorithm>
#include<ctime>
#include<stdio.h>
#include<fstream>
#include<math.h>
#include<string>
class MOVEMIN{/*defining class*/ 
	std::vector<int> a;/*vector of int as private member*/
public:
	MOVEMIN(){/*constructor*/
		std::vector<int>v(10, -1);
		a = v;
		random_vector();/*calling random function*/
	}

	MOVEMIN(int m){/*overloaded constructor*/
		std::vector<int>v(m, -1);/*defining vector of m size*/
		a = v;
		random_vector();/*calling random function*/
	}
	~MOVEMIN(){}/*desturctor*/

	void swap(int&a, int&b){/*swap function*/
		int temp;
		temp = a;
		a = b;
		b = temp;
	}

	std::vector<int>& random_vector(){/*random function*/
		for (int i = 0; i < a.size(); i++){
			a[i] = rand() % 100 + 1;
		}
		std::sort(a.begin(), a.end());
		a[a.size() - 1] = rand()%100+1;
		return a;/*generating vector having only last number as unsorted*/ 
	}

	bool test_moveMIN(std::vector<int> x){/*test for our moveMIN and E_moveMIN function*/
		std::vector<int> y;
		sort(y);/*sorting vector a and storing it into y*/ 
		if (y.size() != x.size())
			return false;
		for (int i = 0; i < y.size();i++)
		if (y[i] != x[i])
			return false;
		return true;
	}
	

	bool moveMin(std::vector<int> &c){/*moveMin function with using two for loop*/
		c = a;
		for (int i = 0; i < c.size()-1;i++){
			for (int j = i+1; j < c.size();j++){
				if (c[i]>c[j])
					swap(c[i],c[j]);
			}
		}
		return true;
	}

	bool E_moveMin(std::vector<int> &d){/*moveMin function with using a for loop*/
		d = a;
		for (int i = d.size()-1; i>0; i--)
		if (d[i]<d[i-1])
			swap(d[i],d[i-1]);
		return true;
	}


	void sort(std::vector<int> &b){/*sort a and storing into b*/
		b = a;
		std::sort(b.begin(), b.end());
	}
};


int main(int argc,char** argv){
	/*argv[1]->file name in which test time for function to be store
	argv[2]->size of our vector
	argv[3]->number of test
	argv[4]->1 for E_movemmin and 2 for simple movemin*/
	srand(time(NULL));
	std::vector<int> out;
	std::ofstream file;//ostream of file
	file.open(argv[1]);
	for (int k = 0; k < std::stoi(argv[3]; k++){/*for loop meant for no. of iteration*/
		MOVEMIN *x = new MOVEMIN(std::stoi(argv[2]);//creating instance of MOVEMIN 

		float a = clock();/*time store in a*/

		if (std::stoi(argv[4]) == 2)
			x->moveMin(out);
		if (std::stoi(argv[4]) ==1)
			x->E_moveMin(out);

		float b = clock();/*time store in b*/

		if (x->test_moveMIN(out))//checking test compatibility
			std::cout << "passed" << std::endl;
		else
			std::cout << "Failed" << std::endl;
		delete x;//destory instance
		float time = b - a;/*difference of time*/
		std::cout << "Time taken : " << time << "msec" << std::endl;
		file << time <<","<< "msec" << std::endl;/*storing into file*/
	}
	file.close();
	system("pause");
	return 0;
}