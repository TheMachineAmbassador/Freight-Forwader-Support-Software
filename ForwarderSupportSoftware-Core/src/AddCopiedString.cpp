#include "AddCopiedString.h"
#include <iomanip>

// TODO make this shitty codes much clear !!!


bool AddCopiedString::isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

double AddCopiedString::applyOperator(double a, double b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    }
    return 0;
}

bool AddCopiedString::isNumberOrExpression(const std::string& word) {
    for (const char c : word) {
        if (!isdigit(c) && c != '.' && c != ',' && !isOperator(c)) {
            return false;
        }
    }
    return true;
}

double AddCopiedString::evaluateExpression(const std::string& expression) {
    std::stack<double> values;
    std::stack<char> operators;

    std::istringstream input(expression);
    char token;
    try {
        while (input >> token) {
            if (isdigit(token)) {
                input.putback(token);
                double value;
                input >> value;
                values.push(value);
            }
            else if (isOperator(token)) {
                while (!operators.empty() && isOperator(operators.top()) &&
                    ((token == '+' || token == '-') || (operators.top() == '*' || operators.top() == '/'))) {
                    if (values.size() < 2) {
                        throw std::runtime_error("Invalid expression");
                    }
                    double b = values.top(); values.pop();
                    double a = values.top(); values.pop();
                    values.push(applyOperator(a, b, operators.top()));
                    operators.pop();
                }
                operators.push(token);
            }
        }
    }
    catch (const std::exception& e) {
        // Ignore any exceptions while reading from the input stream
    }

    while (!operators.empty()) {
        if (values.size() < 2) {
            throw std::runtime_error("Invalid expression");
        }
        double b = values.top(); values.pop();
        double a = values.top(); values.pop();
        values.push(applyOperator(a, b, operators.top()));
        operators.pop();
    }

    if (!values.empty()) {
        return values.top();
    }
    else {
        return 0;
    }
}


void AddCopiedString::addCopiedTexts()
{
    std::string inputText(m_InputBuffer);
    std::istringstream iss(inputText);

    double num;
    double sum = 0;

    std::vector<double> numbers;
    std::vector<std::string> fullText;
    std::string word;
    std::string currentCurrency;

    std::map<std::string, double> lastNumberForCurrency;

    bool inParentheses = false;

    while (iss >> word) {
        // Replace comma with a dot
        std::replace(word.begin(), word.end(), ',', '.');

        if (word.front() == '(') {
            inParentheses = true;
            word = word.substr(1);
        }

        if (word.back() == ')') {
            inParentheses = false;
            word.pop_back();
        }

        if (isNumberOrExpression(word)) {
            try {
                num = evaluateExpression(word);

                if (!inParentheses || (inParentheses && lastNumberForCurrency[currentCurrency] != num)) {
                    numbers.push_back(num);
                    sum += num;
                }

                if (inParentheses) {
                    lastNumberForCurrency[currentCurrency] = num;
                    fullText.push_back("(" + word + " " + currentCurrency + ")");
                }
                else {
                    fullText.push_back(word + " " + currentCurrency);
                }

            }
            catch (...) {
                // Ignore invalid expressions
            }
        }
        else {
            if (!isNumberOrExpression(word)) {
                currentCurrency = word;
            }
            else {
                fullText.push_back(word);
            }
        }
    }

    std::stringstream result_ss;
    result_ss << std::fixed << std::setprecision(2);;  // Force fixed-point notation

    for (size_t i = 0; i < numbers.size(); ++i) {
        result_ss << numbers[i];

        if (i < numbers.size() - 1) {
            result_ss << " + ";
        }
    }
    result_ss << " = " << sum;
    m_ResultStr = result_ss.str();

#if BETA_FULL_TEXT
    std::stringstream fullText_ss;

    for (size_t i = 0; i < fullText.size(); ++i) {
        fullText_ss << fullText[i];

        if (i < fullText.size() - 1) {
            fullText_ss << " + ";
        }
    }
    fullText_ss << " = " << sum;
    fullTextStr = fullText_ss.str();
#endif

    // Reset the updateResult flag after updating the result
    m_UpdateResult = false;
}