#include stdio.h
#include stdlib.h
#include string.h

struct BOOT {  for FAT16
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

int absread(int drive, int sector, int count, void buffer) {
    return 0;   Giả sử đọc thành công.
}

int main() {
    int drive = 3;  ổ D
    struct BOOT boot;

    int res = absread(drive, 1, 0, &boot);
    if (res != 0) {
        printf(Cannot read boot sectorn);
        return 1;
    }

    printf(Reading disk parametersn);

    unsigned int fat = (unsigned int)malloc(boot.FAT_size  boot.bytes_per_sector);
    if (fat == NULL) {
        printf(Not enough memoryn);
        return 1;
    }

    printf(nReading FAT16 parametersn);

    res = absread(drive, boot.FAT_size  boot.reserved, boot.reserved, fat);
    if (res != 0) {
        printf(Cannot read FATn);
        return 1;
    }

    printf(Content of first 150 FAT cellsn);
    for (int i = 0; i  150; i++) {
        printf(%u , fat[i]);
        if ((i + 1) % 20 == 0) {
            printf(n);
        }
    }

    printf(nBit map of first 150 blocksn);
    for (int i = 0; i  150; i++) {
        if (fat[i] == 0) {
            printf(0 );
        } else {
            printf(1 );
        }
        if ((i + 1) % 20 == 0) {
            printf(n);
        }
    }

    free(fat);
    return 0;
}
