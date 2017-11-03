/**
    Created by Matheus Henrique Pitz
    Created in 2017/11/03
    http://www.ioapps.com.br/matheus/
    https://github.com/matheushpitz
**/
#include <windows.h>
#include "GL/glut.h"
#include <iostream>
#include <Object3D.h>

using namespace std;


Object3D *cube;

  void update() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.000, 0.110, 0.392, 0.0);
    glShadeModel(GL_FLAT);
    cube->draw();
    glFlush();
    Sleep(10);
    glutPostRedisplay();
  }

  void init() {
    cout << "Initializing...." << endl;

    cube = new Object3D();

    cube->translateObject(0.0f, 0.0f, -8.0f);

    glClearColor(0.000, 0.110, 0.392, 0.0);
    glEnable(GL_DEPTH_TEST);

    // load vertexs
    // FRONT FACE
    cube->addVertex(1.0f, 1.0f, 1.0f);
    cube->addVertex(1.0f, -1.0f, 1.0f);
    cube->addVertex(-1.0f, -1.0f, 1.0f);
    cube->addVertex(-1.0f, 1.0f, 1.0f);
    // Front Face Color
    cube->addVertexColor(1.0f, 0.0f, 0.0f);
    cube->addVertexColor(1.0f, 0.0f, 0.0f);
    cube->addVertexColor(1.0f, 0.0f, 0.0f);
    cube->addVertexColor(1.0f, 0.0f, 0.0f);
    // Front Face Normals
    cube->addNormal(0.0f, 0.0f, 1.0f);
    cube->addNormal(0.0f, 0.0f, 1.0f);
    cube->addNormal(0.0f, 0.0f, 1.0f);
    cube->addNormal(0.0f, 0.0f, 1.0f);

    // BACK FACE
    cube->addVertex(1.0f, 1.0f, -1.0f);
    cube->addVertex(1.0f, -1.0f, -1.0f);
    cube->addVertex(-1.0f, -1.0f, -1.0f);
    cube->addVertex(-1.0f, 1.0f, -1.0f);
    // Back Face Color
    cube->addVertexColor(0.0f, 1.0f, 0.0f);
    cube->addVertexColor(0.0f, 1.0f, 0.0f);
    cube->addVertexColor(0.0f, 1.0f, 0.0f);
    cube->addVertexColor(0.0f, 1.0f, 0.0f);
    // Back Face Normals
    cube->addNormal(0.0f, 0.0f, -1.0f);
    cube->addNormal(0.0f, 0.0f, -1.0f);
    cube->addNormal(0.0f, 0.0f, -1.0f);
    cube->addNormal(0.0f, 0.0f, -1.0f);

    // LEFT FACE
    cube->addVertex(-1.0f, 1.0f, -1.0f);
    cube->addVertex(-1.0f, -1.0f, -1.0f);
    cube->addVertex(-1.0f, -1.0f, 1.0f);
    cube->addVertex(-1.0f, 1.0f, 1.0f);
    // Left Face Color
    cube->addVertexColor(1.0f, 1.0f, 0.0f);
    cube->addVertexColor(1.0f, 1.0f, 0.0f);
    cube->addVertexColor(1.0f, 1.0f, 0.0f);
    cube->addVertexColor(1.0f, 1.0f, 0.0f);
    // Left Face Normals
    cube->addNormal(-1.0f, 0.0f, 0.0f);
    cube->addNormal(-1.0f, 0.0f, 0.0f);
    cube->addNormal(-1.0f, 0.0f, 0.0f);
    cube->addNormal(-1.0f, 0.0f, 0.0f);

    // RIGHT FACE
    cube->addVertex(1.0f, 1.0f, -1.0f);
    cube->addVertex(1.0f, -1.0f, -1.0f);
    cube->addVertex(1.0f, -1.0f, 1.0f);
    cube->addVertex(1.0f, 1.0f, 1.0f);
    // Right Face Color
    cube->addVertexColor(0.0f, 0.0f, 1.0f);
    cube->addVertexColor(0.0f, 0.0f, 1.0f);
    cube->addVertexColor(0.0f, 0.0f, 1.0f);
    cube->addVertexColor(0.0f, 0.0f, 1.0f);
    // Right Face Normals
    cube->addNormal(1.0f, 0.0f, 0.0f);
    cube->addNormal(1.0f, 0.0f, 0.0f);
    cube->addNormal(1.0f, 0.0f, 0.0f);
    cube->addNormal(1.0f, 0.0f, 0.0f);

    // TOP FACE
    cube->addVertex(1.0f, 1.0f, -1.0f);
    cube->addVertex(1.0f, 1.0f, 1.0f);
    cube->addVertex(-1.0f, 1.0f, 1.0f);
    cube->addVertex(-1.0f, 1.0f, -1.0f);
    // Top Face Color
    cube->addVertexColor(1.0f, 0.0f, 1.0f);
    cube->addVertexColor(1.0f, 0.0f, 1.0f);
    cube->addVertexColor(1.0f, 0.0f, 1.0f);
    cube->addVertexColor(1.0f, 0.0f, 1.0f);
    // Top Face Normals
    cube->addNormal(0.0f, 1.0f, 0.0f);
    cube->addNormal(0.0f, 1.0f, 0.0f);
    cube->addNormal(0.0f, 1.0f, 0.0f);
    cube->addNormal(0.0f, 1.0f, 0.0f);


    // BOTTOM FACE
    cube->addVertex(1.0f, -1.0f, -1.0f);
    cube->addVertex(1.0f, -1.0f, 1.0f);
    cube->addVertex(-1.0f, -1.0f, 1.0f);
    cube->addVertex(-1.0f, -1.0f, -1.0f);
    // Bottom Face Color
    cube->addVertexColor(0.0f, 1.0f, 1.0f);
    cube->addVertexColor(0.0f, 1.0f, 1.0f);
    cube->addVertexColor(0.0f, 1.0f, 1.0f);
    cube->addVertexColor(0.0f, 1.0f, 1.0f);
    // Bottom Face Normals
    cube->addNormal(0.0f, -1.0f, 0.0f);
    cube->addNormal(0.0f, -1.0f, 0.0f);
    cube->addNormal(0.0f, -1.0f, 0.0f);
    cube->addNormal(0.0f, -1.0f, 0.0f);

    cout << "Initialized" << endl;
  }

  void reshape(int x, int y) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,200.0);
        glMatrixMode(GL_MODELVIEW);
        glViewport(0,0,x,y);  //Use the whole window for rendering
  }

