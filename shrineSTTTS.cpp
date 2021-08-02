//A simple wrapper for the Festival TTS system.
//Allows user input of strings to be passed to TTS and displayed on stream
//Written by Geir Anderson

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <cstring>

int main()
{
    printf("Loading Nerd Dictation");
    system("./nerd-dictation/nerd-dictation begin --vosk-model-dir=./nerd-dictation/model &");
    system("clear");
    printf("\n>  ");
    bool exit = false;
    while(!exit)
    {
        std::string input = "";
        getline(std::cin, input);
        if(input == "exit" || input == " exit" || input == "exit " || input == " exit "||
           input == " hex it")
        {
            exit = true;
        }
        else
        {
            char* text = new char [input.length()+1];
            std::strcpy (text,input.c_str());
            char cmd[8192];
            sprintf(cmd, "echo \"%s\" | festival --tts", text);
            system(cmd);
            delete[] text;
            printf(">  ");
        }
    }
    printf("Thank you for using Shrine STTTS, shutting down!!!");
    system("./nerd-dictation/nerd-dictation end");
    printf("\n");
    return 0;
}
