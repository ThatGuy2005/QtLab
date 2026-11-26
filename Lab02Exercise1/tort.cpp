#include "tort.h"
#include "integerfunctions.h"

Tort::Tort() : numerator(0), denominator(1) {}

Tort::Tort(int _numerator) : numerator(_numerator), denominator(1){}

Tort::Tort(int _numerator, int _denominator)
{
    if(_denominator == 0)
        throw "Division by zero!";

    numerator = _numerator;
    denominator = _denominator;
}

Tort::Tort(const Tort& other) : Tort(other.numerator, other.denominator) {}

Tort& Tort::operator+(const Tort& rhs)
{
    if(rhs.denominator == this->denominator)
    {
        this->numerator += rhs.numerator;
        return *this;
    }

    int tempDenominatorLHS = this->denominator;
    int tempNumeratorRHS = rhs.numerator;
    this->denominator *= rhs.denominator;
    this->numerator *= rhs.denominator;

    this->numerator += (tempDenominatorLHS*tempNumeratorRHS);
    this->egyszerusites();

    return *this;
}

Tort& Tort::operator-(const Tort& rhs)
{
    if(rhs.denominator == this->denominator)
    {
        this->numerator -= rhs.numerator;
        return *this;
    }

    int tempDenominatorLHS = this->denominator;
    int tempNumeratorRHS = rhs.numerator;
    this->denominator *= rhs.denominator;
    this->numerator *= rhs.denominator;

    this->numerator -= (tempDenominatorLHS*tempNumeratorRHS);
    this->egyszerusites();

    return *this;
}

Tort& Tort::operator*(const Tort& rhs)
{
    this->denominator *= rhs.denominator;
    this->numerator *= rhs.numerator;
    this->egyszerusites();
    return *this;
}

Tort& Tort::operator/(const Tort& rhs)
{
    this->denominator /= rhs.denominator;
    this->numerator /= rhs.numerator;
    this->egyszerusites();
    return *this;
}

int Tort::lnko(int lhs, int rhs)
{
    return MyFunctions::lnko(lhs,rhs);
}

Tort& Tort::egyszerusites()
{
    int div = MyFunctions::lkkt(this->numerator,this->denominator);
    this->numerator /= div;
    this->denominator /= div;

    return *this;
}

Tort& Tort::forditott()
{
    this->numerator += this->denominator;
    this->denominator = this->numerator - this->denominator;
    this->numerator = this->numerator - this->denominator;

    return *this;
}

int Tort::lkkt(int lhs, int rhs)
{
    return MyFunctions::lkkt(lhs,rhs);
}

bool Tort::Tortegyenlo(const Tort& rhs)
{
    return ((this->numerator * rhs.denominator) == (this->denominator * rhs.numerator));
}

void Tort::print()
{
    std::cout << this->numerator << "/" << this->denominator;
}

std::ostream& operator<<(std::ostream& os, const Tort& quotient)
{
    os << quotient.numerator << "/" << quotient.denominator;
    return os;
}