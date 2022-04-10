#include<iostream>
#include<string>
#include<sstream>

using namespace std;

int main() {
	string line = "2022 Spring c++ Programming";
	stringstream myVal(line);
	string words[10];
	int num = 0;

	while (getline(myVal, words[num], ' ')) {
		cout << words[num] << endl;
		num++;
	}
}