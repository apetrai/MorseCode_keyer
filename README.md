<div align="center">
  <h2> MorseMessenger.  <img height="50" src="https://www.pngrepo.com/png/38633/512/morse-code.png"></h2>
 <img src="https://img.shields.io/github/issues/apetrai/MorseCode_translator">
  <img src="https://img.shields.io/github/v/tag/apetrai/MorseCode_translator">

</div>

## Description

This is a real-time chat application built in C++ using the SFML library, allowing users to communicate using Morse code. The app translates messages into Morse code for sending, and decodes incoming Morse code into readable text this ensures encrypted information being sent and recieved.

The project demonstrates the use of C++ for network communication, real-time messaging, and GUI development using SFML.

## Features

- Real-time chat using Morse code.
- Encoding of text into Morse code.
- Decoding of Morse code back to text.
- User Friendly Graphical User Interface (GUI) with SFML.
- Support for multiple users.
- Error handling for invalid Morse code input.




## Installation and Setup

1. Clone the repository: [via https](https://github.com/apetrai/morse-code-chat-app.git) or [via ssh](git@github.com:apetrai/MorseCode_keyer.git).

**You do not have to install SFML yourself as CMake downloads it externally.** 

2. Compile the project.
    - Run ```cmake . ``` to download the SFML libraries and link all of the source files.
    - There are now two seperate binary executables to compile:
      - For the server app run ```make ServerApp``` to produce the execuatble, then ```./bin/ServerApp```
      OR:
      - For the client app run ```make ClientApp``` to produce the execuatble, then ```./bin/ClientApp```
      
  
## Documentation
**Table of contents:**
   - [How to use](#how-to-use)
   - Functions and Code overview
   - [The Goal](#the-goal)
   - [Future improvements](#future-improvements)
   - License
  ### How to use
   
- Launch the app and enter your message in the text input area.
- The message will automatically be translated into Morse code and sent.
- Incoming Morse code messages from other users will be decoded and displayed as text.

### Future Improvements
- Add message encryption for secure communication.
- Allow file transfers in Morse code.
- Optimize the Morse code encoding/decoding algorithm for speed.

## The Goal

The goal of the project is to create a chat application that allows users to communicate by sending and receiving Morse code messages. The main challenge is to create a smooth and responsive GUI while ensuring that Morse code is encoded and decoded efficiently in real time.

#
