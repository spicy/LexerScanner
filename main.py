

##this is the main for the lexer scanner 

# function named lexer(), which will be responsible for returning a token when required. 
# unction should return a record that contains two fields: one for the token and the other for the actual value
  #of the token, also known as the lexeme
# below is tghe expected output 

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

from lexer import lexer
import numpy as np 
import matplotlib.pyplot as plt

# appending and defining to arrays
# https://stackoverflow.com/questions/19139201/how-to-define-a-global-array-in-python


# we can catagorize the words read by the lexer function into these arrays and append as needed 
# these are global arrays 

keyword = [] 
separator =  []
identifier = []
operator = []
real = []


lexer() #the FSM will be within the lexer function 


