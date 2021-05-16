
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Ugyfel 
{
    int sorszam;
    int erk;
    int ugyi;
    int varakozasi_ideje;

    Ugyfel(int s, int e, int u)
    {
        sorszam = s;
        erk = e;
        ugyi = u;
        varakozasi_ideje = -1;
    }

    bool operator< (const Ugyfel& b) const
    {
        return this->ugyi != b.ugyi ? this->ugyi > b.ugyi : this->erk > b.erk;
    }

    bool operator<< (const Ugyfel& b) const
    {
        return this->erk != b.erk ? this->erk < b.erk : this->ugyi < b.ugyi ;
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
            if ((i < j) != (L[i] << L[j]))
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

int main()
{
    cin.sync_with_stdio(false);
    cin.tie(nullptr);


    // Beolvasas

    int ei, ui, db;
    vector<Ugyfel> ugyfelek;
    cin >> db;

    for (int i = 0; i < db; i++)
    {
        cin >> ei >> ui;
        ugyfelek.push_back(Ugyfel(i, ei, ui));
    }

    // Feldolgozas

    priority_queue<Ugyfel> varolista;

    rendez(ugyfelek, 0, db - 1);


    // Szimul�ci�

    int leghosszabban_varakozo_indexe = -1;
    int leghosszabb_varakozas = -1;
    int aktualis_varakozas = -1;

    int ugyintezes_vege = ugyfelek[0].erk;
    int i = 0;

    while (i < ugyfelek.size() || !varolista.empty())
    {

        //////////////////////// v�r�lista felt�lt�se ////////////////////////////

        while (i < ugyfelek.size() && ugyfelek[i].erk <= ugyintezes_vege) // akik hamarabb �rkeznek, minthogy v�gezn�nek a bentl�v�vel, azok felker�lnek a v�r�list�ra
        {
            varolista.push(ugyfelek[i]);
            i++;
        }

        //////////////////////// sorban�ll�k beh�v�sa ////////////////////////////


        if (!varolista.empty()) // ha van, aki �pp sorba�ll
        {
            aktualis_varakozas = ugyintezes_vege - varolista.top().erk; // ha t�bbet v�rt, mint eddig b�rki, akkor feljegyezz�k a v�rakoz�s idej�t �s sorsz�m�t.
            if (leghosszabb_varakozas < aktualis_varakozas)
            {
                leghosszabb_varakozas = aktualis_varakozas;
                leghosszabban_varakozo_indexe = varolista.top().sorszam;
            }

            ugyintezes_vege += varolista.top().ugyi;

            varolista.pop();
        }
    }

    cout << leghosszabban_varakozo_indexe + 1;
}

