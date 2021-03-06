#pragma once

#include "XPLMUtilities.h"

#include <functional>
#include <string>

class CommandProvider {
    XPLMCommandRef cr = nullptr;

    // handle the command. Return true if handled, false if somebody else should handle this. 
    std::function<bool(void)> begin_func;
    std::function<bool(void)> continue_func;
    std::function<bool(void)> end_func;

    static int handler( XPLMCommandRef inCommand, XPLMCommandPhase inPhase, void * inRefcon);
public:
    CommandProvider(std::string name, std::string description, std::function<bool(void)> func) : CommandProvider(name, description, {}, {}, func) {}
    CommandProvider(std::string name, std::string description, std::function<bool(void)> begin_func, std::function<bool(void)> continue_func, std::function<bool(void)> end_func);
    ~CommandProvider();
};
