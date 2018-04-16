#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;





//quicksort (sortowanie szybkie)
//dzielenie tablicy na dwie czesci: w lewej elementy mniejsze od pivota (x) w prewej wieksze
//wybieranie skrajnego elementu tablicy jako pivot
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


//------------------------------------------------------------------------------
//sortowanie przez scalanie (mergesort)
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
//------------------------------------------------------------------------------
//sortowanie przez kopcowanie (HeapSort)
//heapify - przywraca strukture kopca (warunek kopca)
void heapify(int *tab,int rozmiar,int index)
{
int largest=0, temp;
int lewy=(index +1)*2-1;
int prawy=(index+1)*2;
if(lewy<rozmiar && tab[lewy]>tab[index]) //porownuje element index z lewym elementem -> ustawiam wiekszy z nich
  {
    largest=lewy;
  }
  else largest=index;
  if(prawy<rozmiar && tab[prawy]>tab[largest]) //pozniej prawy porownuje z wiekszym z nich
    {
      largest=prawy;
    }
  if(largest!=index)  //jesli najwiekszym elementem nie jest index to zamieniam je miejscami
    {
      temp=tab[index];
      tab[index]=tab[largest];
      tab[largest]=temp;
      heapify(tab,rozmiar,largest);  //sprawdzam warunek kopca nizej
    }
}

void heapsort(int * tab, int rozmiar)
{
  int K_rozmiar=rozmiar;

  for(int p=(K_rozmiar-1)/2; p>=0; --p)
    {
      heapify(tab, K_rozmiar, p);
    }
  for(int i=rozmiar-1; i>0; --i)
    {
      int temp=tab[i];
      tab[i]=tab[0];   //przerzucenie korzenia do posortowanej czesci tablicy
      tab[0]=temp;      //przerzucanie ostatniego elementu do korzenia
      --K_rozmiar;
      heapify(tab,K_rozmiar,0);
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
	heapsort(tab,n);

	//wypisanie wyników
	for(int i=0;i<n;i++)
		cout<<tab[i]<<" ";


	return 0;
}
