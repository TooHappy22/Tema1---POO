#include <bits/stdc++.h>
#include "PolynomialInternal.h"

using namespace std;

template< class T >
Polynomial< T >::Polynomial() {
	this->degreePolynom = 0;
	this->coeff = new T[degreePolynom + 1];
	this->coeff[0] = 0.0;
}

template< class T >
Polynomial< T >::Polynomial(int degree) {
	this->degreePolynom = degree;

	this->coeff = new T[degree + 1];
	for(int i = 0; i < degree + 1; ++i) {
		this->coeff[i] = 0.0;
	}
}

template< class T >
Polynomial< T >::Polynomial(int degree, T coefficients[]) {
	this->degreePolynom = degree;
	this->coeff = new T[degree + 1];
		
	for(int i = 0; i < degree + 1; ++i) {
		this->coeff[i] = coefficients[i];
	}
}

template< class T >
Polynomial< T >::Polynomial(const Polynomial< T >& other) {
	this->degreePolynom = other.degreePolynom;

	this->coeff = new T[other.degreePolynom + 1];
	for(int i = 0; i < other.degreePolynom + 1; ++i) {
		this->coeff[i] = other.coeff[i];
	}
}

template< class T >
Polynomial< T >::~Polynomial() {
	this->Clear();
}

template< class T >
void Polynomial< T >::Clear() {
	this->degreePolynom = 0;
	delete[] this->coeff;
}

template< class T >
int Polynomial< T >::GetDegree() {
	int degree = 0;

	for(int i = 0; i < this->degreePolynom + 1; ++i) {
		if(this->coeff[i]) {
			degree = i;
		}
	}

	return degree;
}

template< class T >
bool Polynomial< T >::IsNullPolynom() const {
	for(int i = 0; i < this->degreePolynom + 1; ++i) {
		if(this->coeff[i] != 0.0) {
			return 0;
		}
	}

	return 1;
}

template< class T >
T Polynomial< T >::evaluate(const T& x) const {
	T sum = this->coeff[0];

	for(int i = 1; i < this->degreePolynom + 1; ++i) {
		sum += (pow(x, i) * this->coeff[i]);
	}

	return sum;
}

template< class T >
T& Polynomial< T >::operator[](int index) {
	return this->coeff[index];
}

template< class T >
Polynomial< T >& Polynomial< T >::operator=(const Polynomial< T >& other) {
	if(this == &other) {
		return *this;
	}

	this->Clear();

	this->degreePolynom = other.degreePolynom;
	this->coeff = new T[degreePolynom + 1];

	for(int i = 0; i < degreePolynom + 1; ++i) {
		this->coeff[i] = other.coeff[i];
	}

	return *this;
}

template< class T >
bool Polynomial< T >::operator==(const Polynomial< T >& other) const {
	if(this->degreePolynom == other.degreePolynom) {
		for(int i = 0; i < this->degreePolynom + 1; ++i) {
			if(this->coeff[i] != other.coeff[i]) {
				return false;
			}
		}

		return true;
	}

	return false;
}

template< class T >
bool Polynomial< T >::operator!=(const Polynomial< T >& other) const {
	if(*this == other) {
		return false;
	}
	return true;
}

template< class T >
bool Polynomial< T >::operator<(const Polynomial< T >& other) const {
	if(this->degreePolynom < other.degreePolynom) {
		return true;
	}
	if(this->degreePolynom > other.degreePolynom) {
		return false;
	}

	for(int i = this->degreePolynom; i >= 0; --i) {
		if(this->coeff[i] < other.coeff[i]) {
			return true;
		}
		if(this->coeff[i] > other.coeff[i]) {
			return false;
		}
	}

	return false;
}

template< class T >
bool Polynomial< T >::operator<=(const Polynomial< T >& other) const {
	if(*this == other || *this < other) {
		return true;
	}
	return false;
}

template< class T >
bool Polynomial< T >::operator>(const Polynomial< T >& other) const {
	if(this->degreePolynom > other.degreePolynom) {
		return true;
	}
	if(this->degreePolynom < other.degreePolynom) {
		return false;
	}

	for(int i = this->degreePolynom; i >= 0; --i) {
		if(this->coeff[i] > other.coeff[i]) {
			return true;
		}
		if(this->coeff[i] < other.coeff[i]) {
			return false;
		}
	}

	return false;
}

