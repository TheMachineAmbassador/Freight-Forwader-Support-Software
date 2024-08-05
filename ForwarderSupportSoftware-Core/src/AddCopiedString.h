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
public:
    void addCopiedTexts();
private:
    bool isOperator(char c);
    bool isNumberOrExpression(const std::string& word);
    double evaluateExpression(const std::string& expression);
    double applyOperator(double a, double b, char op);
public:
    char m_InputBuffer[2048];
    std::string m_ResultStr;
private:
    bool m_UpdateResult = false;

};

#endif // ADDCOPIEDSTRING_H