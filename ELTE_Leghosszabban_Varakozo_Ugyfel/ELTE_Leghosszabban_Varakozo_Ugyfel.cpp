
#include <iostream>
#include <queue>

using namespace std;

struct Ugyfel 
{
    int erk;
    int ugyi;

    Ugyfel(int e, int u)
    {
        erk = e;
        ugyi = u;
    }
};

struct Input
{
    static const int n_MAX = 10000;
    int n;
    int e[n_MAX];
    int u[n_MAX];
};


Input Beolvas()
{
    Input be;

    cerr << "Adja meg, hogy hany ugyfel adatait fogja megadni: \n";
    cin >> be.n;
    for (int i = 0; i < be.n; i++)
    {
        cerr << "A(z) " << i + 1 << ". ugyfel erkezesi ideje es ugyintezesi ideje: \n";
        cin >> be.e[i] >> be.u[i];
    }
    return be;
}

int Feldolgoz(Input be)
{


    return -1;
}

void Kiir(int ki)
{
    cerr << "--------------------------------------------------\nA leghosszabban varakozo ugyfel sorszama (tobb eseten a legelso): ";
    cout << ki;
}

int main()
{
    Kiir(Feldolgoz(Beolvas()));
}

