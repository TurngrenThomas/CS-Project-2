//Name: Thomas Turngren
//Date:3/3/22
//class: CS 219
//description: completes hexadecimal operations


#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdint.h>

int main(){

    const std::string filename = "Programming-Project-1.txt";

    std::vector<std::string> operation,stroperand1, stroperand2;
    std::vector<unsigned int> operand1, operand2;
    
    std::ifstream fileReader(filename, std::ios::in);

    while(fileReader.good()){
        
        std::string tempoper;
        std::string tempop1, tempop2;

        unsigned int tempoper1, tempoper2;
        fileReader >> tempoper >> tempop1 >> tempop2;
        stroperand1.push_back(tempop1);
        stroperand2.push_back(tempop2);

        std::istringstream(tempop1) >> std::hex >> tempoper1;
        std::istringstream(tempop2) >> std::hex >> tempoper2;

        operation.push_back(tempoper);
        operand1.push_back(tempoper1);
        operand2.push_back(tempoper2);
        if (fileReader.eof()) break;
    }

    for (int i = 0; operation.size() > i; i++){
        if (operation.at(i) == "ADD"){

            uint32_t total = operand1.at(i) + operand2.at(i);
            std::ostringstream hexoutput;
            hexoutput << std::hex << total;
            std::string result = hexoutput.str();
            std::cout << stroperand1.at(i) << " + " << stroperand2.at(i) << " = 0x" << result << std::endl;

        }
        if (operation.at(i) == "AND"){
            uint32_t total = operand1.at(i) & operand2.at(i);
            std::ostringstream hexoutput;
            hexoutput << std::hex << total;
            std::string result = hexoutput.str();
            std::cout << stroperand1.at(i) << " & " << stroperand2.at(i) << " = 0x" << result << std::endl;
        }
        if (operation.at(i) == "ORR"){
            uint32_t total = operand1.at(i) | operand2.at(i);
            std::ostringstream hexoutput;
            hexoutput << std::hex << total;
            std::string result = hexoutput.str();
            std::cout << stroperand1.at(i) << " | " << stroperand2.at(i) << " = 0x" << result << std::endl;

        }
        if (operation.at(i) == "SUB"){
            uint32_t total = operand1.at(i) - operand2.at(i);
            std::ostringstream hexoutput;
            hexoutput << std::hex << total;
            std::string result = hexoutput.str();
            std::cout << stroperand1.at(i) << " - " << stroperand2.at(i) << " = 0x" << result << std::endl;
        }
        if (operation.at(i) == "ASR"){
            uint32_t total = operand1.at(i);
            for(int i = 0; i < operand2.at(i); i++){
                total = total * 2;
                total = total / 2;
            }
            std::ostringstream hexoutput;
            hexoutput << std::hex << total;
            std::string result = hexoutput.str();
            std::cout << stroperand1.at(i) << " shifted right by " << stroperand2.at(i) << " spaces = 0x" << result << std::endl;
        }
        if (operation.at(i) == "LSR"){
            uint32_t total = operand1.at(i) >> operand2.at(i);
            std::ostringstream hexoutput;
            hexoutput << std::hex << total;
            std::string result = hexoutput.str();
            std::cout << stroperand1.at(i) << " shifted right by " << stroperand2.at(i) << " spaces = 0x" << result << std::endl;
        }
        if (operation.at(i) == "LSL"){
            uint32_t total = operand1.at(i) << operand2.at(i);
            std::ostringstream hexoutput;
            hexoutput << std::hex << total;
            std::string result = hexoutput.str();
            std::cout << stroperand1.at(i) << " shifted left by " << stroperand2.at(i) << " spaces = 0x" << result << std::endl;
        }
        if (operation.at(i) == "NOT"){
            uint32_t total = ~(operand1.at(i));
            std::ostringstream hexoutput;
            hexoutput << std::hex << total;
            std::string result = hexoutput.str();
            std::cout << "~" << stroperand1.at(i) << " = 0x" << result << std::endl;

        }
        if (operation.at(i) == "XOR"){
            uint32_t total = operand1.at(i) ^ operand2.at(i);
            std::ostringstream hexoutput;
            hexoutput << std::hex << total;
            std::string result = hexoutput.str();
            std::cout << stroperand1.at(i) << " ^ " << stroperand2.at(i) << " = 0x" << result << std::endl;

        }

    }
    
    return 0;
}
