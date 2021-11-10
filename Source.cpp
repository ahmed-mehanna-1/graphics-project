// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <utility>
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
void draw(GLenum type, vertex<T>* v, float* rgb, int v_no, bool _3d = false, float lw = 5, float ps = 6) {
    glPointSize(ps);
    glLineWidth(lw);
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
    glFlush();
    return;
}

pair<bool, float> _check(float val, float i, bool position, float _val, float plus) {
    if (position && val < _val)
        return pair<bool, float>(true, i + plus);
    else if (!position && val > _val)
        return pair<bool, float>(true, i + plus);
    //else if (top && y < _y)
    //    return pair<bool, float>(true, i + plus);
    //else if (!top && y > _y)
    //    return pair<bool, float>(true, i + plus);

    return pair<bool, float>(false, i);
}

void _(float x, float y, float r, float* rgb, float x_sc = 1, float y_sc = 1, bool full = true, bool _right = true, bool _top = false, bool right = true, bool top = false, float _x = 0, float _y = 0) {
    glColor3f(rgb[0], rgb[1], rgb[2]);
    float base_x = x;
    float base_y = y;
    cout << base_x << endl;
    pair<bool, float> status;

    glBegin(GL_POINTS);
    for (float i = 0; i <= 360;) {
        x = r * cos(i) * x_sc;
        if (!full && _right) {
            status = _check(x, i, right, _x * x_sc, 1);
            i = status.second;
            if (status.first)
                continue;
        }
        y = r * sin(i) * y_sc;
        if (!full && _top) {
            status = _check(y, i, right, _y * y_sc, 1);
            i = status.second;
            if (status.first)
                continue;
        }
        glVertex2d(x + base_x, y + base_y);
        cout << x << "  " << _x << endl;

        i += .5;

        x = r * cos(i) * x_sc;
        if (!full && _right) {
            status = _check(x, i, right, _x * x_sc, .5);
            i = status.second;
            if (status.first)
                continue;
        }
        y = r * sin(i) * y_sc;
        if (!full && _top) {
            status = _check(y, i, right, _y * y_sc, .5);
            i = status.second;
            if (status.first)
                continue;
        }
        glVertex2d(x + base_x, y + base_y);
        i += .5;
        cout << x << "  " << _x << endl;
    }
    glEnd();
}

//void _(float x, float y, float r, float* rgb, float x_sc = 1, float y_sc = 1, bool full = true, bool right = true, float _x = 0) {
//    glColor3f(rgb[0], rgb[1], rgb[2]);
//    pair<bool, float> status;
//    glBegin(GL_POINTS);
//    glVertex2f(x, y);
//    for (float i = 0; i <= 360;) {
//        x = r * cos(i) * x_sc;
//        cout << x << "  " << _x << endl;
//        if (!full)
//            status = _check(x, y, i, right, _x * x_sc, 1);
//        i = status.second;
//        if (status.first)
//            continue;
//        y = r * sin(i) * y_sc + y;
//        glVertex2f(x, y);
//        cout << x << "  " << _x << endl;
//
//        i += .5;
//
//        x = r * cos(i) * x_sc;
//        if (!full)
//            status = _check(x, y, i, right, _x * x_sc, .5);
//        i = status.second;
//        if (status.first)
//            continue;
//        y = r * sin(i) * y_sc + y;
//        glVertex2f(x, y);
//        i += .5;
//        cout << x << "  " << _x << endl;
//    }
//    glEnd();
//}

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

void B() {
    float B_co[] = { 1, 0, 0 };
    vertex<float> B_ve[] = { vertex<float>(-.3, 0),
        vertex<float>(-.3, .6)
    };
    draw(GL_LINES, B_ve, B_co, 2);

    float B_co2[] = { 1, 0, 0 };
    _(-.3, .45, .15, B_co2, 1, 1, false, true, 0);
    
    float B_co3[] = { 1, 0, 0 };
    _(-.3, .15, .15, B_co3, 1.15, 1, false, true, 0);
}

