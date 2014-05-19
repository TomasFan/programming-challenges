#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> DefaultMask();

int main()
{
	ifstream input ("110102.inp");
	ofstream output ("110102.oup");
	int hight, width, field_numb;
	int number = 0;

	input.seekg(0, ios::beg);
	output.clear();

	do{
		number++;
		input >> hight >> width;
		if (!(width && hight)) break; 
		vector< vector<char> > field(hight, std::vector<char>(width));
		for(int row = 0; row < hight; row++){
			for(int collomn = 0; collomn < width; collomn++){
				input >>  field[row][collomn];
				if (field[row][collomn] == '.') field[row][collomn] = '0';
			}
		}
		vector<int> mask = DefaultMask();
		for(int row = 0; row < hight; row++){
			for(int collomn = 0; collomn < width; collomn++){
				if (field[row][collomn] == '*'){
					mask = DefaultMask();

					/*
					123
					8*4
					765
					*/
					if (row == 0){
						mask.erase(remove(mask.begin(), mask.end(), 0), mask.end());
						mask.erase(remove(mask.begin(), mask.end(), 1), mask.end());
						mask.erase(remove(mask.begin(), mask.end(), 2), mask.end());
					}
					if (collomn == 0){
						mask.erase(remove(mask.begin(), mask.end(), 0), mask.end());
						mask.erase(remove(mask.begin(), mask.end(), 7), mask.end());
						mask.erase(remove(mask.begin(), mask.end(), 6), mask.end());
					}
					if (row == hight -1){
						mask.erase(remove(mask.begin(), mask.end(), 4), mask.end());
						mask.erase(remove(mask.begin(), mask.end(), 5), mask.end());
						mask.erase(remove(mask.begin(), mask.end(), 6), mask.end());
					}
					if (collomn == width-1){
						mask.erase(remove(mask.begin(), mask.end(), 3), mask.end());
						mask.erase(remove(mask.begin(), mask.end(), 4), mask.end());
						mask.erase(remove(mask.begin(), mask.end(), 2), mask.end());
					}
					for (int i : mask){
						switch(i){
						case 0:{
							if (field[row-1][collomn-1] == '*') break;
							field[row-1][collomn-1] = field[row-1][collomn-1]++;
							break;
							   }
						case 1:{
							if (field[row-1][collomn] == '*') break;
							field[row-1][collomn] = field[row-1][collomn]++;
							break;
							   }
						case 2:{
							if (field[row-1][collomn+1] == '*') break;
							field[row-1][collomn+1] = field[row-1][collomn+1]++;
							break;
							   }
						case 3:{
							if (field[row][collomn+1] == '*') break;
							field[row][collomn+1] = field[row][collomn+1]++;
							break;
							   }
						case 4:{
							if (field[row+1][collomn+1] == '*') break;
							field[row+1][collomn+1] = field[row+1][collomn+1]++;
							break;
							   }
						case 5:{
							if (field[row+1][collomn] == '*') break;
							field[row+1][collomn] = field[row+1][collomn]++;
							break;
							   }
						case 6:{
							if (field[row+1][collomn-1] == '*') break;
							field[row+1][collomn-1] = field[row+1][collomn-1]++;
							break;
							   }
						case 7:{
							if (field[row][collomn-1] == '*') break;
							field[row][collomn-1] = field[row][collomn-1]++;
							break;
							   }
						}
					}
				}
			}
		}
		output << "Field #" << number << endl;
		for(int row = 0; row < hight; row++){
			for(int collomn = 0; collomn < width; collomn++){
				char tmp = field[row][collomn];
				output << tmp;
			}
			output << endl;
		}
		output << endl;
	}while(width && hight);
	return 0;
}

vector<int> DefaultMask(){
	int myints[] = {0,1,2,3,4,5,6,7};
	vector<int> vec(begin(myints),end(myints));
	return vec;
}


