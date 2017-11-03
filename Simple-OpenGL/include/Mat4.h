#ifndef MAT3_H
#define MAT3_H

#include <stdlib.h>
#include <math.h>


class Mat4
{
    public:
        Mat4();
        virtual ~Mat4();
        void zero();
        void identity();
        void translation(float x, float y, float z);
        void scaling(float x, float y, float z);
        void rotationX(float angle);
        void rotationY(float angle);
        void rotationZ(float angle);
        void setElement(int index, float v);
        void setElements(float* v);
        float getElement(int index);
        Mat4* operator*(Mat4 m);
        float* getPointerMatrix();
        void transpose();

    protected:

    private:
        float *elements;
};

#endif
