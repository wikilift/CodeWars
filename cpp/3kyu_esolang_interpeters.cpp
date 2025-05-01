//https://www.codewars.com/kata/5861487fdb20cff3ab000030/train/cpp

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include <map>

char* boolfuck(const char* code, const char* input) {
    std::vector<bool> tape(1, 0);
    size_t ptr = 0;
    size_t codePtr = 0;
    size_t inputPtr = 0;
    size_t inputBitPtr = 0;
    std::vector<bool> output;
    std::map<size_t, size_t> bracketMap;
    std::stack<size_t> bracketStack;
    
    for (size_t i = 0; code[i]; i++) {
        if (code[i] == '[') bracketStack.push(i);
        else if (code[i] == ']') {
            size_t opening = bracketStack.top();
            bracketStack.pop();
            bracketMap[opening] = i;
            bracketMap[i] = opening;
        }
    }
    
    while (code[codePtr]) {
        switch (code[codePtr]) {
            case '+':
                if (ptr >= tape.size()) tape.resize(ptr + 1, 0);
                tape[ptr] = !tape[ptr];
                break;
            case ',':
                if (input[inputPtr]) {
                    if (ptr >= tape.size()) tape.resize(ptr + 1, 0);
                    tape[ptr] = (input[inputPtr] >> inputBitPtr) & 1;
                    inputBitPtr++;
                    if (inputBitPtr == 8) {
                        inputBitPtr = 0;
                        inputPtr++;
                    }
                } else {
                    if (ptr >= tape.size()) tape.resize(ptr + 1, 0);
                    tape[ptr] = 0;
                }
                break;
            case ';':
                output.push_back(tape[ptr]);
                break;
            case '<':
                if (ptr == 0) {
                    tape.insert(tape.begin(), 0);
                } else {
                    ptr--;
                }
                break;
            case '>':
                ptr++;
                if (ptr >= tape.size()) tape.resize(ptr + 1, 0);
                break;
            case '[':
                if (!tape[ptr]) codePtr = bracketMap[codePtr];
                break;
            case ']':
                if (tape[ptr]) codePtr = bracketMap[codePtr];
                break;
        }
        codePtr++;
    }
    
    size_t outputSize = (output.size() + 7) / 8;
    char* result = (char*)calloc(outputSize + 1, 1);
    
    for (size_t i = 0; i < output.size(); i++) {
        if (output[i]) {
            result[i / 8] |= (1 << (i % 8));
        }
    }
    
    return result;
}