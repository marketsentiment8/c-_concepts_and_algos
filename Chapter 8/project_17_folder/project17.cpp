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

// Function to detect potential cheating
void detectCheating(const std::vector<Racer>& racers, double distance) {
    std::cout << "Suspected cheaters:" << std::endl;
    for (const auto& racer : racers) {
        bool missedSensor = false;
        bool suspiciousSplit = false;
        int prevCheckpointTime = timeToSeconds(racer.checkpoints[0].second);
        for (size_t i = 1; i < racer.checkpoints.size(); ++i) {
            int checkpointTime = timeToSeconds(racer.checkpoints[i].second);
            int splitTime = checkpointTime - prevCheckpointTime;
            double splitDistance = (i * distance) / (racer.checkpoints.size() - 1);
            std::string splitPace = calculatePace(prevCheckpointTime, checkpointTime, splitDistance);
            if (splitTime < 270) { // Less than 4:30 per mile
                suspiciousSplit = true;
            }
            if (splitTime == 0) { // Missed sensor
                missedSensor = true;
            }
            prevCheckpointTime = checkpointTime;
        }
        if (missedSensor || suspiciousSplit) {
            std::cout << "Racer Number: " << racer.number;
            if (missedSensor) {
                std::cout << " - Missed sensor";
            }
            if (suspiciousSplit) {
                std::cout << " - Suspicious split time";
            }
            std::cout << std::endl;
        }
    }
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

    // Read race log data into vector of racers
    std::vector<Racer> racers;
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

    // Detect cheating
    double distance = 13.1; // Total distance of the race in miles
    detectCheating(racers, distance);

    inputFile.close();
    return 0;
}
