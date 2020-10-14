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
