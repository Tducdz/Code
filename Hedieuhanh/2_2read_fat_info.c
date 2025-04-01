#include <stdio.h>
#include <stdlib.h>

int absread(int drive, int sector, int count, void *buffer) {
    return 0; 
}

void print_fat_info(unsigned int *fat, int fat_size) {
    printf("\nThông tin bảng FAT:\n");
    for (int i = 0; i < fat_size; i++) {
        printf("FAT[%d]: 0x%X\n", i, fat[i]);
    }
}

int main() {
    int drive = 3;  /
    struct BOOT boot;

    int res = absread(drive, 1, 0, &boot);
    if (res != 0) {
        printf("Không thể đọc boot sector\n");
        return 1;
    }

    unsigned int *fat = (unsigned int *)malloc(boot.FAT_size * boot.bytes_per_sector);
    if (fat == NULL) {
        printf("Không đủ bộ nhớ\n");
        return 1;
    }

    res = absread(drive, boot.FAT_size * boot.reserved, boot.reserved, fat);
    if (res != 0) {
        printf("Không thể đọc FAT\n");
        free(fat);
        return 1;
    }

    print_fat_info(fat, boot.FAT_size * boot.bytes_per_sector);
    free(fat);
    return 0;
}
