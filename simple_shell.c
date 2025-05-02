#include"simple_shell.h"

int main()
{
    char *line = NULL;
    size_t len;
    ssize_t num_chars;
    pid_t pid;
    int ex, a = 98;
    char **argv = NULL;

    while (1)
    {
        printf("%s ", "($)");
        len = 0;
        num_chars = getline(&line, &len, stdin);
        if (num_chars < 0)
        {
            printf("\n");
            break;
        }
        if (line[0] == '\n')
            continue;
        
        line[num_chars - 1] = '\0';
        argv = (char **)malloc(2 * sizeof(char *));
        argv[0] = line;
        argv[1] = NULL;
        pid = fork();

        if (pid > 0)
        {
            wait(&a);
        }
        else if (pid == 0)
        {
            ex = execve(line, argv, NULL);
            if (ex == -1)
            {
                perror("execve faild");
                exit(EXIT_FAILURE);
            }
            free(line);
            free(argv);
            exit(a);
        }
        else
        {
            perror("fork faild");
        }
    }
    free(line);
    free(argv);
    return 0;
}
