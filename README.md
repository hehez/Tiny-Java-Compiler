# Tiny JAVA compiler

## Short Description

A simple but complete compiler, including the initial phases of a typical front-end. It begins with scanners, various parsing techniques, type checking, syntax-directed translation and code generation. It also contains symbol tables, error recovery and runtime systems.

## Quick Start

### Two ways to run the program:

Run the shell script,
    
    "execript.sh"      --generate all the *.class files

OR

Run the program step by step,

    1. make                             --generate the executable file `tjc`
    2. ./tjc Sample.java                --generate the jsm.txt file
    3. java -jar jasmin.jar jsm.txt     --generate the Sample.class file
    4. java Sample                      --run the source program
