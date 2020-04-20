// lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lab1.h"
#include <iostream>
#include "sstream"
#include "fstream"
#include <string>
#include <vector>

using namespace std;

int main(int argc, char * argv[])
{
	if (argc == 2) {
		vector<string> s;
		if (parseinput(s, argv[fileName])==success) {
			vector<int> c;
			int l = s.size();
			for (int i = 0;i < l;++i) {
				int lw = s[i].size();
				bool f = true;
				int number = 0;
				for (int j = 0;j < lw;++j) {
					if (s[i][j] < '0'||s[i][j] > '9') {
						f = false;
						break;
					}
				}
				if (f == true) {
					istringstream ss(s[i]);
					ss >> number;
					c.push_back(number);
				}
				else {
					cout << s[i]<<endl;
				}
			}
			int intl = c.size();
			for (int i = 0;i < intl;++i) {
				cout << c[i] << endl;
			}
			cout << endl;
		}
		return success;
	}
	else {
		return usagemessage(argc);
	}
    return 0;
}

int usagemessage(int k) {
	cout << "Please give only one extra statement" << endl;
	return failure_openfile;
}

int parseinput(vector<string>& s, char * name){
	ifstream ifs;
	ifs.open(name);
	if (ifs.is_open())
	{
		string line, word;
		while (getline(ifs, line)) {
			istringstream iss(line);
			while (iss >> word) {
				s.push_back(word);
			}
		}
		ifs.close();
		return success;
	}
	else {
		cout << "File cannot open" << endl;
		return failure_statementnumber;
	}
}

