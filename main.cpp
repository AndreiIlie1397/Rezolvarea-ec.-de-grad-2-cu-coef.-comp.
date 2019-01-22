#include "complex.h"
#include <iostream>

int main()
{
    complex a, b(1, 1), c(1,2);
    complex delta, x1, x2;
    cout<<endl<<"\t\tRezolvarea ecuatiei de gradul al doilea cu coeficienti complecsi"<<endl<<endl;
    cout<<"   Introduceti coeficientul termenului x^2: ";
    cin>>a;
    cout<<"   Introduceti coeficientul termenului x: ";
    cin>>b;
    cout<<"   Introduceti termenul liber: ";
    cin>>c;
    delta=(b^2)-(4*a*c);
    if(a==0 && b!=0 && c!=0)
    {
        cout<<"   ("<<b<<")x"<<"+"<<c<<"=0"<<endl;
        x1=(-c)/b;
        cout<<"    Solutia ecuatiei este: "<<x1<<endl;
    }
    if(a==0 && b!=0 && c==0)
    {
        cout<<"   ("<<b<<")x"<<"=0"<<endl;;
        cout<<"    Solutia ecuatiei este: 0"<<endl;
    }
    if(a==0 && b==0 && c!=0)
    {
        cout<<"   "<<c<<"=0"<<endl;
        cout<<"    Ecuatia nu are solutii"<<endl;
    }
    if(a==0 && b==0 && c==0)
        cout<<"   Ecuatia are o infinitate de solutii"<<endl;
    if(a!=0 && b==0 && c==0)
    {
        cout<<"("<<a<<")*x^2=0"<<endl;
        cout<<"Solutia este 0";
    }
    if(a!=0 && b!=0 && c!=0)
    {
        cout<<endl<<"   ("<<a<<")"<<"*x^2"<<"+("<<b<<")"<<"*x"<<"+("<<c<<")=0"<<endl;
        cout<<endl<<"   Discriminantul ecuatiei este: "<<delta<<endl;
        if(delta==0)
        {
            x1=(-b)/(2*a);
            cout<<"   Ecuatia are solutii egale"<<endl;
            cout<<"   Solutia ecuatiei este: "<<x1<<endl;
        }
        else
        {
            x1=(-b+sqrt(delta))/(2*a);
            x2=(-b-sqrt(delta))/(2*a);
            cout<<"   Prima solutie este: "<<x1<<endl;
            cout<<"   A doua solutie este: "<<x2<<endl;
        }
    }
    if(a!=0 && b==0 && c!=0)
    {
        cout<<endl<<"   ("<<a<<")x^2"<<"+"<<c<<"=0"<<endl;
        cout<<endl<<"   Discriminantul ecuatiei este: "<<delta<<endl;
        if(delta==0)
        {
            x1=0;
            cout<<"   Ecuatia are solutii egale"<<endl;
            cout<<"   Solutia ecuatiei este: "<<x1<<endl;
        }
        else
        {
            x1=(+sqrt(delta))/(2*a);
            x2=(-sqrt(delta))/(2*a);
            cout<<"   Prima solutie este: "<<x1<<endl;
            cout<<"   A doua solutie este: "<<x2<<endl;
        }
    }
    if(a!=0 && b!=0 && c==0)
    {
        cout<<"   ("<<a<<")x^2"<<"+"<<"("<<b<<")x=0"<<endl;
        cout<<endl<<"   Discriminantul ecuatiei este: "<<delta<<endl;
        if(delta==0)
        {
            x1=(-b)/(2*a);
            cout<<"   Ecuatia are solutii egale"<<endl;
            cout<<"   Solutia ecuatiei este: "<<x1<<endl;
        }
        else
        {
            x1=(-b+sqrt(delta))/(2*a);
            x2=(-b-sqrt(delta))/(2*a);
            cout<<"   Prima solutie este: "<<x1<<endl;
            cout<<"   A doua solutie este: "<<x2<<endl;
        }
    }
    return 0;
}
