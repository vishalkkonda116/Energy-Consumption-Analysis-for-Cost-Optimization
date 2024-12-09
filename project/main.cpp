#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>


struct EnergyData {
    std::string time;  
    double consumption; 
};


std::vector<EnergyData> loadCSV(const std::string& filename);
void analyzeData(const std::vector<EnergyData>& data);
void visualizeData(const std::vector<EnergyData>& data);
double calculateCost(const std::vector<EnergyData>& data);
double calculateOptimizedCost(const std::vector<EnergyData>& data);

int main() {
    const std::string filename = "sample_energy_data.csv";

   
    auto data = loadCSV(filename);
    if (data.empty()) {
        std::cerr << "Failed to load data from " << filename << "\n";
        return 1;
    }
    analyzeData(data);
    visualizeData(data);


    double currentCost = calculateCost(data);
    double optimizedCost = calculateOptimizedCost(data);

    std::cout << "\nCost Analysis:\n";
    std::cout << "Current Cost: ₹" << currentCost << "\n";
    std::cout << "Optimized Cost: ₹" << optimizedCost << "\n";

    if (optimizedCost < currentCost) {
        std::cout << "Recommendation: Shift part of the peak hour usage to non-peak hours to save ₹"
                  << (currentCost - optimizedCost) << ".\n";
    } else {
        std::cout << "Recommendation: No further cost optimization possible.\n";
    }

    return 0;
}
