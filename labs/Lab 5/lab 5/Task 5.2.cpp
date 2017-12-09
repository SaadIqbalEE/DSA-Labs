#include<iostream>//lib
#include<fstream>
#include<sstream>
#include<string>
#include<map>
#include<vector>

using namespace std;

class CSVRow{//class CSVRow taken from stackoverflow
	vector<std::string> m_data;
public:
	std::string const& operator[](std::size_t index) const{
		return m_data[index];
	}
	size_t size() const{
		return m_data.size();
	}
	void readNextRow(std::istream& str) {
		std::string line;
		std::getline(str, line);
		std::stringstream lineStream(line);
		std::string cell;
		m_data.clear();
		while (std::getline(lineStream, cell, ',')) {
			m_data.push_back(cell);
		}
	}
};
istream& operator >>(istream& str, CSVRow& data) {
	data.readNextRow(str);
	return str;
}



int main(int argc,char** argv){//command line argumnent
	map<string, unsigned int> data;
	if (!argc>1)
		cout << "OOP....Enter file name"<<endl;
	else{
		ifstream file;
		file.open(argv[1]);
		if (file.is_open()){
			int c = 1;
			CSVRow row;
			cout << "Names and marks" << endl << "******************" << endl<<endl;
			while (file >> row)
			{
				if (c> 1){
					cout << row[0] << endl<<row[1]<<endl;
					data[row[0]] = stoi(row[1]);
				}
				c++;
			}
		}
		else
			cout << "Error in opening......." << endl;
		file.close();
	}
	map<string, unsigned int>::iterator itr = data.begin();
	double mean=0.0;
	int numbers = 0;
	while (!(itr==data.end())){
		if (itr->first[0] == 'M' || itr->first[0] == 'm'){
			numbers++;
			mean += itr->second;
		}
		itr++;
	}
	cout << "Mean marks of students,whose name starts from M: "<<mean/numbers<<endl;//mean of m peoples
	system("pause");
	return 0;
}