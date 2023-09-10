#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

/// <summary>
/// Please remove any trailing whitespaces within the text file.
/// </summary>
/// <returns>Returns the dumped config space of a PCI device grouped by dword.</returns>

int main() {
    std::ifstream input_file("config_space.txt");
    std::ofstream output_file("output_dword_config_space.txt");
    std::string line;
    int i = 1;

    while (std::getline(input_file, line)) 
    {
        // Hinder the first line from being printed
        if (i != 1) 
        {
            std::string dword = line.substr(line.find(":") + 2);
            dword.erase(std::remove_if(dword.begin(), dword.end(), ::isspace), dword.end());

            // Replace every 8 characters with a comma
            for (size_t j = 8; j < dword.length(); j += 9) 
            {
                dword.insert(j, ",");
            }

            std::cout << dword << std::endl;
            output_file << dword << std::endl;
        }
        i++;
    }

    input_file.close();
    output_file.close();
    return 0;
}
