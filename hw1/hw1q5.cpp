#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream input;
	input.open("hw1q5.txt");
	string inst;
	vector<string> words;
	input >> inst;

	while(input >> inst)
	{
		words.push_back(inst);
	}

	for(int i=0; i<words.size(); i++)
	{
		cout << words.at(words.size()-(i+1)) << endl;
	}

	input.close();
}