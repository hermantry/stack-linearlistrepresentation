#ifndef HERMAN_H_INCLUDED
#define HERMAN_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

#define IndexMin 1
#define IndexMax 100
#define Nil NULL

typedef int infotype;
typedef int address;
typedef struct
{
    infotype Info;
    address Next;
}ElmtList;

typedef struct
{
    address First;
}List;

ElmtList TabElmt[IndexMax+1];
address FirstAvail;

#define First(L) (L).First
#define Next(P) TabElmt[P].Next
#define Info(P) TabElmt[P].Info


boolean MemFull();

void InitTab();

void AllocTab(address *P);

void DeallocTab(address P);

boolean ListEmpty(List L);

void CreateList(List *L);

address Search(List L, infotype X);

boolean FSearch(List L, address P);

address SearchPrec(List L, infotype X);

void InsVFirst(List *L, infotype X);

void InsVLast(List *L, infotype X);

void DelVFirst(List *L, infotype *X);

void DelVLast(List *L, infotype *X);

void InsertFirst(List *L, address P);

void InsertAfter(List *L, address P, address Prec);

void InsertLast(List *L, address P);

void DelFirst(List *L, address *P);

void DelP(List *L, infotype X);

void DelLast(List *L, address *P);

void DelAfter(List *L, address *Pdel, address Prec);

void PrintInfo(List L);

int NbElmt(List L);

infotype Maxs(List L);

address AdrMax(List L);

infotype Mins(List L);

address AdrMin(List L);

float Average(List L);

void DelAll(List *L);

void InversList(List *L);

List FInversList(List L);

void CopyList(List *L1, List *L2);

List FCopyList(List L);

void CpAlokList(List Lin, List *Lout);

void Konkat(List L1, List L2, List *L3);

void Konkat1(List *L1, List *L2, List *L3);

void PecahList(List *L1, List *L2, List L3);


#endif // HERMAN_H_INCLUDED
