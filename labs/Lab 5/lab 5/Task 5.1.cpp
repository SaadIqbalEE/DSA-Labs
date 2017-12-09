#include<iostream>//library

using namespace std;

int hammingWeight(int num){//function of humming weight
	int n=0;
	if (num <0)
		return -1;//check for negative number
	else{
		while (num > 0)
		{
			n += num & 1;
			num /= 2;
		}
		return n;
	}
}

int main(){
	cout << "Enter number" << endl;
	int x;
	cin >> x;
	cout << "Hamming weight is: ";
	if (hammingWeight(x) == -1)
		cout << "Error"<<endl;//check
	else
		cout<<hammingWeight(x);//returning humming number
	cout << endl;
	system("pause");
	return 0;
}