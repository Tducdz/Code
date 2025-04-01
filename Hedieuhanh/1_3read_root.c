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
    char name[8];  // Tên file (8 ký tự)
    char ext[3];   // Phần mở rộng (3 ký tự)
    char attr;     // Thuộc tính (chẳng hạn, có phải là file hay thư mục)
    char reserved[10]; // Dữ liệu dự trữ
    char time[2];  // Thời gian
    char date[2];  // Ngày
    int first_cluster; // Chỉ số cluster đầu tiên
    long size;     // Kích thước của file
};

// Giả sử hàm này đã được định nghĩa ở đâu đó để đọc từ đĩa.
int absread(int drive, int sector, int count, void* buffer) {
    // Đọc dữ liệu từ ổ đĩa vào bộ nhớ
    return 0;  // Giả sử đọc thành công.
}

void print_root_info(struct ROOT* root, int root_size) {
    printf("Danh sách các file trong thư mục gốc:\n");
    for (int i = 0; i < root_size; i++) {
        if (root[i].name[0] == 0) continue; // Nếu tên file bằng NULL, bỏ qua.
        
        // In tên file
        for (int j = 0; j < 8 && root[i].name[j] != ' '; j++) {
            printf("%c", root[i].name[j]);
        }
        
        // In độ dài file
        printf("\t Kích thước: %ld byte\n", root[i].size);
    }
}

int find_file(struct ROOT* root, int root_size, const char* filename) {
    for (int i = 0; i < root_size; i++) {
        if (root[i].name[0] == 0) continue; // Nếu tên file bằng NULL, bỏ qua.
        
        // Kiểm tra tên file có giống không
        char str[9] = {0};
        for (int j = 0; j < 8 && root[i].name[j] != ' '; j++) {
            str[j] = root[i].name[j];
        }

        if (strcmp(str, filename) == 0) {
            return root[i].first_cluster; // Trả về cluster đầu tiên của file
        }
    }
    return -1; // Không tìm thấy file
}

int calculate_clusters(int* fat, int first_cluster) {
    int cluster_count = 0;
    int cur = first_cluster;
    while (cur < 0xFFF8) {  // Kiểm tra nếu cur không phải là EOF
        cluster_count++;
        cur = fat[cur];  // Lấy giá trị của cluster tiếp theo
    }
    return cluster_count;
}

int main() {
    int drive = 3; // ổ D
    struct BOOT boot;

    // Đọc boot sector
    int res = absread(drive, 1, 0, &boot);
    if (res != 0) {
        printf("Không thể đọc boot sector\n");
        return 1;
    }

    // Đọc FAT16
    unsigned int* fat = (unsigned int*)malloc(boot.FAT_size * boot.bytes_per_sector);
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

    // Đọc ROOT
    struct ROOT* root = (struct ROOT*)malloc(boot.ROOT_size * sizeof(struct ROOT));
    if (root == NULL) {
        printf("Không đủ bộ nhớ cho ROOT\n");
        free(fat);
        return 1;
    }

    int root_begin = boot.reserved + boot.FAT_size * boot.FAT_cnt;
    res = absread(drive, boot.ROOT_size, root_begin, root);
    if (res != 0) {
        printf("Không thể đọc ROOT\n");
        free(root);
        free(fat);
        return 1;
    }

    print_root_info(root, boot.ROOT_size);

    char filename[9];
    printf("Enter a file name: ");
    scanf("%s", filename);

    int first_cluster = find_file(root, boot.ROOT_size, filename);
    if (first_cluster != -1) {
        int cluster_count = calculate_clusters(fat, first_cluster);
        printf("File %s có %d khối nhớ.\n", filename, cluster_count);
    } else {
        printf("Không tìm thấy file %s.\n", filename);
    }

    free(root);
    free(fat);
    
    return 0;
}
