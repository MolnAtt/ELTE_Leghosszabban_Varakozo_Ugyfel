
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Ugyfel 
{
    int sorszam;
    int erk;
    int ugyi;
    int varakozasi_ido;

    Ugyfel(int s, int e, int u)
    {
        sorszam = s;
        erk = e;
        ugyi = u;
        varakozasi_ido = -1;
    }

    

};

void rendez(vector<Ugyfel>& L, int e, int v)
{
    if (e < v)
    {
        int i = e;
        int j = v;
        while (i != j)
        {
            if ((i < j) != (L[i].erk < L[j].erk))
            {
                swap(L[i], L[j]);
                swap(i, j);
            }
            j += i < j ? -1 : 1;
        }
        rendez(L, e, j - 1);
        rendez(L, j + 1, v);
    }
}

void rendez(vector<Ugyfel>& L) { rendez(L, 0, L.size() - 1); }

static void Kiir(vector<Ugyfel> ugyfelek)
{
    cerr << "------------------------------\n";
    for (Ugyfel& ugyfel : ugyfelek)
    {
        cerr << ugyfel.sorszam << " " << ugyfel.erk << " " << ugyfel.ugyi << endl;
    }
    cerr << "------------------------------\n";
}

vector<Ugyfel> Beolvas()
{
    int ei, ui, db;
    vector<Ugyfel> ugyfelek;
    cerr << "Adja meg, hogy hany ugyfel adatait fogja megadni: \n";
    cin >> db;

    for (int i = 0; i < db; i++)
    {
        cerr << "A(z) " << i + 1 << ". ugyfel erkezesi ideje es ugyintezesi ideje: \n";
        cin >> ei >> ui;
        ugyfelek.push_back(Ugyfel(i, ei, ui));
    }
    return ugyfelek;
}

void Kiir(Ugyfel leghosszabban_varakozo)
{
    cerr << "--------------------------------------------------\nA leghosszabban varakozo ugyfel sorszama (tobb eseten a legelso): ";
    cout << leghosszabban_varakozo.sorszam;
}


Ugyfel Feldolgoz(vector<Ugyfel> ugyfelek)
{
    priority_queue<Ugyfel> sor;

    cerr << "Ugyfelek eredetileg:\n";
    Kiir(ugyfelek);

    // 1. érkezési sorrendbe rakjuk az ügyfeleket:

    rendez(ugyfelek);

    cerr << "Ugyfelek erkezesi sorrendben:\n";
    Kiir(ugyfelek);

    for (Ugyfel& ugyfel : ugyfelek)
    {

    }

    Ugyfel leghosszabban_varakozo = ugyfelek[0];
    
    // Szimuláció

    return leghosszabban_varakozo;
}




int main()
{
    Kiir(Feldolgoz(Beolvas()));
}

