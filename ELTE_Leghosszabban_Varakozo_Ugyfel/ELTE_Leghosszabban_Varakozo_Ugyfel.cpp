
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
        return this->ugyi == b.ugyi ? this->erk > b.erk : this->ugyi > b.ugyi;
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

/** /
static void Kiir(vector<Ugyfel> ugyfelek)
{
    cerr << "------------------------------\n";
    for (Ugyfel& ugyfel : ugyfelek)
    {
        cerr << ugyfel.sorszam << " " << ugyfel.erk << " " << ugyfel.ugyi << endl;
    }
    cerr << "------------------------------\n";
}
/**/
vector<Ugyfel> Beolvas()
{
    int ei, ui, db;
    vector<Ugyfel> ugyfelek;
//    cerr << "Adja meg, hogy hany ugyfel adatait fogja megadni: \n";
    cin >> db;

    for (int i = 0; i < db; i++)
    {
  //      cerr << "A(z) " << i + 1 << ". ugyfel erkezesi ideje es ugyintezesi ideje: \n";
        cin >> ei >> ui;
        ugyfelek.push_back(Ugyfel(i, ei, ui));
    }
    return ugyfelek;
}

void Kiir(int leghosszabban_varakozo_indexe)
{
    cerr << "--------------------------------------------------\nA leghosszabban varakozo ugyfel sorszama (tobb eseten a legelso): ";
    cout << leghosszabban_varakozo_indexe + 1;
}


int Feldolgoz(vector<Ugyfel> ugyfelek)
{
    priority_queue<Ugyfel> varolista;

    //cerr << "Ugyfelek eredetileg:\n";
    //Kiir(ugyfelek);

    // 1. érkezési sorrendbe rakjuk az ügyfeleket:

    rendez(ugyfelek);

    //cerr << "Ugyfelek erkezesi sorrendben:\n";
    //Kiir(ugyfelek);

    // Szimuláció


    int leghosszabban_varakozo_indexe = -1;
    int leghosszabb_varakozas = -1;
    int aktualis_varakozas = -1;

    int ugyintezes_vege = ugyfelek[0].erk;
    int i = 0;

    while (i < ugyfelek.size() || !varolista.empty())
    {
        while (i< ugyfelek.size() && ugyfelek[i].erk <= ugyintezes_vege) // akik hamarabb érkeznek, minthogy végeznének a bentlévõvel, azok felkerülnek a várólistára
        {
            varolista.push(ugyfelek[i]);
      //      cerr << ugyfelek[i].erk << " idopontban erkezo " << ugyfelek[i].ugyi << " munkaideju ugyfel (" << ugyfelek[i].sorszam << ".) beallt a sorba.\n";
            i++;
        //    cerr << "----------------------\n";
        }

        // itt már szabad az ügyintézõ
/** /
        if (i< ugyfelek.size())
        {
            cerr << "az ugyintezo " << ugyintezes_vege << " idopontban vegez, a kovetkezo ugyfel viszont " << ugyfelek[i].erk << " idopontban erkezik.\n";
        }
        else
        {
            cerr << "nem jon tobb ugyfel!\n";
        }
/**/
        if (!varolista.empty()) // ha van, aki épp sorbaáll
        {   
//            cerr << "nem ures meg a varolista, ezert behivjuk a ("<< varolista.top().sorszam <<") szamu ugyfelet, aki "<< varolista.top().erk <<" ota var itt.\n";
            aktualis_varakozas = ugyintezes_vege - varolista.top().erk; // ha többet várt, mint eddig bárki, akkor feljegyezzük a várakozás idejét és sorszámát.
            if (leghosszabb_varakozas < aktualis_varakozas)
            {
  //              cerr << "talaltam szerencsetlenebb ugyfelet az eddig rekordernel: (" << leghosszabban_varakozo_indexe << ".) ugyfel " << leghosszabb_varakozas << " idejet veri (" << varolista.top().sorszam << ".) ezzel: "<< aktualis_varakozas << endl;
                leghosszabb_varakozas = aktualis_varakozas;
                leghosszabban_varakozo_indexe = varolista.top().sorszam;
            }

            // bejelenti az ügyfélszolgálatos, hogy mikor lesz legközelebb szabad
            ugyintezes_vege += varolista.top().ugyi;
    //        cerr << "bejelenti az ugyfelszolgalatos, hogy legkozelebb " <<varolista.top().ugyi << " ido mulva " << ugyintezes_vege << "-kor lesz szabad.\n";

            // beviszi magával az ügyfelet
            varolista.pop();
      //      cerr << "behivja ezt az ugyfelet.\n";
        //    cerr << "=============================\n";
        }
        // léptet 
//        i++;
    }


    return leghosszabban_varakozo_indexe;
}




int main()
{
    Kiir(Feldolgoz(Beolvas()));
}

