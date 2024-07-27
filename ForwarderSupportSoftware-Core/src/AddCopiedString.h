#ifndef ADDCOPIEDSTRING_H
#define ADDCOPIEDSTRING_H

#include <regex>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <stack>
#include <array>

class AddCopiedString
{
// Variables
private:
    bool updateResult = false;

	
public:
    char inputBuffer[4096];

    // Public member funcs
    void addCopiedTexts();
    std::string resultStr;

// Parmaters, functions
private:
    bool isOperator(char c);
    bool isNumberOrExpression(const std::string& word);
    double evaluateExpression(const std::string& expression);
    double applyOperator(double a, double b, char op);
};

#endif