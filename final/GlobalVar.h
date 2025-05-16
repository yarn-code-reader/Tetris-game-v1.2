#pragma once
// globals.h
#ifndef GLOBALS_H
#define GLOBALS_H

//When you want to share a variable between multiple source files in a project, you use extern to declare it in a header file, and then define it in one source file.
// This avoids multiple definitions, which can cause linker errors.
extern int sizeOfBlock;
extern float winH;
extern float winW;
extern float scaleConstantOfBlocks;
extern int maxScore;
#endif
