#include "GameUtils.h"

double genera_aleatorio(int n, int m){
    return n + rand()%(m+1-n);
}