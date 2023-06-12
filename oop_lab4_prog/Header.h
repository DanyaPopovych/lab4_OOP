#include <iostream>
using namespace std;
class CFixedPointNumber
{
private:
    int intN;
    int drobN;
    static int counter;
public:
    CFixedPointNumber();
    CFixedPointNumber(int numberA, int numberB);
    void setInt(int intN);
    int getInt()const;
    int getDouble()const;
    void setDouble(float number);
    float getDoubleOfNumber()const;
    static int getCounter();
    CFixedPointNumber addiction(const CFixedPointNumber& another)const;
    CFixedPointNumber substraction(const CFixedPointNumber& another)const;
    CFixedPointNumber dividing(const CFixedPointNumber& another)const;
    CFixedPointNumber muptiplying(const CFixedPointNumber& another)const;


    CFixedPointNumber operator+(const CFixedPointNumber& another)const;
    CFixedPointNumber operator-(const CFixedPointNumber& another)const;
    CFixedPointNumber operator*(const CFixedPointNumber& another)const;
    CFixedPointNumber operator/(const CFixedPointNumber& another)const;
    operator double()const;

    friend istream& operator>> (istream& input,  CFixedPointNumber number);
    friend ostream& operator<< (ostream& output, const CFixedPointNumber number);
    friend bool operator>( CFixedPointNumber& number,  CFixedPointNumber& another);
    friend bool operator<(CFixedPointNumber& number, CFixedPointNumber& another);
    friend bool operator==( CFixedPointNumber& number, CFixedPointNumber& another);

};