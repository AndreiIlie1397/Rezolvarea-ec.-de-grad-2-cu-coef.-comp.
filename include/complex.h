#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
using namespace std;
class complex
{
private:
    double re, im;
public:
    /// constructorul de initializare
    complex(double r=0, double i=0);

    /// constructorul de copiere
    complex(const complex &c);

    /// setare parte reala
    void set_real(double r);

    /// setare parte imaginara
    void set_imaginar(double i);

    /// returnare parte reala
    double get_real() const;

    /// returnare parte imaginara
    double get_imaginar() const;

    /// citire
    friend istream& operator>>(istream &in, complex &c);

    /// afisare
    friend ostream& operator<<(ostream &out, const complex &c);

    /// adunare complex-complex
    friend complex operator+(const complex &a, const complex &b);

    /// adunare complex-double
    friend complex operator+(const complex &a, const double &b);

    /// adunare double-complex
    friend complex operator+(const double &a, const complex &b);

    /// numarul insusi
    friend complex operator+(const complex &a);

    /// scadere complex-complex
    friend complex operator-(const complex &a, const complex &b);

    /// scadere complex-double
    friend complex operator-(const complex &a, const double &b);

    /// scadere double-complex
    friend complex operator-(const double &a, const complex &b);

    /// opusul numarului
    friend complex operator-(const complex &a);

    /// inmultire complex-complex
    friend complex operator*(const complex &a, const complex &b);

    /// inmultire complex-double
    friend complex operator*(const complex &a, const double &b);

    /// inmultire double-complex
    friend complex operator*(const double &a, const complex &b);

    /// impartire complex-complex
    friend complex operator/(const complex &a, const complex &b);

    /// impartire complex-double
    friend complex operator/(const complex &a, const double &b);

    /// impartire double-complex
    friend complex operator/(const double &a, const complex &b);

    /// == complex-complex
    friend bool operator==(const complex &a, const complex &b);

    /// == complex-double
    friend bool operator==(const complex &a, const double &b);

    /// == double-complex
    friend bool operator==(const double &a, const complex &b);

    /// != complex-complex
    friend bool operator!=(const complex &a, const complex &b);

    /// != complex-double
    friend bool operator!=(const complex &a, const double &b);

    /// != double-complex
    friend bool operator!=(const double &a, const complex &b);

    /// += complex-complex
    complex &operator+=(const complex &a);

    /// += complex-double
    complex &operator+=(const double &a);

    /// -= complex-complex
    complex &operator-=(const complex &a);

    /// -= complex-double
    complex &operator-=(const double &a);

    /// *= complex-complex
    complex &operator*=(const complex &a);

    /// *= complex-double
    complex &operator*=(const double &a);

    /// /= complex-complex
    complex &operator/=(const complex &a);

    /// /= complex-double
    complex &operator/=(const double &a);

    /// ridicare la putere
    complex operator^(const int &a) const;

    /// modul
    friend double abs(const complex &a);

    /// radical
    friend complex sqrt(const complex &a);
};

#endif
