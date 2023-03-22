#output:
    #keyword while
    #separator (
    #identifier t
    #operator <
    #identifier lower
    #separator )
    #identifier r
    #operator =
    #real 28.00
    #separator ;


###################################################################################################
###################################################################################################

import re
from enum import Enum

class TokenType(Enum):
    NONE = 0
    KEYWORD = 1
    SEPARATOR = 2
    IDENTIFIER = 3
    OPERATOR = 4
    REAL = 5

# instantiate like this: token1 = Token(TokenType.KEYWORD, "while")
class Token:
    # constructor
    def __init__(self, tokenType, str):
        # Instance variable
        self.tokenType = tokenType
        self.str = str

def lexer():
    print ("executing lexer function...")

    tokens = []

     # currently a non exhaustive list of regex for tokens
     # '^' matches "starts with"... '|' is OR operator in regex
    startsWithKeywordRegex = "^while|^if|^int"
    startsWithOperatorRegex = "^=|^<|^>"
    startsWithRealRegex = "^[0-9]*"
    startsWithSeparatorRegex = "^(|^)"

    with open('input_scode.txt', 'r') as fileobj:
        # Remove all spaces then start reading from each line of the file
        filestring = fileobj.read().replace(' ', '')
        for line in filestring:
            while True:
                # continue as long as the line string is not empty
                if line is "": 
                    break
                
                match = None
                curTokenType = TokenType.NONE
                # check if the line starts with any of the supported keywords, operators, constants, or separators
                if (match := re.search(startsWithKeywordRegex, line)) is not None:
                    curTokenType = TokenType.KEYWORD
                elif (match := re.search(startsWithOperatorRegex, line)) is not None:
                    curTokenType = TokenType.OPERATOR
                elif (match := re.search(startsWithRealRegex, line)) is not None:
                    curTokenType = TokenType.REAL
                elif (match := re.search(startsWithSeparatorRegex, line)) is not None:
                    curTokenType = TokenType.SEPARATOR
                else:
                    print("Error, unable to parse line to token")
                    break

                if match is not None and curTokenType is not TokenType.NONE:
                    # remove whatever matched from the front of the string
                    line = line[match.len():]
                    # append the token we found to the running list
                    tokens.append(Token(curTokenType, match))

    # once done, print them all out
    for token in tokens:
        print(token.tokenType + " " + token.str + "\n")