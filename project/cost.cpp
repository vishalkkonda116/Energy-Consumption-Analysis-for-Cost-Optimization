#include <iostream>
#include <vector>
#include <string>
#include "utils.h" // Include the header file where EnergyData is defined

// Function to calculate the current cost based on peak and non-peak rates
double calculateCost(const std::vector<EnergyData>& data) {
    const double PEAK_RATE = 7.0;    // ₹7/kWh for peak hours
    const double NON_PEAK_RATE = 4.0; // ₹4/kWh for non-peak hours

    double totalCost = 0.0;

    for (const auto& entry : data) {
        int hour = std::stoi(entry.time.substr(0, 2)); // Extract hour from "HH:MM"

        if (hour >= 18 && hour <= 23) { // Peak hours: 18:00 to 23:00
            totalCost += entry.consumption * PEAK_RATE;
        } else { // Non-peak hours
            totalCost += entry.consumption * NON_PEAK_RATE;
        }
    }

    return totalCost;
}

// Function to calculate the optimized cost (by shifting usage during peak hours to non-peak)
double calculateOptimizedCost(const std::vector<EnergyData>& data) {
    const double PEAK_RATE = 7.0;
    const double NON_PEAK_RATE = 4.0;

    double optimizedCost = 0.0;

    for (const auto& entry : data) {
        int hour = std::stoi(entry.time.substr(0, 2)); // Extract hour from "HH:MM"

        if (hour >= 18 && hour <= 23 && entry.consumption > 0.5) {
            // Shift 50% of peak consumption to non-peak hours
            optimizedCost += (entry.consumption * 0.5) * PEAK_RATE; // 50% at peak rate
            optimizedCost += (entry.consumption * 0.5) * NON_PEAK_RATE; // 50% at non-peak rate
        } else if (hour >= 18 && hour <= 23) {
            optimizedCost += entry.consumption * PEAK_RATE;
        } else {
            optimizedCost += entry.consumption * NON_PEAK_RATE;
        }
    }

    return optimizedCost;
}
