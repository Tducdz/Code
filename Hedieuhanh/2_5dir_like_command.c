#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void list_files(struct ROOT *root, int root_size) {
    printf("\nDanh sách các file trong thư mục gốc:\n");
    for (int i = 0; i < root_size; i++) {
        if (root[i].name[0] == 0) continue;

        for (int j = 0; j < 8 && root[i].name[j] != ' '; j++) {
            printf("%c", root[i].name[j]);
        }
        printf("\n");
    }
}

int main() {
    struct ROOT *root = (struct ROOT *)malloc(20 * sizeof(struct ROOT)); 
    list_files(root, 20);
    free(root);
    return 0;
}
