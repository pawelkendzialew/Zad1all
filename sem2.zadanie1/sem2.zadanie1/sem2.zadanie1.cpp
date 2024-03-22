#include <iostream>
#include <ctime>
#include <cmath>
#include <cassert>
#include <iomanip>

using namespace std;

double obliczWartoscFunkcjiKwadratowej(double a, double b, double c, double x) 
{
	return a * pow(x, 2) + b * x + c;
}

double minimumFunkcjiKwadratowej(double a, double b, double c, double xp, double xk,int n)
{
    assert(xp < xk);
    assert(a >= 0);
    srand(time(0));

    double najmniejszaWartoscY = obliczWartoscFunkcjiKwadratowej(a, b, c, xp);
    double szukanyX = xp;
    int maxStag = n; // gdy przez maxStag iteracji nie znajdziemy lepszego wyniku kończymy poszukiwania
    int liczStag = 0;
    int m = 10 * n;
    for (int i = 0; i < m; i++)
    {
        double aktualnyX = xp + (double)(rand()) / (RAND_MAX / (xk -( xp)));
        double aktualnyY = obliczWartoscFunkcjiKwadratowej(a, b, c, aktualnyX);

        if (aktualnyY < najmniejszaWartoscY)
        {
            najmniejszaWartoscY = aktualnyY;
            szukanyX = aktualnyX;
            liczStag = 0;
        }
        else
        {
            liczStag++;
        }
        if (liczStag >= maxStag)
        {
            break;
        }
    }
    return szukanyX;
   
}

void testFunkcja(int n)
{
    double a = 1.0;
    double b = 2.0;
    double c = 1.0;
    double xp = -5.0;
    double xk = 5.0;
    double eps = 0.0005;
    double szukanyX = minimumFunkcjiKwadratowej(a, b, c, xp, xk, n);
    double szukanyY = obliczWartoscFunkcjiKwadratowej(a, b, c, szukanyX);
    double oczekiwanyX = -1.0;
    double oczekiwanyY = 0.0;
    cout << "Test funkcji #1";
    if(szukanyX + eps>= oczekiwanyX >= szukanyX -eps && szukanyY + eps>= oczekiwanyY >= szukanyY -eps)
    cerr <<endl<<"OK!";
    else
    cerr << "Blad!";
    
}

void testFunkcja1(int n)
{
    double a = 1.0;
    double b = 2.0;
    double c = 1.0;
    double xp = -6.0;
    double xk = -2.0;
    double eps = 0.001;
    double szukanyX = minimumFunkcjiKwadratowej(a, b, c, xp, xk, n);
    double szukanyY = obliczWartoscFunkcjiKwadratowej(a, b, c, szukanyX);
    double oczekiwanyX = -2.0;
    double oczekiwanyY = 1.0;
    cout << "Test funkcji #2";
    if(szukanyX + eps>= oczekiwanyX >= szukanyX -eps && szukanyY + eps>= oczekiwanyY >= szukanyY -eps)
    cerr <<endl<<"OK!";
    else
    cerr <<endl<< "Blad!";
    
}

void testFunkcja2(int n)
{
    double a = 1.0;
    double b = 2.0;
    double c = 1.0;
    double xp = 0.0;
    double xk = 5.0;
    double eps = 0.0005;
    double szukanyX = minimumFunkcjiKwadratowej(a, b, c, xp, xk, n);
    double szukanyY = obliczWartoscFunkcjiKwadratowej(a, b, c, szukanyX);
    double oczekiwanyX = 0.0;
    double oczekiwanyY = 1.0;
    cout << "Test funkcji #3";
    if(szukanyX + eps>= oczekiwanyX >= szukanyX -eps && szukanyY + eps>= oczekiwanyY >= szukanyY -eps)
    cerr <<endl<<"OK!";
    else
    cerr <<endl<< "Blad!";
    
}

int main()
{
    int n;
    cout << "Podaj liczbe iteracji bez poprawy wyniku: " << endl;
    cin >> n;

    cout << fixed << setprecision(4) << endl;
    double szukanyX = minimumFunkcjiKwadratowej(1.0, 2.0, 1.0, -5.0, 5.0, n);
    double szukanyY = obliczWartoscFunkcjiKwadratowej(1.0, 2.0, 1.0, szukanyX);
 cout << "Najmniejsza wartosc y: " << szukanyY<< " dla argumentu x: " << szukanyX << endl;

    double szukanyX1 = minimumFunkcjiKwadratowej(1.0, 2.0, 1.0, -6.0, -2, n);
    double szukanyY1 = obliczWartoscFunkcjiKwadratowej(1.0, 2.0, 1.0, szukanyX1);
 cout << "Najmniejsza wartosc y: " << szukanyY1<< " dla argumentu x: " << szukanyX1 << endl;

    double szukanyX2 = minimumFunkcjiKwadratowej(1.0, 2.0, 1.0, 0.0, 5.0, n);
    double szukanyY2 = obliczWartoscFunkcjiKwadratowej(1.0, 2.0, 1.0, szukanyX2);
    cout << "Najmniejsza wartosc y: " << szukanyY2<< " dla argumentu x: " << szukanyX2<< endl;
    cout <<endl;
    
    testFunkcja(n);
    testFunkcja1(n);
    testFunkcja2(n);
}
