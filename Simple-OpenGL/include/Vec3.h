#ifndef VEC3_H
#define VEC3_H
#include <Mat4.h>
#include <stdlib.h>



class Vec3
{
    public:
        Vec3();
        Vec3(float x, float y, float z);
        virtual ~Vec3();
        void zero();
        float getX();
        float getY();
        float getZ();
        void setX(float x);
        void setY(float y);
        void setZ(float z);

    protected:

    private:
        float *elements;
};

#endif // VEC3_H
