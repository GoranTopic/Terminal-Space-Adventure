# Terminal Space Invaders :space_invader: 

## About
This is Space Invader Game Engine :video_game: for the terminal using ncurses as a display engine  and written entirely on C.:rocket:

![Space-adventure-demo](assets/Space-Adveture-demo.gif)

## Usage 
  To run the game on your terminal window simply run: `./game 2>/dev/null` 
  for some reason some of the std Errors I could not redirect out of std thus it is nesesary to add the `2> /dev/null` jus tin case. 

## Compile

  The compilations should run with `gcc main.c -o game` 
  
  Although you might need to install some dependencies. 

## How it works
One might think that it would be simple to create a game on C from scratch, but that would be naive. Just like me when I first started this project. 

Note that this is C; So you have to mange memory direcly. If you need a variable or a array of variables you need to ask the computer for it. 

Also, we are going to be using ncurses to display thing on the terminal window. However, ncurses is only able to display to diaply a charater in a given cordinate. 

The onus is stil on us to do everything else.

  1 first we need to define the screen width and height. We need to know the boarders of or game and we need to do dynamically, incase the terminal window gets resized
  

  2 first, we need a array of Chars, an object if you will to be able to represent the space ships 
  
  3 

## ToDO

  [ ] Add make file to compilation 
  
  [ ] make sound be sycronized with space ship firing
  
  
  
