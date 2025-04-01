#include <stdio.h>
#include <stdlib.h>

struct BOOT {
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

int absread(int drive, int sector, int count, void *buffer) {
    return 0; 
}

void print_boot_info(struct BOOT *boot) {
    printf("Thông tin BOOT:\n");
    printf("Số byte mỗi sector: %d\n", boot->bytes_per_sector);
    printf("Số sector mỗi cluster: %d\n", boot->sectors_per_cluster);
    printf("Số sector dự trữ: %d\n", boot->reserved);
    printf("Số FAT: %d\n", boot->FAT_cnt);
    printf("Kích thước FAT: %d\n", boot->FAT_size);
    printf("Kích thước ROOT: %d\n", boot->ROOT_size);
    printf("Tổng số sector: %d\n", boot->total_sectors);
    printf("Mã media: %d\n", boot->media);
}

int main() {
    int drive = 3; 
    struct BOOT boot;

    int res = absread(drive, 1, 0, &boot);
    if (res != 0) {
        printf("Không thể đọc boot sector\n");
        return 1;
    }

    print_boot_info(&boot);
    return 0;
}
