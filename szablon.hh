#ifndef SZABLON_HH
#define SZABLON_HH

#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<ctime>

using namespace std;

//szablon do tworzenia tablic
template < int ilosc>
class tablica_int
{
  public:
    int tablica[ilosc];



//------------------------------------------------------------------------------
//funkcja inicjujaca tablice liczbami losowymi
    void uzupelnij()
    {
      for(int i=0; i<ilosc; i++)
        {
          tablica[i]=rand();
        }
    }
//------------------------------------------------------------------------------
//funkcja wyswietlajaca tablice
    void pokaz()
    {
      for(int i=0; i<ilosc; i++)
        {
          cout<<tablica[i]<<endl;
        }
    }
//------------------------------------------------------------------------------
//funkcja przygotowywujaca tablice do sortowanie (tablice posortowane w jakimś %)
    void sortuj(int koniec)
    {
      sort(tablica, tablica+koniec);
    }
//------------------------------------------------------------------------------
//funkcja sortujaca tablice malejaco
  void sortuj_malejaco()
    {
      sort(tablica,tablica+ilosc, greater<int>());
    }
//------------------------------------------------------------------------------
//funkcja zwracajac rozmiar tablicy
  int rozmiar()
    {
      return ilosc;
    }
//------------------------------------------------------------------------------
//funkcja sprawdzajaca czy tablica jest posortowana
bool czy_posortowana()
  {
    int licznik=0;
    for(int i=0;i<ilosc-1;i++)
      {
        if(tablica[i]<=tablica[i+1])
        {
        licznik++;
        }
      }
      if(licznik==ilosc-1)
      {
        return 1;
      }
      else return 0;
  }



};




# endif
