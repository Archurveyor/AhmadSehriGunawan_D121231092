#include <stdio.h>

void convertToSevenSegment(int num) {
    int segments[7] = {0};

    switch (num) {
        case 0:
            segments[0] = segments[1] = segments[2] = segments[3] = segments[4] = segments[5] = 1;
            break;
        case 1:
            segments[1] = segments[2] = 1;
            break;
        case 2:
            segments[0] = segments[1] = segments[3] = segments[4] = segments[6] = 1;
            break;
        case 3:
            segments[0] = segments[1] = segments[2] = segments[3] = segments[6] = 1;
            break;
        case 4:
            segments[1] = segments[2] = segments[5] = segments[6] = 1;
            break;
        case 5:
            segments[0] = segments[2] = segments[3] = segments[5] = segments[6] = 1;
            break;
        case 6:
            segments[0] = segments[2] = segments[3] = segments[4] = segments[5] = segments[6] = 1;
            break;
        case 7:
            segments[0] = segments[1] = segments[2] = 1;
            break;
        case 8:
            segments[0] = segments[1] = segments[2] = segments[3] = segments[4] = segments[5] = segments[6] = 1;
            break;
        case 9:
            segments[0] = segments[1] = segments[2] = segments[3] = segments[5] = segments[6] = 1;
            break;
    }

    // representasi seven segment display
    printf(" %c \n", segments[0] ? '_' : ' ');
    printf("%c%c%c\n", segments[5] ? '|' : ' ', segments[6] ? '_' : ' ', segments[1] ? '|' : ' ');
    printf("%c%c%c\n\n", segments[4] ? '|' : ' ', segments[3] ? '_' : ' ', segments[2] ? '|' : ' ');
    printf("| A | B | C | D | E | F | G |\n");
    printf("|---|---|---|---|---|---|---|\n");
    printf("| %i | %i | %i | %i | %i | %i | %i |\n\n", segments[0],segments[1],segments[2],segments[3],segments[4],segments[5],segments[6]);
    printf("    [A]\n");
    printf(" [F]   [B]\n");
    printf("    [G]\n");
    printf(" [E]   [C]\n");
    printf("    [D]\n\n");
}

int main() {
    int choice;

    printf("\nPilih jenis input (1: desimal, 2: biner): ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Pilihan tidak valid. Program berhenti.\n");
        return 1;
    }

    if (choice == 1) {
        int decimalInput;
        printf("Masukkan angka desimal di bawah 10: ");
        scanf("%d", &decimalInput);

        if (decimalInput < 0 || decimalInput > 9) {
            printf("Invalid input. Please enter a number between 0 and 9.\n");
            return 1;
        }

        convertToSevenSegment(decimalInput);
    } else {
        int binaryInput;
        printf("Masukkan angka biner di bawah 10: ");
        scanf("%d", &binaryInput);

        if (binaryInput < 0 || binaryInput > 1001) {
            printf("Invalid input. Please enter a binary number between 0 and 1001\n");
            return 1; // Return non-zero sebagai tanda error
        }

        int temp = binaryInput;
        while (temp > 0) {
        int digit = temp % 10;
        if (digit != 0 && digit != 1) {
            printf("Invalid input. Please enter a binary number.\n");
            return 1;
        }
        temp /= 10;
        }

        int num = 0;
        int base = 1;
        while (binaryInput > 0) {
            int lastDigit = binaryInput % 10;
            num += lastDigit * base;
            binaryInput /= 10;
            base *= 2;
        }

        convertToSevenSegment(num);
    }

    return 0; // Return zero menandakan perintah sesuai
}