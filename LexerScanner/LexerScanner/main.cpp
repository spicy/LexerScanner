#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

enum class TokenType
{
    NONE = 0,
    KEYWORD = 1,
    SEPARATOR = 2,
    IDENTIFIER = 3,
    OPERATOR = 4,
    REAL = 5
};


class Token
{
public:
    TokenType type;
    string str;
    Token(TokenType newType, string newStr) : type(newType), str(newStr) { }
};


void lexer()
{
    //Token tokens[];
    regex startsWithKeywordRegex("^while|^if|^int");
    regex startsWithOperatorRegex("^=|^<|^>");
    regex startsWithRealRegex("^[0-9]");
    regex startsWithSeparatorRegex("^(|^)");

    string input;
    std::ifstream myfile("input_scode.txt");

    // Get input from file
    if (myfile.is_open()) {
        while (myfile.good()) {
            myfile >> input;
        }
    }

    string runningInput = input;
    while (true)
    {
        // continue as long as the line string is not empty
        if (runningInput.length() == 0) break;

        //string to be searched
        string mystr = "She sells_sea shells in the sea shore";


        TokenType curTokenType = TokenType::NONE;
        smatch match;
        // check if the line starts with any of the supported keywords, operators, constants, or separators
        if (regex_search(mystr, match, startsWithKeywordRegex))
        {
            curTokenType = TokenType::KEYWORD;
        }
        else if (regex_search(mystr, match, startsWithOperatorRegex))
        {
            curTokenType = TokenType::OPERATOR;
        }
        else if (regex_search(mystr, match, startsWithRealRegex))
        {
            curTokenType = TokenType::REAL;
        }
        else if (regex_search(mystr, match, startsWithSeparatorRegex))
        {
            curTokenType = TokenType::SEPARATOR;
        }
        else
        {
            //maybe?
            curTokenType = TokenType::IDENTIFIER;
        }

        cout << "String that matches the pattern:" << endl;
        for (auto instance : match)
            cout << instance << " ";
    }
}

int main()
{
    lexer();
}


/*
    with open('input_scode.txt', 'r') as fileobj:
        # Remove all spaces then start reading from each line of the file
        filestring = fileobj.read().replace(' ', '')
        while True:
            # continue as long as the line string is not empty
            if filestring == "":
                break

            match = None
            curTokenType = TokenType.NONE

            # check if the line starts with any of the supported keywords, operators, constants, or separators
            if (match := re.search(startsWithKeywordRegex, filestring)) != None:
                curTokenType = TokenType.KEYWORD
                print("KEYWORD")
            elif (match := re.search(startsWithOperatorRegex, filestring)) != None:
                curTokenType = TokenType.OPERATOR
                print("OPERATOR")
            elif (match := re.search(startsWithRealRegex, filestring)) != None:
                curTokenType = TokenType.REAL
                print("REAL")
            elif (match := re.search(startsWithSeparatorRegex, filestring)) != None:
                curTokenType = TokenType.SEPARATOR
                print("SEPARATOR")
            else:
                print("LITERAL?")
                break

            print(match.group(1))
            if match != None and curTokenType != TokenType.NONE:
                # remove whatever matched from the front of the string
                filestring = filestring[match.len():]
                # append the token we found to the running list
                #tokens.append(Token(curTokenType, match))

    # once done, print them all out
    #for token in tokens:
    #    print(token.tokenType + " " + token.str + "\n")
*/
