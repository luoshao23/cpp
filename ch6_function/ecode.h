#ifndef ECODE_H
#define ECODE_H

#include <iostream>
using namespace std;

class ErrCode {
public:
	ErrCode();
	ErrCode(const int e);
	string msg();
private:
	int ecode;
};

#endif
