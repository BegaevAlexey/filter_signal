#ifndef FILTER_SIGNAL_UTILS_H
#define FILTER_SIGNAL_UTILS_H

#include <string>
#include <iostream>
#include <libconfig.h++>
#include <vector>
#include <fstream>
#include <algorithm>

namespace uts
{
    /*!
     * @brief Загрузка конфигурационного файла приложения
     * @param configList[in] Путь до конфиг. файла
     * @param cfg[out] Объект конфигурационного файла
     */
    void loadConfig(const std::string &configList, libconfig::Config &cfg);

    /*!
     * @brief Получение параметра конфиграционного файла
     * @tparam T Тип запрашиваемого параметра
     * @param cfg[in] Объект конфигурационного файла
     * @param sCONF_PARAM[in] Полное имя параметра конфиг файла
     * @return Запрашиваемый параметр
     */
    template<class T>
    T getCfgPrm(libconfig::Config &cfg, const std::string &sCONF_PARAM) {
        T param;
        if (cfg.lookupValue(sCONF_PARAM, param)) {
            std::cout << "[INFO] Param '" << sCONF_PARAM << "': " << param << std::endl;
        } else {
            std::cerr << "[ERROR] No '" << sCONF_PARAM << "' setting in configuration file.\n";
            exit(EXIT_FAILURE);

        }
        return param;
    }

    /*!
     * @brief Получение параметра конфиграционного файла. Если нет параметра, то выдача по-умолчанию параметра
     * @tparam T Тип запрашиваемого параметра
     * @param cfg[in] Объект конфигурационного файла
     * @param sCONF_PARAM[in] Полное имя параметра конфиг файла
     * @param defParam[in] Значение параметра по умалчанию
     * @return Запрашиваемый параметр
     */
    template<class T>
    T getCfgPrmDef(libconfig::Config &cfg, const std::string &sCONF_PARAM, const T &defParam) {
        T param;
        if (cfg.lookupValue(sCONF_PARAM, param)) {
            std::cout << "[INFO] Param '" << sCONF_PARAM << "': " << param << std::endl;
            return param;
        } else {
            std::cerr << "[WARNING] No '" << sCONF_PARAM << "' setting in configuration file.\n";
            return defParam;
        }
    }

    /*!
     * @brief Загрузка значений из файла
     * @param fileName[in] Название файла
     * @param nums[out] Вектор для заполнения
     */
    void fillVectorNumbers(const std::string &fileName, std::vector<int> &nums);

   /*!
    * @brief Запись значений в файл
    * @param fileName[in] Название файла
    * @param nums[in] Вектор с числами
    */
    void writeNum(const std::string &fileName, const std::vector<int> &nums);

    /*!
     * @brief Фильтрация входных значений
     * @param nums[in] Входные данные для фильтрации
     * @param threshold[in] Порог фильтрации
     * @return Отрфильтрованный набор чисел
     */
    template<class T>
    std::vector<T> makeFilter(const std::vector<T> &nums, float threshold = 0.3)
    {
        std::vector<T> filter = nums;
        std::sort(filter.begin(), filter.end());
        T median = filter[filter.size()/2];
        T low    = median - median * threshold;
        T high   = median + median * threshold;
        filter.erase(std::remove_if(filter.begin(), filter.end(), [&](T num)
        {
            return (low > num) && (num > high);
        }), filter.end());

        return filter;
    }

}// namespace uts
#endif //FILTER_SIGNAL_UTILS_H
