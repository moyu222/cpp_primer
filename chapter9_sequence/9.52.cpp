#include <stack>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>

// Placeholder: evaluates a flat expression without parentheses.
// For now, just returns the input string.
std::string calculateStr(const std::string &s)
{
    // Future: implement actual evaluation logic here.
    return s;
}

// Evaluates a fully parenthesized expression.
// Removes parentheses and applies calculateStr to each subexpression.
std::string evalParenthesesExpression(const std::string &expression)
{
    std::stack<char> stk;

    for (char c : expression)
    {
        if (c == ')')
        {
            std::string subexpr;
            while (!stk.empty() && stk.top() != '(')
            {
                subexpr += stk.top();
                stk.pop();
            }

            if (stk.empty())
            {
                std::cerr << "Error: unmatched ')' in expression: " << expression << std::endl;
                return "";
            }

            stk.pop(); // remove '('

            // Reverse and evaluate the subexpression
            std::string reversed(subexpr.rbegin(), subexpr.rend());
            std::string result = calculateStr(reversed);

            // Push result back onto the stack
            for (char rc : result)
                stk.push(rc);
        }
        else
        {
            stk.push(c);
        }
    }

    // Final check for unmatched '('
    std::string final;
    while (!stk.empty())
    {
        if (stk.top() == '(')
        {
            std::cerr << "Error: unmatched '(' in expression: " << expression << std::endl;
            return "";
        }
        final += stk.top();
        stk.pop();
    }

    // Reverse and evaluate the final expression
    std::string reversed(final.rbegin(), final.rend());
    return calculateStr(reversed);
}

int main()
{
    std::vector<std::string> test_cases = {
        "12+34-56-((78-9)+10)",
        "(12+34)-(56-((78-9)+10))",
        "((12+34-(56-10)-1",
        "12+34)-(56-10)-1"
    };

    for (const auto &expr : test_cases)
    {
        std::cout << "Input:    " << expr << std::endl;
        std::string result = evalParenthesesExpression(expr);
        std::cout << "Expanded: " << result << std::endl << std::endl;
    }

    std::cout << "Enter expression: ";
    std::string input;
    std::getline(std::cin, input); // support full line input
    std::string result = evalParenthesesExpression(input);
    std::cout << "Expanded: " << result << std::endl;

    return 0;
}
