#include "GameUtils.h"

double genera_aleatorio(int n, int m){
    return m + rand()%(n + 1 - m);
}