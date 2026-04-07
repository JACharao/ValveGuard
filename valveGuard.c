#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *arquivo;
    char linha[100];
    long memoria_total;
    
    arquivo = fopen("/proc/meminfo", "r");  

    if(arquivo == NULL) {
        printf("Erro ao acessar o sistema de arquivos do Kernel\n");
        return 1;
    }
    
    if(fgets(linha, sizeof(linha), arquivo)) {

        sscanf(linha, "MemTotal: %ld", &memoria_total);

        printf("Valve-Guard: Memória total detectada: %ld MB\n", memoria_total / 1024);
    }
    
    fclose(arquivo);
    return 0;
}