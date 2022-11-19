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
#include <stdlib.h>
#include "brainVM.h"


BrainF_VM* createVM(int (*outputHandler) (int), int (*inputHandler) (void)) {

    BrainF_VM* newVM = (BrainF_VM*)malloc(sizeof(BrainF_VM));
    newVM->head = NULL;
    newVM->tape = (unsigned char*)calloc(TAPE_SIZE, sizeof(unsigned char*));
    newVM->outputHandler = outputHandler;
    newVM->inputHandler = inputHandler;
    return newVM;
}

BrainF_Instr* createInstr() {
    
    BrainF_Instr* newInstr = (BrainF_Instr*)malloc(sizeof(BrainF_Instr));
    newInstr->count = 0;
    newInstr->loop = NULL;
    newInstr->next = NULL;
    newInstr->type = 0;
    return newInstr;

}


BrainF_Instr* parseProgram(FILE* src) {
    
    BrainF_Instr* head = createInstr();
    BrainF_Instr* current = head;

    signed char ch;
    while((ch = fgetc(src)) != EOF) {

        switch(ch) {

            case '+':
            case '-':
                current->type = '+';
                while(ch == '+' || ch == '-') {
                    ch == '+' ? current->count++ : current->count--;
                    ch = fgetc(src);
                }
                ungetc(ch, src);
                break;

            case '>':
            case '<':
                current->type = '>';
                while(ch == '>' || ch == '<') {
                    ch == '>' ? current->count++ : current->count--;
                    ch = fgetc(src);
                }
                ungetc(ch, src);
                break;

            case '.':
            case ',':
                current->type = (ch == '.' ? '.' : ',');
                while(ch == current->type) {
                    current->count++;
                    ch = fgetc(src);
                }
                ungetc(ch, src);
                break;

            case '[':
                current->type = '[';
                current->loop = parseProgram(src);
                break;

            case ']':
                return head;

            default:
                continue;
        }
        current->next = createInstr();
        current = current->next;
    }
    return head;
}

void executeSequence(BrainF_Instr* head, BrainF_VM* vm)  {

    BrainF_Instr* current = head;
    while(current->type != 0) {
    
        switch (current->type) {
            
            case '+':
                *(vm->tape) += current->count;
                break;

            case '>':
                vm->tape += current->count;
                break;

            case '.':
                for(int i = 0; i < current->count; i++)
                    vm->outputHandler(*(vm->tape));
                break;

            case ',':
                for(int i = 0; i < current->count; i++)
                    *(vm->tape) = vm->inputHandler();
                break;

            case '[':
                while(*(vm->tape) != 0) executeSequence(current->loop, vm);
                break;
        }

        current = current->next;
    }
}

void executeProgram(BrainF_VM* vm)  {

    executeSequence(vm->head, vm);
}



int BrainF_getchar() {
    char temp = getchar();
    while(getchar() != '\n') {} //clean stdin
    return temp;
}
