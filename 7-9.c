#include <stdio.h>

void showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg, void (*callbacks[])()) {
    while (1) {
        printf("%s\n", menuTitle);
        for (int i = 0; i < menuSize; ++i)
            printf("%d - %s\n", i, menuOptions[i]);
        printf("%s", inputMsg);
        int selection;
        char c;
        if (scanf("%d%c", &selection, &c) != 2 || c != '\n')
            scanf("%*[^\n]");
        else if (selection >= 0 && selection < menuSize) {
            callbacks[selection]();
            return;
        }
    }
}

void printHello() {
    printf("Hello, Charlz\n");
}

void printCongrats() {
    printf("Congratulations!\n");
}

void printCondolences() {
    printf("My condolences...\n");
}

int main(void) {
    char *options[3] = {"IT", "Discrete Math", "English"};
    void (*callbacks[])() = {printHello, printCongrats, printCondolences};
    showMenu("Available lectures", options, 3, "Select lecture: ", callbacks);
    return 0;
}