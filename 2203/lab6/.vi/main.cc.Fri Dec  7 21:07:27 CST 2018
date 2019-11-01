/*
   lab5.cc -- Build a window manager

   Author: Larry Morell and Ryne Whitaker

   Modification History
   7/13/2018  -- Original version
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctype.h> 
#include <cstring> 
#include <ncurses.h> 
#include <time.h>
#include <stdlib.h>
#include "BorderedWindow.h"
#include "DebugWindow.h"
#include "CommandWindow.h"
using namespace std;

// displays win/loss/tie message based on int cond (1 = win, 2 = lose, 3 = tie)
void displayMessage(Window &gameMsg, int &randMsg, int cond) { 
   // Vector of messages to be used for win, lose, or tie scenarios
   vector <string> winMessages {"You win!", "Congratulations, you win!", "You win... Take that, computer!", "You won!", "VICTORY SCREECH", "Is it VE day?", "Song of the game: All I Do Is Win - DJ Khaled", "All you do is win win win, no matter what", "I'll pop open the champagne!", "Quit while you're on top!", "You should go to the casino with that kind of luck!", "The man, the myth, the LEGEND!"};
   vector <string> loseMessages {"You lose!", "You lost. Come on, you're the one with a brain, right?", "You lost. Again.", "You done lost.", "I'm disappointed :(", "I'm not saying I'm mad, I'm just disappointed.", "The computer wins this time", "You do know how rock paper scissors works, right?", "Better luck next time!", "You've got it, don't give up!", "Yeah, you should probably just accept defeat.", "I've got a white flag over here if you want to use it."};
   vector <string> tieMessages {"It's a tie!", "Issa whole tie", "I'll be here all day at this pace", "If you think I have nothing better to be doing than judging your games, you're right.", "You're supposed to choose what beats their play.", "Ready for a rematch?", "I'm ready for a rematch!", "Another one!", "Song of the game: Mob Ties - Drake", "Song of the game: Suit & Tie - Justin Timberlake", "Song of the game: Same Thing - Marian Hill", "Song of the game: New Person, Same Old Mistakes - Tame Impala"};

   gameMsg.clear(); gameMsg.refresh(); gameMsg.hide();

   if (cond == 1) {
   gameMsg.write(winMessages[randMsg]); // write random new win message if win
   }
   else if (cond == 2) {
   gameMsg.write(loseMessages[randMsg]); // write random new lose message if lose
   }
   else if (cond == 3) {
   gameMsg.write(tieMessages[randMsg]); // write random new tie message if tie
   }
}

// processes player choice vs computer choice and displays choices on the screen
void process(Window &gameMsg, Window &playerBoard, Window &computerBoard, Window &tiesBoard, string player, string computer, int &pWins, int &cWins, int &ties, int &randMsg) {
   Window pRock(1, 20, 0, 0, "Player: ");
   pRock.write("Rock");
   
   Window pPaper(1, 20, 0, 0, "Player: ");
   pPaper.write("Paper");
   
   Window pScissors(1, 20, 0, 0, "Player: ");
   pScissors.write("Scissors");
   
   Window cRock(1, 20, 0, 20, "Computer: ");
   cRock.write("Rock");
   
   Window cPaper(1, 20, 0, 20, "Computer: ");
   cPaper.write("Paper");
   
   Window cScissors(1, 20, 0, 20, "Computer: ");
   cScissors.write("Scissors");
   
   Window error(1, 100, 2, 0, "");
   error.write("Please enter a valid selection. Enter \"r\" for rock, \"p\" for paper, \"s\" for scissors, or \"q\" to quit.");

   pRock.hideAll();
   cRock.hideAll();
   
   if (player == "r" && computer == "rock") // if player rock and computer rock
   {
   pRock.hideAll();
   pRock.refreshAll();
   pRock.show();
   cRock.show();
   cRock.refreshAll();
   ties++;
   tiesBoard.write(ties);
   displayMessage(gameMsg, randMsg, 3); // display tie message
   }
   else if (player == "r" && computer == "paper") // if player rock and computer paper
   {
   pRock.hideAll();
   pRock.refreshAll();
   pRock.show();
   cPaper.show();
   cPaper.refreshAll();
   cWins++;
   computerBoard.write(cWins);
   displayMessage(gameMsg, randMsg, 2); // display lose message
   }
   else if (player == "r" && computer == "scissors") // if player rock and computer scissors
   {
   pRock.hideAll();
   pRock.refreshAll();
   pRock.show();
   cScissors.show();
   cScissors.refreshAll();
   pWins++;
   playerBoard.write(pWins);
   displayMessage(gameMsg, randMsg, 1); // display win  message
   }
   else if (player == "p" && computer == "rock") // if player paper and computer rock
   {
   pRock.hideAll();
   pRock.refreshAll();
   pPaper.show();
   cRock.show();
   cRock.refreshAll();
   pWins++;
   playerBoard.write(pWins);
   displayMessage(gameMsg, randMsg, 1); // display win message
   }
   else if (player == "p" && computer == "paper") // if player paper and computer paper
   {
   pRock.hideAll();
   pRock.refreshAll();
   pPaper.show();
   cPaper.show();
   cPaper.refreshAll();
   ties++;
   tiesBoard.write(ties);
   displayMessage(gameMsg, randMsg, 3); // display tie message
   }
   else if (player == "p" && computer == "scissors") // if player paper and computer scissors
   {
   pRock.hideAll();
   pRock.refreshAll();
   pPaper.show();
   cScissors.show();
   cScissors.refreshAll();
   cWins++;
   computerBoard.write(cWins);
   displayMessage(gameMsg, randMsg, 2); // display lose message
   }
   else if (player == "s" && computer == "rock") // if player scissors and computer rock
   {
   pRock.hideAll();
   pRock.refreshAll();
   pScissors.show();
   cRock.show();
   cRock.refreshAll();
   cWins++;
   computerBoard.write(cWins);
   displayMessage(gameMsg, randMsg, 2); // display lose message
   }
   else if (player == "s" && computer == "paper") // if player scissors and computer paper
   {
   pRock.hideAll();
   pRock.refreshAll();
   pScissors.show();
   cPaper.show();
   cPaper.refreshAll();
   pWins++;
   playerBoard.write(pWins);
   displayMessage(gameMsg, randMsg, 1); // display win message
   }
   else if (player == "s" && computer == "scissors") // if player scissors and computer scissors
   {
   pRock.hideAll();
   pRock.refreshAll();
   pScissors.show();
   cScissors.show();
   cScissors.refreshAll();
   ties++;
   tiesBoard.write(ties);
   displayMessage(gameMsg, randMsg, 3); // display tie message
   }
   else // Hide all windows and display error message requesting valid input
   {
   gameMsg.hide();
   pRock.hideAll();
   pRock.refreshAll();
   error.show();
   error.refresh();
   }
}

int main (int argc, char *argv[]) {
   initscr();
   cbreak();      /* Input line buffering disabled; pass on every char*/
   
   Window gameMsg(1, 100, 3, 0, ""); // Create a window for displaying win/loss/tie messages
   
   Window playerBoard(1, 100, 5, 0, ""); // Create a window for displaying the number of player wins
   playerBoard.write("Player: ");

   Window computerBoard(1, 100, 6, 0, ""); // Create a window for displaying the number of computer wins
   computerBoard.write("Computer: ");
   
   Window tiesBoard(1, 100, 7, 0, ""); // Create a window for displaying the number of ties
   tiesBoard.write("Ties: ");
   
   int pWins = 0;  // Counter for player wins
   int cWins = 0;  // Counter for computer wins
   int ties = 0;  // Counter for ties
   string player;

   srand(time(NULL)); // initialize the random seed for computer selection
   const string plays[3] {"rock", "paper", "scissors"}; // Valid selection for the computer
   CommandWindow c1; // command window for interfacing with the game

   Window mousePrompt(1, 100, 3, 0, ""); // Window that holds the mouse/no mouse prompt
   mousePrompt.write("Type 0 to enter keyboard mode or 1 to enter mouse mode, then press enter.");
   string mode = c1.readString(); // mode selection
   bool mouseMode;
   if (mode == "0")
	   mouseMode = false; // not in mouse mode
   else if (mode == "1")
	   mouseMode = true; // in mouse mode

   if (!mouseMode) { // keyboard mode
      player = c1.readString();
      while (!(player == "q" or player == "Q")) {
         int randPlay = rand() % 3; // random play selection for computer
         int randMsg = rand() % 12; // random message selection
	 string computer = plays[randPlay];  // random play selection for computer
         process(gameMsg, playerBoard, computerBoard, tiesBoard, player, computer, pWins, cWins, ties, randMsg); // it is a lot of parameters, but processes whether the player or computer won, or if it was a tie 
         c1.clear();
         player = c1.readString();   
      }
   }
   else { // mouse mode
      mousemask(BUTTON1_CLICKED | BUTTON2_CLICKED | BUTTON3_CLICKED | BUTTON1_TRIPLE_CLICKED, NULL); // mouse inputs to be listened to
      MEVENT event;
      int ch = getch();
         while (getmouse(&event) != BUTTON1_TRIPLE_CLICKED) { // exit game if left mouse button is triple clicked
            int randPlay = rand() % 3; // random play selection for computer
            int randMsg = rand() % 12; // random message selection
	    if (getmouse(&event) == BUTTON1_CLICKED) {
	       player = "r"; // set player selection to rock if left mouse button is clicked
	       c1.pause();
	    }
	    else if (getmouse(&event) == BUTTON2_CLICKED) {
               player = "p"; // set player selection to paper if middle button (scroll wheel) is clicked
	       c1.pause();
	    }
	    else if (getmouse(&event) == BUTTON3_CLICKED) {
               player = "s"; // set player selection to scissors if right mouse button is clicked
	       c1.pause();
	    }
            string computer = plays[randPlay];
            process(gameMsg, playerBoard, computerBoard, tiesBoard, player, computer, pWins, cWins, ties, randMsg); // process computer and player plays 
	    getmouse(&event);
	 }
   }

   endwin();         /* End curses mode        */
   return 0;
}

