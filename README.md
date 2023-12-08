# Overview

I wanted to see if I could write a simple tone generator in C. I had studied the sine wave formula and I was wondering if I could make it work in code.

The program generates a .wav file and saves it to the directory the main file is located in.

!!DISCLAIMER!!
This project is largely unfinished. As you can see if you look inside the main file, there is much code commented out. I was trying to implement a TUI, and will probably do so in the near future. For now, the code works. If you would like to contribute to development, please see below.

# Demo

Here is a link to a youtube video with me demonstrating the program and explaining some modifications I made to the original sine wave formula to add modulation.

[Demo Video](https://youtu.be/-LbBSpipwbg)


# Compilation

If you would like to test the code for yourself, you can compile it with this command (UNIX based systems only)
    
    gcc main.c -o out -lm -lsndfile

From there, you can run it with

    ./out


# Development Environment

This program was developed using Neovim on Arch Linux.


# Future updates

I am not sure how much attention I will be giving this in the future since the primary goal of this project has already been met, but a few things that could be added are as follows:

- the ability to add tones sequentially instead of stacking them as chords
- a simple GUI or TUI to add notes and adjust their length
- the ability to add reverb or other types of modulation
- the ability to preview or listen to the signal in real time instead of needing to generate a wav file.
