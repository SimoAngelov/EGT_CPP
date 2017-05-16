/*
 * BigInteger.h
 *
 *  Created on: Apr 18, 2017
 *      Author: SimoAngelov
 */

#ifndef BIGINTEGER_H_
#define BIGINTEGER_H_

#include <string>
#include <vector>
using std::string;
using std::vector;
class BigInteger {
private:
	string numStr;
	int carry;
	vector<int> numberArr;
	BigInteger product;
	void toIntArray();
	static char digitChar[10];
	void addIfEqual(const vector<int>& num1, const vector<int>& num2, string& result);
	void addIfNotEqual(const vector<int>& num1, const vector<int>& num2, string& result);
	void subtractIfEqualSize(const vector<int>& num1, const vector<int>& num2, string& result);
	void subtractIfNotEqualSize(const vector<int>& num1, const vector<int>& num2, string& result);
	void removeBeginZeros(string& result);
	void printV(const vector<int>& num) const;
	void multiply1AtATime(const vector<int>& num, int multiplyer, int powerOf10, string& result);
public:
	BigInteger();
	BigInteger(string );


	virtual ~BigInteger();
	const string& getNumStr() const;
	void setNumStr(const string& numStr);
	const vector<int>& getNumberArr() const;
	void setNumberArr(const vector<int>& numberArr);

	void input();
	void input(const string& arg);
	void output() const;

	string add(const BigInteger&);
	string subtract(const BigInteger&);
	string multiply(const BigInteger&);
	BigInteger operator +(const BigInteger& num2);
	BigInteger operator -(const BigInteger& num2);

	bool isEqualTo(const BigInteger&) const;
	bool isNotEqualTo(const BigInteger&) const;
	bool isGreaterThan(const BigInteger&) const;
	bool isLessThan(const BigInteger&) const;

};

#endif /* BIGINTEGER_H_ */
