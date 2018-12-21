#pragma once
class add {
public:
	int reg;
	int operator()(int first, int second);
};
class addition {
public:
	int reg;
	int operator()(int first, int second);
};
class times {
public:
	int reg;
	int operator()(int first, int second);
};
class divides {
public:
	int reg;
	int operator()(int first, int second);
};
class modulus {
public:
	int reg;
	int operator()(int first, int second);
};
class negate {
public:
	int reg;
	int operator()(int first);
};
class equal_to {
public:
	int reg;
	bool operator()(int first, int second);
};