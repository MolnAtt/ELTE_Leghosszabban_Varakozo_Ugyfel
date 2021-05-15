
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Ugyfel 
{
    static vector<Ugyfel> lista;
    static Ugyfel leghosszabban_varakozo;

    int sorszam;
    int erk;
    int ugyi;
    int varakozasi_ido;

    Ugyfel(int s, int e, int u)
    {
        sorszam = s;
        erk = e;
        ugyi = u;
    }

    static void rendez() { rendez(0, lista.size() - 1); }
    static void rendez(int e, int v)
    {
        if (e < v)
        {
            int i = e;
            int j = v;
            while (i != j)
            {
                if ((i < j) != (lista[i].erk < lista[j].erk))
                {
                    swap(lista[i], lista[j]);
                    swap(i, j);
                }
                j += i < j ? -1 : 1;
            }
            rendez(e, j - 1);
            rendez(j + 1, v);
        }
    }

    static void Kiir()
    {
        cerr << "------------------------------\n";
        for (Ugyfel& ugyfel : lista)
        {
            cerr << ugyfel.sorszam << " " << ugyfel.erk << " " << ugyfel.ugyi;
        }
        cerr << "------------------------------\n";
    }
};

void Beolvas()
{
    int ei, ui, db;
    cerr << "Adja meg, hogy hany ugyfel adatait fogja megadni: \n";
    cin >> db;

    for (int i = 0; i < db; i++)
    {
        cerr << "A(z) " << i + 1 << ". ugyfel erkezesi ideje es ugyintezesi ideje: \n";
        cin >> ei >> ui;
        Ugyfel::lista.push_back(Ugyfel(i, ei, ui));
    }
}

Ugyfel Feldolgoz()
{
    priority_queue<Ugyfel> sor;

    cerr << "Ugyfelek eredetileg:\n";
    Ugyfel::Kiir();

    // 1. érkezési sorrendbe rakjuk az ügyfeleket:

    Ugyfel::rendez();

    cerr << "Ugyfelek erkezesi sorrendben:\n";
    Ugyfel::Kiir();


    Ugyfel leghosszabban_varakozo = Ugyfel::lista[0];
    
    // Szimuláció

    return leghosszabban_varakozo;
}

void Kiir(Ugyfel leghosszabban_varakozo)
{
    cerr << "--------------------------------------------------\nA leghosszabban varakozo ugyfel sorszama (tobb eseten a legelso): ";
    cout << leghosszabban_varakozo.sorszam;
}



int main()
{
    Beolvas();
    Kiir(Feldolgoz());
}

