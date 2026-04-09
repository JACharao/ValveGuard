#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


#define RESET   "\033[0m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define RED     "\033[1;31m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"


void print_bar(double percent) {
    int size = 20; 
    int filled = (int)(percent * size / 100);

    
    if (percent > 80) printf(RED);
    else if (percent > 50) printf(YELLOW);
    else printf(GREEN);

    printf("[");
    for (int i = 0; i < size; i++) {
        if (i < filled) printf("#"); 
        else printf("-");            
    }
    printf("] %.2f%%%s\n", percent, RESET);
}

int main() {
    FILE *file;
    char line[256];
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

    /
    while(1) {
        
        file = fopen("/proc/meminfo", "r");
        if(file) {
            fgets(line, sizeof(line), file); sscanf(line, "MemTotal: %ld", &total);
            fgets(line, sizeof(line), file); sscanf(line, "MemFree: %ld", &free);
            fgets(line, sizeof(line), file); sscanf(line, "MemAvailable: %ld", &available);
            fclose(file);
        }

        
        file = fopen("/proc/uptime", "r");
        if(file) { fscanf(file, "%lf", &uptime); fclose(file); }

        
        long used = total - available;
        double usage_percent = ((double)used / total) * 100;

        
        printf("\033[H\033[J");
        
        
        printf(CYAN "========================================\n" RESET);
        printf(WHITE "         VALVE-GUARD v0.4              \n" RESET);
        printf(CYAN "========================================\n" RESET);
        
        printf(WHITE "CPU: " RESET "%s\n", cpuModel);
        printf(WHITE "Uptime: " RESET "%.2f seconds\n", uptime);
        printf("----------------------------------------\n");

        
        printf(WHITE "RAM Usage:\n" RESET);
        print_bar(usage_percent);

        
        printf("\nDetails:\n");
        printf("  Total:     %ld MB\n", total / 1024);
        printf("  Available: %ld MB\n", available / 1024);
        printf("  Used:      " RED "%ld MB\n" RESET, used / 1024);
        
        printf(CYAN "========================================\n" RESET);
        printf("Press CTRL+C to exit...\n");

        
        sleep(1);
    }
    return 0;
}

