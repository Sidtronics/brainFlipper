/*
* The MIT License (MIT)
* 
* Copyright (c) 2022 Siddhesh Dharme
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include <stdio.h>

#define TAPE_SIZE 30000

typedef struct BrainF_Instr {

    char type;
    int count;
    struct BrainF_Instr *next, *loop;

} BrainF_Instr;

typedef struct BrainF_VM {

    BrainF_Instr *head;
    unsigned char *tape;
    int (*outputHandler) (int);
    int (*inputHandler) (void);

} BrainF_VM;

BrainF_VM* createVM(int (*outputHandler) (int), int (*inputHandler) (void));

BrainF_Instr* createInstr();

BrainF_Instr* parseProgram(FILE*);

void executeSequence(BrainF_Instr*, BrainF_VM*);

void executeProgram(BrainF_VM*);

int BrainF_getchar();
