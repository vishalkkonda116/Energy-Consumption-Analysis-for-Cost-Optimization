#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "utils.h"


std::vector<EnergyData> loadCSV(const std::string& filename) {
    std::vector<EnergyData> data;
    std::ifstream file(filename);
    std::string line;

    if (file.is_open()) {
        getline(file, line); 
        while (getline(file, line)) {
            std::stringstream ss(line);
            std::string time;
            double consumption;

            getline(ss, time, ',');
            ss >> consumption;

            data.push_back({time, consumption});
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << "\n";
    }
    return data;
}


void analyzeData(const std::vector<EnergyData>& data) {
    double totalConsumption = 0.0;
    double peakConsumption = 0.0;
    std::string peakTime;

    for (const auto& entry : data) {
        totalConsumption += entry.consumption;
        if (entry.consumption > peakConsumption) {
            peakConsumption = entry.consumption;
            peakTime = entry.time;
        }
    }

    std::cout << "\nData Analysis:\n";
    std::cout << "Total Consumption: " << totalConsumption << " kWh\n";
    std::cout << "Peak Usage: " << peakConsumption << " kWh at " << peakTime << "\n";
}


void visualizeData(const std::vector<EnergyData>& data) {
    std::cout << "\nVisualization (Hourly Usage):\n";
    for (const auto& entry : data) {
        std::cout << entry.time << " | ";
        int bars = static_cast<int>(entry.consumption * 10);
        for (int i = 0; i < bars; ++i) {
            std::cout << "*";
        }
        std::cout << " (" << entry.consumption << " kWh)\n";
    }
}
