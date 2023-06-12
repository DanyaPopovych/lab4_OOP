#include "Header.h"
int CFixedPointNumber::counter;

CFixedPointNumber::CFixedPointNumber() {
	intN = 0;
	drobN = 0;
}

CFixedPointNumber::CFixedPointNumber(int numberA, int numberB) {
	intN = numberA;
	drobN = numberB;
	counter++;
}


void CFixedPointNumber::setInt(int integer) {
	intN = integer;
}

int CFixedPointNumber::getInt()const {
	return intN;
}
int CFixedPointNumber::getDouble()const {
	return drobN;
}
int CFixedPointNumber::getCounter() {
	return counter;
}
void CFixedPointNumber::setDouble(float number) {
	intN = (int)(number);
	drobN = (int)((number - intN) * 100);
}
float CFixedPointNumber::getDoubleOfNumber()const {
	double intN1 = (double)(intN);
	double drobN1 = (double)(drobN);
	return (intN1 + drobN1 / 100);
}
CFixedPointNumber CFixedPointNumber::addiction(const CFixedPointNumber& another)const {
	int intNumber = intN + another.intN;
	int drobNumber = drobN + another.drobN;
	if (drobNumber >= 100) {
		intNumber++;
		drobNumber -= 100;
	}
	return CFixedPointNumber(intNumber, drobNumber);
}
CFixedPointNumber CFixedPointNumber::substraction(const CFixedPointNumber& another)const {
	int intNumber = intN - another.intN;
	int drobNumber = drobN - another.drobN;
	if (drobNumber < 100) {
		intNumber--;
		drobNumber += 100;
	}
	return CFixedPointNumber(intNumber, drobNumber);
}

CFixedPointNumber CFixedPointNumber::muptiplying(const CFixedPointNumber& another)const {
	int intNumber;
	int drobNumber;
	if (drobN == 0 && another.drobN == 0) {
		drobNumber = 0;
		intNumber = intN * another.intN;

	}
	else if (drobN == 0) {
		intNumber = (intN * another.intN) + (drobN * another.drobN) / 100;
		drobNumber = (intN * another.drobN);
		if (drobNumber >= 100) {
			intNumber++;
			drobNumber -= 100;
		}
	}
	else if (another.drobN == 0) {
		intNumber = (intN * another.intN) + (drobN * another.drobN) / 100;
		drobNumber = (another.intN * drobN);
		if (drobNumber >= 100) {
			intNumber++;
			drobNumber -= 100;
		}
	}
	else if (drobN != 0 && another.drobN != 0) {
		drobNumber = ((another.drobN * drobN) / 100) + (another.drobN * intN) + (another.intN * drobN);

		intNumber = intN * another.intN;
		if (drobNumber >= 100) {
			intNumber++;
			drobNumber -= 100;
		}
	}
	return CFixedPointNumber(intNumber, drobNumber);
}

CFixedPointNumber CFixedPointNumber::dividing(const CFixedPointNumber& another)const {
	int totalFractionalPart = intN * 100 + drobN;
	int anotherTotalFractionalPart = another.intN * 100 + another.drobN;
	int intNumber = totalFractionalPart / anotherTotalFractionalPart;
	int drobNumber = ((totalFractionalPart % anotherTotalFractionalPart) * 100) / anotherTotalFractionalPart;
	return CFixedPointNumber(intNumber, drobNumber);
}
CFixedPointNumber CFixedPointNumber::operator+(const CFixedPointNumber& another)const {
	int intNumber = intN + another.intN;
	int drobNumber = drobN + another.drobN;
	if (drobNumber >= 100) {
		intNumber++;
		drobNumber -= 100;
	}
	return CFixedPointNumber(intNumber, drobNumber);
	
}
CFixedPointNumber CFixedPointNumber::operator-(const CFixedPointNumber& another)const {
	int intNumber = intN - another.intN;
	int drobNumber = drobN - another.drobN;
	if (drobNumber < 100) {
		intNumber--;
		drobNumber += 100;
	}
	return CFixedPointNumber(intNumber, drobNumber);
}
CFixedPointNumber CFixedPointNumber::operator*(const CFixedPointNumber& another)const {
	int intNumber;
	int drobNumber;
	if (drobN == 0 && another.drobN == 0) {
		drobNumber = 0;
		intNumber = intN * another.intN;

	}
	else if (drobN == 0) {
		intNumber = (intN * another.intN) + (drobN * another.drobN) / 100;
		drobNumber = (intN * another.drobN);
		if (drobNumber >= 100) {
			intNumber++;
			drobNumber -= 100;
		}
	}
	else if (another.drobN == 0) {
		intNumber = (intN * another.intN) + (drobN * another.drobN) / 100;
		drobNumber = (another.intN * drobN);
		if (drobNumber >= 100) {
			intNumber++;
			drobNumber -= 100;
		}
	}
	else if (drobN != 0 && another.drobN != 0) {
		drobNumber = ((another.drobN * drobN) / 100) + (another.drobN * intN) + (another.intN * drobN);

		intNumber = intN * another.intN;
		if (drobNumber >= 100) {
			intNumber++;
			drobNumber -= 100;
		}
	}
	return CFixedPointNumber(intNumber, drobNumber);
}
CFixedPointNumber CFixedPointNumber::operator/(const CFixedPointNumber& another)const {
	int totalFractionalPart = intN * 100 + drobN;
	int anotherTotalFractionalPart = another.intN * 100 + another.drobN;
	int intNumber = totalFractionalPart / anotherTotalFractionalPart;
	int drobNumber = ((totalFractionalPart % anotherTotalFractionalPart) * 100) / anotherTotalFractionalPart;
	return CFixedPointNumber(intNumber, drobNumber);
}
CFixedPointNumber::operator double()const {
	double intN1 = (double)(intN);
	double drobN1 = (double)(drobN);
	return (intN1 + drobN1 / 100);
}
bool operator>(CFixedPointNumber& number, CFixedPointNumber& another) {
	double number1 = (double)(number.intN) + (double)(number.drobN) / 100;
	double number2 = (double)(another.intN) + (double)(another.drobN) / 100;
	if (number1 > number2) {
		return true;
	}
	else {
		return false;
	}

}
bool operator<(CFixedPointNumber& number, CFixedPointNumber& another) {
	double number1 = (double)(number.intN) + (double)(number.drobN) / 100;
	double number2 = (double)(another.intN) + (double)(another.drobN) / 100;
	if (number1 < number2) {
		return true;
	}
	else {
		return false;
	}

}
bool operator==(CFixedPointNumber& number, CFixedPointNumber& another) {
	double number1 = (double)(number.intN) + (double)(number.drobN) / 100;
	double number2 = (double)(another.intN) + (double)(another.drobN) / 100;
	if (number1 == number2) {
		return true;
	}
	else {
		return false;
	}

}
istream& operator>> (istream& input, CFixedPointNumber number) {
	input >> number.intN >> number.drobN;
	return input;
}
ostream& operator<< (ostream& output,const CFixedPointNumber number) {
	output << number.getDoubleOfNumber();
	return output;
}

