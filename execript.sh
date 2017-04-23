#!/bin/bash
# @Time    : 4/23/17 1:29 AM
# @Author  : hehez
# @File    : execript.sh
# @Version : 1.0

# A Simple Shell Script To Get jsm.txt And All *.class files From Each Of It

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
