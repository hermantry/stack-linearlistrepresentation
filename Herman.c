#include "Herman.h"

boolean MemFull() { return (FirstAvail == Nil); }

void InitTab() {
    address P;

    for (P=IndexMin; P<IndexMax; P++)
        Next(P) = P + 1;

    Next(IndexMax) = Nil;
    FirstAvail = IndexMin;
}
