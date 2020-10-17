#include "Herman.h"

boolean MemFull() { return (FirstAvail == Nil); }

void InitTab() {
    address P;

    for (P=IndexMin; P<IndexMax; P++)
        Next(P) = P + 1;

    Next(IndexMax) = Nil;
    FirstAvail = IndexMin;
}

void AllocTab(address *P) {
    if (MemFull()) {
        (*P) = Nil;
        printf("Tidak tersedia memori siap pakai.\n");
    } else {
        (*P) = FirstAvail;
        FirstAvail = Next(FirstAvail);
    }
}

void DeallocTab(address P) {
    Next(P) = FirstAvail;
    FirstAvail = (P);
}

boolean ListEmpty(List L) {
    return (First(L) == Nil);
}

void CreateList(List *L) {
    First(*L) = Nil;
}

address Search(List L, infotype X) {
    address P = First(L);

    while (Info(P) != X && P != Nil)
        P = Next(P);

    return P;
}

boolean FSearch(List L, address P) {
    address Pp = First(L);
    boolean Found = false;

    while (Found == false && Pp != Nil) {
        if (Pp == P) {
            Found = true;
            break;
        } else {
            Pp = Next(Pp);
        }
    }

    return Found;
}

address SearchPrec(List L, infotype X)
{
    address P,Prec;

    P=Search(L,X);
    Prec=First(L);
    while(Next(Prec)!=Nil && Next(Prec)!=P)
    {
        Prec=Next(Prec);
    }

    if(Next(Prec)==P)
    {
        return Prec;
    }
    else
    {
        return Nil;
    }
}
