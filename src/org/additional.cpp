#include "org/additional.h"

std::string additional::SelectFolder()
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen("kdialog --getexistingdirectory .", "r"), pclose);

    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }

    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }

    
    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }

    return result;
}

