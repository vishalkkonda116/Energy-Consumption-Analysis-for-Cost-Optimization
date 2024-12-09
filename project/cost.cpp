#include <iostream>
#include <vector>
#include <string>
#include "utils.h" 

double calculateCost(const std::vector<EnergyData>& data) {
    const double PEAK_RATE = 7.0;   
    const double NON_PEAK_RATE = 4.0; 

    double totalCost = 0.0;

    for (const auto& entry : data) {
        int hour = std::stoi(entry.time.substr(0, 2)); 

        if (hour >= 18 && hour <= 23) { // Peak hours: 18:00 to 23:00
            totalCost += entry.consumption * PEAK_RATE;
        } else { // Non-peak hours
            totalCost += entry.consumption * NON_PEAK_RATE;
        }
    }

    return totalCost;
}


double calculateOptimizedCost(const std::vector<EnergyData>& data) {
    const double PEAK_RATE = 7.0;
    const double NON_PEAK_RATE = 4.0;

    double optimizedCost = 0.0;

    for (const auto& entry : data) {
        int hour = std::stoi(entry.time.substr(0, 2)); 

        if (hour >= 18 && hour <= 23 && entry.consumption > 0.5) {
           
            optimizedCost += (entry.consumption * 0.5) * PEAK_RATE; 
            optimizedCost += (entry.consumption * 0.5) * NON_PEAK_RATE; 
        } else if (hour >= 18 && hour <= 23) {
            optimizedCost += entry.consumption * PEAK_RATE;
        } else {
            optimizedCost += entry.consumption * NON_PEAK_RATE;
        }
    }

    return optimizedCost;
}
