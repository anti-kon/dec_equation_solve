#include <iostream>
#include <array>
#include <fstream>
#include <vector>
#include <cmath>

typedef struct {std::string path; std::string getPath() const {return path;}} FilePath;

const FilePath input_file_path = {"..\\files\\input.txt"};
const FilePath output_file_path = {"..\\files\\output.txt"};

std::array<float, 3> readInputEquation(const FilePath& input_path){
    std::ifstream file_read(input_path.getPath());

    std::array<float, 3> equation_coefficients{};
    for(auto &coefficient : equation_coefficients)
        file_read >> coefficient;

    file_read.close();
    return equation_coefficients;
}

void printRoots(const std::vector<float>& roots, const FilePath& output_path){
    std:: ofstream file_write(output_path.getPath());

    for(auto root : roots)
        file_write << root << " ";

    file_write.close();
}

std::vector<float> SolveEquation(std::array<float, 3> coefficients){
    float discriminant = std::pow(coefficients[1], 2.0f) - 4 * coefficients[0] * coefficients[2];

    std::vector<float> roots;
    if(discriminant >= 0)
        roots.push_back((-coefficients[1] - std::sqrt(discriminant)) / (2 * coefficients[0]));
    if(discriminant > 0)
        roots.push_back((-coefficients[1] + std::sqrt(discriminant)) / (2 * coefficients[0]));

    return roots;
}

int main() {
    printRoots(SolveEquation(readInputEquation(input_file_path)), output_file_path);
}