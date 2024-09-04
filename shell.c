#include <stdio.h>    // Standard I/O library
#include <stdlib.h>   // Standard library for memory allocation, process control, etc.
#include <string.h>   // String manipulation functions
#include <unistd.h>   // POSIX operating system API for system calls
#include <sys/types.h> // Defines types used in system calls
#include <sys/wait.h> // Declarations for waiting functions

// Function declarations for built-in shell commands
int cd(char **args);
int help(char **args);
int shell_exit(char **args);

// List of built-in commands, followed by their corresponding functions.
char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

// Array of function pointers for built-in commands
int (*builtin_func[]) (char **) = {
    &cd,
    &help,
    &shell_exit
};

// Function to return the number of built-in commands
int num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

// Built-in function implementation for the 'cd' command
int cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "Expected argument to \"cd\"\n"); // Print error if no argument provided
    } else {
        if (chdir(args[1]) != 0) { // Change directory to the path specified in args[1]
            perror("cd"); // Print error if chdir fails
        }
    }
    return 1;
}

// Built-in function implementation for the 'help' command
int help(char **args) {
    int i;
    printf("Simple Shell\n");
    printf("Type program names and arguments, and hit enter.\n");
    printf("The following are built in:\n");

    for (i = 0; i < num_builtins(); i++) {
        printf("  %s\n", builtin_str[i]); // Print list of built-in commands
    }

    printf("Use the man command for information on other programs.\n");
    return 1;
}

// Built-in function implementation for the 'exit' command
int shell_exit(char **args) {
    return 0; // Return 0 to indicate shell should terminate
}

// Function to launch a program
int launch(char **args) {
    pid_t pid, wpid;
    int status;

    pid = fork(); // Fork a new process
    if (pid == 0) {
        // Child process
        if (execvp(args[0], args) == -1) { // Replace child process with new program
            perror("execvp"); // Print error if execvp fails
        }
        exit(EXIT_FAILURE); // Exit child process if execvp fails
    } else if (pid < 0) {
        // Error forking
        perror("fork"); // Print error if fork fails
    } else {
        // Parent process
        do {
            wpid = waitpid(pid, &status, WUNTRACED); // Wait for child process to change state
        } while (!WIFEXITED(status) && !WIFSIGNALED(status)); // Continue waiting while child is not exited or signaled
    }

    return 1; // Return 1 to continue execution of the shell
}

// Function to execute shell built-in or launch program
int execute(char **args) {
    int i;

    if (args[0] == NULL) {
        // An empty command was entered
        return 1; // Return 1 to continue execution of the shell
    }

    for (i = 0; i < num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args); // Execute built-in command
        }
    }

    return launch(args); // Launch program if not a built-in command
}

// Function to read a line of input from stdin
char *read_line(void) {
    char *line = NULL;
    ssize_t bufsize = 0; // getline() allocates buffer
    getline(&line, &bufsize, stdin); // Read line from stdin
    return line; // Return the line read
}

// Function to split a line into tokens (very naively)
#define LSH_TOK_BUFSIZE 64
#define LSH_TOK_DELIM " \t\r\n\a"
char **split_line(char *line) {
    int bufsize = LSH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*)); // Allocate buffer for tokens
    char *token;

    if (!tokens) {
        fprintf(stderr, "allocation error\n"); // Print error if allocation fails
        exit(EXIT_FAILURE); // Exit if allocation fails
    }

    token = strtok(line, LSH_TOK_DELIM); // Get the first token
    while (token != NULL) {
        tokens[position] = token; // Add token to the array
        position++;

        if (position >= bufsize) {
            bufsize += LSH_TOK_BUFSIZE; // Increase buffer size
            tokens = realloc(tokens, bufsize * sizeof(char*)); // Reallocate buffer
            if (!tokens) {
                fprintf(stderr, "allocation error\n"); // Print error if reallocation fails
                exit(EXIT_FAILURE); // Exit if reallocation fails
            }
        }

        token = strtok(NULL, LSH_TOK_DELIM); // Get the next token
    }
    tokens[position] = NULL; // Null-terminate the array of tokens
    return tokens; // Return the array of tokens
}

// Main loop where the shell repeatedly reads input, parses it, and executes it
void shell_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("> "); // Print prompt
        line = read_line(); // Read input line
        args = split_line(line); // Split input line into tokens
        status = execute(args); // Execute the command

        free(line); // Free the input line
        free(args); // Free the array of tokens
    } while (status); // Continue until the shell_exit command is executed
}

int main(int argc, char **argv) {
    // Load config files, if any.

    // Run command loop.
    shell_loop(); // Start the main loop

    // Perform any shutdown/cleanup.

    return EXIT_SUCCESS; // Exit successfully
}
