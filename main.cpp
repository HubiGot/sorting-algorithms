#include<iostream>
#include<cstdlib>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iomanip>
#include"szablon.hh"

using namespace std;

//deklaracje funkcji

void insertionsort(int *tab, int rozmiar);
void IntroSort(int *tab, int rozmiar, int M);
void heapsort(int * tab, int rozmiar);
void heapify(int *tab,int rozmiar,int index);
void MedianOfThree(int *tab, int &l, int &p);
int partition(int *tab, int l, int p);
void IntrospectiveSort(int *tab,int N);
void quicksort(int tablica[],int l, int p);
void merge(int tablica[], int l, int srodek, int p);
void mergesort(int tablica[],int l, int p);
int partition_quick(int tablica[],int l, int p);

//------------------------------------------------------------------------------

//Mediana z 3
void MedianOfThree(int *tab, int &l, int &p)
{
  if(tab[++l-1]>tab[--p])
    swap(tab[l-1],tab[p]);
  if(tab[l-1]>tab[p/2])
    swap(tab[l-1],tab[p/2]);
  if(tab[p/2]>tab[p])
    swap(tab[p/2],tab[p]);
  swap(tab[p/2],tab[p-1]);
}

// element osiowy (rozbudowany dla sortowania introspektywnego)
int partition(int *tab, int l, int p)
{
  int i,j;
  if(p>=3)
    MedianOfThree(tab,l,p);
  for(i=l,j=p-2; ;)
    {
      for( ;tab[i]<tab[p-1]; ++i);
      for( ;j>=l &&tab[j]>tab[p-1]; --j);
      if(i<j)
        swap(tab[i++],tab[j--]);
      else break;
    }
    swap(tab[i],tab[p-1]);
    return i;
}


// sortowanie introspektywne (hybrydowe)
void IntrospectiveSort(int *tab,int N)
{
  IntroSort(tab,N,floor(2*log(N)/M_LN2));
  insertionsort(tab,N);
}



void IntroSort(int *tab, int rozmiar, int M)
{
  int i;
  if(M<=0)
  {
    heapsort(tab,rozmiar);
    return;
  }
  i=partition(tab,0,rozmiar);
  if(i>9)
    IntroSort(tab,i,M-1);
  if(rozmiar-1-i>9)
    IntroSort(tab+i+1,rozmiar-1-i,M-1);
}


//------------------------------------------------------------------------------


//dzielenie tablicy na dwie czesci: w lewej elementy mniejsze od pivota (x) w prewej wieksze
//wybieranie skrajnego elementu tablicy jako pivot
//wersja podstawowa dla quicksorta
int partition_quick(int tablica[],int l, int p)
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
//quicksort (sortowanie szybkie)
void quicksort(int tablica[],int l, int p)
{
  int d;
  if(l<p)
    {
    d=partition_quick(tablica,l,p); //punkt podzialu tablicy na dwie czesci
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

  for(int p=(K_rozmiar-1)/2; p>=0; --p) //tworzenie kopca
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
//------------------------------------------------------------------------------
//sortowanie przez wstawianie (insertion sort)
void insertionsort(int *tab, int rozmiar)
{
  int i,j;
  int temp;
  for(i=1; i<rozmiar; i++)
    {
      temp=tab[i];
      for(j=i; j>0 && temp<tab[j-1]; --j) //szukam miejsca dla elementu
        {
          tab[j]=tab[j-1];    //przesuwam elementy
        }
      tab[j]=temp;    //gdy znalazlem miejsce dla elementu to go wstawiam
    }
}


int main()
{
  clock_t begin,end;
  double t1=0.0,t2=0.0;
  tablica_int <20000> nowa[100];
  srand(time(NULL)); //zapewnia losowosc liczb w tablicach
int n[100];
for(int i=0;i<100;i++) //inicjalizajca tablic elementami
  {
    nowa[i].uzupelnij();
    n[i]=nowa[i].rozmiar();
  }


  for(int i=0;i<100;i++)
    {
      pom = new int[n[i]]; //przydzielenie pamieci na tablice pomocnicza dla mergesort
    }                       //wyciagniete w osobna petle zeby pomiary zlozonosci byly wiarygodne


begin=clock();
for(int i=0;i<100;i++) // sortowanie
  {
    quicksort(nowa[i].tablica,0,n[i]-1);
    //mergesort(nowa[i].tablica,0,n[i]-1);
    //IntrospectiveSort(nowa[i].tablica,n[i]);
  }
end=clock();

t1 +=(double)(end-begin)/CLOCKS_PER_SEC;
cout<<"Czas "<<t1/100<<cout<<endl;
printf("%10f",t1/100);cout<<endl;

  for(int i=0;i<100;i++) //sprawdzenie czy tablice sa posortowane
    {
      nowa[i].czy_posortowana();
      cout<<"Tablica "<<i<<" posortowana :)"<<endl;
    }
    /*for(int i=0;i<20;i++) //wyswietlanie elementow
      {
      nowa[i].pokaz();cout<<endl;
    }*/

	return 0;

}
