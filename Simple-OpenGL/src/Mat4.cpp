/**
    Created by Matheus Henrique Pitz
    Created in 2017/11/03
    http://www.ioapps.com.br/matheus/
    https://github.com/matheushpitz
**/
#include "Mat4.h"

#define PI 3.14159265

Mat4::Mat4() {
    this->elements = (float*)malloc(sizeof(float) * 16);
    this->identity();
}

Mat4::~Mat4() {
    free(this->elements);
}

void Mat4::zero() {
    this->elements[0] = 0.0f;
    this->elements[1] = 0.0f;
    this->elements[2] = 0.0f;
    this->elements[3] = 0.0f;

    this->elements[4] = 0.0f;
    this->elements[5] = 0.0f;
    this->elements[6] = 0.0f;
    this->elements[7] = 0.0f;

    this->elements[8] = 0.0f;
    this->elements[9] = 0.0f;
    this->elements[10] = 0.0f;
    this->elements[11] = 0.0f;

    this->elements[12] = 0.0f;
    this->elements[13] = 0.0f;
    this->elements[14] = 0.0f;
    this->elements[15] = 0.0f;
}

void Mat4::identity() {
    this->zero();

    this->elements[0] = 1.0f;

    this->elements[5] = 1.0f;

    this->elements[10] = 1.0f;

    this->elements[15] = 1.0f;
}

void Mat4::translation(float x, float y, float z) {
    this->elements[3] = x;
    this->elements[7] = y;
    this->elements[11] = z;
}

void Mat4::scaling(float x, float y, float z) {
    this->elements[0] = x;
    this->elements[5] = y;
    this->elements[10] = z;
}

void Mat4::rotationX(float angle) {
    float c = (float)cos(angle * PI/180);
    float s = (float)sin(angle * PI/180);

    this->elements[5] = c;
    this->elements[6] = s * -1.0f;
    this->elements[9] = s;
    this->elements[10] = c;
}

void Mat4::rotationY(float angle) {
    float c = (float)cos(angle * PI/180);
    float s = (float)sin(angle * PI/180);

    this->elements[0] = c;
    this->elements[2] = s;
    this->elements[8] = s * -1.0f;
    this->elements[10] = c;
}

void Mat4::rotationZ(float angle) {
    float c = (float)cos(angle * PI/180);
    float s = (float)sin(angle * PI/180);

    this->elements[0] = c;
    this->elements[1] = s * -1.0f;
    this->elements[4] = s;
    this->elements[5] = c;
}

void Mat4::setElement(int index, float v) {
    if(index > -1 && index < 16) {
        this->elements[index] = v;
    }
}

void Mat4::setElements(float* v) {
    for(int i = 0; i < 16; i++) {
        this->setElement(i, v[i]);
    }
}

float Mat4::getElement(int index) {
    if(index > -1 && index < 16) {
        return this->elements[index];
    }
    return 0.0f;
}
/**
* Multiply 2 matrices
**/
Mat4* Mat4::operator*(Mat4 m) {
    Mat4 *result = new Mat4();

    result->setElement(0, (this->getElement(0) * m.getElement(0) + this->getElement(1) * m.getElement(4) + this->getElement(2) * m.getElement(8) + this->getElement(3) * m.getElement(12)));
    result->setElement(1, (this->getElement(0) * m.getElement(1) + this->getElement(1) * m.getElement(5) + this->getElement(2) * m.getElement(9) + this->getElement(3) * m.getElement(13)));
    result->setElement(2, (this->getElement(0) * m.getElement(2) + this->getElement(1) * m.getElement(6) + this->getElement(2) * m.getElement(10) + this->getElement(3) * m.getElement(14)));
    result->setElement(3, (this->getElement(0) * m.getElement(3) + this->getElement(1) * m.getElement(7) + this->getElement(2) * m.getElement(11) + this->getElement(3) * m.getElement(15)));

    result->setElement(4, (this->getElement(4) * m.getElement(0) + this->getElement(5) * m.getElement(4) + this->getElement(6) * m.getElement(8) + this->getElement(7) * m.getElement(12)));
    result->setElement(5, (this->getElement(4) * m.getElement(1) + this->getElement(5) * m.getElement(5) + this->getElement(6) * m.getElement(9) + this->getElement(7) * m.getElement(13)));
    result->setElement(6, (this->getElement(4) * m.getElement(2) + this->getElement(5) * m.getElement(6) + this->getElement(6) * m.getElement(10) + this->getElement(7) * m.getElement(14)));
    result->setElement(7, (this->getElement(4) * m.getElement(3) + this->getElement(5) * m.getElement(7) + this->getElement(6) * m.getElement(11) + this->getElement(7) * m.getElement(15)));

    result->setElement(8, (this->getElement(8) * m.getElement(0) + this->getElement(9) * m.getElement(4) + this->getElement(10) * m.getElement(8) + this->getElement(11) * m.getElement(12)));
    result->setElement(9, (this->getElement(8) * m.getElement(1) + this->getElement(9) * m.getElement(5) + this->getElement(10) * m.getElement(9) + this->getElement(11) * m.getElement(13)));
    result->setElement(10, (this->getElement(8) * m.getElement(2) + this->getElement(9) * m.getElement(6) + this->getElement(10) * m.getElement(10) + this->getElement(11) * m.getElement(14)));
    result->setElement(11, (this->getElement(8) * m.getElement(3) + this->getElement(9) * m.getElement(7) + this->getElement(10) * m.getElement(11) + this->getElement(11) * m.getElement(15)));

    result->setElement(12, (this->getElement(12) * m.getElement(0) + this->getElement(13) * m.getElement(4) + this->getElement(14) * m.getElement(8) + this->getElement(15) * m.getElement(12)));
    result->setElement(13, (this->getElement(12) * m.getElement(1) + this->getElement(13) * m.getElement(5) + this->getElement(14) * m.getElement(9) + this->getElement(15) * m.getElement(13)));
    result->setElement(14, (this->getElement(12) * m.getElement(2) + this->getElement(13) * m.getElement(6) + this->getElement(14) * m.getElement(10) + this->getElement(15) * m.getElement(14)));
    result->setElement(15, (this->getElement(12) * m.getElement(3) + this->getElement(13) * m.getElement(7) + this->getElement(14) * m.getElement(11) + this->getElement(15) * m.getElement(15)));

    return result;
}

float* Mat4::getPointerMatrix() {
    return this->elements;
}
/**
* Generate the transpose matrix.
**/
void Mat4::transpose() {
    float *aux = (float*)malloc(sizeof(float) * 16);

    for(int i = 0; i < 16; i++) {
        aux[i] = this->elements[i];
    }

    this->setElement(1, aux[4]);
    this->setElement(2, aux[8]);
    this->setElement(3, aux[12]);

    this->setElement(4, aux[1]);
    this->setElement(6, aux[9]);
    this->setElement(7, aux[13]);

    this->setElement(8, aux[2]);
    this->setElement(9, aux[6]);
    this->setElement(11, aux[14]);

    this->setElement(12, aux[3]);
    this->setElement(13, aux[7]);
    this->setElement(14, aux[11]);

    free(aux);
}
