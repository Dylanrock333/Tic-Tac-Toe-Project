# Tic-Tac-Toe-Project
This program uses C++ to run a tic-tac-toe game.

Program will use three functions that will be used within the main function.

  **printDisplay**
    function will display the 3X3 game table with its ledgers as seen below. In addition, the X's and O's will be inserted their respective spot as the game is played.
    
                                                               1      2       3    

                                                                  |       |        
                                                      a           |       |        
                                                                  |       |        
                                                            _____________________  
                                                                  |       |        
                                                      b           |       |   
                                                                  |       |        
                                                            _____________________  
                                                                  |       |        
                                                      c           |       | 
                                                                  |       |        
  **getCoordinatesPlayr**
    function will retrive the coordinates from the user and insert the X or O in the coordinant array. As an example if the user types letter ( a ) and number ( 2 ), ie. the top middle spot, the respective X or O will be placed in coordinant[1]. The coordinant array will have 9 elements that start of as a single whitespace " " to represent an empty table. The coordinant a1 is index [0], a2 is index [1], ... , c2 is index [7], and c3 is index [8].
    
                                                               1      2       3    

                                                                  |       |        
                                                      a           |   X   |        
                                                                  |       |        
                                                            _____________________  
                                                                  |       |        
                                                      b           |       |   
                                                                  |       |        
                                                            _____________________  
                                                                  |       |        
                                                      c           |       | 
                                                                  |       |        
  
  **gameOvercheckplyer**
  function will run a simple algorithm to check whether theres a winner (three of the same X or O in a row) or if the game should continue. One loop will check the three vertival spots to find a match. The second loop will check the three horizontal spots to find a match. Finally, the last loop will check the two diagonal spots. If a match is found then function will return true, else the function will return false.
  
  
  
  
  In the **main** function a loop will run nine times, each time all three functions will be called. Before functions are called an if statement will determine wehether its player 1's turn or player 2's turn. After, the functions printDisplay, getCoordinatesPlayr, and gameOvercheckplyer will be called in that order. If gameOver is set to true then winner is declared and game over message will apprear with the respective winner.
  
  
  
  
