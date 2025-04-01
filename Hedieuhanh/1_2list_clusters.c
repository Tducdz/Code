#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BOOT { // for FAT16
    char jmp[3];
    char OEM[8];
    int bytes_per_sector;
    char sectors_per_cluster;
    int reserved;
    char FAT_cnt;
    int ROOT_size;
    int total_sectors;
    char media;
    int FAT_size;
    int sectors_per_track;
    int head_cnt;
    long hidden_sectors;
    long total_sectors_long;
    char unknown[3];
    long serial;
    char volume[11];
    char FAT_type[8];
    char loader[448];
    char mark[2];
};

struct ROOT {
    char name[8];
    char ext[3];
    char attr;
    char reserved[10];
    char time[2];
    char date[2];
    int first_cluster;
    long size;
};

int absread(int drive, int sector, int count, void* buffer) {
    return 0;
}

int main() {
    int drive = 3; // ổ D
    struct BOOT boot;

    int res = absread(drive, 1, 0, &boot);
    if (res != 0) {
        printf("Cannot read boot sector\n");
        return 1;
    }

    unsigned int* fat = (unsigned int*)malloc(boot.FAT_size * boot.bytes_per_sector);
    if (fat == NULL) {
        printf("Not enough memory\n");
        return 1;
    }

    res = absread(drive, boot.FAT_size * boot.reserved, boot.reserved, fat);
    if (res != 0) {
        printf("Cannot read FAT\n");
        free(fat);
        return 1;
    }

    unsigned int first_cluster = 23;
    unsigned int cur = first_cluster;
    printf("Clusters of file starting from %u: ", first_cluster);
    while (cur < 0xFFF8) {
        printf("%u ", cur);
        cur = fat[cur];
    }
    printf("\n");

    struct ROOT* root = (struct ROOT*)malloc(boot.ROOT_size * sizeof(struct ROOT));
    if (root == NULL) {
        printf("Not enough memory for root\n");
        free(fat);
        return 1;
    }

    int root_begin = boot.reserved + boot.FAT_size * boot.FAT_cnt;
    res = absread(drive, boot.ROOT_size, root_begin, root);
    if (res != 0) {
        printf("Cannot read ROOT\n");
        free(root);
        free(fat);
        return 1;
    }

    printf("\nFiles in ROOT:\n");
    for (int i = 0; i < boot.ROOT_size; i++) {
        if (root[i].name[0] == 0) continue;
        for (int j = 0; j < 8 && root[i].name[j] != ' '; j++) {
            printf("%c", root[i].name[j]);
        }
        printf("\n");
    }

    free(root);
    free(fat);
    return 0;
}
