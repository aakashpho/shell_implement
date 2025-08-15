#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    char* delimeter = " ";
    while (1)
    {
        char* line_data = NULL;
        size_t line_size = 0;
        char** cmd_args = malloc(sizeof(char*) * 10);
        char* token = NULL;
        printf("> ");
        if (getline(&line_data, &line_size,stdin))
        {
            printf("Your Command: %s\n", line_data);
            int pos = 0;
            int n = 1;
            token = strtok(line_data, delimeter);
            while (token != NULL)
            {
                cmd_args[pos] = token;
                pos++;
                token = strtok(NULL, delimeter);
                if (pos >= n*10 - 1)
                {
                    n++;
                    cmd_args = realloc(cmd_args, sizeof(char*) * n * 10);
                }
            }
            cmd_args[pos] = NULL;
        }
        free(line_data);
        free(cmd_args);
    }
    return 0;
}