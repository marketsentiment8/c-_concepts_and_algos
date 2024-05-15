#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

struct Racer {
    int number;
    std::vector<std::pair<int, std::string>> checkpoints; // pair of sensor ID and timestamp
};

// Function to convert time from HH MM SS format to total seconds
int timeToSeconds(const std::string& timeStr) {
    std::stringstream ss(timeStr);
    int hours, minutes, seconds;
    char colon;
    ss >> hours >> colon >> minutes >> colon >> seconds;
    return hours * 3600 + minutes * 60 + seconds;
}

// Function to calculate time difference in minutes and seconds
std::string calculateTimeDifference(int start, int end) {
    int diffSeconds = end - start;
    int minutes = diffSeconds / 60;
    int seconds = diffSeconds % 60;
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << minutes << ":" << std::setw(2) << std::setfill('0') << seconds;
    return ss.str();
}

// Function to calculate pace in minutes per mile
std::string calculatePace(int start, int end, double distance) {
    double diffMinutes = (end - start) / 60.0;
    double pace = diffMinutes / distance;
    int paceMinutes = static_cast<int>(pace);
    int paceSeconds = static_cast<int>((pace - paceMinutes) * 60);
    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << paceMinutes << ":" << std::setw(2) << std::setfill('0') << paceSeconds;
    return ss.str();
}

int main() {
    std::ifstream inputFile("race_log.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Read gun time
    std::string gunTimeStr;
    std::getline(inputFile, gunTimeStr);
    int gunTime = timeToSeconds(gunTimeStr);

    // Read race log data into vector of racers
    std::vector<Racer> racers;
    std::map<int, std::string> racerNames;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::stringstream ss(line);
        std::string token;
        std::getline(ss, token, ','); // Sensor ID
        int sensorID = std::stoi(token);
        std::getline(ss, token, ','); // Racer number
        int racerNumber = std::stoi(token);
        std::getline(ss, token); // Timestamp
        racers.push_back({racerNumber, {{sensorID, token}}});
    }

    // Sort racers by racer number
    std::sort(racers.begin(), racers.end(), [](const Racer& a, const Racer& b) {
        return a.number < b.number;
    });

    // Process race data for each racer
    int prevCheckpointTime = gunTime;
    double distance = 13.1; // Total distance of the race in miles
    for (size_t i = 0; i < racers.size(); ++i) {
        auto& racer = racers[i];
        // Find race splits and overall time for each racer
        int overallFinishTime = timeToSeconds(racer.checkpoints.back().second);
        int overallTime = overallFinishTime - gunTime;
        std::string overallTimeStr = calculateTimeDifference(gunTime, overallFinishTime);
        std::string overallPace = calculatePace(gunTime, overallFinishTime, distance);

        // Calculate split times and pace for each split
        std::cout << "Racer Number: " << racer.number << std::endl;
        std::cout << "Overall Finish Place: " << i + 1 << std::endl;
        std::cout << "Overall Race Time: " << overallTimeStr << std::endl;
        std::cout << "Overall Race Pace: " << overallPace << " per mile" << std::endl;
        std::cout << "Race Splits:" << std::endl;

        for (size_t j = 0; j < racer.checkpoints.size(); ++j) {
            int checkpointTime = timeToSeconds(racer.checkpoints[j].second);
            int splitTime = checkpointTime - prevCheckpointTime;
            std::string splitTimeStr = calculateTimeDifference(prevCheckpointTime, checkpointTime);
            std::string splitPace = calculatePace(prevCheckpointTime, checkpointTime, (j + 1) * 7.0);
            std::string splitType;
            switch (racer.checkpoints[j].first) {
                case 0:
                    splitType = "Start";
                    break;
                case 1:
                    splitType = "Midpoint";
                    break;
                case 2:
                    splitType = "Finish";
                    break;
            }
            std::cout << "Split " << j + 1 << " (" << splitType << "): " << splitTimeStr << " (" << splitPace << " per mile)" << std::endl;
            prevCheckpointTime = checkpointTime;
        }
        std::cout << std::endl;
    }

    inputFile.close();
    return 0;
}