template< class T >
bool Polynomial< T >::operator>=(const Polynomial< T >& other) const {
	if(*this == other || *this > other) {
		return true;
	}
	return false;
}

template< class T >
Polynomial< T > Polynomial< T >::operator+(const Polynomial< T >& other) const {
	Polynomial< T > result(max(this->degreePolynom, other.degreePolynom));

	for(int i = 0; i < result.degreePolynom + 1; ++i) {
		if(i < this->degreePolynom + 1)
			result.coeff[i] += this->coeff[i];
		if(i < other.degreePolynom + 1)
			result.coeff[i] += other.coeff[i];
	}
	result.degreePolynom = result.GetDegree();

	return result;
}

template< class T >
Polynomial< T > Polynomial< T >::operator-(const Polynomial< T >& other) const {
	Polynomial< T > result;
	if(this->degreePolynom >= other.degreePolynom) {
		result = *this;
	} else {
		result = -other;
	}

	for(int i = 0; i < min(other.degreePolynom + 1, this->degreePolynom + 1); ++i) {
		result.coeff[i] = (this->coeff[i] - other.coeff[i]);
	}
	result.degreePolynom = result.GetDegree();

	return result;
}

template< class T >
Polynomial< T > Polynomial< T >::operator-() const {
	Polynomial< T > result(*this);

	for(int i = 0; i < this->degreePolynom + 1; ++i) {
		result.coeff[i] = -this->coeff[i];
	}

	return result;
}

template< class T >
Polynomial< T > Polynomial< T >::operator*(const Polynomial< T >& other) const {
	Polynomial< T > result(this->degreePolynom + other.degreePolynom);

	for(int i = 0; i < this->degreePolynom + 1; ++i) {
		for(int j = 0; j < other.degreePolynom + 1; ++j) {
			result.coeff[i + j] += this->coeff[i] * other.coeff[j];
		}
	}

	result.degreePolynom = result.GetDegree();

	return result;
}

template< class T >
Polynomial< T > Polynomial< T >::operator/(const Polynomial< T >& other) const {	
	if(this->degreePolynom < other.degreePolynom) {
		Polynomial< T > result;
		return result;
	}
	if(other.IsNullPolynom()) {
		throw 1;
	}

	Polynomial< T > result(this->degreePolynom - other.degreePolynom);
	Polynomial< T > temp(*this);

	while(temp.degreePolynom >= other.degreePolynom) {
		result.coeff[temp.degreePolynom - other.degreePolynom] = temp.coeff[temp.degreePolynom] / other.coeff[other.degreePolynom];
		Polynomial< T > aux(temp.degreePolynom);

		for(int i = 0; i < other.degreePolynom + 1; ++i) {
			aux.coeff[temp.degreePolynom - other.degreePolynom + i] = result.coeff[temp.degreePolynom - other.degreePolynom] * other.coeff[i];
		}

		temp = temp - aux;
	}

	return result;
}

template< class T >
Polynomial< T > Polynomial< T >::operator%(const Polynomial< T >& other) const {
	if(other.IsNullPolynom()) {
		throw 1;
	}

	Polynomial< T > reminder = (*this - (*this / other) * other);
 
	return reminder;
}

template< class T >
istream& operator>>(istream& in, Polynomial< T >& other) {
	other.Clear();

	in >> other.degreePolynom;

	other.coeff = new T[other.degreePolynom + 1];

	for(int i = 0; i < other.degreePolynom + 1; ++i) {
		in >> other.coeff[i];
	}

	return in;
}

template< class T >
ostream& operator<<(ostream& out, Polynomial< T >& other) {
	out << other.coeff[other.degreePolynom] << "*X^" << other.degreePolynom;
	for(int i = other.degreePolynom - 1; i >= 0; --i) {
		if(other.coeff[i] >= 0) {
			out << " + ";
		} else {
			out << " - ";
		}
		out << abs(other.coeff[i]) << "*X^" << i;
	}

	return out;
}