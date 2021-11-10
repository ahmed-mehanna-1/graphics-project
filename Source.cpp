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

void E()
{
    float E_co[] = { 1, 0, 0 };
    vertex<float> E_ve[] = { vertex<float>(.25, .5),
        vertex<float>(0, .5),
        vertex<float>(0, 0),
        vertex<float>(.25, 0),
    };
    draw(GL_LINE_STRIP, E_ve, E_co, 4);

    float E_co2[] = { 1, 0, 0 };
    vertex<float> E_ve2[] = { vertex<float>(0, .25),
        vertex<float>(.25, .25)
    };
    draw(GL_LINES, E_ve2, E_co2, 2);

}
void F()
{
    float F_co[] = { 1, 0, 0 };
    vertex<float> F_ve[] = { vertex<float>(.25, .5),
        vertex<float>(0, .5),
        vertex<float>(0, -.25),
       
    };
    draw(GL_LINE_STRIP, F_ve, F_co, 3);

    float F_co2[] = { 1, 0, 0 };
    vertex<float> F_ve2[] = { vertex<float>(0, .125),
        vertex<float>(.25, .125)
    };
    draw(GL_LINES, F_ve2, F_co2, 2);

}

void H()
{
    float H_co[] = { 1, 0, 0 };
    vertex<float> H_ve[] = { vertex<float>(0, .5),
        vertex<float>(0, -.5)
    };
    draw(GL_LINES, H_ve, H_co, 2);

    float H_co2[] = { 1, 0, 0 };
    vertex<float> H_ve2[] = { vertex<float>(.25, .5),
        vertex<float>(.25, -.5)
    };
    draw(GL_LINES, H_ve2, H_co2, 2);

    float H_co3[] = { 1, 0, 0 };
    vertex<float> H_ve3[] = { vertex<float>(0, 0),
        vertex<float>(.25, 0)
    };
    draw(GL_LINES, H_ve3, H_co3, 2);
}

void I()
{
    float I_co[] = { 1, 0, 0 };
    vertex<float> I_ve[] = { vertex<float>(0, .5),
        vertex<float>(.5, .5)
    };
    draw(GL_LINES, I_ve, I_co, 2);

    float I_co2[] = { 1, 0, 0 };
    vertex<float> I_ve2[] = { vertex<float>(0, -.5),
        vertex<float>(.5, -.5)
    };
    draw(GL_LINES, I_ve2, I_co2, 2);

    float I_co3[] = { 1, 0, 0 };
    vertex<float> I_ve3[] = { vertex<float>(.25, .5),
        vertex<float>(.25, -.5)
    };
    draw(GL_LINES, I_ve3, I_co3, 2);
}

void K()
{
    float K_co[] = { 1, 0, 0 };
    vertex<float> K_ve[] = { vertex<float>(0, .5),
        vertex<float>(0, -.5)
    };
    draw(GL_LINES, K_ve, K_co, 2);

    float K_co2[] = { 1, 0, 0 };
    vertex<float> K_ve2[] = { vertex<float>(.35, .5),
        vertex<float>(0, 0)
    };
    draw(GL_LINES, K_ve2, K_co2, 2);

    float K_co3[] = { 1, 0, 0 };
    vertex<float> K_ve3[] = { vertex<float>(.35, -.5),
        vertex<float>(0, 0)
    };
    draw(GL_LINES, K_ve3, K_co3, 2);

}

void L()
{
    float L_co[] = { 1, 0, 0 };
    vertex<float> L_ve[] = { vertex<float>(0, .75),
        vertex<float>(0, 0),
        vertex<float>(.3, 0),
    };
    draw(GL_LINE_STRIP, L_ve, L_co, 3);
}
void M()
{
    float M_co[] = { 1, 0, 0 };
    vertex<float> M_ve[] = { vertex<float>(0, 0),
        vertex<float>(0, .5),
        vertex<float>(.25, .25),
        vertex<float>(.5, .5),
        vertex<float>(.5, 0)
    };
    draw(GL_LINE_STRIP, M_ve, M_co, 5);
}

void N()
{
    float N_co[] = { 1, 0, 0 };
    vertex<float> N_ve[] = { vertex<float>(0, 0),
        vertex<float>(0, .5),
        vertex<float>(.25, 0),
        vertex<float>(.25, .5),
    };
    draw(GL_LINE_STRIP, N_ve, N_co, 4);

}

void T()
{
    float T_co[] = { 1, 0, 0 };
    vertex<float> T_ve[] = { vertex<float>(0, .5),
        vertex<float>(.5, .5)
    };
    draw(GL_LINES, T_ve, T_co, 2);

    float T_co2[] = { 1, 0, 0 };
    vertex<float> T_ve2[] = { vertex<float>(.25, .5),
        vertex<float>(.25, -.5)
    };
    draw(GL_LINES, T_ve2, T_co2, 2);
}

void V()
{
    float V_co[] = { 1, 0, 0 };
    vertex<float> V_ve[] = { vertex<float>(0, .5),
        vertex<float>(.125, 0),
        vertex<float>(.25, .5),
    };
    draw(GL_LINE_STRIP, V_ve, V_co, 3);
}

void W()
{
    float W_co[] = { 1, 0, 0 };
    vertex<float> W_ve[] = { vertex<float>(0, .5),
        vertex<float>(.125, 0),
        vertex<float>(.25, .5),
        vertex<float>(.375, 0),
        vertex<float>(.5, .5)
    };
    draw(GL_LINE_STRIP, W_ve, W_co, 5);
}

void X()
{
    float X_co[] = { 1, 0, 0 };
    vertex<float> X_ve[] = { vertex<float>(0, .5),
        vertex<float>(.25, 0)
    };
    draw(GL_LINE_STRIP, X_ve, X_co, 2);
    
    float X_co2[] = { 1, 0, 0 };
    vertex<float> X_ve2[] = { vertex<float>(.25, .5),
        vertex<float>(0, 0)
    };
    draw(GL_LINE_STRIP, X_ve2, X_co2, 2);
}

void Y()
{
    float Y_co[] = { 1, 0, 0 };
    vertex<float> Y_ve[] = { vertex<float>(0, .5),
        vertex<float>(.25, 0)
    };
    draw(GL_LINE_STRIP, Y_ve, Y_co, 2);

    float Y2_co[] = { 1, 0, 0 };
    vertex<float> Y2_ve[] = { vertex<float>(.5, .5),
        vertex<float>(.25, 0)
    };
    draw(GL_LINE_STRIP, Y2_ve, Y2_co, 2);

    float Y3_co[] = { 1, 0, 0 };
    vertex<float> Y3_ve[] = { vertex<float>(.25, 0),
        vertex<float>(.25, -.5)
    };
    draw(GL_LINE_STRIP, Y3_ve, Y3_co, 2);

}
void Z()
{
    float Z_co[] = { 1, 0, 0 };
    vertex<float> Z_ve[] = { vertex<float>(0, 0),
        vertex<float>(.5, 0),
        vertex<float>(0, -.5),
        vertex<float>(.5, -.5)
    };
    draw(GL_LINE_STRIP, Z_ve, Z_co, 4);
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

    Y();
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


