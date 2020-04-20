#pragma once

#include <string>
#include <vector>

using namespace std;

enum argument { programName, fileName };
enum status {success,failure_statementnumber,failure_openfile};
int usagemessage(int k);
int parseinput(vector<string>&, char *);