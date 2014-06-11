#############################
## DAVID LETTIER (C) 2011
## HANGMAN
## CSC 102 FINAL STUDY PROJ
#############################

import os
import random


def hangMan( string ):

    os.system("CLS")
    
    man = """   
                  ----- 
                  |   |
                 ( )  |
                 -|-  |
                 / \  |
                      |
               ----------"""
    man1 = """   
                  ----- 
                  |   |
                 ( )  |
                 -|-  |
                 /    |
                      |
               ----------"""
    man2 = """   
                  ----- 
                  |   |
                 ( )  |
                 -|-  |
                      |
                      |
               ----------"""
    man3 = """   
                  ----- 
                  |   |
                 ( )  |
                 -|   |
                      |
                      |
               ----------"""
    man4 = """   
                  ----- 
                  |   |
                 ( )  |
                  |   |
                      |
                      |
               ----------"""
    man5 = """   
                  ----- 
                  |   |
                 ( )  |
                      |
                      |
                      |
               ----------"""
    man6 = """   
                  ----- 
                  |   |
                      |
                      |
                      |
                      |
               ----------"""
               
    images = [ man6, man5, man4, man3, man2, man1, man ]
    
    blanks = [ ]            
    for i in string:
        blanks.append( "_" )
    mask = " ".join( blanks )
    
    
    answer = [ ]
    for x in string:
        answer.append( x )
    reveal = " ".join( answer )
    
    
    print "\n"
    print "Welcome to Hangman.".center( 41 )
    print man6
    print "\n"
    print mask.center( 41 )
    print "\n"
    
    deadCtr = 0
    win = 0
    prevGuess = " "
    
    while ( deadCtr < 6 ):
    
        guess = raw_input( "      Guess a letter in the word: " )
        
        try:
            guess = guess[0].lower( )
        except: # Empty input.
            guess = " "
            
        if ( guess in string ):
    
            # Update blanks.
            # Display current man image.
            # See if they won.
            
            os.system("CLS")
            
            if ( prevGuess == guess ): # They input the same guess.
            
                # Increase death counter.
                # Wipe screen.
                # Display new man image.           
                
                os.system("CLS")
                
                deadCtr += 1
                
                print images[ deadCtr ]
                print "\n"
                print mask.center( 41 )
                print "\n"
                print " YOU ALREADY GUESS THAT.".center( 41 )
                print "\n"         
                continue;
                
            print images[ deadCtr ]
            print "\n"
            for index, value in enumerate( answer ): # Update the mask.
                # Print index, value, and answer.
                if ( value == guess ): # Update mask with guess character.
                    # Print blanks.
                    blanks[index] = value;
            mask = " ".join( blanks )
            print mask.center( 41 )
            if ( mask == reveal ):
                # They won.
                win = 1;
                print "\n"  
                break;
            print "\n"
        else: # They guessed wrong.
        
            # Increase death counter.
            # Wipe screen.
            # Display new man image.   
            
            os.system("CLS")
            
            deadCtr += 1 # Increase the death counter.
            
            print images[ deadCtr ]
            print "\n"
            print mask.center( 41 )
            print "\n"
            
        prevGuess = guess # See next loop, if they guess the same guess.
        
    if ( win == 1 ):
        print "YOU WON, YAY! :)".center( 41 );
        print "\n"
    else: # they lost
        print "GAME OVER, YOU DIED. :(".center( 41 );
        print "\n"
    
def main( ):
    words = [ "bob", "cat", "david", "lettier", "python" ]
    randNum = random.randint( 0, 4 )
    hangMan( words[ randNum ] );
    again = raw_input( "Play again (y/n)? " )
    try:
        again = again[0].lower( )
    except: # Empty input.
        again = "n"
    while ( again != "n" ):
        randNum = random.randint( 0, 4 )
        hangMan( words[ randNum ] );
        again = raw_input( "Play again (y/n)? " )
        try:
            again = again[0].lower( )
        except: # Empty input.
            again = "n"
    os.system("CLS")
    
    
main( );