void arrowKeysEvent(int key, int x, int y) {
    return;
    switch(key) {
        case GLUT_KEY_UP:
            // key up function
            break;
        case GLUT_KEY_DOWN:
            // key down function
            break;
        case GLUT_KEY_LEFT:
            // key left function
            break;
        case GLUT_KEY_RIGHT:
            // key right function
            break;
    }
}

void keyEvent(unsigned char key, int x, int y) {
    float tAmount = 0.5f;
    float rAmount = 1.0f;
    float sAmount = 0.1f;
    if(key == 'w') {
        cube->addTranslationObject(0.0f, 0.0f, tAmount * -1.0f);
    } else if(key == 's') {
        cube->addTranslationObject(0.0f, 0.0f, tAmount);
    } else if(key == 'a') {
        cube->addTranslationObject(tAmount * -1.0f, 0.0f, 0.0f);
    } else if(key == 'd') {
        cube->addTranslationObject(tAmount, 0.0f, 0.0f);
    } else if(key == 'q') {
        cube->addTranslationObject(0.0f, tAmount * -1.0f, 0.0f);
    } else if(key == 'e') {
        cube->addTranslationObject(0.0f, tAmount, 0.0f);
    } else if(key == 'r') {
        // RESET CUBE
        cube->translateObject(0.0f, 0.0f, -8.0f);
        cube->rotateObject(0.0f, 0.0f, 0.0f);
        cube->scaleObject(1.0f, 1.0f, 1.0f);
    } else if(key == 'x') {
        cube->addRotationObject(rAmount, 0.0f, 0.0f);
    } else if(key == 'y') {
        cube->addRotationObject(0.0f, rAmount, 0.0f);
    } else if(key == 'z') {
        cube->addRotationObject(0.0f, 0.0f, rAmount);
    } else if(key == '1') {
        cube->addScaleObject(sAmount * -1.0f, 0.0f, 0.0f);
    } else if(key == '2') {
        cube->addScaleObject(sAmount, 0.0f, 0.0f);
    } else if(key == '3') {
        cube->addScaleObject(0.0f, sAmount * -1.0f, 0.0f);
    } else if(key == '4') {
        cube->addScaleObject(0.0f, sAmount, 0.0f);
    } else if(key == '5') {
        cube->addScaleObject(0.0f, 0.0f, sAmount * -1.0f);
    } else if(key == '6') {
        cube->addScaleObject(0.0f, 0.0f, sAmount);
    }
}

  int main(int argc, char** argv) {
    cout << "Initializing Open GL" << endl;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1280, 720);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Test");
    init();
    glutSpecialFunc(arrowKeysEvent);
    glutKeyboardFunc(keyEvent);
    glutDisplayFunc(update);
    glutReshapeFunc(reshape);

    // COMMANDS
    cout << endl;
    cout << "Commands:" << endl;
    cout << "W and S move cube on z axis" << endl;
    cout << "A and D move cube on x axis" << endl;
    cout << "Q and E move cube on y axis" << endl;
    cout << "X rotate cube on x axis" << endl;
    cout << "Y rotate cube on y axis" << endl;
    cout << "Z rotate cube on z axis" << endl;
    cout << "1 and 2 scale cube on x axis" << endl;
    cout << "3 and 4 scale cube on y axis" << endl;
    cout << "5 and 6 scale cube on z axis" << endl;
    cout << "R reset the cube" << endl;

    glutMainLoop();
  }
