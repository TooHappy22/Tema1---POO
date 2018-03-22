#include <bits/stdc++.h>
#include "PairPolynomialInternal.h"
using namespace std;

template< class T >
PairPolynomial< T >::PairPolynomial() {
	this->root = 0;
	Polynomial< T > other;
	this->polynom = other;
}
 
template< class T >
PairPolynomial< T >::PairPolynomial(const T& root, const Polynomial< T >& other) {
	this->root = root;
	this->polynom = other;
}

template< class T >
bool PairPolynomial< T >::IsRootForPolynom() const {
	if(this->polynom.evaluate(this->root) == 0) {
		return 1;
	} else {
		return 0;
	}
}

template< class T >
Polynomial< T > PairPolynomial< T >::GetPolynom() {
	return this->polynom;
}

template< class T >
T PairPolynomial< T >::GetRoot() {
	return this->root;
}

template< class T >
istream& operator>>(istream& in, PairPolynomial< T >& other) {
	in >> other.root;
	in >> other.polynom;

	return in;
}

template< class T >
ostream& operator<<(ostream& out, PairPolynomial< T >& other) {
	if(other.IsRootForPolynom()) {
		out << "DA!";
	} else {
		out << "NU!";
	}

	return out;
}