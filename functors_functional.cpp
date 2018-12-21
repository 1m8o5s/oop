#include "fucntors_definiton.h"
int add::operator()(int first, int second) {
	reg = (first + second) / 10;
	return (first + second) % 10;
}
int addition::operator()(int first, int second) {
	reg = (first - second) / 10;
	return (first - second) % 10;
}

int times::operator()(int first, int second) {
	reg = (first * second) / 10;
	return (first * second) % 10;
}

int divides::operator()(int first, int second) {
	reg = (first / second) / 10;
	return (first / second) % 10;
}

int modulus::operator()(int first, int second) {
	reg = (first % second) / 10;
	return (first % second) % 10;
}
int negate::operator()(int first) {
	reg = first;
	return -first;
}

bool equal_to::operator()(int first, int second) {
	return first == second;
}