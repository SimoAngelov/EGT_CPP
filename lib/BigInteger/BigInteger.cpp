/*
 * BigInteger.cpp
 *
 *  Created on: Apr 18, 2017
 *      Author: SimoAngelov
 */

#include "BigInteger.h"
#include <iostream>
using namespace std;

char BigInteger::digitChar[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8',
		'9' };
BigInteger::BigInteger() {
	// TODO Auto-generated constructor stub
	setNumStr("0");
	carry = 0;

}
BigInteger::BigInteger(string numStr) {
	setNumStr(numStr);
	carry = 0;

	toIntArray();
}

BigInteger::~BigInteger() {
	// TODO Auto-generated destructor stub
}
//getters and setters

void BigInteger::setNumStr(const string& numStr) {
	this->numStr = numStr;
}
const string& BigInteger::getNumStr() const {
	return numStr;
}
const vector<int>& BigInteger::getNumberArr() const {
	return numberArr;
}

void BigInteger::setNumberArr(const vector<int>& numberArr) {
	this->numberArr = numberArr;
}

//Business Logic
void BigInteger::toIntArray() {
	int size = numStr.length();
	for (int i = 0; i < size; i++) {
		int digit = numStr.at(i) - 48;
		numberArr.push_back(digit);
	}
}

void BigInteger::input() {
	cout << "Enter a number up to 40 digits: " << endl;
	string numStr;
	cin >> numStr;
	setNumStr(numStr);
	toIntArray();
}

void BigInteger::input(const string& arg){
	setNumStr(arg);
		toIntArray();
}

void BigInteger::output() const {

	cout << numStr << endl;
}
string BigInteger::add(const BigInteger& numArg) {
	string result = "";
	vector<int> num1 = this->getNumberArr();
	vector<int> num2 = numArg.getNumberArr();
	int size;
	if (num1.size() == num2.size()) {
		this->addIfEqual(num1, num2, result);
	} else {
		if (this->isGreaterThan(numArg)) {
			size = num1.size();
			this->addIfNotEqual(num1, num2, result);

		} else {
			size = num2.size();
			this->addIfNotEqual(num2, num1, result);
		}
	}
	carry = 0;
	return result;

}
void BigInteger::addIfEqual(const vector<int>& num1, const vector<int>& num2, string& result){
	int size = num2.size();
	int digitSum = 0;
	for (int i = size - 1; i >= 0; i--) {
		if (i == 0) {
			digitSum = num1[i] + num2[i] + carry;
//			cout << num1[i] << " + " << num2[i] << " + " << carry << " = "
//					<< digitSum << endl;

			int digit = digitSum % 10;
			carry = digitSum / 10;
			if (carry == 0) {
				result.insert(0, 1, digitChar[digit]);
			} else {
				result.insert(0, 1, digitChar[digit]);
				result.insert(0, 1, digitChar[carry]);
			}
		} else {
			digitSum = num1[i] + num2[i] + carry;
//			cout << num1[i] << " + " << num2[i] << " + " << carry << " = "
//					<< digitSum << endl;
			int digit = digitSum % 10;
//			cout << "digit: " << digit << endl;
			//char ch = digit+48;
			carry = digitSum / 10;
			result.insert(0, 1, digitChar[digit]);
			digitSum = 0;
		}

	}

}
void BigInteger::addIfNotEqual(const vector<int>& num1, const vector<int>& num2,
		string& result) {
	int size = num1.size();
	int digitSum = 0;
	int j = num2.size() - 1;
	for (int i = size - 1; i >= 0; i--) {
		if (i == 0) {
			digitSum = num1[i] + carry;
//			cout << num1[i] << " + " << carry << " = " << digitSum << endl;

			int digit = digitSum % 10;
			carry = digitSum / 10;
			if (carry == 0) {
				result.insert(0, 1, digitChar[digit]);
			} else {
				result.insert(0, 1, digitChar[digit]);
				result.insert(0, 1, digitChar[carry]);
			}
		} else {
			if (j >= 0) {
				digitSum = num1[i] + num2[j] + carry;
//				cout << num1[i] << " + " << num2[j] << " + " << carry << " = "
//						<< digitSum << endl;
				int digit = digitSum % 10;
//				cout << "digit: " << digit << endl;
				carry = digitSum / 10;
				result.insert(0, 1, digitChar[digit]);
				digitSum = 0;
				j--;
			} else {
				digitSum = num1[i] + carry;
//				cout << num1[i] << " + " << carry << " = " << digitSum << endl;
				int digit = digitSum % 10;
//				cout << "digit: " << digit << endl;
				carry = digitSum / 10;
				result.insert(0, 1, digitChar[digit]);
				digitSum = 0;
			}
		}

	}

}

