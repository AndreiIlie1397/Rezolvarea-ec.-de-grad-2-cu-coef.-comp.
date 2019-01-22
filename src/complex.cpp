#include "complex.h"
#include <math.h>

complex::complex(double r, double i):re(r), im(i) {}

complex::complex(const complex &c):re(c.re), im(c.im) {}

void complex::set_real(double r)
{
    re=r;
}

void complex::set_imaginar(double i)
{
    im=i;
}

double complex::get_real() const
{
    return re;
}

double complex::get_imaginar() const
{
    return im;
}

istream &operator>>(istream &in, complex &c)
{
    double n;
    in>>n;
    c.set_real(n);
    in>>n;
    c.set_imaginar(n);
    return in;
}

ostream &operator<<(ostream &out, const complex &c)
{
    if(c.get_real()==0)
    {
        if(c.get_imaginar()>0 && c.get_imaginar()!=1)
            out<<"i*"<<c.get_imaginar();
        if(c.get_imaginar()<0 && c.get_imaginar()!=-1)
            out<<"-i*"<<abs(c.get_imaginar());
        if(c.get_imaginar()==0)
            out<<"0";
        if(c.get_imaginar()==1)
            out<<"i";
        if(c.get_imaginar()==-1)
            out<<"-i";
    }
    if(c.get_real()!=0)
    {
        if(c.get_imaginar()==0)
            out<<c.get_real();
        if(c.get_imaginar()>0 && c.get_imaginar()!=1)
            out<<c.get_real()<<"+i*"<<c.get_imaginar();
        if(c.get_imaginar()<0 && c.get_imaginar()!=-1)
            out<<c.get_real()<<"-i*"<<abs(c.get_imaginar());
        if(c.get_imaginar()==1)
            out<<c.get_real()<<"+i";
        if(c.get_imaginar()==-1)
            out<<c.get_real()<<"-i";
    }
    return out;
}

complex operator+(const complex &a, const complex &b)
{
    return complex(a.get_real()+b.get_real(), a.get_imaginar()+b.get_imaginar());
}

complex operator+(const complex &a, const double &b)
{
    return complex(a.get_real()+b, a.get_imaginar());
}

complex operator+(const double &a, const complex &b)
{
    return complex(a+b.get_real(), b.get_imaginar());
}

complex operator+(const complex &a)
{
    return complex(+a.get_real(), +a.get_imaginar());
}

complex operator-(const complex &a,const complex &b)
{
    return complex(a.get_real()-b.get_real(), a.get_imaginar()-b.get_imaginar());
}

complex operator-(const complex &a, const double &b)
{
    return complex(a.get_real()-b, a.get_imaginar());
}

complex operator-(const double &a, const complex &b)
{
    return complex(a-b.get_real(), -b.get_imaginar());
}

complex operator-(const complex &a)
{
    return complex(-a.get_real(), -a.get_imaginar());
}

complex operator*(const complex &a, const complex &b)
{
    return complex(a.get_real()*b.get_real()-a.get_imaginar()*b.get_imaginar(), a.get_real()*b.get_imaginar()+ b.get_real()*a.get_imaginar());
}

complex operator*(const complex &a, const double &b)
{
    return complex(a.get_real()*b, b*a.get_imaginar());
}

complex operator*(const double &a,const complex &b)
{
    return complex(a*b.get_real(), a*b.get_imaginar());
}

complex operator/(const complex &a, const complex &b)
{
    if(b==0)
        return 0;
    complex c(b.get_real(), -b.get_imaginar());
    return complex((a*c)/((b.get_real()*b.get_real()+b.get_imaginar()*b.get_imaginar())));
}

complex operator/(const complex &a, const double &b)
{
    if(b==0)
        return 0;
    return complex(a.get_real()/b, a.get_imaginar()/b);
}

complex operator/(const double &a, const complex &b)
{
    if(b==0)
        return 0;
    complex c(b.get_real(), -b.get_imaginar());
    return complex((a*c)/((b.get_real()*b.get_real()+b.get_imaginar()*b.get_imaginar())));
}

bool operator==(const complex &a, const complex &b)
{
    if(a.get_real()==b.get_real() && a.get_imaginar()==b.get_imaginar())
        return true;
    return false;
}

bool operator==(const complex &a, const double &b)
{
    if(a.get_real()==b && a.get_imaginar()==0)
        return true;
    return false;
}

bool operator==(const double &a, const complex &b)
{
    if(a==b.get_real() && b.get_imaginar()==0)
        return true;
    return false;
}

bool operator!=(const complex &a, const complex &b)
{
    if(a.get_real()==b.get_real() && a.get_imaginar()==b.get_imaginar())
        return false;
    return true;
}

bool operator!=(const complex &a, const double &b)
{
    if(a.get_real()==b && a.get_imaginar()==0)
        return false;
    return true;
}

bool operator!=(const double &a, const complex &b)
{
    if(a==b.get_real() && b.get_imaginar()==0)
        return false;
    return true;
}

complex &complex::operator+=(const complex &a)
{
    this->set_real(this->get_real()+a.get_real());
    this->set_imaginar(this->get_imaginar()+a.get_imaginar());
    return *this;
}

complex &complex::operator+=(const double &a)
{
    this->set_real(this->get_real()+a);
    return *this;
}

complex &complex::operator-=(const complex &a)
{
    this->set_real(this->get_real()-a.get_real());
    this->set_imaginar(this->get_imaginar()-a.get_imaginar());
    return *this;
}

complex &complex::operator-=(const double &a)
{
    this->set_real(this->get_real()-a);
    return *this;
}

complex &complex::operator*=(const complex &a)
{
    double c=re;
    this->re=re*a.get_real()-im*a.get_imaginar();
    this->im=c*a.get_imaginar()+im*a.get_real();
    return *this;
}

complex &complex::operator*=(const double &a)
{
    this->set_real(this->get_real()*a);
    this->set_imaginar(this->get_imaginar()*a);
    return *this;
}

complex &complex::operator/=(const complex &a)
{
    if(a==0)
        cout<<"Nu se poate imparti.";
    return *this=0;
    if(a!=0)
    {
        double c, t=re;
        c=a.get_real()*a.get_real()+a.get_imaginar()*a.get_imaginar();
        this->re=(re*a.get_real()+im*a.get_imaginar())/c;
        this->im=(im*a.get_real()-t*a.get_imaginar())/c;
        return *this;
    }
}

complex &complex::operator/=(const double &a)
{
    if(a==0)
        cout<<"Nu se poate imparti.";
    return *this=0;
    if(a!=0)
    {
        this->set_real(this->get_real()/a);
        this->set_imaginar(this->get_imaginar()/a);
        return *this;
    }
}

double abs(const complex &a)
{
    return sqrt(a.get_real()*a.get_real()+a.get_imaginar()*a.get_imaginar());
}

complex sqrt(const complex &a)
{
    complex rad;
    rad.re=(1/sqrt(2))*sqrt(abs(a)+a.re);
    rad.im=(1/sqrt(2))*sqrt(abs(a)-a.re);
    if(a.im<0)
        rad.im=-rad.im;
    return rad;
}

complex complex::operator^(const int &a)const
{
    complex b(*this);
    if(a==0)
        return 1;
    for(int i=1; i<a; i++)
        b*=*this;
    return b;
}
