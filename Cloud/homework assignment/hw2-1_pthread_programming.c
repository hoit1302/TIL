//
// 2021 Fall - Cloud Computing (01)
// Homework #2: Pthread Programming
//
// Copyright (c) Prof. Jaehyeong Sim
// Department of Computer Science and Engineering, Ewha Womans University
//

#include <pthread.h>
#include <stdio.h>
#include <string.h>

#define STR_SIZE 128

char original_string[STR_SIZE] = "Computer, Ewha";

int iter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void* get_str(void* data) {
    ////////////////////////
    // You need to fill here
    int ch_i = 0;
    char* str_data = (char*)data;
    char ch = str_data[0];
    char buffer[STR_SIZE] = "";

    pthread_mutex_lock(&lock);
    while (ch != '\0') {
        char str_ch[2] = ""; str_ch[0] = ch; str_ch[1] = '\0';
        strcat(buffer, str_ch);

        int find_flag = 0;
        for (int i = 0; i < (int)strlen(original_string); i++) {
            if (ch == original_string[i]) {
                original_string[i] = '_';
                find_flag = 1;
                break;
            }
        }
        if (!find_flag) {
            printf("Error: cannot find a character it wants from the original string. exit.\n");
            pthread_exit((void*)1);
        }

        printf("Iteration %d:\tthread %d got %c\tfrom\t%s\n",
               iter++, pthread_self(), ch, original_string);
        ch = str_data[++ch_i];
    }
    pthread_mutex_unlock(&lock);

    printf("*** Thread %d made a string: %s\n", pthread_self(), buffer);
    return 0;
    ////////////////////////
}

int main() {
    char target_string1[STR_SIZE] = "Ewha";
    char target_string2[STR_SIZE] = "Computer";

    printf("*** The initial original string:\t\t%s\n", original_string);

    ////////////////////////
    // You need to fill here
    pthread_t thread0, thread1;
    void *rc0 = NULL;

    pthread_create(&thread0, NULL, get_str, (void*)target_string1);
    pthread_create(&thread1, NULL, get_str, (void*)target_string2);

    pthread_join(thread0, &rc0);
	if ((long)(int*)rc0 == 1) {
		return 0;
	}
	pthread_join(thread1, &rc0);
	if ((long)(int*)rc0 == 1) {
		return 0;
    }
    ////////////////////////

    printf("*** Final original string:\t\t\t%s\n", original_string);
    return 0;
}
