#include <iostream>

#include "process/ProcessRunner.h"

int main() {
    ProcessRunner runner;

    ProcessResult result = runner.run("echo Hello from child process", "");

    std::cout << "Child process output:\n";
    std::cout << result.stdout_output;

    std::cout << "Exit code: "
              << result.exit_code
              << std::endl;

    return 0;
}