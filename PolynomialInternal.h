#ifndef __POLYNOMIALINTERNAL_H_INCLUDED__
#define	__POLYNOMIALINTERNAL_H_INCLUDED__
#include <bits/stdc++.h>

template< class T > class PairPolynomial;

template< class T >
class Polynomial {
	private:
		int degreePolynom;
		T* coeff;
	public:
		Polynomial();
		Polynomial(int);
		Polynomial(int, T*);
		Polynomial(const Polynomial< T >&);
		~Polynomial();
		void Clear();
		int GetDegree();
		bool IsNullPolynom() const;
		T evaluate(const T&) const;
		T operator[](const int) const;
		Polynomial< T >& operator=(const Polynomial< T >&);
		bool operator==(const Polynomial< T >&) const;
		bool operator!=(const Polynomial< T >&) const;
		bool operator<(const Polynomial< T >&) const;
		bool operator<=(const Polynomial< T >&) const;
		bool operator>=(const Polynomial< T >&) const;
		bool operator>(const Polynomial< T >&) const;
		Polynomial< T > operator+(const Polynomial< T >&) const;
		Polynomial< T > operator-(const Polynomial< T >&) const;
		Polynomial< T > operator-() const;
		Polynomial< T > operator*(const Polynomial< T >&) const;
		Polynomial< T > operator/(const Polynomial< T >&) const;
		Polynomial< T > operator%(const Polynomial< T >&) const;
		template< class U > friend std::istream& operator>>(std::istream&, Polynomial< U >&);
		template< class U > friend std::ostream& operator<<(std::ostream&, Polynomial< U >&);
};

#endif