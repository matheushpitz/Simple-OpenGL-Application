#ifndef OBJECT3D_H
#define OBJECT3D_H
#include<Vec3.h>
#include<Mat4.h>
#include "GL/gl.h"
#include "GL/glut.h"

#define MAX_VERTEXS 50

class Object3D
{
    public:
        Object3D();
        virtual ~Object3D();
        void draw();
        void addVertex(Vec3* v);
        void addVertex(float x, float y, float z);
        void addVertexColor(Vec3* c);
        void addVertexColor(float r, float g, float b);
        void addNormal(float nx, float ny, float nz);
        void rotateObject(float x, float y, float z);
        void translateObject(float x, float y, float z);
        void scaleObject(float x, float y, float z);
        void addRotationObject(float x, float y, float z);
        void addTranslationObject(float x, float y, float z);
        void addScaleObject(float x, float y, float z);
        void setViewMatrix(float* m);

    protected:

    private:
        void updateModelMatrix();

        Vec3 *vertexs;
        Vec3 *colors;
        Vec3 *normals;
        int vertexsCount;
        int colorsCount;
        int normalsCount;
        Mat4 *modelViewMatrix;
        Mat4 *viewMatrix;
        float rotX, rotY, rotZ, tX, tY, tZ, sX, sY, sZ;
};

#endif // OBJECT3D_H
