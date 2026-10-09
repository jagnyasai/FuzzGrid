
#include "ProcessRunner.h"

#include <unistd.h>
#include <sys/wait.h>

#include <cstdio>


ProcessResult ProcessRunner::run(
    const std::string& program,
    const std::string& input
) {
    ProcessResult result;

    int stdin_pipe[2];
    int stdout_pipe[2];

    if (pipe(stdin_pipe) == -1) {
        result.exit_code = -1;
        return result;
    }

    if (pipe(stdout_pipe) == -1) {
        result.exit_code = -1;
        return result;
    }

    pid_t pid = fork();

    if (pid == -1) {
        result.exit_code = -1;
        return result;
    }

    if (pid == 0) {
        // Child process

         dup2(stdin_pipe[0], STDIN_FILENO);
         dup2(stdout_pipe[1], STDOUT_FILENO);
    }
    else {
        // Parent process
    }

    return result;
}