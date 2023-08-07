#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

static int ft_strlen(char *str);
static void ms_system_call(int result);
static void ms_error(char *message, char *blame);
static void ms_execute(char **argv, int idx, int fd, char **envp);

int main(int argc, char **argv, char **envp) {
    int     idx, pid, fd;
    int     pipe_fd[2];
    (void)  argc;

    ms_system_call(fd = dup(STDIN_FILENO));
    idx = 0;
    while (argv[idx] && argv[idx + 1]) {
        argv = &argv[idx + 1];
        idx = 0;
        while (argv[idx] && strcmp(argv[idx], ";") && strcmp(argv[idx], "|"))
            idx++;
        if (strcmp(argv[0], "cd") == 0) {
            if (idx != 2)
                ms_error("error: cd: bad arguments", NULL);
            else if (chdir(argv[1]))
                ms_error("error: cd: cannot change directory to ", argv[1]);
        } else if (idx != 0 && (argv[idx] == NULL || strcmp(argv[idx], ";") == 0)) {
            ms_system_call(pid = fork());
            if (pid == 0) {
                ms_execute(argv, idx, fd, envp);
            } else {
                ms_system_call(waitpid(pid, NULL, 0));
                ms_system_call(close(fd));
                ms_system_call(fd = dup(STDIN_FILENO));
            }
        } else if (idx != 0 && strcmp(argv[idx], "|") == 0) {
            ms_system_call(pipe(pipe_fd));
            ms_system_call(pid = fork());
            if (pid == 0) {
                ms_system_call(dup2(pipe_fd[1], STDOUT_FILENO));
                ms_system_call(close(pipe_fd[0]));
                ms_system_call(close(pipe_fd[1]));
                ms_execute(argv, idx, fd, envp);
            } else {
                ms_system_call(waitpid(pid, NULL, 0));
                ms_system_call(close(pipe_fd[1]));
                ms_system_call(close(fd));
                fd = pipe_fd[0];
            }
        }
    }
    close(fd);
    exit(0);
}

static int ft_strlen(char *str) {
    int len = 0;

    while (str[len])
        len++;
    return (len);
}

static void ms_system_call(int result) {
    if (result == -1) {
        ms_error("error: fatal", NULL);
        exit(1);
    }
}

static void ms_error(char *message, char *blame) {
    ms_system_call(write(STDERR_FILENO, message, ft_strlen(message)));
    if (blame)
        ms_system_call(write(STDERR_FILENO, blame, ft_strlen(blame)));
    ms_system_call(write(STDERR_FILENO, "\n", 1));
}

static void ms_execute(char **argv, int idx, int in_fd, char **envp) {
    argv[idx] = NULL;
    ms_system_call(dup2(in_fd, STDIN_FILENO));
    ms_system_call(close(in_fd));
    execve(argv[0], argv, envp);
    ms_error("error: cannot execute ", argv[0]);
}