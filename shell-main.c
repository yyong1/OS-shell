#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>

#define MAX_COMMAND_LEN 100
#define MAX_ARGS 10

// Colors for output
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define RESET "\033[0m"

// Function declarations
void prompt();
int parse_command(char *command, char **args);
void execute_command(char **args);

int main(void) {
    char command[MAX_COMMAND_LEN];
    char *args[MAX_ARGS];

    while (1) {
        prompt(); // Display the prompt
        fgets(command, MAX_COMMAND_LEN, stdin); // Get user input
        if (strcmp(command, "exit\n") == 0) // Exit the shell if user types "exit"
            break;
        if (parse_command(command, args) != -1) // Parse the command and execute it
            execute_command(args);
    }

    return 0;
}

void prompt() {
    char cwd[PATH_MAX];
    if (getcwd(cwd, sizeof(cwd)) != NULL){ // Get current working directory
        char* colors[6] = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN}; // Define colors
        int color_index = 0;
        char *token = strtok(cwd, "/"); // Split cwd into tokens using "/"
        while (token != NULL) {
            printf("%s%s/", colors[color_index], token); // Print token with color
            token = strtok(NULL, "/");
            color_index = (color_index + 1) % 6; // Cycle through colors
        }
        printf("%s $ " RESET, colors[color_index]); // Print prompt with final color
    }else{
        printf("prompt $ ");
    }
}
// Tokonize the command string by spaces (from video tutorial)
int parse_command(char *command, char **args) {
    int i = 0;
    char *token = strtok(command, " \n");
    while (token != NULL && i < MAX_ARGS - 1) { // Parse the command and its arguments
        args[i] = token;
        token = strtok(NULL, " \n");
        i++;
    }
    args[i] = NULL; // Add NULL terminator to the arguments array
    if (i == 0) // Return -1 if no arguments were found
        return -1;
    else
        return 0;
}

void execute_command(char **args) {
    pid_t pid = fork(); // Create a new process
    if (pid == 0) {
        // Child process
        if (strcmp(args[0], "cd") == 0){ // "cd" command
            if (chdir(args[1]) != 0) // Check if changing the directory to the given path was successful
                exit(1);
        } else if (strcmp(args[0], "mv") == 0) { // "mv" command
            if (args[1] != NULL && args[2] != NULL) { // Check if enough arguments provided
                execlp("mv", "mv", args[1], args[2], NULL); // Call system "mv" command with provided arguments
                perror("mv"); // Print error message if system command failed
                exit(1);
            } else {
                printf("Not enough arguments provided for 'mv'\n");
                exit(1);
            }
        } else if (strcmp(args[0], "du") == 0) { // "du" command
            if (args[1] != NULL) { // Check if directory argument provided
                execlp("du", "du", "-sh", args[1], NULL); // Call system "du" command with provided argument
                perror("du"); 
                exit(1);
            } else {
                printf("No directory provided for 'du'\n");
                exit(1);
            }
        } else if (strcmp(args[0], "date") == 0) { // "date" command
            execlp("date", "date", NULL); // Call system "date" command
            perror("date"); 
            exit(1);
        } else if (strcmp(args[0], "rev") == 0) { // "rev" command
            if (access(args[1], R_OK) == 0) { // Reverse values from the file
                execvp(args[0], args);
            } else { // Revers not file input 
                char* str = args[1];
                int length = strlen(str);
                int i, j;
                char temp;
                for (i = 0, j = length - 1; i < j; i++, j--) {
                    temp = str[i];
                    str[i] = str[j];
                    str[j] = temp;
                }
                printf("%s\n", str);
            }
            exit(1);
        } else if (strcmp(args[0], "art") == 0) {
        // To execute this programm you should have .jpg file in derictory
        // witch will be same as for shell-main.c (or type PATH to .jpg 
        // like: /Users/username/myshellProj/burch.jpg). 
        // If you have problem just install (sudo port install jp2a) to your computer
        if (args[1] != NULL) { // Check if directory argument provided
                execlp("jp2a", "jp2a", "--colors", args[1], NULL); // Call "jp2a" command with provided argument
                perror("jp2a"); 
                exit(1);
            } else {
                printf("No file provided for 'jp2a'\n");
                exit(1);
            }
        } else {
            execvp(args[0], args);
            printf("Command not found: %s\n", args[0]);
            exit(1);
        }

    } else if (pid > 0) {
        // Parent process
        int status;
        waitpid(pid, &status, 0); // Wait for child process to complete
    } else {
        printf("Failed to create child process\n");
    }
}

