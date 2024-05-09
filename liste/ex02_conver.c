#include <stdio.h>

#define MILE_YARD 1760
#define YARDE_FEET 3
#define FEET_THUMBS 12
#define THUMBS_MM 25.4

struct misuraUK{
    float miglia;
    float yarde;
    float piedi;
    float pollici;
};

struct misuraUE{
    float km;
    float m;
    float mm;
};

void stampa(struct misuraUE m);
struct misuraUE convert(struct misuraUK m);

struct misuraUE convert(struct misuraUK muk){
    struct misuraUE mue;
    mue.mm = (muk.miglia * MILE_YARD * YARDE_FEET * FEET_THUMBS * THUMBS_MM) + (muk.yarde * YARDE_FEET * FEET_THUMBS * THUMBS_MM) + (muk.piedi * FEET_THUMBS * THUMBS_MM) * (muk.pollici * THUMBS_MM);
    mue.m = mue.mm / 1000;
    mue.km = mue.m / 1000;
    return mue;
}

void stampa(struct misuraUE m){ printf("\nKm: %f\tm: %f\tmm: %f", m.km, m.m, m.mm); }

typedef struct misuraUK misuk;

int main(){
    misuk m1 = {1, 0, 0, 0};
    struct misuraUE m2 = convert(m1);
    stampa(m2);
    return 0;
}