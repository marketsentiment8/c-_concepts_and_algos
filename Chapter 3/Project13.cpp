#include <iostream>

int main() {
    
    for (int thousands = 1; thousands <= 9; thousands++) {
        for (int hundreds = 0; hundreds <= 9; hundreds++) {
            for (int tens = 0; tens <= 9; tens++) {
                for (int ones = 1; ones <= 9; ones += 2) { 
                   
                    if (thousands != hundreds && thousands != tens && thousands != ones
                        && hundreds != tens && hundreds != ones && tens != ones) {
                        
                        if (thousands == 3 * tens) {
                            
                            if (thousands + hundreds + tens + ones == 27) {
                                std::cout << "The address is: " << thousands << hundreds << tens << ones << std::endl;
                                return 0; 
                            }
                        }
                    }
                }
            }
        }
    }
    std::cout << "Address not found!" << std::endl;
    return 0;
}
