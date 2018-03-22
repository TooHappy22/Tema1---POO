#ifndef __PAIRPOLYNOMIALINTERNAL_H_INCLUDED__
#define	__PAIRPOLYNOMIALINTERNAL_H_INCLUDED__
#include "PolynomialInternal.h"
#include <bits/stdc++.h>

template< class T > class Polynomial;

template< class T >
class PairPolynomial {
	private:
		T root;
		Polynomial< T > polynom;
	public:
		PairPolynomial();
		PairPolynomial(const T&, const Polynomial< T >&);
		bool IsRootForPolynom() const;
		Polynomial< T > GetPolynom();
		T GetRoot();
		template< class U > friend std::istream& operator>>(std::istream&, PairPolynomial< U >&);
		template< class U > friend std::ostream& operator<<(std::ostream&, PairPolynomial< U >&);

		friend class Polynomial< T >;
};

#endif