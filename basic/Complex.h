class Complex
{
  public:
    double re, im;
    Complex(double r, double i);
    Complex(double r);
    Complex(void);

    friend Complex operator+(Complex, Complex);
    friend Complex operator-(Complex, Complex);
    friend Complex operator*(Complex, Complex);
    friend Complex operator/(Complex, Complex);
    friend Complex operator-(Complex);
    friend Complex operator==(Complex, Complex);
    friend Complex operator!=(Complex, Complex);
};

Complex::Complex(double r, double i)
{
    re = r;
    im = i;
}

Complex::Complex(double r)
{
    re = r;
    im = 0;
}

Complex::Complex(void)
{
    re = im = 0;
}

Complex operator+(Complex a1, Complex a2)
{
    return Complex(a1.re + a2.re, a1.im + a2.im);
}