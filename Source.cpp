// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// cc main.c -lglut -lGLU -lGL
#include <iostream>
#include <utility>
// #include <GL/glut.h>
#include "GL/freeglut.h"
#include "GL/gl.h"
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

pair<bool, float> _check(float val, float i, bool position, bool dir, float _val, float plus) {
    
    switch (dir) {
    case true:
        if (position && val > _val)
            return pair<bool, float>(true, i + plus);
        else if (!position && val < _val)
            return pair<bool, float>(true, i + plus);
        break;
    case false:
        if (position && val < _val)
            return pair<bool, float>(true, i + plus);
        else if (!position && val > _val)
            return pair<bool, float>(true, i + plus);
        break;
    }

    return pair<bool, float>(false, i);
}

template <typename T>
void _(
    vertex<T> v,
    float r,
    float* rgb,
    float x_sc = 1,
    float y_sc = 1,
    bool full = true, 
    bool right = true, 
    bool left = false, 
    bool top = false, 
    bool bottom = false, 
    float _right = 0,
    float _left = 0, 
    float _top = 0, 
    float _bottom = 0) {

    glColor3f(rgb[0], rgb[1], rgb[2]);
    float base_x = v.x;
    float base_y = v.y;
    float x1, y1, x2, y2;

    cout << "hello2" << endl;
    pair<bool, float> status;

    glBegin(GL_POINTS);
    for (float i = 0; i <= 360;) {
        x1 = r * cos(i) * x_sc;
        if (!full && right) {
            status = _check(x1, i, right, true, _right * x_sc, 1);
            i = status.second;
            if (status.first)
                continue;
        }
        if (!full && left) {
            status = _check(x1, i, left, false, _left * x_sc, 1);
            i = status.second;
            if (status.first)
                continue;
        }
        y1 = r * sin(i) * y_sc;
        if (!full && top) {
            status = _check(y1, i, top, true, _top * y_sc, 1);
            i = status.second;
            if (status.first)
                continue;
        }
        if (!full && bottom) {
            status = _check(y1, i, bottom, false, _bottom * y_sc, 1);
            i = status.second;
            if (status.first)
                continue;
        }
        i += .5;

        x2 = r * cos(i) * x_sc;
        if (!full && right) {
            status = _check(x2, i, right, true, _right * x_sc, .5);
            i = status.second;
            if (status.first)
                continue;
        }
        if (!full && left) {
            status = _check(x2, i, left, false, _left * x_sc, .5);
            i = status.second;
            if (status.first)
                continue;
        }
        y2 = r * sin(i) * y_sc;
        if (!full && top) {
            status = _check(y2, i, top, true, _top * y_sc, .5);
            i = status.second;
            if (status.first)
                continue;
        }
        if (!full && bottom) {
            status = _check(y2, i, bottom, false, _bottom * y_sc, .5);
            i = status.second;
            if (status.first)
                continue;
        }
        i += .5;

        glVertex2d(x1 + base_x, y1 + base_y);
        glVertex2d(x2 + base_x, y2 + base_y);
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

void B() {
    float B_co[] = { 1, 0, 0 };
    vertex<float> B_ve[] = { vertex<float>(-.3, 0),
        vertex<float>(-.3, .6)
    };
    draw(GL_LINES, B_ve, B_co, 2, false, 7);

    float B_co2[] = { 1, 0, 0 };
    _(vertex<float>(-.3, .45), .15, B_co2, 1, 1, false, false, true);
    
    float B_co3[] = { 1, 0, 0 };
    _(vertex<float>(-.3, .15), .15, B_co3, 1.15, 1, false, false, true);
}

void C() {
    float C_co[] = { 1, 0, 0 };
    _(vertex<float>(-.3, .3), .25, C_co, .5, 1, false, true, false, false, false, .125);
}

void D() {
    float D_co[] = { 1, 0, 0 };
    vertex<float> D_ve[] = { vertex<float>(-.3, 0),
        vertex<float>(-.3, .6)
    };
    draw(GL_LINES, D_ve, D_co, 2, false, 7);

    float D_co2[] = { 1, 0, 0 };
    _(vertex<float>(-.3, .3), .15, D_co2, 1, 2, false, false, true, false, false);
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
    _(vertex<float>(-.3, .3), .25, G_co, .5, .9, false, true, false, false, false, .05);

    float G_co2[] = { 1, 0, 0 };
    vertex<float> G_ve[] = { vertex<float>(-.3, .075),
        vertex<float>(-.25, .075),
        vertex<float>(-.25, .25),
        vertex<float>(-.3, .25)
    };
    draw(GL_LINE_STRIP, G_ve, G_co2, 4, false, 7);
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

void J() {
    float J_co[] = { 1, 0, 0 };
    _(vertex<float>(-.3, .3), .25, J_co, .5, 1, false, false, false, true);

    float J_co2[] = { 1, 0, 0 };
    vertex<float> J_ve[] = { vertex<float>(-.175, .28), vertex<float>(-.175, .9) };
    draw(GL_LINES, J_ve, J_co, 2, false, 7);
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
    _(vertex<float>(-.3, .3), .25, O_co, .65);
}

void P() {
    //float P_co[] = { 1, 0, 0 };
    //vertex<float> P_ve[] = { vertex<float>(-.3, 0),
    //    vertex<float>(-.3, .6)
    //};
    //draw(GL_LINES, P_ve, P_co, 2, false, 7);

    //float P_co2[] = { 1, 0, 0 };
    //_(-.3, .45, .15, P_co2, 1, 1, false, false, true, false);


    float P_co[] = { 1, 0, 0 };
    vertex<float> P_ve[] = { vertex<float>(-.3, 0),
        vertex<float>(-.3, .6),
        vertex<float>(-.3, .58),
        vertex<float>(-.25, .58),
        vertex<float>(-.3, .3),
        vertex<float>(-.25, .3)
    };
    draw(GL_LINES, P_ve, P_co, 6, false, 7);

    float P_co2[] = { 1, 0, 0 };
    _(vertex<float>(-.295, .445), .15, P_co2, .8, 1, false, false, true, false, false, 0, .05);
}

void Q() {
    float O_co[] = { 1, 0, 0 };
    _(vertex<float>(-.3, .3), .25, O_co, .65);

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
    draw(GL_LINES, R_ve, R_co, 6, false, 7);

    float R_co2[] = { 1, 0, 0 };
    _(vertex<float>(-.295, .445), .15, R_co2, .8, 1, false, false, true, false, false, 0, .05);

    float R_co3[] = { 1, 0, 0 };
    vertex<float> R_ve3[] = { vertex<float>(-.28, .3),
        vertex<float>(-.2, 0)
    };
    draw(GL_LINES, R_ve3, R_co3, 2, false, 7);

}

void S() {
    float S_co[] = { 1, 0, 0 };
    _(vertex<float>(-.37, .55), .25, S_co, .7, 1.2, false, true, false, false, true, .2, 1, 1, -.15);
    float S_co2[] = { 1, 0, 0 };
    _(vertex<float>(-.4, -.15), .25, S_co2, .7, 1.2, false, false, true, true, false, 1, -.2, .15, 1);

    float S_co3[] = { 1, 0, 0 };
    vertex<float> S_ve[] = { vertex<float>(-.52, .375), vertex<float>(-.25, .01) };
    draw(GL_LINES, S_ve, S_co3, 2, false, 10);
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
    _(vertex<float>(-.3, .3), .25, U_co, .5, .9, false, false, false, true, false, 0, 0, .015);

    float U_co2[] = { 1, 0, 0 };
    vertex<float> U_ve2[] = { vertex<float>(-.426, .28),
        vertex<float>(-.426, .65),
        vertex<float>(-.177, .28),
        vertex<float>(-.177, .65)
    };
    draw(GL_LINES, U_ve2, U_co2, 4, false, 7);
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

void a() {
    float a_col[] = {1, 0, 0};
    _(vertex<float>(-.3, .3), .2, a_col, .8, 1, false, true, true, false, true, .2, -.1, 0, 0);

    float a_col2[] = {1, 0, 0};
    _(vertex<float>(-.25, .1), .2, a_col2, .7, .8, false, true, false, false, false, .15);

    float a_col3[] = {1, 0, 0};
    vertex<float> a_ve[] = {
        vertex<float>(-.139, .3),
        vertex<float>(-.139, -.05)
    };
    draw(GL_LINES, a_ve, a_col3, 2, false, 7);
}

void b() {
    float b_co[] = { 1, 0, 0 };
    vertex<float> b_ve[] = { vertex<float>(-.3, 0),
        vertex<float>(-.3, .6)
    };
    draw(GL_LINES, b_ve, b_co, 2, false, 7);
    
    float b_co2[] = { 1, 0, 0 };
    _(vertex<float>(-.3, .15), .15, b_co2, .8, 1, false, false, true);
}

void c() {
    float c_co[] = { 1, 0, 0 };
    _(vertex<float>(-.3, .3), .25, c_co, .5, .8, false, true, false, false, false, .125);
}

void d() {
    float d_co[] = { 1, 0, 0 };
    vertex<float> d_ve[] = { vertex<float>(-.3, 0),
        vertex<float>(-.3, .6)
    };
    draw(GL_LINES, d_ve, d_co, 2, false, 7);
    
    float d_co2[] = { 1, 0, 0 };
    _(vertex<float>(-.3, .15), .15, d_co2, .8, 1, false, true, false);
}

void e() {
    float e_co[] = { 1, 0, 0 };
    _(vertex<float>(-.3, .3), .25, e_co, .4, .8, false, true, false, false, false, .2);
    float e_co2[] = { 1, 0, 0 };
    _(vertex<float>(-.3, .3), .25, e_co2, .4, .8, false, false, true, false, true, 0, 0, 0, .08);


    float e_co3[] = {1, 0, 0};
    vertex<float> e_ve[] = {
        vertex<float>(-.2, .35),
        vertex<float>(-.4, .35)
    };
    draw(GL_LINES, e_ve, e_co3, 2, false, 7);
}

void f() {
    float f_co[] = { 1, 0, 0 };
    _(vertex<float>(-.35, .2), .22, f_co, .4, 1, false, true, true, false, true, 0, -.2);

    float f_co2[] = { 1, 0, 0 };
    vertex<float> f_ve[] = { 
        vertex<float>(-.43, .3), 
        vertex<float>(-.43, .05),
        vertex<float>(-.47, .3),
        vertex<float>(-.38, .3)
    };
    draw(GL_LINES, f_ve, f_co2, 4, false, 7);
}

void g() {
    float g_co[] = {1, 0, 0};
    _(vertex<float>(0, .2), .1, g_co, .7, 1.2, false, true, false, false, false, .05);

    float g_co2[] = {1, 0, 0};
    _(vertex<float>(-.02, -.1), .1, g_co2, .6, 1, false, false, true, true, false, 0, -.08);

    float g_co3[] = {1, 0, 0};
    vertex<float> g_ve[] = {
        vertex<float>(.04, -.1),
        vertex<float>(.04, .32)
    };
    draw(GL_LINES, g_ve, g_co3, 2, false, 7);
}

void h() {
    float h_co[] = {1, 0, 0};
    _(vertex<float>(0, .2), .15, h_co, .5, 1, false, false, true, false, true, 0, -.1);

    float h_co2[] = {1, 0, 0};
    vertex<float> h_ve[] = {
        vertex<float>(-.05, .6),
        vertex<float>(-.05, .05),
        vertex<float>(.075, .2),
        vertex<float>(.075, .05)
    };
    draw(GL_LINES, h_ve, h_co2, 4, false, 6);
}

void i() {
    glPointSize(3.0);
    float i_co[] = {1, 0, 0};
    _(vertex<float>(0, .2), .05, i_co, .3, .5);

    float i_co2[] = {1, 0, 0};
    vertex<float> i_ve[] = {
        vertex<float>(0, .15),
        vertex<float>(0, -.05)
    };
    draw(GL_LINES, i_ve, i_co2, 2, false, 7);
}

void j() {
    float j_co[] = { 1, 0, 0 };
    _(vertex<float>(-.3, .1), .15, j_co, .4, 1, false, false, true, true, false, 0, -.05);

    float j_co2[] = { 1, 0, 0 };
    vertex<float> j_ve[] = { vertex<float>(-.24, .08), vertex<float>(-.24, .4) };
    draw(GL_LINES, j_ve, j_co, 2, false, 7);

    glPointSize(3.0);
    float i_co[] = {1, 0, 0};
    _(vertex<float>(-.24, .45), .05, i_co, .3, .5);
}

void k() {
    float k_co[] = {1, 0, 0};
    vertex<float> k_ve[] = {
        vertex<float>(-.1, -.2),
        vertex<float>(-.1, .2),
        vertex<float>(-.1, -.1),
        vertex<float>(-.03, .15),
        vertex<float>(-.07, 0),
        vertex<float>(-.03, -.2)
    };
    draw(GL_LINES, k_ve, k_co, 6, false, 7);
}

void l() {
    float l_co[] = {1, 0, 0};
    vertex<float> l_ve[] = {
        vertex<float>(-.1, -.2),
        vertex<float>(-.1, .2)
    };
    draw(GL_LINES, l_ve, l_co, 2, false, 7);
}

void m() {
    float m_co[] = {1, 0, 0};
    _(vertex<float>(.015, .2), .15, m_co, .3, 1, false, false, false, false, true);

    float m_co2[] = {1, 0, 0};
    _(vertex<float>(.105, .2), .15, m_co2, .3, 1, false, false, false, false, true);

    float m_co3[] = {1, 0, 0};
    vertex<float> m_ve[] = {
        vertex<float>(-.029, .35),
        vertex<float>(-.029, .1), 
        vertex<float>(.06, .2),
        vertex<float>(.06, .1),
        vertex<float>(.15, .2),
        vertex<float>(.15, .1)
    };
    draw(GL_LINES, m_ve, m_co3, 6, false, 6);

}

void n() {
    float n_co[] = {1, 0, 0};
    _(vertex<float>(.015, .2), .15, n_co, .3, 1, false, false, false, false, true);

    float n_co2[] = {1, 0, 0};
    vertex<float> n_ve[] = {
        vertex<float>(-.029, .35),
        vertex<float>(-.029, .1), 
        vertex<float>(.06, .2),
        vertex<float>(.06, .1),
    };
    draw(GL_LINES, n_ve, n_co2, 4, false, 6);
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

    n();
    //glColor3f(0, 1, 0);
    //glBegin(GL_POINTS);
    //glVertex2f(0, 0);
    //glEnd();

    //float S_co[] = { 1, 0, 0 };
    //_(0, 0, .15, S_co, 1, 1, false, true, false, false, false, .05);
    //float S_co2[] = { 1, 0, 0 };
    //_(0, -.3, .15, S_co, 1, 1, false, true, false, true, false, -.05);

    //glColor3f(1, 0, 0);
    //float x[]{ 1, 0, 0 };
    //_(-.3, .55, .25, x, .7, 1.2, false, true, false, false, true, .125, 1, 1, -.2);
    //float x1[]{ 1, 0, 0 };
    //_(-.3, -.25, .25, x1, .7, 1.2, false, false, true, true, false, 1, -.125, .2, 1);
    //_(-.3, .3, .25, x, .5, 1, false, true, false, false, false, .125, -.47, .47, -.47);
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
