#include <iostream>
#include <array>
#include <fstream>
#include <vector>
#include <cmath>
#include "dec_equation_solve.h"

const FilePath INPUT_FILE_PATH = "..\\files\\input.txt";
const FilePath OUTPUT_FILE_PATH = "..\\files\\output.txt";

Equation readInputEquation(const FilePath& input_path){
    std::ifstream file_read(input_path);

    Equation equation_coefficients{};
    for(auto &coefficient : equation_coefficients)
        file_read >> coefficient;

    file_read.close();
    return equation_coefficients;
}

void printRoots(const std::vector<Root>& roots, const FilePath& output_path){
    std:: ofstream file_write(output_path);

    for(auto root : roots)
        file_write << root << " ";

    file_write.close();
}

std::vector<Root> SolveEquation(Equation coefficients){
    Root discriminant = std::pow(coefficients[1], 2.0f) - 4 * coefficients[0] * coefficients[2];

    std::vector<Root> roots;
    if(discriminant >= 0)
        roots.push_back((-coefficients[1] - std::sqrt(discriminant)) / (2 * coefficients[0]));
    if(discriminant > 0)
        roots.push_back((-coefficients[1] + std::sqrt(discriminant)) / (2 * coefficients[0]));

    return roots;
}

int main() {
    printRoots(SolveEquation(readInputEquation(INPUT_FILE_PATH)), OUTPUT_FILE_PATH);
}