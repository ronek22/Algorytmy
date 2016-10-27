//Jakub Ronkiewicz, gr 4, HeapSort Rekurencyjnie
/*przed wykonaniem program nalezy utworzyc plik "unsorted.txt"
Liczby zapisane są w kolejnych wierszach pliku
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define C 200


void copyArray(int desc[], int src[], int length){
  int i;
  for(i=0;i<length;i++){
    desc[i] = src[i];
  }
}
void RandomTab(int tab[], int length){
  int los,i;
  for(i=0;i<length;i++){
    los = rand() % length;
    tab[i] = los;
  }
}

void DecreasingTab(int tab[], int length){
  int i;
  for(i=0; i<length;i++){
    tab[i]=length-i;
  }
}

void swap(int tab[], int a, int b){
  int temp = tab[a];
  tab[a] = tab[b];
  tab[b] = temp;
}

int Partition(int A[], int p, int r) { // p-poczatek tablicy, r-koniec
  int x,i,j;
  x = A[r];
  i = p-1;
  for(j=p;j<=r;j++){
    if(A[j] <= x){
      i++;
      swap(A,i,j);
    }
  }
  if(i<r) return i;
  else return i-1;
}

void insertSort(int a[], int length)
{
    int i, j, value;

    for (i = 1; i < length; ++i) {
        value = a[i];
        for (j = i - 1; j >= 0 && a[j] > value; --j)
            a[j + 1] = a[j];
        a[j + 1] = value;
    }
}

void Quicksort(int A[], int p, int r) {
  int q;
  if(p<r){
    q=Partition(A,p,r);
    Quicksort(A,p,q);
    Quicksort(A,q+1,r);
  }
}

void Quicksort2(int A[], int p, int r) {
  if((r-p+1) < C) {
    insertSort(A, r+1);
  }
  int q;
  if(p<r){
    q=Partition(A,p,r);
    Quicksort(A,p,q);
    Quicksort(A,q+1,r);
  }
}

int main(){
  int i, length=0;
  double Tn;
  int zarodek = time(NULL);
  srand(zarodek);
  struct timespec tp0, tp1;
  //losowe - parzysty numer tablicy
  //niekorzystne - nieparzysty numer tablicy
  int tab1[100],tab2[100],tab3[500];
  int tab4[500],tab5[1000], tab6[1000];
  int tab7[2500], tab8[2500];

  RandomTab(tab1, 100);
  copyArray(tab2,tab1,100);

  printf("Tab1\n");
  for(i=0;i<100;i++){
    printf("%d ", tab1[i]);;
  }
  printf("\nTab2\n");
  for(i=0;i<100;i++){
    printf("%d ", tab2[i]);;
  }





  // Quicksort(tab,0,length-1);


  return 0;
}
