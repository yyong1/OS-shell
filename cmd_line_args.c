#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// -----> to compile the file 
// -----> gcc cmd_line_args.c -o filename ; ./filename
int main(void)
{
    char *cmd = NULL, *cmd_cpy = NULL, *token = NULL;
    char *delim = " \n";
    size_t n = 0;
    int argc = 0, i = 0;
    char **argv = NULL;

    printf("prompt$ ");

    if (getline(&cmd, &n, stdin) == -1)
        return -1;

    cmd_cpy = strdup(cmd);

    // part just for test

    // while(cmd[i]){
    //     if (cmd[i] == '\n')
    //         printf("\\n ---> Input has %ld characters", strlen(cmd));
    //     else
    //         printf("%c", cmd[i]);
    //     i++;
    // }

    // test
    token = strtok(cmd, delim);
    while (token)
    {
        token = strtok(NULL, delim);
        argc++;
    }

    printf("%d\n", argc);

    return 0;
}