#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string>
#include<time.h>
#include<algorithm>

class MOVEMIN{
	std::vector<int> a;
public:
	MOVEMIN(){
		std::vector<int>v(100, -1);
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
		a[a.size() - 1] = (rand() % 100 + 1);
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


int main(){
	srand(time(NULL));
	std::vector<int> out;
	for (int k = 0; k < 100; k++){
		MOVEMIN *x = new MOVEMIN;
		x->moveMin(out);
		if (x->test_moveMIN(out))
			std::cout << "passed" << std::endl;
		else
			std::cout << "Failed" << std::endl;
		delete x;
	}
	system("pause");
	return 0;
}