#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg) {
    while (1) {
        printf("%s\n", menuTitle);
        for (int i = 0; i < menuSize; ++i)
            printf("%d - %s\n", i, menuOptions[i]);
        printf("%s", inputMsg);
        int selection;
        char c;
        if (scanf("%d%c", &selection, &c) != 2 || c != '\n')
            scanf("%*[^\n]");
        else if (selection >= 0 && selection < menuSize)
            return selection;
    }
}

int main(void) {
    char *options[3] = {"IT", "Discrete Math", "English"};
    printf("Selected %d\n", showMenu("Available lectures", options, 3, "Select lecture: "));
    return 0;
}