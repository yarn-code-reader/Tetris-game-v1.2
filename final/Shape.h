#pragma once
#include "Peice.h"
class I_Shape : public Peice
{
public:
	I_Shape(float x, float y);
	void rotate(int modify[4][2]);
};

class Z_Shape : public Peice
{
public:
	Z_Shape(float x, float y);
	void rotate(int modify[4][2]);
};

class T_Shape : public Peice
{
public:
	T_Shape(float x, float y);
	void rotate(int modify[4][2]);
};

class S_Shape : public Peice
{
public:
	S_Shape(float x, float y);
	void rotate(int modify[4][2]);
};

class O_Shape : public Peice
{
public:
	O_Shape(float x, float y);
	void rotate(int modify[4][2]);
};

class L_Shape : public Peice
{
public:
	L_Shape(float x, float y);
	void rotate(int modify[4][2]);
};

class J_Shape : public Peice
{
public:
	J_Shape(float x, float y);
	void rotate(int modify[4][2]);
};

