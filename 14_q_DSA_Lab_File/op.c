#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp1, *fp2;
    char ch;

    char source_file[100], target_file[100];

    printf("Enter the name of the source file: ");
    scanf("%s", source_file);

    printf("Enter the name of the target file: ");
    scanf("%s", target_file);

    // Open source file in read mode
    fp1 = fopen(source_file, "r");
    if (fp1 == NULL) {
        printf("Error opening source file.\n");
        return 1;
    }

    // Open target file in write mode
    fp2 = fopen(target_file, "w");
    if (fp2 == NULL) {
        printf("Error opening target file.\n");
        fclose(fp1);
        return 1;
    }

    // Copy and convert characters
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(islower(ch) ? toupper(ch) : ch, fp2);
    }

    fclose(fp1);
    fclose(fp2);

    printf("File copied and converted successfully.\n");

    return 0;
}