void C() {
    float C_co[] = { 1, 0, 0 };
    //_(-.3, .3, .25, C_co, .7, 1, false, false, .1);
    _(-.3, .3, .25, C_co, .7, 1, false, true, false, false, false, .1);
    //_(0, 0, .25, C_co, .8, 1.35, false, false, 0);
}

void D() {
    float D_co[] = { 1, 0, 0 };
    vertex<float> D_ve[] = { vertex<float>(-.3, 0),
        vertex<float>(-.3, .6)
    };
    draw(GL_LINES, D_ve, D_co, 2);

    float D_co2[] = { 1, 0, 0 };
    _(-.3, .3, .15, D_co2, 1, 2, false, true, false, true);
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

void G() {
    float G_co[] = { 1, 0, 0 };
    _(-.3, .3, .25, G_co, .5, .9, false, true, false, false, false, .05);

    float G_co2[] = { 1, 0, 0 };
    vertex<float> G_ve[] = { vertex<float>(-.3, .075),
        vertex<float>(-.25, .075),
        vertex<float>(-.25, .25),
        vertex<float>(-.3, .25)
    };
    draw(GL_LINE_STRIP, G_ve, G_co2, 4);
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

void O() {
    float O_co[] = { 1, 0, 0 };
    _(-.3, .3, .25, O_co, .65);
}

void P() {
    float P_co[] = { 1, 0, 0 };
    vertex<float> P_ve[] = { vertex<float>(-.3, 0),
        vertex<float>(-.3, .6)
    };
    draw(GL_LINES, P_ve, P_co, 2);

    float P_co2[] = { 1, 0, 0 };
    _(-.3, .45, .15, P_co2, 1, 1, false, true, false, true);
}

void Q() {
    float O_co[] = { 1, 0, 0 };
    _(-.3, .3, .25, O_co, .65);

    float Q_co[] = { 1, 0, 0 };
    vertex<float> Q_ve[] = { vertex<float>(-.3, .3),
        vertex<float>(-.2, -.05)
    };
    draw(GL_LINES, Q_ve, Q_co, 2, false, 7);
}

void R() {
    float R_co[] = { 1, 0, 0 };
    vertex<float> R_ve[] = { vertex<float>(-.3, 0),
        vertex<float>(-.3, .6),
        vertex<float>(-.3, .58),
        vertex<float>(-.25, .58),
        vertex<float>(-.3, .3),
        vertex<float>(-.25, .3)
    };
    draw(GL_LINES, R_ve, R_co, 6, 7);

    float R_co2[] = { 1, 0, 0 };
    _(-.295, .445, .15, R_co2, .8, 1, false, true, false, true, false, .05);

    float R_co3[] = { 1, 0, 0 };
    vertex<float> R_ve3[] = { vertex<float>(-.25, .3),
        vertex<float>(-.2, .1)
    };
    draw(GL_LINES, R_ve3, R_co3, 2);

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

void U() {
    float U_co[] = { 1, 0, 0 };
    _(-.3, .3, .25, U_co, .5, .9, false, false, true, false, true, 0, .015);

    float U_co2[] = { 1, 0, 0 };
    vertex<float> U_ve2[] = { vertex<float>(-.426, .3),
        vertex<float>(-.426, .65),
        vertex<float>(-.177, .3),
        vertex<float>(-.177, .65)
    };
    draw(GL_LINES, U_ve2, U_co2, 4, 20);
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

    Q();
    //glColor3f(0, 1, 0);
    //glBegin(GL_POINTS);
    //glVertex2f(0, 0);
    //glEnd();

    //glColor3f(1, 0, 0);
    //float x[]{ 1, 0, 0 };
    // _(-.3, .3, .25, x, 1, 1, false, true, true, false, false, .05, .05);
    //_(-.9, 0, .5);
    //_(0, 0, .5, x, .5, 1, false, true, -.15);
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
