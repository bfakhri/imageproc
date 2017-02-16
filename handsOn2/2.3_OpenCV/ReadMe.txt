// Bijan Fakhri
// Exercise 2.3
// 2-16-17

This code was written and tested on:
OS: Ubuntu 14.04.5 LTS
OpenCV: 3.2

To compile, 'cd' into the directory containing 'Exercise2.3.cpp' and run the 'make' command. The makefile should compile the 'cpp' file and create an executable 'Exercise2.3.exec'. 
To run, ensure that the 'zebras.jpg' image is in the same directory as the executable. Then execute the command './Exercise2.3.exec' and the program should run. 

The program will first display the original 'zebras.jpg' image. The program will then display the zebra image after undergoing DFT and Inverse DFT (with truncation) using different L values. Press any key to skip the the next image. The L value of the image currently displayed will be displayed in the console. The same process repeats with the DCT. 

At the L-value that I have chosen to provide a noticable difference, the image is written to a file with a descriptive name. It is also announced in the console. 
