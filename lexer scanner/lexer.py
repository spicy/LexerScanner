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


def lexer():
    print ("executing lexer function...")

# program to read file char by char 
#will put chars together to form a word
    word = '' # this will hold the string 
    number = '' # this will be a number 
    current_state = 0

    with open("input_scode.txt") as fileobj:
        for line in fileobj:
             for ch in line:



                 if ch != ' ' and ch != ';' and ch != '(' and ch != ')' and ch != '<' and ch != '>' and ch != '=': #checks for spaces and ;
                    word += ch #append to word

                 if ch.isnumeric() or ch == '.':
                     number += ch #add into string if it is numeric

                     if current_state == 2:# now we are in 2nd number after the .
                         current_state = 3
                         print("real = " + number)
                         number = ''

                     if current_state == 1: #now we are in 1st number after the .
                         current_state = 2

                     if ch == '.': #after . set flag to inc number to 1 
                         current_state += 1
                         current_state = 1



                 if ch == ';': #check for ;
                     print("separator = " + ch) #prints the character (seperator)
                 if ch == '(':
                     print("seporator = " + ch)
                 if ch == ')':
                     print("seporator = " + ch)
                 if ch == '<' or ch == '>':
                     print ("operator = "+ ch)                     
               
        
                 if ch == ' ': #if there is a space word is complete 
                    if word == "while":
                        print("keyword = "+ word) #print keyword
                        word = ''                 #clear the word

                    if word != "while" and word != ' ' and word != '' and ch != ';' and ch != '(' and ch != ')' and ch != '<' and ch != '>' and ch != '=' :
                        print("identifier = "+ word)
                        word = '' #clear the word
