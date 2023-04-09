#include <iostream>
#include <regex>
#include <fstream>
#include <vector>
#include <list>
#include <filesystem>

using namespace std;

enum class TokenType
{
    NONE,
    KEYWORD,
    SEPARATOR,
    IDENTIFIER,
    OPERATOR,
    REAL
};


class Token
{
public:
    TokenType type;
    string match;
    Token(TokenType newType, string newMatch) : type(newType), match(newMatch) { }
    Token() : type(TokenType::NONE), match("") { }
};

Token greedilyGetNextToken(string input)
{
    string largestMatch;
    TokenType largestMatchType = TokenType::NONE;

    // Try to match all lexing cases at the start of the input.
    smatch keywordMatch;
    regex startsWithKeywordRegex("^while|^if|^float|^double|^int|^string");
    if (regex_search(input, keywordMatch, startsWithKeywordRegex))
    {
        if (keywordMatch.length() > largestMatch.length())
        {
            largestMatch = keywordMatch[0];
            largestMatchType = TokenType::KEYWORD;
        }
    }

    smatch operatorMatch;
    regex startsWithOperatorRegex("^[=]|^[<]|^[>]");
    if (regex_search(input, operatorMatch, startsWithOperatorRegex))
    {
        if (operatorMatch.length() > largestMatch.length())
        {
            largestMatch = operatorMatch[0];
            largestMatchType = TokenType::OPERATOR;
        }
    }

    smatch realMatch;
    regex startsWithRealRegex("^[-+]?[0-9]*\.?[0-9]+");
    if (regex_search(input, realMatch, startsWithRealRegex))
    {
        if (realMatch.length() > largestMatch.length())
        {
            largestMatch = realMatch[0];
            largestMatchType = TokenType::REAL;
        }
    }

    smatch separatorMatch;
    regex startsWithSeparatorRegex("^[(]|^[)]|^[;]");
    if (regex_search(input, separatorMatch, startsWithSeparatorRegex))
    {
        if (separatorMatch.length() > largestMatch.length())
        {
            largestMatch = separatorMatch[0];
            largestMatchType = TokenType::SEPARATOR;
        }
    }

    smatch identifierMatch;
    // no space
    regex startsWithIdentifierRegex("^[_A-Za-z]+");
    if (regex_search(input, identifierMatch, startsWithIdentifierRegex))
    {
        if (identifierMatch.length() > largestMatch.length())
        {
            largestMatch = identifierMatch[0];
            largestMatchType = TokenType::IDENTIFIER;
        }
    }

    if (largestMatchType == TokenType::NONE || largestMatch.empty()) return Token(TokenType::NONE, "Error");;

    return Token(largestMatchType, largestMatch);
}

inline const char* TypeToString(TokenType type)
{
    switch (type)
    {
    case TokenType::NONE:       return "NONE";
    case TokenType::KEYWORD:    return "keyword";
    case TokenType::SEPARATOR:  return "separator";
    case TokenType::IDENTIFIER: return "identifier";
    case TokenType::OPERATOR:   return "operator";
    case TokenType::REAL:       return "real";
    default:                    return "UNKNOWN";
    }
}

void lexer()
{
    list<Token> tokens;

    string input;
    std::ifstream myfile("input_scode.txt");
    // Get input from file
    if (myfile.is_open()) {
        while (myfile.good()) {
            myfile >> input;

            string runningInput = input;
            while (true)
            {
                // continue as long as the line string is not empty
                if (runningInput.length() == 0) break;

                Token token = greedilyGetNextToken(runningInput);
                if (token.type == TokenType::NONE || token.match == "")
                {
                    cout << "Error when getting next token.\n\n";
                    break;
                }

                tokens.push_back(token);

                int numToRemoveFromFront = token.match.length();
                runningInput.erase(0, numToRemoveFromFront);
            }
        }

        std::ofstream outfile("output.txt");

         if ( outfile.is_open() ) 
         {
            for (Token token : tokens)
            {            
                outfile << TypeToString(token.type) << "         '" << token.match << "'" << endl;
            }
            
        }
        //    cout << TypeToString(token.type) << "         '" << token.match << "'" << endl;
        outfile.close();
        
    }
}


int main()
{
    lexer();
}
