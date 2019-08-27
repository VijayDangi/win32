Compile code by following command using Microsoft C Compiler

      > cl.exe /EHsc /c SquareAnimation1.cpp
      > link.exe SquareAnimation1.obj user32.lib gdi32.lib kernel32.lib /SUBSYSTEM:WINDOWS
      
    Combination of above commands
    
      > cl.exe /EHsc SquareAnimation1.cpp /LINK user32.lib gdi32.lib kernel32.lib /SUBSYSTEM:WINDOWS


Using GNU C Compiler on Windows i.e. MinGW

      > g++ -D UNICODE -D _UNICODE -c SquareAnimation1.cpp -o SquareAnimation.o
      > g++ -o SquareAnimation1.exe SquareAnimation1.o -lgdi32 -Wl,--subsystem,windows
