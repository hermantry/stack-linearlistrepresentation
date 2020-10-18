#include "Herman.h"

boolean MemFull() { return (FirstAvail == Nil); }

void InitTab() {
    address P;

    for (P = IndexMin; P < IndexMax; P++)
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
        } else
            Pp = Next(Pp);
    }

    return Found;
}

address SearchPrec(List L, infotype X) {
    address P, Prec;

    P=Search(L, X);
    Prec = First(L);
    while(Next(Prec) != Nil && Next(Prec) != P)
        Prec = Next(Prec);

    if (Next(Prec) == P)
        return Prec;
    else
        return Nil;
}

void InsVFirst(List *L, infotype X) {
    address P;

    AllocTab(&P);
    if (P != Nil) {
        Info(P) = X;
        InsertFirst(&(*L), P);
    }
}

void InsVLast(List *L, infotype X) {
    address P;

    AllocTab(&P);
    if (P != Nil) {
        Info(P) = X;
        InsertLast(&(*L), P);
    }
}

void DelVFirst(List *L, infotype *X) {
    address P;

    DelFirst(&(*L), &P);
    (*X) = Info(P);
    Next(P) = Nil;
    DeallocTab(P);
}

void DelVLast(List *L, infotype *X) {
    address P;

    DelLast(&(*L), &P);
    (*X) = Info(P);
    DeallocTab(P);
}

void InsertFirst(List *L, address P) {
    if (ListEmpty(*L)) {
        Next(P) = Nil;
        First(*L) = P;
    } else {
        Next(P) = First(*L);
        First(*L) = P;
    }
}
