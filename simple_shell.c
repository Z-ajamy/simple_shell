#include "simple_shell.h"
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char *find_command(char *command);

int main(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t num_chars;
    pid_t pid;
    int status;
    char **argv = NULL;
    char *path_cmd = NULL;

    while (1)
    {
        printf("($) ");
        num_chars = getline(&line, &len, stdin);
        if (num_chars == -1)
        {
            printf("\n");
            break;
        }

        if (line[0] == '\n')
            continue;

        line[num_chars - 1] = '\0';

        argv = malloc(2 * sizeof(char *));
        if (!argv)
        {
            perror("malloc");
            continue;
        }

        argv[0] = line;
        argv[1] = NULL;

        path_cmd = find_command(line);
        if (!path_cmd)
        {
            fprintf(stderr, "Command not found: %s\n", line);
            free(argv);
            continue;
        }

        pid = fork();
        if (pid < 0)
        {
            perror("fork");
        }
        else if (pid == 0)
        {
            if (execve(path_cmd, argv, environ) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            wait(&status);
        }

        free(argv);
        if (path_cmd != line)
            free(path_cmd);
    }

    free(line);
    return 0;
}

/**
 * find_command - يبحث في PATH عن مسار الأمر الكامل
 */
char *find_command(char *command)
{
    char *path = getenv("PATH");
    char *path_copy = strdup(path);
    char *dir = strtok(path_copy, ":");
    char full_path[1024];

    if (access(command, X_OK) == 0)
    {
        free(path_copy);
        return command;  // المسار الكامل تم إدخاله من البداية
    }

    while (dir)
    {
        snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return strdup(full_path);
        }
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}
