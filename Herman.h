#ifndef HERMAN_H_INCLUDED
#define HERMAN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "bool.h"

#define IndexMin 1
#define IndexMax 100
#define Nil NULL

typedef int infotype;
typedef int address;

typedef struct {
    infotype Info;
    address Next;
}ElmtList;

typedef struct {
    address First;
}List;

ElmtList TabElmt[IndexMax+1];
address FirstAvail;

#define First(L) (L).First
#define Next(P) TabElmt[P].Next
#define Info(P) TabElmt[P].Info

int NbElmt(List L);
float Average(List L);

address AdrMax(List L);
address AdrMin(List L);
address Search(List L, infotype X);
address SearchPrec(List L, infotype X);

boolean MemFull();
boolean ListEmpty(List L);
boolean FSearch(List L, address P);

infotype Mins(List L);
infotype Maxs(List L);

List FCopyList(List L);
List FInversList(List L);

void InitTab();
void AllocTab(address *P);
void DeallocTab(address P);
void CreateList(List *L);
void InsVFirst(List *L, infotype X);
void InsVLast(List *L, infotype X);

void InsertFirst(List *L, address P);
void InsertAfter(List *L, address P, address Prec);
void InsertLast(List *L, address P);

void DelAll(List *L);
void DelP(List *L, infotype X);
void DelLast(List *L, address *P);
void DelFirst(List *L, address *P);
void DelVLast(List *L, infotype *X);
void DelVFirst(List *L, infotype *X);
void DelAfter(List *L, address *Pdel, address Prec);

void PrintInfo(List L);
void InversList(List *L);

void CopyList(List *L1, List *L2);
void CpAlokList(List Lin, List *Lout);
void Konkat(List L1, List L2, List *L3);
void Konkat1(List *L1, List *L2, List *L3);
void PecahList(List *L1, List *L2, List L3);

#endif // HERMAN_H_INCLUDED
