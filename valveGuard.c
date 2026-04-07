#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *file;
    char line[100];
    long total = 0, free = 0, used = 0;
    
    file = fopen("/proc/meminfo", "r");  

    if(file == NULL) {
        printf("Error accessing the Kernel file system.\n");
        return 1;
    }
    
    if(fgets(line, sizeof(line), file)) {
        sscanf(line, "MemTotal: %ld", &total);
    }

    if(fgets(line, sizeof(line), file)) {
        sscanf(line, "MemFree: %ld", &free);
    }
    
    fclose(file);

    used = total - free;

    printf("==============================\n");
    printf("       VALVE-GUARD v0.2       \n");
    printf("==============================\n");
    printf("Total RAM:  %ld MB\n", total / 1024);
    printf(" Free RAM:   %ld MB\n", free / 1024);
    printf(" Used RAM:   %ld MB\n", used / 1024);
    printf("==============================\n");

    return 0;
}
