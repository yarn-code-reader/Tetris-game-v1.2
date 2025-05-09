#include "Shape.h"
#include "GlobalVar.h"

I_Shape :: I_Shape(float x = 240, float y = 100) {
	this->x = x;
	this->y = y;
	type = 1;

	int temp[4][2] = {
   {0,1},
   {1,1},
   {2,1},
   {3,1}
	};

	for (int i = 0; i < 4; i++) {
		shape[i][0] = temp[i][0];
		shape[i][1] = temp[i][1];
	}
}

void I_Shape:: rotate(int modify[4][2]) {
	cout << "in I rotate function" << endl;
	if (rotationState == 0) {
		int temp[4][2] = { {0, 1}, {1, 1}, {2, 1}, {3, 1} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 1;
	}
	else if (rotationState == 1) {
		int temp[4][2] = { {2, 0}, {2, 1}, {2, 2}, {2, 3} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 2;
	}
	else if (rotationState == 2) {
		int temp[4][2] = { {0, 2}, {1, 2}, {2, 2}, {3, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 3;
	}
	else if (rotationState == 3) {
		int temp[4][2] = { {1, 0}, {1, 1}, {1, 2}, {1, 3} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 0;
	}
}

///\note

Z_Shape::Z_Shape(float x = 240, float y = 100) {
	this->x = x;
	this->y = y;
	type = 2;

	int temp[4][2] = { {0, 0}, {1, 0}, {1, 1}, {2, 1} };

	for (int i = 0; i < 4; i++) {
		shape[i][0] = temp[i][0];
		shape[i][1] = temp[i][1];
	}
}

void Z_Shape::rotate(int modify[4][2]) {
	cout << "in Z rotate function" << endl;
	if (rotationState == 0) {
		int temp[4][2] = { {1, 0}, {0, 1}, {1, 1}, {2, 1} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 1;
	}
	else if (rotationState == 1) {
		int temp[4][2] = { {1, 0}, {1, 1}, {1, 2}, {2, 1} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 2;
	}
	else if (rotationState == 2) {
		int temp[4][2] = { {0, 1}, {1, 1}, {2, 1}, {1, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 3;
	}
	else if (rotationState == 3) {
		int temp[4][2] = { {0, 1}, {1, 0}, {1, 1}, {1, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 0;
	}
}
///\note

T_Shape::T_Shape(float x = 240, float y = 100) {
	this->x = x;
	this->y = y;
	type = 1;

	int temp[4][2] = { {1, 0}, {0, 1}, {1, 1}, {2, 1} };
	for (int i = 0; i < 4; i++) {
		shape[i][0] = temp[i][0];
		shape[i][1] = temp[i][1];
	}
}

void T_Shape::rotate(int modify[4][2]) {
	cout << "in I rotate function" << endl;
	if (rotationState == 0) {
		int temp[4][2] = { {1, 0}, {0, 1}, {1, 1}, {2, 1} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 1;
	}
	else if (rotationState == 1) {
		int temp[4][2] = { {1, 0}, {1, 1}, {1, 2}, {2, 1} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 2;
	}
	else if (rotationState == 2) {
		int temp[4][2] = { {0, 1}, {1, 1}, {2, 1}, {1, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 3;
	}
	else if (rotationState == 3) {
		int temp[4][2] = { {0, 1}, {1, 0}, {1, 1}, {1, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 0;
	}
}
///\note

S_Shape::S_Shape(float x = 240, float y = 100) {
	this->x = x;
	this->y = y;
	type = 1;

	int temp[4][2] = { {1, 0}, {2, 0}, {0, 1}, {1, 1} };

	for (int i = 0; i < 4; i++) {

		shape[i][0] = temp[i][0];
		shape[i][1] = temp[i][1];

	}
}

void S_Shape::rotate(int modify[4][2]) {
	cout << "in S rotate function" << endl;
	if (rotationState == 0) {
		int temp[4][2] = { {1, 0}, {2, 0}, {0, 1}, {1, 1} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 1;
	}
	else if (rotationState == 1) {
		int temp[4][2] = { {1, 0}, {1, 1}, {2, 1}, {2, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 2;
	}
	else if (rotationState == 2) {
		int temp[4][2] = { {1, 1}, {2, 1}, {0, 2}, {1, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 3;
	}
	else if (rotationState == 3) {
		int temp[4][2] = { {0, 0}, {0, 1}, {1, 1}, {1, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 0;
	}
}
///\note

O_Shape::O_Shape(float x = 240, float y = 100) {
	this->x = x;
	this->y = y;
	type = 1;

	int temp[4][2] = {
	   {1,1},

	   {1,2}, {2,1},
	   {2,2}
	};

	for (int i = 0; i < 4; i++) {

		shape[i][0] = temp[i][0];
		shape[i][1] = temp[i][1];

	}
}

void O_Shape::rotate(int modify[4][2]) {
	cout << "in O rotate function" << endl;
}

///\note

L_Shape::L_Shape(float x = 240, float y = 100) {
	this->x = x;
	this->y = y;
	type = 1;

	int temp[4][2] = { {2, 0}, {0, 1}, {1, 1}, {2, 1} };
	for (int i = 0; i < 4; i++) {
		shape[i][0] = temp[i][0];
		shape[i][1] = temp[i][1];
	}
}

void L_Shape::rotate(int modify[4][2]) {
	cout << "in L rotate function" << endl;
	if (rotationState == 0) {
		int temp[4][2] = { {2, 0}, {0, 1}, {1, 1}, {2, 1} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 1;
	}
	else if (rotationState == 1) {
		int temp[4][2] = { {1, 0}, {1, 1}, {1, 2}, {2, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 2;
	}
	else if (rotationState == 2) {
		int temp[4][2] = { {0, 1}, {1, 1}, {2, 1}, {0, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 3;
	}
	else if (rotationState == 3) {
		int temp[4][2] = { {0, 0}, {1, 0}, {1, 1}, {1, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 0;
	}
}

///\note

J_Shape::J_Shape(float x = 240, float y = 100) {
	this->x = x;
	this->y = y;
	type = 1;

	int temp[4][2] = { {0, 0}, {0, 1}, {1, 1}, {2, 1} };
	for (int i = 0; i < 4; i++) {
		shape[i][0] = temp[i][0];
		shape[i][1] = temp[i][1];
	}
}

void J_Shape::rotate(int modify[4][2]) {
	cout << "in J rotate function" << endl;
	if (rotationState == 0) {
		int temp[4][2] = { {0, 0}, {0, 1}, {1, 1}, {2, 1} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 1;
	}
	else if (rotationState == 1) {
		int temp[4][2] = { {1, 0}, {2, 0}, {1, 1}, {1, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 2;
	}
	else if (rotationState == 2) {
		int temp[4][2] = { {0, 1}, {1, 1}, {2, 1}, {2, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 3;
	}
	else if (rotationState == 3) {
		int temp[4][2] = { {1, 0}, {1, 1}, {0, 2}, {1, 2} };
		for (int i = 0; i < 4; i++) {
			modify[i][0] = temp[i][0];
			modify[i][1] = temp[i][1];
		}
		rotationState = 0;
	}
}
///\note

