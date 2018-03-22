#include <bits/stdc++.h>
#include "Polynomial.h"
#include "PairPolynomial.h"

using namespace std;

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	Polynomial< double > p1, p2;
	cin >> p1;
	cout << "Primul polinom:\n"; cout << p1 << endl;
	
	cin >> p2;
	cout << "Al doilea polinom:\n"; cout << p2 << endl;

	try {
		if(p1 == p1 / p2 * p2 + p1 % p2) {
			cout << "YES\n";
		}
	} catch (int x) {
		cerr << "Eroare! Impartire la polinomul nul!\n";
	}

	Polynomial< double > p10;
	p10 = -p2;

	cout << "Opusul celui de al doilea polinom este: \n";
	cout << p10 << endl;

	Polynomial< double > p3(p2);
	cout << "O copie a celui de al doilea polinom:\n"; cout << p3 << endl;

	cout << "Coeficientul termenului de grad 2 al primului polinom:\n"; cout << p1[2] << '\n';

	cout << "Evaluarea celui de al doilea polinom in valoarea 2:\n"; cout << p2.evaluate(2) << '\n';

	Polynomial< double > p4;
	p4 = p1 + p2;
	cout << "Suma celor doua polinoame:\n"; cout << p4 << endl;

	Polynomial< double > p5;
	p5 = p1 - p2;
	cout << "Diferenta celor doua polinoame:\n"; cout << p5 << endl;

	Polynomial< double > p6 = p1 * p2;
	cout << "Produsul celor doua polinoame:\n"; cout << p6 << endl;

	Polynomial< double > p7;
	try {
		p7 = p1 / p2;
		cout << "Catul celor doua polinoame:\n"; cout << p7 << endl;
	} catch (int x) {
		cerr << "Eroare! Impartire la polinomul nul!\n";
	}

	Polynomial< double > p8;
	try {
		p8 = p1 % p2;
		cout << "Restul celor doua polinoame:\n"; cout << p8 << endl;
	} catch (int x) {
		cerr << "Eroare! Impartire la polinomul nul!\n";
	}

	PairPolynomial< double > R;
	
	cin >> R;
	Polynomial< double > aux; aux = R.GetPolynom();
	cout << "Este " << R.GetRoot() << " radacina a polinomului: "; cout << aux << " ?\n";
	cout << R << '\n';

	return 0;
}