string BigInteger::subtract(const BigInteger& numArg) {
	string result = "";
	vector<int> num1 = this->getNumberArr();
	vector<int> num2 = numArg.getNumberArr();
//	cout << "num1 = ";
//	this->output();
//	cout << "num2 = ";
//	numArg.output();
	if (num1.size() == num2.size()) {
		if (this->isEqualTo(numArg)) {
			result.insert(0, "0");
		} else if (!this->isEqualTo(numArg) && this->isGreaterThan(numArg)) {
//			cout << "case2" << endl;
			subtractIfEqualSize(num1, num2, result);
		} else {
//			cout << "case3" << endl;
			subtractIfEqualSize(num2, num1, result);
//			cout << "Result after subtractIftEqual " << result << endl;
			result.insert(0, "-");
//			cout << "after inserting a - " << result << endl;
		}
	} else {
		if (this->isGreaterThan(numArg)) {

			this->subtractIfNotEqualSize(num1, num2, result);

		} else {

			this->subtractIfNotEqualSize(num2, num1, result);
//			cout << "Result after subtractIFNotEqual " << result << endl;
			result.insert(0, "-");
//			cout << "after inserting a - " << result << endl;
		}
	}

	return result;
}

void BigInteger::subtractIfEqualSize(const vector<int>& num1,
		const vector<int>& num2, string& result) {
//	cout << "\nSubtract if equal size - Enter" << endl;
//	printV(num1);
//		cout << "Num2 = ";
//		printV(num2);
	int size = num1.size();
	int diff = 0;
	int digit = 0;
	carry = 0;
	for (int i = size - 1; i >= 0; i--) {
		diff = num1[i] - num2[i] - carry;
//		cout << num1[i] << " - " << num2[i] << " - " << carry << " = " << diff
//				<< endl;
		if (diff < 0) {
			digit = 10 + diff;
			carry = 1;
		} else {
			digit = diff;
			carry = 0;
		}
//		cout << "digit: " << digit << endl;
		result.insert(0, 1, digitChar[digit]);
//		cout << "Result = " << result << endl;
	}
//	cout << "\nSubtract if equal size - Leave" << endl;
	removeBeginZeros(result);
}
void BigInteger::printV(const vector<int>& num) const{
	for(unsigned int i = 0; i < num.size(); i++){
		cout << num[i];
	}
	cout << endl;
}
void BigInteger::subtractIfNotEqualSize(const vector<int>& num1,
		const vector<int>& num2, string& result) {
//	cout << "\nSubtract if NOT equal size - Enter" << endl;
//	cout << "Num1 = ";
//	printV(num1);
//	cout << "Num2 = ";
//	printV(num2);
	int size = num1.size();
	int diff = 0;
	int digit = 0;
	carry = 0;
	int j = num2.size() - 1;

	for (int i = size - 1; i >= 0; i--) {
		if (j >= 0) {
			diff = num1[i] - num2[j] - carry;
//			cout << num1[i] << " - " << num2[j] << " - " << carry << " = "
//					<< diff << endl;
			if (diff < 0) {
				digit = 10 + diff;
				carry = 1;
			} else {
				digit = diff;
				carry = 0;
			}
			result.insert(0, 1, digitChar[digit]);
			j--;
		} else {
			diff = num1[i] - carry;
//			cout << num1[i] << " - " << carry << " = " << diff << endl;
			if (diff < 0) {
				digit = 10 + diff;
				carry = 1;
			} else {
				digit = diff;
				carry = 0;
			}
//			cout << "digit: " << digit << endl;
			result.insert(0, 1, digitChar[digit]);
//			cout << "Result = " << result << endl;
		}
	}
	removeBeginZeros(result);
//	cout << "\nSubtract if NOT equal size - Leave" << endl;
}

