#include <stdio.h>
#include <stdlib.h>

struct ROOT {
    char name[8];              // Tên file (8 ký tự)
    char ext[3];               // Phần mở rộng (3 ký tự)
    char attr;                 // Thuộc tính
    char reserved[10];         // Dữ liệu dự trữ
    char time[2];              // Thời gian
    char date[2];              // Ngày
    int first_cluster;         // Chỉ số cluster đầu tiên
    long size;                 // Kích thước file
};

// Hàm đọc dữ liệu từ ổ đĩa (Giả sử đã định nghĩa)
int absread(int drive, int sector, int count, void *buffer) {
    return 0;  // Thành công giả
}

void print_root_info(struct ROOT *root, int root_size) {
    printf("\nDanh sách các file trong thư mục gốc:\n");
    for (int i = 0; i < root_size; i++) {
        if (root[i].name[0] == 0) continue; 

    
        for (int j = 0; j < 8 && root[i].name[j] != ' '; j++) {
            printf("%c", root[i].name[j]);
        }


        printf("\t Kích thước: %ld byte\n", root[i].size);
    }
}

int main() {
    int drive = 3;  // Ổ D
    struct BOOT boot;

    int res = absread(drive, 1, 0, &boot);
    if (res != 0) {
        printf("Không thể đọc boot sector\n");
        return 1;
    }

    struct ROOT *root = (struct ROOT *)malloc(boot.ROOT_size * sizeof(struct ROOT));
    if (root == NULL) {
        printf("Không đủ bộ nhớ cho ROOT\n");
        return 1;
    }

    int root_begin = boot.reserved + boot.FAT_size * boot.FAT_cnt;
    res = absread(drive, boot.ROOT_size, root_begin, root);
    if (res != 0) {
        printf("Không thể đọc ROOT\n");
        free(root);
        return 1;
    }

    print_root_info(root, boot.ROOT_size);
    free(root);

    return 0;
}
