#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

// Struct to store energy data
struct EnergyData {
    std::string time;   // Time in "HH:MM" format
    double consumption; // Energy consumption in kWh
};

// Function prototypes
std::vector<EnergyData> loadCSV(const std::string& filename);
void analyzeData(const std::vector<EnergyData>& data);
void visualizeData(const std::vector<EnergyData>& data);
double calculateCost(const std::vector<EnergyData>& data);
double calculateOptimizedCost(const std::vector<EnergyData>& data);

int main() {
    const std::string filename = "sample_energy_data.csv";

    // Step 1: Load data from CSV
    auto data = loadCSV(filename);
    if (data.empty()) {
        std::cerr << "Failed to load data from " << filename << "\n";
        return 1;
    }

    // Step 2: Analyze data
    analyzeData(data);

    // Step 3: Visualize data
    visualizeData(data);

    // Step 4: Cost analysis
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