void BigInteger::removeBeginZeros(string& result) {
	int size = result.length();
	int lengthOfZeroes = 0;
	if (result.at(0) == '0') {
		lengthOfZeroes = 1;
		for (int i = 1; i < size; i++) {
			if (result.at(i) == digitChar[0]) {
				lengthOfZeroes++;
			} else {
				break;
			}
		}
		result.erase(0, lengthOfZeroes);
	}
//	cout << "After removing zeroes!\n" << result << endl;
}
//Comparison
bool BigInteger::isEqualTo(const BigInteger& numArg) const {
	int size1 = this->numberArr.size();
	int size2 = numArg.getNumberArr().size();
	bool flag = true;
	if (size1 != size2) {
		flag = false;
	} else {
		for (int i = 0; i < size1; i++) {
			if (this->getNumberArr()[i] != numArg.getNumberArr()[i]) {
				flag = false;
				break;
			}
		}
	}

	return flag;
}

bool BigInteger::isNotEqualTo(const BigInteger& numArg) const {
	return !this->isEqualTo(numArg);

}
bool BigInteger::isGreaterThan(const BigInteger& numArg) const {
	cout << endl;
//	cout << "Entering isGreaterThan" << endl;
	int size1 = this->getNumberArr().size();
	int size2 = numArg.getNumberArr().size();

//	cout << "num1 = ";
//	this->output();
//	cout << "num2 = ";
//	numArg.output();

	bool flag = true;
	if (size1 == size2 && !this->isEqualTo(numArg)) {
		for (int i = 0; i < size1; i++) {
			if (this->getNumberArr()[i] > numArg.getNumberArr()[i]) {
//				cout << "index = " << i << endl;
//				cout << "comparing " << this->getNumberArr()[i] << " with "
//						<< numArg.getNumberArr()[i] << endl;
				flag = true;
				break;
			} else if (this->getNumberArr()[i] == numArg.getNumberArr()[i]) {

			} else {
//				cout << "index = " << i << endl;
//				cout << "comparing " << this->getNumberArr()[i] << " with "
//						<< numArg.getNumberArr()[i] << endl;
				flag = false;
				break;
			}
		}
	} else {
		flag = (size1 > size2) ? true : false;
	}
//	cout << "Leaving isGreaterThan" << endl;
	cout << endl;
	return flag;

}

void BigInteger::multiply1AtATime(const vector<int>& num, int multiplyer,
		int powerOf10, string& currentProduct) {
	int product = 1;
	carry = 0;
	int digit = 0;
	if(powerOf10 > 0){
		for(int i = 0; i < powerOf10; i++){
			currentProduct.insert(0, "0");
		}
	}
	for(unsigned int i = num.size() - 1; i >= 0; i--){
		if(i > 0){
			product = multiplyer * num[i];
				digit = (product % 10) + carry;
				carry = product / 10;
				currentProduct.insert(0, 1, digitChar[digit]);
		} else {
			product = multiplyer * num[i];
				digit = (product % 10) + carry;
				carry = product / 10;
				currentProduct.insert(0, 1, digitChar[digit]);
				currentProduct.insert(0, 1, carry);
		}
	}
}

string BigInteger::multiply(const BigInteger&) {

	for(unsigned int i = 0; i < this->getNumberArr().size(); i++){

	}
}

bool BigInteger::isLessThan(const BigInteger& numArg) const {
	bool flag = true;
	if (this->isGreaterThan(numArg) || this->isEqualTo(numArg)) {
		flag = false;
	}
	return flag;
}


//Overloaded operators

BigInteger BigInteger::operator +(const BigInteger& num2) {
	BigInteger result = this->add(num2);
	return result;
}
BigInteger BigInteger::operator -(const BigInteger& num2) {
	BigInteger result = this->subtract(num2);
	return result;
}
