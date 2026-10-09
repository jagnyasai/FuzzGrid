#pragma once

#include "ProcessResult.h"

#include <string>

class ProcessRunner
{
public:
     ProcessResult run(
        const std::string& program,
        const std::string& input
    );
};


