#include "IntToString.h"

string IntToString::intToString(int num){
	string result;          // string which will contain the result
	ostringstream convert;   // stream used for the conversion
	convert << num;      // insert the textual representation of 'Number' in the characters in the stream
	result = convert.str(); // set 'Result' to the contents of the stream

	return result;
}