/**
    Created by Matheus Henrique Pitz
    Created in 2017/11/03
    http://www.ioapps.com.br/matheus/
    https://github.com/matheushpitz
**/
#include "Vec3.h"

Vec3::Vec3() {
    this->elements = (float*)malloc(sizeof(float) * 3);
    this->zero();
}

Vec3::Vec3(float x, float y, float z) {
    this->elements = (float*)malloc(sizeof(float) * 3);
    this->setX(x);
    this->setY(y);
    this->setZ(z);
}

Vec3::~Vec3(){
    free(this->elements);
}

float Vec3::getX() {
    return this->elements[0];
}

float Vec3::getY() {
    return this->elements[1];
}

float Vec3::getZ() {
    return this->elements[2];
}

void Vec3::zero() {
    this->elements[0] = 0.0f;
    this->elements[1] = 0.0f;
    this->elements[2] = 0.0f;
}

void Vec3::setX(float x) {
    this->elements[0] = x;
}

void Vec3::setY(float y) {
    this->elements[1] = y;
}

void Vec3::setZ(float z) {
    this->elements[2] = z;
}
