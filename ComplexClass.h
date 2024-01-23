#pragma once

#include <cmath>
#include <iostream>
#include <type_traits>
#include <stdexcept>
#include <sstream>


template <typename T> class Complex {
public:
    Complex(T real, T imag) : real(real), imag(imag) {
        static_assert(std::is_arithmetic<T>::value, "Template type must be numeric");
    }

    T getReal() const { return real; }
    void setReal(T real) { this->real = real; }

    T getImag() const { return imag; }
    void setImag(T imag) { this->imag = imag; }

    Complex<T> operator+(const Complex<T>& other) const {
        return Complex<T>(real + other.real, imag + other.imag);
    }

    Complex<T> operator-(const Complex<T>& other) const {
        return Complex<T>(real - other.real, imag - other.imag);
    }

    Complex<T> operator*(const Complex<T>& other) const {
        return Complex<T>(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    Complex<T> operator/(const Complex<T>& other) const {
        T denominator = other.real * other.real + other.imag * other.imag;
        return Complex<T>((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }


    Complex<T> operator^(T exponent) {
        T r = std::pow(getMod(), exponent);
        T arg = std::atan2(getImag(), getReal());
        T newReal = r * std::cos(exponent * arg);
        T newImag = r * std::sin(exponent * arg);
        return Complex<T>(newReal, newImag);
    }

    friend Complex<T> operator""_i(const char* literal) {
        T real, imag;
        char plusOrMinus;

        std::stringstream ss(literal);
        ss >> real >> plusOrMinus >> imag;

        if (plusOrMinus == '+') {
            return Complex<T>(real, imag);
        } else if (plusOrMinus == '-') {
            return Complex<T>(real, -imag);
        } else {
            throw std::invalid_argument("Invalid format for imaginary part in complex literal");
    }

    T getMod() const { return std::sqrt(real * real + imag * imag); }

    void print() const {
        std::cout << "(" << real << " + " << imag << "i)" << std::endl;
    }

private:
    T real;
    T imag;
};

template <typename T> bool operator<(const Complex<T>& a, const Complex<T>& b) {
    return a.getMod() < b.getMod();
}

template <typename T> bool operator>(const Complex<T>& a, const Complex<T>& b) {
    return a.getMod() > b.getMod();
}

template <typename T>
bool operator<=(const Complex<T>& a, const Complex<T>& b) {
    return a.getMod() <= b.getMod();
}

template <typename T>
bool operator>=(const Complex<T>& a, const Complex<T>& b) {
    return a.getMod() >= b.getMod();
}

template <typename T>
bool operator==(const Complex<T>& a, const Complex<T>& b) {
    return (a.getReal() == b.getReal()) && (a.getImag() == b.getImag());
}

template <typename T>
bool operator!=(const Complex<T>& a, const Complex<T>& b) {
    return !(a == b);
}

template <typename T> bool operator<(const Complex<T>& a, const T& num) {
    return a.getMod() < num;
}

template <typename T> bool operator>(const Complex<T>& a, const T& num) {
    return a.getMod() > num;
}

template <typename T> bool operator<= (const Complex<T>& a, const T& num) {
    return a.getMod() <= num;
}

template <typename T> bool operator>=(const Complex<T>& a, const T& num) {
    return a.getMod() >= num;
}

template <typename T>
bool operator==(const Complex<T>& a, const int& num) {
    return (a.getReal() == num) && (a.getImag() == 0);
}

template <typename T>
bool operator!=(const Complex<T>& a, const int& num) {
    return !(a == num);
}

template <typename T>
bool operator==(const Complex<T>& a, const float& num) {
    return (a.getReal() == num) && (a.getImag() == 0);
}

template <typename T>
bool operator!=(const Complex<T>& a, const float& num) {
    return !(a == num);
}

template <typename T>
bool operator==(const Complex<T>& a, const double& num) {
    return (a.getReal() == num) && (a.getImag() == 0);
}

template <typename T>
bool operator!=(const Complex<T>& a, const double& num) {
    return !(a == num);
}

