#include <iostream>
#include <fstream>
#include <vector>

#include "utils.h"

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Not enough arguments!" << std::endl;
        exit(EXIT_FAILURE);
    }

    /// load config
    libconfig::Config cfg;
    uts::loadConfig(argv[1], cfg);

    /// read numbers from file
    const auto readFileName = uts::getCfgPrm<std::string>(cfg, "cfg");
    std::vector<int> inputNumber;
    uts::fillVectorNumbers(readFileName, inputNumber);





    std::cout << "\n\t***END PROGRAM***" << std::endl;
    return 0;
}
