#include "utils.h"

void uts::loadConfig(const std::string &configList, libconfig::Config &cfg)
{

    // Read config file
    try
    {
        cfg.readFile(configList.c_str());
    }
    catch(const libconfig::FileIOException &fioex)
    {
        std::cerr << "I/O error while reading file." << std::endl;
        exit(EXIT_FAILURE);
    }
    catch(const libconfig::ParseException &pex)
    {
        std::cerr << "Parse error at " << pex.getFile() << ":" << pex.getLine()
                  << " - " << pex.getError() << std::endl;
        exit(EXIT_FAILURE);
    }
}

void uts::fillVectorNumbers(const std::string &fileName, std::vector<int> &nums)
{
    std::ifstream file(fileName);
    std::string line;
    if (file.is_open())
    {
        while ( getline (file,line) )
        {
            nums.push_back(std::stoi(line));
        }
        file.close();
    }
}
