#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;





//quicksort (sortowanie szybkie)
//dzielenie tablicy na dwie czesci: w lewej elementy mniejsze od pivota (x) w prewej wieksze
int partition(int tablica[],int l, int p)
{
int x=tablica[l]; //obieram pivot
int i = l;        //indeks poczatkowy w tabeli
int j = p;        //indeks koncowy w tabeli
int w;
while(1)
  {
    while(tablica[j]>x) j--;      //elementy wieksze od x
    while(tablica[i]<x) i++;
    if(i<j)   //zamiana elementow miejscami
    {
      w=tablica[i];
      tablica[i]=tablica[j];
      tablica[j]=w;
      i++;
      j--;
    }
    else        //gdy i>=j zwracamy j jako punkt podzialu tablicy
    return j;
  }

}

void quicksort(int tablica[],int l, int p)
{
  int d;
  if(l<p)
    {
    d=partition(tablica,l,p); //punkt podzialu tablicy na dwie czesci
    quicksort(tablica,l,d); //rekurencyjne wywolanie dla lewej czesci tablicy
    quicksort(tablica,d+1,p); //rekurencyjne wywolanie dla prawej czesci tablicy
    }
}



int *pom;


void merge(int tablica[], int l, int srodek, int p)
{
	int i = l, j = srodek + 1;


  for(int i = l;i<=p; i++) //przepisanie do tablicy pomocniczej
    pom[i] = tablica[i];

  //scalanie podtablic
  for(int k=l;k<=p;k++)
  {
  if(i<=srodek)       //jesli znajdujemy sie ciegle w lewej podtablicy
    {
    if(j <= p)        //jesli znajdujemy sie ciegle w prawej podtablicy
      {
         if(pom[j]<pom[i])
             tablica[k] = pom[j++];  //do wlasciwej tablicy wstawiamy element o indeksie j
         else
             tablica[k] = pom[i++];  // do wlasciwej tablicy wstawiamy element o indeksie i
      }

    else tablica[k] = pom[i++];     //jesli skonczyla sie prawa podtablica
    }
  else tablica[k] = pom[j++];       //jesli skonczyla sie lewa podtablica
    }
}

void mergesort(int tablica[],int l, int p)
{

	if(p<=l) return; //jeden element jest od razu posortowany
  else
  {
	int srodek = (p+l)/2;

	mergesort(tablica, l, srodek); //rekurencja dla lewej podtablicy
	mergesort(tablica, srodek+1, p); //rekurencja dla prawej podtablicy
  merge(tablica, l, srodek, p); // scalanie podtablic
  }
}




int main()
{
	int *tab,
	n; //liczba elementów tablicy
  cout<<"Podaj liczbe elementow do posortowania "<<endl;
	cin>>n;
	tab = new int[n]; //przydzielenie pamięci na tablicę liczb
	pom = new int[n]; //przydzielenie pamięci na tablicę pomocniczą
  cout<<"Podaj wartosci elementow: "<<endl;
	//wczytanie elementów tablicy
	for(int i=0;i<n;i++)
		cin>>tab[i];

	//sortowanie wczytanej tablicy
	mergesort(tab,0,n-1);

	//wypisanie wyników
	for(int i=0;i<n;i++)
		cout<<tab[i]<<" ";


	return 0;
}
