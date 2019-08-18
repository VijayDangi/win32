Compile code by following command using Microsoft C Compiler

      > cl.exe /EHsc /c SquareAnimation1.cpp
      > link.exe SquareAnimation1.obj user32.lib gdi32.lib kernel32.lib /SUBSYSTEM:WINDOWS
      
  Combination of above commands
    
      > cl.exe /EHsc SquareAnimation1.cpp /LINK user32.lib gdi32.lib kernel32.lib /SUBSYSTEM:WINDOWS
