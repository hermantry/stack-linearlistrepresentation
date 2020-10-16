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

    while(Info(P) != X && P != Nil)
        P = Next(P);

    return P;
}
