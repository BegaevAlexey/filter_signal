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
    const auto readFileName = uts::getCfgPrm<std::string>(cfg, "src");
    std::vector<int> inNums;
    uts::fillVectorNumbers (readFileName, inNums);
    std::cout << "[INFO] In file: " << inNums.size() << std::endl;
    std::vector<int> outNums;
    for(int i=0; i<inNums.size(); i += 10)
    {
        auto first = inNums.begin() + i;
        auto last = first;
        if(i+10 < inNums.size())
        {
            last  = first + 10;
        }
        else
        {
            last = inNums.end();
        }
        std::vector<int> temp(first, last);


        auto tempFilter = uts::makeFilter(temp);

        outNums.insert(outNums.end(), tempFilter.begin(), tempFilter.end());
    }

    /// write result
    std::cout << "[INFO] OUt file: " << outNums.size() << std::endl;
    auto writeFile = uts::getCfgPrmDef<std::string>(cfg, "res", "result.txt");
    uts::writeNum(writeFile, outNums);

    std::cout << "\n\t***END PROGRAM***" << std::endl;
    return 0;
}
