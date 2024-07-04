//
//  Complex.h
//  laboratory3
//
//  Created by Илья Атмажитов on 19.06.2024.
//

#ifndef Complex_h
#define Complex_h

#include <iostream>

class Complex {
public:
    double real, imag;

    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        os << c.real << (c.imag >= 0 ? "+" : "-") << std::abs(c.imag) << "i";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Complex& c) {
        is >> c.real >> c.imag;
        return is;
    }

    // Сложение комплексных чисел
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    double abs() const {
        return sqrt(real * real + imag * imag);
    }

    Complex conjugate() const {
        return Complex(real, -imag);
    }

    // Умножение на скаляр
    Complex operator*(double scalar) const {
        return Complex(real * scalar, imag * scalar);
    }

    Complex operator*(const Complex & other) const {
        return Complex(real*other.real-imag*other.imag, imag*other.real+real*other.imag);
    }

    Complex operator += (const Complex & other) {
        *this = *this + other;
        return *this;
    }



};

inline Complex sqrt(const Complex& z) {
    double r = std::sqrt(z.abs());
    double theta = std::atan2(z.imag, z.real) / 2;
    return Complex(r * std::cos(theta), r * std::sin(theta));
}

inline double abs(const Complex& c) {
    return c.abs();
}


#endif /* Complex_h */
