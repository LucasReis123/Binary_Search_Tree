#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAM_ARESTAS 6

typedef struct no{
    int chave;
    struct no *esq;
    struct no *dir;
} No;

No* criaNo(int chave);
void inserirNo(No *no, int valor);
int altura(No *raiz);
void busca(No *no, int valor, int *procura);
void exibirEmOrdem(No* no);

int main(){
    clock_t start, end;
    double cpu_time_used;

    // Enter your tree values ​​here
    int arv[] = {8,11,13,45,47,48,52,106,124,150,195,217,251,277,290,307,319,325,404,424,427,449,455,529,535,539,569,580,589,600,617,622,648,667,670,737,753,757,915,925,933,941,958,978,988,1019,1033,1046,1072,1102,1110,1114,1128,1133,1176,1262,1269,1281,1311,1327,1343,1364,1392,1394,1401,1404,1405,1408,1467,1484,1493,1505,1530,1565,1582,1606,1626,1632,1651,1687,1688,1719,1720,1721,1751,1753,1778,1784,1807,1810,1811,1812,1832,1846,1890,1896,1905,1916,1929,1951,1957,1971,1998,2015,2016,2033,2043,2048,2052,2081,2088,2118,2131,2148,2173,2250,2255,2287,2292,2296,2315,2368,2380,2382,2389,2427,2428,2438,2500,2540,2547,2557,2564,2567,2598,2610,2621,2630,2647,2650,2661,2668,2672,2686,2690,2695,2742,2765,2789,2791,2801,2823,2858,2937,2947,2959,2982,2985,2994,2997,3024,3027,3069,3089,3102,3105,3106,3117,3172,3240,3277,3296,3298,3305,3311,3386,3394,3405,3417,3430,3440,3444,3445,3452,3454,3474,3512,3523,3541,3544,3584,3593,3610,3615,3627,3642,3669,3676,3686,3734,3762,3790,3798,3825,3826,3860,3895,3973,3994,4021,4070,4072,4074,4111,4134,4217,4235,4257,4276,4279,4284,4296,4298,4304,4307,4359,4372,4378,4409,4415,4424,4446,4451,4467,4509,4520,4560,4574,4590,4592,4620,4628,4665,4674,4679,4689,4702,4710,4725,4744,4847,4863,4871,4881,4903,4930,4934,4938,4958,5022,5024,5026,5028,5101,5108,5112,5140,5181,5194,5232,5235,5240,5243,5244,5252,5258,5295,5307,5350,5389,5402,5408,5434,5471,5472,5476,5498,5510,5512,5527,5528,5532,5554,5578,5579,5587,5674,5688,5718,5721,5724,5727,5735,5769,5771,5787,5797,5802,5817,5824,5847,5852,5906,5910,5923,6068,6073,6075,6082,6110,6118,6127,6134,6155,6157,6170,6184,6194,6205,6211,6218,6263,6294,6322,6330,6339,6342,6356,6380,6396,6412,6432,6437,6440,6464,6485,6548,6551,6584,6589,6659,6665,6681,6732,6734,6755,6757,6786,6797,6849,6877,6887,6927,6931,6933,6949,6960,7075,7091,7100,7107,7117,7143,7147,7156,7194,7239,7301,7306,7330,7341,7370,7392,7397,7433,7438,7466,7509,7512,7541,7594,7607,7618,7629,7635,7642,7689,7718,7738,7749,7754,7806,7873,7874,7876,7883,7890,7901,7931,8016,8021,8023,8057,8082,8103,8104,8123,8158,8176,8181,8184,8199,8245,8295,8309,8321,8342,8397,8466,8500,8533,8568,8577,8584,8604,8630,8635,8689,8740,8754,8772,8810,8816,8821,8830,8868,8903,8913,8916,8948,8966,8991,9011,9037,9059,9061,9098,9161,9162,9183,9187,9287,9295,9296,9325,9361,9368,9375,9393,9394,9423,9438,9463,9531,9554,9568,9578,9581,9585,9605,9613,9636,9637,9640,9661,9669,9672,9674,9678,9711,9726,9754,9813,9824,9841,9846,9855,9926,9939,9966};

    No *raiz_arv = malloc(sizeof(No));
    raiz_arv->chave = arv[0];
    raiz_arv->dir = NULL;
    raiz_arv->esq = NULL;

    int i = 0;
    int *procura = malloc(sizeof(int));
    (*procura) = 0;
    int tam1 = (sizeof(arv))/(sizeof(int));

    for(i = 1; i < tam1; i++){
        inserirNo(raiz_arv, arv[i]);
    }

    start = clock();
    busca(raiz_arv, 6050, procura);
    end = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    // If you want to know how the tree turned out:
    // exibirEmOrdem(raiz_arv);
    
    
    printf("\nAltura da Arvore: %d\n", altura(raiz_arv));
    printf("Quantidade de vezes que a chamada procurou 6050 na Arvore: %d\n", *procura);
    printf("Tempo gasto na funcao de busca: %lfs\n", cpu_time_used);

    free(raiz_arv);
    free(procura);

}

void inserirNo(No *no, int valor){
    /*
        Inserts a node into the tree according to the idea of ​​a 
        "binary search tree" (smaller keys on the left and larger keys
        on the right)
    */
    if((valor < no->chave) && (no->esq == NULL)){
        no->esq = criaNo(valor);
        return;
    }

    if((valor > no->chave) && (no->dir == NULL)){
        no->dir = criaNo(valor);
        return;
    }

    if((valor < no->chave) && (no->esq != NULL)){
        inserirNo(no->esq, valor);
        return;
    }

    if((valor > no->chave) && (no->dir != NULL)){
        inserirNo(no->dir, valor);
        return;
    }
}

No* criaNo(int chave){
    /*
        It takes a value as a parameter,
        creates a leaf node with that value and returns it
    */
    No *aux = malloc(sizeof(No));
    aux->chave = chave;
    aux->dir = NULL;
    aux->esq = NULL;
    return aux;
}

int altura(No *raiz){
    /*
        Receives a binary search tree as a parameter and returns its height
    */
    if(raiz == NULL){
        return -1;
    }
    else{
        int esq = altura(raiz->esq);
        int dir = altura(raiz->dir);
        if(esq > dir){
            return esq + 1;
        }
        else{
            return dir + 1;
        }
    }
}

void busca(No *no, int valor, int *procura){
    /*
        This function looks for a value in a binary tree
    */

    int i = 0;
    
    // Looping para fazer a função demorar um pouco a fim de mostrar
    // algum tempo na busca! (não é necessária para o funcionamento da árvore)

    for(i = 0; i < 1000000; i++){
        i = i;
    }
    

    if(no == NULL){
        (*procura)++;
        return;
    }

    if(valor == no->chave){
        return;
    }
    if(valor < no->chave){
        (*procura)++;
        busca(no->esq, valor, procura);
    }

    if(valor > no->chave){
        (*procura)++;
        busca(no->dir, valor, procura);
    }
}

void exibirEmOrdem(No* no) {
    /*
        print the tree in order
    */
    
    if (no->esq != NULL)
        exibirEmOrdem(no->esq);
    
    printf("%d ", no->chave);

    if (no->dir != NULL)
        exibirEmOrdem(no->dir);
}
