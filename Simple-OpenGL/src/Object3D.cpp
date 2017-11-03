/**
    Created by Matheus Henrique Pitz
    Created in 2017/11/03
    http://www.ioapps.com.br/matheus/
    https://github.com/matheushpitz
**/
#include "Object3D.h"

Object3D::Object3D() {
    this->vertexsCount = 0;
    this->colorsCount = 0;
    this->normalsCount = 0;
    this->vertexs = new Vec3[MAX_VERTEXS]();
    this->colors = new Vec3[MAX_VERTEXS]();
    this->normals = new Vec3[MAX_VERTEXS]();

    // init variables
    this->rotX = 0.0f;
    this->rotY = 0.0f;
    this->rotZ = 0.0f;
    this->sX = 1.0f;
    this->sY = 1.0f;
    this->sZ = 1.0f;
    this->tX = 0.0f;
    this->tY = 0.0f;
    this->tZ = 0.0f;

    this->modelViewMatrix = new Mat4();
    this->viewMatrix = new Mat4();

    this->updateModelMatrix();
}

Object3D::~Object3D() {
    // clear memory instances.
    delete [] this->vertexs;
    delete this->modelViewMatrix;
}

void Object3D::draw() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glMultMatrixf(this->modelViewMatrix->getPointerMatrix());
    for(int i = 0; i < this->vertexsCount/4; i++) {
        glBegin(GL_QUADS);
            for(int j = 0; j < 4; j++) {
                int index = i*4+j;
                glNormal3f(this->normals[index].getX(), this->normals[index].getY(), this->normals[index].getZ());
                glVertex3f(this->vertexs[index].getX(), this->vertexs[index].getY(), this->vertexs[index].getZ());
                glColor4f(this->colors[index].getX(), this->colors[index].getY(), this->colors[index].getZ(), 1.0f);
            }
        glEnd();
    }
    glPopMatrix();
}

void Object3D::addVertex(Vec3* v) {
    if(this->vertexsCount < MAX_VERTEXS) {
        this->vertexs[this->vertexsCount] = *v;
        this->vertexsCount++;
    }
}

void Object3D::addVertexColor(Vec3* c) {
    if(this->colorsCount < MAX_VERTEXS) {
        this->colors[this->colorsCount] = *c;
        this->colorsCount++;
    }
}

void Object3D::addVertex(float x, float y, float z) {
    if(this->vertexsCount < MAX_VERTEXS) {
        Vec3 *v = new Vec3(x, y, z);
        this->vertexs[this->vertexsCount] = *v;
        this->vertexsCount++;
    }
}

void Object3D::addVertexColor(float r, float g, float b) {
    if(this->colorsCount < MAX_VERTEXS) {
        Vec3 *c = new Vec3(r, g, b);
        this->colors[this->colorsCount] = *c;
        this->colorsCount++;
    }
}

void Object3D::addNormal(float nx, float ny, float nz) {
    if(this->normalsCount < MAX_VERTEXS) {
        Vec3 *n = new Vec3(nx, ny, nz);
        this->normals[this->normalsCount] = *n;
        this->normalsCount++;
    }
}

void Object3D::updateModelMatrix() {
    Mat4 *tMatrix = new Mat4();
    Mat4 *sMatrix = new Mat4();
    Mat4 *rxMatrix = new Mat4();
    Mat4 *ryMatrix = new Mat4();
    Mat4 *rzMatrix = new Mat4();

    // make Translation Matrix
    tMatrix->translation(this->tX, this->tY, this->tZ);

    // make scaling matrix.
    sMatrix->scaling(this->sX, this->sY, this->sZ);

    // make Pitch Rotation Matrix
    rxMatrix->rotationX(this->rotX);

    // make Yaw Rotation Matrix
    ryMatrix->rotationY(this->rotY);

    // make Roll Rotation Matrix
    rzMatrix->rotationZ(this->rotZ);

    // multiply Rotation Z with Y
    Mat4 *rzyMatrix = (*rzMatrix) * (*ryMatrix);
    // multiply Rotation ZY with X
    Mat4 *rzyxMatrix = (*rzyMatrix) * (*rxMatrix);
    // multiply Rotation ZYX with Translation.
    Mat4 *trMatrix = (*tMatrix) * (*rzyxMatrix);
    // multiply Translation and Rotation Matrix with Scaling.
    Mat4 *modelMatrix = (*trMatrix) * (*sMatrix);
    // clear instance of memory
    delete this->modelViewMatrix;
    // multiply Model and View Matrix.
    this->modelViewMatrix = (*modelMatrix) * (*this->viewMatrix);

    this->modelViewMatrix->transpose();

    // delete all from memory.
    delete tMatrix;
    delete sMatrix;
    delete trMatrix;
    delete rxMatrix;
    delete ryMatrix;
    delete rzMatrix;
    delete rzyMatrix;
    delete rzyxMatrix;
    delete modelMatrix;
}
/**
* Set rotation to object.
**/
void Object3D::rotateObject(float x, float y, float z) {
    this->rotX = x;
    this->rotY = y;
    this->rotZ = z;

    this->updateModelMatrix();
}
/**
* Set scale to object.
**/
void Object3D::scaleObject(float x, float y, float z) {
    this->sX = x;
    this->sY = y;
    this->sZ = z;

    this->updateModelMatrix();
}
/**
* Set translation to object.
**/
void Object3D::translateObject(float x, float y, float z) {
    this->tX = x;
    this->tY = y;
    this->tZ = z;

    this->updateModelMatrix();
}
/**
* Add rotation to object.
**/
void Object3D::addRotationObject(float x, float y, float z) {
    this->rotX += x;
    this->rotY += y;
    this->rotZ += z;

    this->updateModelMatrix();
}
/**
* Add scale to object.
**/
void Object3D::addScaleObject(float x, float y, float z) {
    this->sX += x;
    this->sY += y;
    this->sZ += z;

    this->updateModelMatrix();
}
/**
*
**/
void Object3D::addTranslationObject(float x, float y, float z) {
    this->tX += x;
    this->tY += y;
    this->tZ += z;

    this->updateModelMatrix();
}

void Object3D::setViewMatrix(float* m) {
    this->viewMatrix->setElements(m);
}
