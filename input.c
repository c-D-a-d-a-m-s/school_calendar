#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//function prototypes

void get_user_input(char *prompt, char **user_input_dptr);

int main() {

    char *str_ptr = NULL;

    while (true) {
        get_user_input("Enter input.\n", &str_ptr);
        printf("\nYou entered: %s\n", str_ptr);
    }

    return 0;
}
void get_user_input(char *prompt, char **user_input_dptr) {
    int stdin_drain = 0;
    bool invalid_input = true;
    const size_t MAX_USER_INPUT = 100;

    do {
        char *temp_str_ptr = (char*) calloc(MAX_USER_INPUT, sizeof(char));
        fputs(prompt, stdout);
        fputs("\033[38;2;254;254;0;1ms_cal-$ \033[0m", stdout);
        fgets(temp_str_ptr, MAX_USER_INPUT, stdin);

        for (size_t i = 0; i < MAX_USER_INPUT; i++) {
            if (*(temp_str_ptr + i) == '\n') {
                *(temp_str_ptr + i) = '\0';
                *user_input_dptr = (char*) calloc(i + 1, sizeof(char));
                strcpy(*user_input_dptr, temp_str_ptr);
                invalid_input = false;
                break;
            }
            if (i == MAX_USER_INPUT - 1 && i != EOF) {
                do
                    stdin_drain = getchar();
                while (stdin_drain != EOF && stdin_drain != '\n' );
                clearerr(stdin);

                fputs("\033[38;2;254;0;0;1mERROR: User input exceeds maximum character limit.\033[0m\n\n", stdout);
            }
        }
        free(temp_str_ptr);
        temp_str_ptr = NULL;
    } while (invalid_input);
}