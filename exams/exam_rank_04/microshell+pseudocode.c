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

    // 0. fd에 STDIN_FILENO를 복사
    ms_system_call(fd = dup(STDIN_FILENO));
    idx = 0;
    while (argv[idx] && argv[idx + 1]) {
        // 1. argv 세팅 (맨 처음의 경우 argv[0]는 프로그램 이름이므로 그 다음을, 그 외의 경우 ";" 또는 "|" 다음을 가리키게 하기 위함)
        argv = &argv[idx + 1];
        // 2. 문자열 끝 또는 ";" 또는 "|"를 만날 때까지 인덱스 밀기
        idx = 0; // ⭐️
        while (argv[idx] && strcmp(argv[idx], ";") && strcmp(argv[idx], "|"))
            idx++;
        // 3. cd인지 확인
        if (strcmp(argv[0], "cd") == 0) {
            // 3-1. cd의 인자가 1개가 아니라면 오류 출력
            if (idx != 2)
                ms_error("error: cd: bad arguments", NULL);
            // 3-2. cd 실행, 실패하면 오류 출력
            else if (chdir(argv[1]))
                ms_error("error: cd: cannot change directory to ", argv[1]);
        }
        // 4. 마지막 명령어 또는 ";"를 만났을 때
        else if (idx != 0 && (argv[idx] == NULL || strcmp(argv[idx], ";") == 0)) {
            // 4-1. fork
            ms_system_call(pid = fork());
            // 4-2. 자식 프로세스: 명령어 실행, 실패하면 오류 출력
            if (pid == 0) {
                ms_execute(argv, idx, fd, envp);
            }
            // 4-3. 부모 프로세스: waitpid, fd에 STDIN_FILENO 복사
            else {
                ms_system_call(waitpid(pid, NULL, 0));
                ms_system_call(close(fd));
                ms_system_call(fd = dup(STDIN_FILENO));
            }
        }
        // 5. "|"를 만났을 때
        else if (idx != 0 && strcmp(argv[idx], "|") == 0) {
            // 5-1. pipe
            ms_system_call(pipe(pipe_fd));
            // 5-2. fork
            ms_system_call(pid = fork());
            // 5-3. 자식 프로세스: pipe_fd[1]을 출력으로 설정, 안쓰는 fd 닫아주기, 명령어 실행, 실패하면 오류 출력
            if (pid == 0) {
                ms_system_call(dup2(pipe_fd[1], STDOUT_FILENO));
                ms_system_call(close(pipe_fd[0]));
                ms_system_call(close(pipe_fd[1]));
                ms_execute(argv, idx, fd, envp);
            }
            // 5-4. 부모 프로세스: waitpid, 안쓰는 fd 닫아주기, fd에 pipe_fd[0] 저장
            else {
                ms_system_call(waitpid(pid, NULL, 0));
                ms_system_call(close(pipe_fd[1]));
                ms_system_call(close(fd));
                fd = pipe_fd[0];
            }
        }
    }
    // 6. fd 닫아주기
    close(fd);
    exit(0);
}

static int ft_strlen(char *str) {
    int len = 0;

    while (str[len])
        len++;
    return (len);
}

// write, close, fork, waitpid, dup, dup2, pipe 등 시스템 호출 함수 사용 시 필요한 함수
static void ms_system_call(int result) {
    if (result == -1) {
        ms_error("error: fatal", NULL);
        exit(1);
    }
}

// 에러를 출력하는 함수
static void ms_error(char *message, char *blame) {
    ms_system_call(write(STDERR_FILENO, message, ft_strlen(message)));
    if (blame)
        ms_system_call(write(STDERR_FILENO, blame, ft_strlen(blame)));
    ms_system_call(write(STDERR_FILENO, "\n", 1));
}

// in_fd를 STDIN에 복사하고 명령어를 실행하는 함수
static void ms_execute(char **argv, int idx, int in_fd, char **envp) {
    argv[idx] = NULL;
    ms_system_call(dup2(in_fd, STDIN_FILENO));
    ms_system_call(close(in_fd));
    execve(argv[0], argv, envp);
    ms_error("error: cannot execute ", argv[0]);
}