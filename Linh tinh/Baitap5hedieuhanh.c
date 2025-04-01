#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#define NUM_PHILOSOPHERS 5
pthread_mutex_t chopsticks[NUM_PHILOSOPHERS];
void* philosopher(void* philosopher_id) {
    int id = *(int*)philosopher_id;
    while (1) {
        printf("Triết gia %d đang suy nghĩ...\n", id);
        sleep(1);  // Triết gia suy nghĩ
        printf("Triết gia %d đang đói và muốn ăn...\n", id);
        pthread_mutex_lock(&chopsticks[id]);
        pthread_mutex_lock(&chopsticks[(id + 1) % NUM_PHILOSOPHERS]);
        printf("Triết gia %d đang ăn...\n", id);
        sleep(2);  // Triết gia ăn
        pthread_mutex_unlock(&chopsticks[id]); 
        pthread_mutex_unlock(&chopsticks[(id + 1) % NUM_PHILOSOPHERS]);     
        printf("Triết gia %d đã ăn xong và đang suy nghĩ lại...\n", id);
        sleep(1);  // Triết gia tiếp tục suy nghĩ
    }
    return NULL;
}
int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];
    int philosopher_ids[NUM_PHILOSOPHERS];
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&chopsticks[i], NULL);
    }
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&chopsticks[i]);
    }
    return 0;
}