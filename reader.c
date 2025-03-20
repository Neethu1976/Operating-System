#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int readcount = 0;  // Number of readers in the critical section
int writecount = 0; // Number of writers in the critical section
bool writing = false;

void reader_enter() {
    if (writing) {
        // If a writer is active, print a message and return to menu
        printf("Writer is trying to enter\n");
        return;  // Return to menu without entering
    }

    readcount++;
    printf("Reader %d has entered and is reading\n", readcount);
}

void reader_leave() {
    if (readcount > 0) {
        printf("Reader %d has left after reading\n", readcount);
        readcount--;
    } else {
        printf("No reader is currently in the critical section!\n");
    }
}

void writer_enter() {
    if (writing || readcount > 0) {
        // If there are active readers or another writer, print a message and return to menu
        printf("Writer is trying to enter\n");
        return;  // Return to menu without entering
    }

    writing = true;
    writecount++;
    printf("Writer %d has entered and is writing\n", writecount);
}

void writer_leave() {
    if (writing) {
        printf("Writer %d has finished writing and left\n", writecount);
        writing = false;
    } else {
        printf("No writer is currently in the critical section!\n");
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n1. Reader Enter\n2. Writer Enter\n3. Reader Leave\n4. Writer Leave\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                reader_enter();
                break;
            case 2:
                writer_enter();
                break;
            case 3:
                reader_leave();
                break;
            case 4:
                writer_leave();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

