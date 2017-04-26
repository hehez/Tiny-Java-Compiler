#!/bin/bash

# A Simple Shell Script To Get jsm.txt And All *.class From Each Of It

function genJsmTxt() {
	./tjc $(basename $1) >> out.txt
	java -jar jasmin.jar jsm.txt
}

function loop() {
	make clean
	make
    for i in "$1"/*
    do
    	if [[ $i == *.java ]]; then
    		genJsmTxt $i
        fi
    done
}

# Start
loop "$PWD"
