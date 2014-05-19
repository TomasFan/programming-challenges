#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

int main()
{
	ifstream input ("110103.inp");
	ofstream output ("110103.oup");
	int number = 0;
	float temp;
	vector<float> digits;

	input.seekg(0, ios::beg);
	output.clear();

	while (input >> number)
	{
		digits.clear();
		for (int i = 0; i < number; i++){
			input >> temp;
			digits.push_back(temp);
		}
		float avg = accumulate(digits.begin(), digits.end(), 0) / digits.size();
		float result(0);
		for ( float item : digits)
		{
			result += item > avg ? item - avg : 0 ;
		}
		output << result << endl;
	}

	return 0;
}