

#tokens can be 
# keywords,
# constants,
# identifiers,
# strings,
# numbers,
# operators
#punctuations symbols


def lexer():
    print ("executing lexer function...")

# program to read file word by word
    with open('input_scode.txt','r') as file: # opening the text file
  
    # reading each line   
        for line in file:
  
        # reading each word       
            for word in line.split():
  
                 
                print(word) #this prints the words individually 
                            #here we input code to catagorize the words read individually 
