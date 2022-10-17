//
// Created by Oreofe Solarin on 10/7/22.
//

#ifndef HW3_SIMPLEPOLYNOMIAL_HPP
#define HW3_SIMPLEPOLYNOMIAL_HPP
class Polynomial
{
private:
    int Nterms;
    double* pCoeffs;// from lowest to highest order
public:
    // functions
    double evaluateAt(double x);
    void print(void);
    int coeff(int coeff);
    int degree();
    void change_cooeff(int newcoeff, int degree);
    Polynomial operator + (Polynomial & p);

    // constructor
    Polynomial( double Coeffs[], int N_terms );// full construction from given array of coefficients
    // destructor
    ~Polynomial();// destructor VERY important this case
};

// full constructor. Must be passed an array of coeffs. and the array size.
Polynomial::Polynomial( double Coeffs[], int N_terms )
{
    Nterms = N_terms;
    pCoeffs = new double[ Nterms ];// allocate an array to hold the coefficient values
    for(int i=0; i<Nterms; i++)
        pCoeffs[i] = Coeffs[i];// assign in straight order
}

// destructor - releases memory for the dynamically allocated coefficient array
Polynomial::~Polynomial()
{
    if( pCoeffs )
    {
        delete [] pCoeffs;
        pCoeffs = NULL;
    }
}
// finds P(x)
double Polynomial::evaluateAt(double x)
{
    double sum = 0.0;
    double xPow = 1.0;
    if( pCoeffs )
        for(int i=0; i<Nterms; i++)
        {
            sum += xPow*pCoeffs[i];// add up the terms
            xPow *= x;// build up the power of x from term to term
        }

    return sum;
}
// simple version produces crude output. Finetune to suit.
void Polynomial::print(void)
{
    // 1st term
    std::cout << pCoeffs[Nterms-1] << "x^" << Nterms-1;
    // remaining terms
    for(int i=Nterms-2; i>=0; i--)
        std::cout << " + " << pCoeffs[i] << "x^" << i;
    std::cout << std::endl;
    return;
}

int Polynomial::coeff(int coeff) {
    std::cout << "Coefficient of the term: " << pCoeffs[coeff] << std::endl;
    return pCoeffs[coeff];
}

int Polynomial::degree() {
    std::cout << "Highest Degree: " <<  Nterms-1 << std::endl;
    return Nterms - 1;

}

void Polynomial::change_cooeff(int newcoeff, int degree) {
    pCoeffs[degree] = newcoeff;
    print();
}

Polynomial Polynomial::operator+(Polynomial &p) {
    int number = p.Nterms < Nterms ? p.Nterms + 1 : Nterms + 1;
//    std::cout
    for (int i = 0; i < number; ++i) {
        pCoeffs[i] = pCoeffs[i] + p.pCoeffs[i];
    }

    return {pCoeffs, number};
}


#endif //HW3_SIMPLEPOLYNOMIAL_HPP
