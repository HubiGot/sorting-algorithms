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


template < int ilosc>
class tablica_int
{
  public:
    int tablica[ilosc];


//tablica_int();
//~tablica_int();
//------------------------------------------------------------------------------
    void uzupelnij()
    {
      for(int i=0; i<ilosc; i++)
        {
          tablica[i]=rand();
        }
    }
//------------------------------------------------------------------------------
    void pokaz()
    {
      for(int i=0; i<ilosc; i++)
        {
          cout<<tablica[i]<<endl;
        }
    }
//------------------------------------------------------------------------------
    void sortuj(int koniec)
    {
      sort(tablica, tablica+koniec);
    }
//------------------------------------------------------------------------------
  void sortuj_malejaco()
    {
      sort(tablica,tablica+ilosc, greater<int>());
    }
//------------------------------------------------------------------------------
  int rozmiar()
    {
      return ilosc;
    }
//------------------------------------------------------------------------------
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
