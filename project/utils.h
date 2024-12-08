#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>

struct EnergyData {
    std::string time;
    double consumption;
};

std::vector<EnergyData> loadCSV(const std::string& filename);
void analyzeData(const std::vector<EnergyData>& data);
void visualizeData(const std::vector<EnergyData>& data);

#endif // UTILS_H
