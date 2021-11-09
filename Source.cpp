// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <GL/glut.h>
#include <math.h>
#define PI 3.141592653589793238
using namespace std;


template <typename T>
struct vertex {
    float x;
    float y;
    float z = 0;
    vertex(float x, float y) {
        this->x = x;
        this->y = y;
    }
    vertex(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

template <typename T>
void draw(GLenum type, vertex<T>* v, float* rgb, int v_no, bool _3d = false) {
    glBegin(type);
    glColor3f(rgb[0], rgb[1], rgb[2]);
    for (int i = 0; i < v_no; i++) {
        cout << v[i].x << "  " << v[i].y << "  " << v[i].z << endl;
        if (!_3d)
            glVertex2f(v[i].x, v[i].y);
        else
            glVertex3f(v[i].x, v[i].y, v[i].z);
    }
    glEnd();
    return;
}

void _(float x, float y, float r) {
    float base_x = x;
    glBegin(GL_POINTS);
    for (float i = 0; i <= 360;) {
        x = r * cos(i);
        if (x < base_x) {
            i += 1;
            continue;
        }
        y = r * sin(i);
        glVertex2d(x, y);

        i += .5;
        x = r * cos(i);
        if (x < base_x) {
            i += .5;
            continue;
        }
        y = r * sin(i);
        glVertex2d(x, y);
        i += .5;
        cout << x << "  " << base_x << endl;
    }
    glEnd();
}

void A() {
    float A_co[] = { 1, 0, 0 };
    vertex<float> A_ve[] = { vertex<float>(-.3, 0),
        vertex<float>(-.15, .6),
        vertex<float>(0, 0)
    };
    draw(GL_LINE_STRIP, A_ve, A_co, 3);

    float A_co2[] = { 1, 0, 0 };
    vertex<float> A_ve2[] = { vertex<float>(-.22, .3),
        vertex<float>(-.08, .3)
    };
    draw(GL_LINES, A_ve2, A_co2, 2);
}

void display() {

    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(6.0);
    glLineWidth(5);

    //gluOrtho2D(0, 1, 0, 1);

    /*
        GL_POINTS
        GL_LINES (no. of lines % 2 = 0)
        GL_LINE_STRIP, GL_TRIANGLES
        GL_TRIANGLE_STRIP (takes last two points)
        GL_TRIANGLE_FAN (takes first and last points)
        GL_QUADS (no. of points % 4 = 0)
        GL_QUAD_STRIP
        GL_POLYGON (any no. of points)
    */

    A();
    //glColor3f(0, 1, 0);
    //glBegin(GL_POINTS);
    //glVertex2f(0, 0);
    //glEnd();

    //glColor3f(1, 0, 0);
    //_(0, 0, .5);
    //_circle2();

    glutSwapBuffers();  //  in Double Buffers => glutSwapBuffers(hDC)
}


double rotate_y = 0, rotate_x = 0;

void display3d() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(rotate_x, 1, 0, 0);
    glRotatef(rotate_y, 0, 1, 0);

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y) {
    if (key == GLUT_KEY_RIGHT)
        rotate_y += 5;
    else if (key == GLUT_KEY_LEFT)
        rotate_y -= 5;
    else if (key == GLUT_KEY_UP)
        rotate_x += 5;
    else if (key == GLUT_KEY_DOWN)
        rotate_x -= 5;

    glutPostRedisplay();

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);  //
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);   //GLUT_DOUBLE GLUT_DEPTH
//
    glutInitWindowSize(700, 400);   //
    glutInitWindowPosition(90, 90);   //
    glutCreateWindow("Project"); //
    //glEnable(GLUT_DEPTH);

    glutDisplayFunc(display);   //  Seting the function that will create the graphics
    //glutSpecialFunc(specialKeys);
    glutMainLoop(); // To keep the window running
}
