#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE *file;
    char line[100];
    char cpuModel[100] = "unknown";
    long total, free, available;
    double uptime;

    
    file = fopen("/proc/cpuinfo", "r");
    if(file) {
        while(fgets(line, sizeof(line), file)) {
            if(sscanf(line, "model name : %[^\n]", cpuModel)) break;
        }
        fclose(file);
    }

    while(1) {
        
        file = fopen("/proc/meminfo", "r");
        if(file) {
            fgets(line, sizeof(line), file); 
            sscanf(line, "MemTotal: %ld", &total);
            
            fgets(line, sizeof(line), file); 
            sscanf(line, "MemFree: %ld", &free);
            
            fgets(line, sizeof(line), file); 
            sscanf(line, "MemAvailable: %ld", &available);
            
            fclose(file);
        }

        
        file = fopen("/proc/uptime", "r");
        if(file) {
            fscanf(file, "%lf", &uptime);
            fclose(file);
        }

        printf("\033[H\033[J");
        
        printf("==============================\n");
        printf("       VALVE-GUARD v0.3     \n");
        printf("==============================\n");
        printf("CPU: %s\n", cpuModel);
        printf("Uptime: %.2f seconds\n", uptime);
        printf("------------------------------\n");
        printf("RAM Total:     %ld MB\n", total / 1024);
        printf("RAM Available: %ld MB\n", available / 1024);
        printf("RAM Used:      %ld MB\n", (total - available) / 1024);
        printf("==============================\n");
        printf("Press CTRL+C to exit...\n");

        sleep(1);
    }
    return 0;
}

