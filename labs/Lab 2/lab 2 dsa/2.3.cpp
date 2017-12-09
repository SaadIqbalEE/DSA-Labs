#include<iostream>
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
class MOVEMIN{
	std::vector<int> a;
public:
	MOVEMIN(){
		std::vector<int>v(10, -1);
		a = v;
		random_vector();
	}

	MOVEMIN(int m){
		std::vector<int>v(m, -1);
		a = v;
		random_vector();
	}
	~MOVEMIN(){}

	void swap(int&a, int&b){
		int temp;
		temp = a;
		a = b;
		b = temp;
	}

	std::vector<int>& random_vector(){
		for (int i = 0; i < a.size(); i++){
			a[i] = rand() % 100 + 1;
		}
		std::sort(a.begin(), a.end());
		a[a.size() - 1] = rand()%100+1;
		return a;
	}

	bool test_moveMIN(std::vector<int> x){
		std::vector<int> y;
		sort(y);
		if (y.size() != x.size())
			return false;
		for (int i = 0; i < y.size();i++)
		if (y[i] != x[i])
			return false;
		return true;
	}
	

	bool moveMin(std::vector<int> &c){
		c = a;
		for (int i = 0; i < c.size()-1;i++){
			for (int j = i+1; j < c.size();j++){
				if (c[i]>c[j])
					swap(c[i],c[j]);
			}
		}
		return true;
	}

	bool E_moveMin(std::vector<int> &d){
		d = a;
		for (int i = d.size()-1; i>0; i--)
		if (d[i]<d[i-1])
			swap(d[i],d[i-1]);
		return true;
	}


	void sort(std::vector<int> &b){
		b = a;
		std::sort(b.begin(), b.end());
	}
};


int main(int argc,char** argv){
	/*For efficient f(x) use 1 and for other algorithm use 2*/
	srand(time(NULL));
	std::vector<int> out;
	int no_of_Rnum = std::stoi(argv[2]);
	int no_of_Iter = std::stoi(argv[3]);
	std::ofstream file;
	file.open(argv[1]);
	for (int k = 0; k < no_of_Iter; k++){
		MOVEMIN *x = new MOVEMIN(no_of_Rnum);
		float a = clock();
		if (std::stoi(argv[4]) == 2)
			x->moveMin(out);
		if (std::stoi(argv[4]) ==1)
			x->E_moveMin(out);
		float b = clock();
		if (x->test_moveMIN(out))
			std::cout << "passed" << std::endl;
		else
			std::cout << "Failed" << std::endl;
		delete x;
		float time = b - a;
		std::cout << "Time taken : " << time << "msec" << std::endl;
		file << time <<","<< "msec" << std::endl;
	}
	file.close();
	system("pause");
	return 0;
}