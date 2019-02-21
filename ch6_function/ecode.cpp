#include <iostream>
#include "ecode.h"
using namespace std;

ErrCode::ErrCode() = default;
ErrCode::ErrCode(const int e)
{
	this -> ecode = e;
}

string ErrCode::msg()
{
	string s;
	switch (ecode) {
		case 0:
			s = "okay";
			break;
		case 42:
			s = "Missing";
			break;
		default:
			s = "Error";
			break;
	}
	return s;
}
