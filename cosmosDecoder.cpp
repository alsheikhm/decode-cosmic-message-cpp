// Mohammed Al-Sheikh
// cosmosDecoder.cpp

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cctype>

// Print function using vector string parameter
void print(const std::vector<std::string>& vector)
{
    for(std::string string : vector)
    {
        std::cout << string << std::endl;
    }
    
    std::cout << std::endl;
}

int main()
{
    std::vector<std::string> code;
    
    // Reading from the input file "signal.txt"
    std::ifstream signalFile("signal.txt");
    
    // Checks if file was properly opened, display error message and return 1 if failed
    if(!signalFile.is_open())
    {
        std::cout << "Error Opening Signal File 'signal.txt'" << std::endl << std::endl;
        return 1;
    }
    
    // Converts every byte in each line of text file to an ASCII character, then pushes string to vector
    std::string binary;
    while(std::getline(signalFile, binary))
    {
        std::string binaryToASCII;
        
        for(int i = 0; (i + 7) < binary.size(); i += 8)
        {
            int asciiValue = 0;
            std::string byte = binary.substr(i, 8);
            
            for(int j = 0; j < 8; j++)
            {
                asciiValue = (asciiValue * 2) + (byte[j] - '0');
            }
            
            char c = static_cast<char>(asciiValue);
            binaryToASCII += c;
        }
        
        code.push_back(binaryToASCII);
    }
    
    print(code);
    
    // Filters in only every third character starting from second character in each string of the vector
    for(std::string& string : code)
    {
        std::string filterThird = "";
        for(int i = 1; i < static_cast<int>(string.length()); i += 3)
        {
            filterThird += string[i];
        }
        
        string = filterThird;
    }
    
    print(code);
    
    // Filters in only letter and number characters in each string of the vector
    for(std::string& string : code)
    {
        std::string filterAlNum = "";
        for(int i = 0; i < static_cast<int>(string.length()); ++i)
        {
            if(isalnum(string[i]))
            {
                filterAlNum += string[i];
            }
        }
        
        string = filterAlNum;
    }
    
    print(code);
    
    // Reverses each string in the vector
    for(std::string& string : code)
    {
        reverse(string.begin(), string.end());
    }
    
    print(code);
    
    // Builds then displays final decoded message by pieceing together each string in the vector
    std::string finalMessage = "";
    for(std::string string : code)
    {
        finalMessage += string;
    }
    
    std::cout << finalMessage << std::endl << std::endl;
    
    signalFile.close();
    
    return 0;
}
