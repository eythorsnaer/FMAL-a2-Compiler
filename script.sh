#!/bin/bash
./Compiler < program.l > program.code
./Interpreter < program.code
