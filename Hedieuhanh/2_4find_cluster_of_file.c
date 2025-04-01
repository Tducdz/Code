#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_clusters(unsigned int *fat, int first_cluster) {
    int cur = first_cluster;
    printf("\nCác cluster của file bắt đầu từ cluster %d:\n", first_cluster);
    while (cur < 0xFFF8) {  
        printf("%d ", cur);
        cur = fat[cur];  
    }
    printf("\n");
}

int main() {
    
    unsigned int *fat;
    int first_cluster = 5;
    print_clusters(fat, first_cluster);
    return 0;
}
