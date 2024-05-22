#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>

struct Time {
    int hours;
    int minutes;
    int seconds;
    
    Time() : hours(0), minutes(0), seconds(0) {}
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}
    
    int toSeconds() const {
        return hours * 3600 + minutes * 60 + seconds;
    }
    
    static Time fromSeconds(int totalSeconds) {
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;
        return Time(h, m, s);
    }
    
    Time operator-(const Time& other) const {
        return Time::fromSeconds(this->toSeconds() - other.toSeconds());
    }
    
    friend std::istream& operator>>(std::istream& is, Time& t) {
        is >> t.hours >> t.minutes >> t.seconds;
        return is;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Time& t) {
        os << std::setw(2) << std::setfill('0') << t.hours << ":"
           << std::setw(2) << std::setfill('0') << t.minutes << ":"
           << std::setw(2) << std::setfill('0') << t.seconds;
        return os;
    }
};

struct SensorData {
    int sensorID;
    int racerNumber;
    Time timestamp;
};

struct RacerInfo {
    int number;
    Time startTime;
    Time midTime;
    Time endTime;
    bool hasStart = false;
    bool hasMid = false;
    bool hasEnd = false;
};

void loadRaceData(const std::string& filename, std::vector<SensorData>& data, Time& gunTime) {
    std::ifstream file(filename);
    std::string line;
    
    std::getline(file, line);
    std::istringstream ss(line);
    ss >> gunTime;
    
    while (std::getline(file, line)) {
        SensorData entry;
        char comma;
        std::istringstream ss(line);
        ss >> entry.sensorID >> comma >> entry.racerNumber >> comma >> entry.timestamp;
        data.push_back(entry);
    }
}

int calculateSplitTime(const Time& start, const Time& end) {
    return (end - start).toSeconds();
}

double calculatePace(int seconds, double distance) {
    return static_cast<double>(seconds) / 60.0 / distance;
}

void detectCheaters(const std::map<int, RacerInfo>& racers) {
    const double maxAllowedPace = 4.5; // 4:30 per mile

    for (const auto& [number, racer] : racers) {
        if (!racer.hasStart || !racer.hasMid || !racer.hasEnd) {
            std::cout << "Racer " << number << " missed a sensor checkpoint." << std::endl;
        } else {
            int startToMid = calculateSplitTime(racer.startTime, racer.midTime);
            int midToEnd = calculateSplitTime(racer.midTime, racer.endTime);
            
            double pace1 = calculatePace(startToMid, 7.0);
            double pace2 = calculatePace(midToEnd, 6.1);
            
            if (pace1 < maxAllowedPace) {
                std::cout << "Racer " << number << " has a suspiciously fast split time for the first half: " << pace1 << " min/mile." << std::endl;
            }
            if (pace2 < maxAllowedPace) {
                std::cout << "Racer " << number << " has a suspiciously fast split time for the second half: " << pace2 << " min/mile." << std::endl;
            }
        }
    }
}

int main() {
    std::string filename = "race_log.txt";
    Time gunTime;
    std::vector<SensorData> data;
    loadRaceData(filename, data, gunTime);
    
    std::map<int, RacerInfo> racers;
    
    for (const auto& entry : data) {
        if (racers.find(entry.racerNumber) == racers.end()) {
            racers[entry.racerNumber] = RacerInfo{entry.racerNumber};
        }
        
        if (entry.sensorID == 0) {
            racers[entry.racerNumber].startTime = entry.timestamp;
            racers[entry.racerNumber].hasStart = true;
        } else if (entry.sensorID == 1) {
            racers[entry.racerNumber].midTime = entry.timestamp;
            racers[entry.racerNumber].hasMid = true;
        } else if (entry.sensorID == 2) {
            racers[entry.racerNumber].endTime = entry.timestamp;
            racers[entry.racerNumber].hasEnd = true;
        }
    }
    
    detectCheaters(racers);
    
    return 0;
}
