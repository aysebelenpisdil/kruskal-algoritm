#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_EDGES 100

typedef struct {
    int kaynak, hedef, agirlik;
} Kenar;

int ebeveyn[MAX_VERTICES], seviye[MAX_VERTICES];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        ebeveyn[i] = i;
        seviye[i] = 0;
    }
}

int findSet(int v) {
    if (ebeveyn[v] != v)
        ebeveyn[v] = findSet(ebeveyn[v]);
    return ebeveyn[v];
}

void unionSet(int u, int v) {
    int kokU = findSet(u);
    int kokV = findSet(v);
    if (kokU != kokV) {
        if (seviye[kokU] < seviye[kokV])
            ebeveyn[kokU] = kokV;
        else if (seviye[kokU] > seviye[kokV])
            ebeveyn[kokV] = kokU;
        else {
            ebeveyn[kokV] = kokU;
            seviye[kokU]++;
        }
    }
}

int karsilastir(const void* a, const void* b) {
    Kenar* e1 = (Kenar*)a;
    Kenar* e2 = (Kenar*)b;
    return e1->agirlik - e2->agirlik;
}

void kruskal(Kenar kenarlar[], int E, int V) {
    makeSet(V);
    qsort(kenarlar, E, sizeof(Kenar), karsilastir);

    for (int i = 0; i < E; i++) {
        int u = kenarlar[i].kaynak;
        int v = kenarlar[i].hedef;
        if (findSet(u) != findSet(v)) {
            printf("Secilen Kenar: (%d - %d), Agirlik = %d\n",
                   u, v, kenarlar[i].agirlik);
            unionSet(u, v);
        }
    }
}

int main() {
    Kenar kenarlar[] = {
        {0, 1, 4}, {0, 2, 8}, {1, 2, 11},
        {1, 3, 8}, {2, 4, 7}, {3, 4, 2}
    };
    int V = 5;
    int E = sizeof(kenarlar) / sizeof(kenarlar[0]);

    kruskal(kenarlar, E, V);
    return 0;
}
