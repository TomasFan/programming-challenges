#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct kandidate{
public :
	kandidate(string Name):name(Name), vote_count(0), number(0) { };
	int vote_count;
	int number;
	string name;
	vector< vector<int> > votes;
};


int main()
{
	ifstream input ("110108.inp");
	ofstream output ("110108.oup");
	int time, kandidate_number, voters_sum;
	vector<kandidate> kandidates;
	vector< vector<int> > votes;

	input.seekg(0, ios::beg);
	output.clear();

	input >> time;

	do{
		input >> kandidate_number;

		for(int i = 0;i < kandidate_number; i++){
			//char k_name[80];
			string k_name;
			input >> ws;
			getline(input, k_name);
			kandidates.push_back(kandidate(k_name));
		}
		//input >> noskipws;
		int voter_num(0);
		int voted_kandidate;
		while(input.good()){
			vector<int> row;
			votes.push_back(row);
			for(int i = 0; i < kandidate_number; i++){
				input >> std::dec >> voted_kandidate;
				votes[voter_num].push_back(voted_kandidate);
			}
			voter_num++;
		}
		voters_sum = votes.size();
		time--;
	}while(time > 0);

	int fill_time = 0;
	for(vector<int> vote:votes){
		kandidates[vote[fill_time] - 1].votes.push_back(vote);
	}
	fill_time++;

	kandidate * min = NULL;
	kandidate * elected = NULL;
	while (elected == NULL){
		for(kandidate selected:kandidates){
			if ((float)selected.votes.size()/voters_sum < 0.5){
				if (min == 0){
					min = new kandidate(selected);
				}else if (min->votes.size() > selected.votes.size()){
					min = new kandidate(selected);
				}
			} else { 
				elected = new kandidate(selected);
			}
		}

		for(vector<int> vote:min->votes){
			kandidates[vote[fill_time] - 1].votes.push_back(vote);
		}
		fill_time++;
	}

	output << elected->name << endl;

	return 0;
}


