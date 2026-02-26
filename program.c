#include <stdio.h>
#include <string.h>

#define FILE_NAME "attendance.txt"

int isAlreadyMarked(char id[]) {
    FILE *file = fopen(FILE_NAME, "r");
    char storedID[50];

    if (file == NULL)
        return 0;

    while (fscanf(file, "%s", storedID) != EOF) {
        if (strcmp(id, storedID) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

void markAttendance() {
    FILE *file = fopen(FILE_NAME, "a");
    char id[50];

    printf("Scan QR Code (Enter Student ID): ");
    scanf("%s", id);

    if (isAlreadyMarked(id)) {
        printf("Attendance already marked!\n");
    } else {
        fprintf(file, "%s\n", id);
        printf("Attendance marked successfully!\n");
    }

    fclose(file);
}

void viewAttendance() {
    FILE *file = fopen(FILE_NAME, "r");
    char id[50];

    if (file == NULL) {
        printf("No attendance records found.\n");
        return;
    }

    printf("\n--- Attendance List ---\n");
    while (fscanf(file, "%s", id) != EOF) {
        printf("%s\n", id);
    }

    fclose(file);
}

int main() {
    int choice;

    do {
        printf("\n1. Mark Attendance\n");
        printf("2. View Attendance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                markAttendance();
                break;
            case 2:
                viewAttendance();
                break;
            case 3:
                printf("Exiting Program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice != 3);

    return 0;
}

