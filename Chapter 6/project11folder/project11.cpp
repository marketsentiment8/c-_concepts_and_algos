#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

void createBarChart(const std::vector<int>& values, const std::string& filename) {
    const int width = 500;
    const int height = 500;
    const int maxBarHeight = 400;
    const int barWidth = 50;
    const int barSpacing = 20;

    int maxValue = *std::max_element(values.begin(), values.end());
    if (maxValue == 0) {
        maxValue = 1; // Avoid division by zero
    }

    std::ofstream svgFile(filename);
    svgFile << "<?xml version=\"1.0\" standalone=\"no\"?>\n";
    svgFile << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n";
    svgFile << "<svg width=\"" << width << "\" height=\"" << height << "\" xmlns=\"http://www.w3.org/2000/svg\">\n";

    for (size_t i = 0; i < values.size(); ++i) {
        int barHeight = static_cast<int>(static_cast<double>(values[i]) / maxValue * maxBarHeight);
        int x = i * (barWidth + barSpacing) + barSpacing;
        int y = height - barHeight;

        svgFile << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << barWidth << "\" height=\"" << barHeight
                << "\" style=\"fill:blue;\"/>\n";
    }

    svgFile << "</svg>\n";
    svgFile.close();
}

int main() {
    std::vector<int> values(4);
    std::cout << "Enter four nonnegative integer values:\n";
    for (int& value : values) {
        std::cin >> value;
    }

    createBarChart(values, "barchart.svg");

    std::cout << "SVG file 'barchart.svg' created successfully.\n";
    return 0;
}
