#include <stdio.h>
#include <stdlib.h>

//struktury do drzewa
typedef struct wezel{
  int key;
  struct wezel* lewy;
  struct wezel* prawy;
} Wezel;




// void WSTAW(Wsk *korzen, int wartosc){
//   Wsk x,y;
//   Wsk z = (Wsk) malloc (sizeof(Wezel));
//   z->key=wartosc;z->lewy=NULL;z->prawy=NULL;
//
//   //jesli drzewo jest puste
//   if(*korzen==NULL){
//     *korzen = z;
//     (*korzen)->ojciec=NULL;
//   } else {
//       x=*korzen;
//       while(x!=NULL){
//         y=x;
//         if(y->key > wartosc) //jesli wartosc jest mniejsza od akutlanego klucza to idz na lewo
//           x=y->lewy;
//         else
//           x=y->prawy;
//       }
//       z->ojciec=y;
//       if(y->key > wartosc) y->lewy = z;
//       else y->prawy = z;
//   }
// }

Wezel* INSERT(Wezel *korzen, int wartosc){
  if(korzen==NULL){
    korzen = (Wezel*) malloc(sizeof(Wezel));
    korzen->key=wartosc;
    korzen->lewy=NULL;
    korzen->prawy=NULL;
  } else if(wartosc < korzen->key){
    korzen->lewy = INSERT(korzen->lewy, wartosc);
  } else {
    korzen->prawy = INSERT(korzen->prawy,wartosc);
  }
  return korzen;
}

void DRUKUJ(Wezel * korzen){
  if(korzen!=NULL){
    DRUKUJ(korzen->lewy);
    printf("%d ", korzen->key);
    DRUKUJ(korzen->prawy);
  }
}

// void DRUKUJ(Wsk korzen){
//   if(korzen!=NULL){
//     printf("Drzewo nie jest puste\n");
//     DRUKUJ(korzen->lewy);
//     printf("%d,", korzen->key);
//     DRUKUJ(korzen->prawy);
//   }
// }

int main(){
  Wezel *korzen = NULL;
  korzen = INSERT(korzen,3);
  korzen = INSERT(korzen,5);
  korzen = INSERT(korzen,10);
  korzen = INSERT(korzen,2);
  korzen = INSERT(korzen,15);
  korzen = INSERT(korzen,1);
  DRUKUJ(korzen);
  // ojciec = INSERT(ojciec,3);

//  DRUKUJ(korzen);

  return 0;
}
