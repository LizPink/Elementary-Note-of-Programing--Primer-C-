#include <fstream>
#include <iostream>

void loadFromFile(const std::string& filename)
{
    std::ifstream fin(filename);
    std::string temp;

    while(fin >> temp)
    {
        std::cout << temp << "\n";
    }
}

int main(int argc, char *argv[])
{
    loadFromFile("student.txt");

    return 0;
}