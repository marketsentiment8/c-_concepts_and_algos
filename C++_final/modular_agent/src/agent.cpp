#include <iostream>
#include <fstream> // Include for file operations
#include "gpt4_api.hpp"

int main() {
    std::cout << "Starting the modular agent...\n";
    // Call GPT-4 API for generating modified code
    auto [reasoning, modified_code, plugins] = GPT4_API::generate_modified_code();
    std::cout << reasoning << "\n";
    
    // Write the modified code to a file
    std::ofstream file("modified_code.py");
    if (file.is_open()) {
        file << modified_code;
        file.close();
        std::cout << "Modified code written to modified_code.py\n";
    } else {
        std::cerr << "Unable to open file for writing\n";
    }
    
    // Write plugins to separate files
    for (int i = 0; i < plugins.size(); ++i) {
        std::ofstream plugin_file("plugin" + std::to_string(i+1) + ".py");
        if (plugin_file.is_open()) {
            plugin_file << plugins[i];
            plugin_file.close();
            std::cout << "Plugin " << i+1 << " written to plugin" << i+1 << ".py\n";
        } else {
            std::cerr << "Unable to open file for writing plugin" << i+1 << ".py\n";
        }
    }

    // Execute the modified code
    // Add your code for executing the modified code
    return 0;
}
