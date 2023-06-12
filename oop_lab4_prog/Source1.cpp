#include "Header.h"

int main() {
	CFixedPointNumber a(1, 50);
	CFixedPointNumber b(1, 32);

	CFixedPointNumber sumOverride = a + b;
	CFixedPointNumber substractOverride = a - b;
	CFixedPointNumber multiplyOverride = a * b;
	CFixedPointNumber divisionOverride = a / b;

	CFixedPointNumber sumOperator = a.addiction(b);
	CFixedPointNumber substractOperator = a.substraction(b);
	CFixedPointNumber multiplyOperator = a.muptiplying(b);
	CFixedPointNumber divisionOperator = a.dividing(b);

	std::cout << "a = " << a.getDoubleOfNumber() << std::endl;
	std::cout << "b = " << b.getDoubleOfNumber() << std::endl;
	std::cout << "sumOverride = " << sumOverride.getDoubleOfNumber() << std::endl;
	std::cout << "substractOverride = " << substractOverride.getDoubleOfNumber() << std::endl;
	std::cout << "multiplyOverride = " << multiplyOverride.getDoubleOfNumber() << std::endl;
	std::cout << "divisionOverride = " << divisionOverride.getDoubleOfNumber() << std::endl;
	std::cout << std::endl;

	std::cout << "a = " << a.getDoubleOfNumber() << std::endl;
	std::cout << "b = " << b.getDoubleOfNumber() << std::endl;
	std::cout << "sumOperator = " << sumOperator.getDoubleOfNumber() << std::endl;
	std::cout << "substractOperator = " << substractOperator.getDoubleOfNumber() << std::endl;
	std::cout << "multiplyOperator = " << multiplyOperator.getDoubleOfNumber() << std::endl;
	std::cout << "divisionOperator = " << divisionOperator.getDoubleOfNumber() << std::endl;
	std::cout << std::endl;
	if (a > b) {
		std::cout << a << " > " << b;
	}
	else if (a < b) {
		std::cout << a << " < " << b;
	}
	else if (a == b) {
		std::cout << a << " = " << b;
	}
	std::cout << std::endl;
	std::cout << "Count of objects: " << a.getCounter() << std::endl;


}