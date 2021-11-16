// Test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// cc main.c -lglut -lGLU -lGL
#include <iostream>
#include <utility>
#include <GL/glut.h>
//#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>
#include <map>
#include <functional>
#define PI 3.141592653589793238
using namespace std;

//rgb(170, 20, 240)
float def_color[] = {.666, .078, .941};
const int def_lw = 7;
const int def_ps = 6;

float letter_size = 1;

float shift_x = 0;
float shift_y = 0;

template <typename T>
struct vertex
{
    float x;
    float y;
    float z = 0;
    vertex(float x, float y)
    {
        this->x = ((x + shift_x + 1) * letter_size - 1);
        this->y = ((y + shift_y - 1)) * letter_size + 1;
    }
    vertex(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

template <typename T>
void draw(GLenum type, vertex<T> *v, float *rgb, int v_no, bool _3d = false, int lw = def_lw, int ps = def_ps)
{
    float color[] = {rgb[0], rgb[1], rgb[2]};
    glPointSize(ps);
    glLineWidth(lw);
    glBegin(type);
    glColor3f(color[0], color[1], color[2]);
    for (int i = 0; i < v_no; i++)
    {
        // cout << v[i].x << "  " << v[i].y << "  " << v[i].z << endl;
        if (!_3d)
            glVertex2f(v[i].x, v[i].y);
        else
            glVertex3f(v[i].x, v[i].y, v[i].z);
    }
    glEnd();
    glFlush();
    return;
}

pair<bool, float> _check(float val, float i, bool position, bool dir, float _val, float plus)
{

    switch (dir)
    {
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
    float *rgb,
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
    float _bottom = 0,
    int ps = def_ps)
{

    glPointSize(ps);
    glColor3f(rgb[0], rgb[1], rgb[2]);
    float base_x = v.x;
    float base_y = v.y;
    float x1, y1, x2, y2;

    pair<bool, float> status;

    glBegin(GL_POINTS);
    for (float i = 0; i <= 360;)
    {
        x1 = r * cos(i) * x_sc;
        if (!full && right)
        {
            status = _check(x1, i, right, true, _right * x_sc, 1);
            i = status.second;
            if (status.first)
                continue;
        }
        if (!full && left)
        {
            status = _check(x1, i, left, false, _left * x_sc, 1);
            i = status.second;
            if (status.first)
                continue;
        }
        y1 = r * sin(i) * y_sc;
        if (!full && top)
        {
            status = _check(y1, i, top, true, _top * y_sc, 1);
            i = status.second;
            if (status.first)
                continue;
        }
        if (!full && bottom)
        {
            status = _check(y1, i, bottom, false, _bottom * y_sc, 1);
            i = status.second;
            if (status.first)
                continue;
        }
        i += .5;

        x2 = r * cos(i) * x_sc;
        if (!full && right)
        {
            status = _check(x2, i, right, true, _right * x_sc, .5);
            i = status.second;
            if (status.first)
                continue;
        }
        if (!full && left)
        {
            status = _check(x2, i, left, false, _left * x_sc, .5);
            i = status.second;
            if (status.first)
                continue;
        }
        y2 = r * sin(i) * y_sc;
        if (!full && top)
        {
            status = _check(y2, i, top, true, _top * y_sc, .5);
            i = status.second;
            if (status.first)
                continue;
        }
        if (!full && bottom)
        {
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

void A(float _co[3] = def_color)
{
    vertex<float> A_ve[] = {
        vertex<float>(-.925, .6),
        vertex<float>(-.85, .9),
        vertex<float>(-.775, .6)};
    draw(GL_LINE_STRIP, A_ve, _co, 3);

    vertex<float> A_ve2[] = {
        vertex<float>(-.89, .75),
        vertex<float>(-.81, .75)};
    draw(GL_LINES, A_ve2, _co, 2);
}

void B(float _co[3] = def_color)
{
    vertex<float> B_ve[] = {
        vertex<float>(-.87, .6),
        vertex<float>(-.87, .9)};
    draw(GL_LINES, B_ve, _co, 2);

    _(vertex<float>(-.87, .825), .07, _co, 1, 1, false, false, true);
    _(vertex<float>(-.87, .675), .07, _co, 1.15, 1, false, false, true);
}

void C(float _co[3] = def_color)
{
    _(vertex<float>(-.85, .75), .15, _co, .5, 1, false, true, false, false, false, .1);
}

void D(float _co[3] = def_color)
{
    vertex<float> D_ve[] = {
        vertex<float>(-.87, .6),
        vertex<float>(-.87, .9)};
    draw(GL_LINES, D_ve, _co, 2, false, 7);

    _(vertex<float>(-.87, .75), .07, _co, 1, 2.1, false, false, true);
}

void E(float _co[3] = def_color)
{
    vertex<float> E_ve[] = {
        vertex<float>(-.77, .6),
        vertex<float>(-.87, .6),
        vertex<float>(-.87, .9),
        vertex<float>(-.77, .9)};
    draw(GL_LINE_STRIP, E_ve, _co, 4);

    vertex<float> E_ve2[] = {
        vertex<float>(-.87, .75),
        vertex<float>(-.79, .75)};
    draw(GL_LINES, E_ve2, _co, 2);
}

void F(float _co[3] = def_color)
{
    vertex<float> F_ve[] = {
        vertex<float>(-.87, .6),
        vertex<float>(-.87, .9),
        vertex<float>(-.77, .9)};
    draw(GL_LINE_STRIP, F_ve, _co, 3);

    vertex<float> F_ve2[] = {
        vertex<float>(-.87, .75),
        vertex<float>(-.79, .75)};
    draw(GL_LINES, F_ve2, _co, 2);
}

void G(float _co[3] = def_color)
{
    _(vertex<float>(-.85, .75), .15, _co, .5, .9, false, true, false, false, false, .03);

    vertex<float> G_ve[] = {
        vertex<float>(-.84, .615),
        vertex<float>(-.82, .615),
        vertex<float>(-.82, .7),
        vertex<float>(-.85, .7)};
    draw(GL_LINE_STRIP, G_ve, _co, 4, false, 6);
}

void H(float _co[3] = def_color)
{
    vertex<float> H_ve[] = {
        vertex<float>(-.9, .6),
        vertex<float>(-.9, .9),
        vertex<float>(-.8, .6),
        vertex<float>(-.8, .9),
        vertex<float>(-.9, .75),
        vertex<float>(-.8, .75)};
    draw(GL_LINES, H_ve, _co, 6);
}

void I(float _co[3] = def_color)
{
    vertex<float> I_ve[] = {
        vertex<float>(-.85, .6),
        vertex<float>(-.85, .9),
        vertex<float>(-.9, .6),
        vertex<float>(-.8, .6),
        vertex<float>(-.9, .9),
        vertex<float>(-.8, .9)};
    draw(GL_LINES, I_ve, _co, 6);
}

void J(float _co[3] = def_color)
{
    _(vertex<float>(-.87, .82), .15, _co, .5, 1.5, false, true, true, true, false, .1, -.05);

    vertex<float> J_ve[] = {
        vertex<float>(-.82, .65),
        vertex<float>(-.82, .9)};
    draw(GL_LINES, J_ve, _co, 2);
}

void K(float _co[3] = def_color)
{
    vertex<float> K_ve[] = {
        vertex<float>(-.87, .6),
        vertex<float>(-.87, .9),
        vertex<float>(-.87, .75),
        vertex<float>(-.78, .9),
        vertex<float>(-.86, .77),
        vertex<float>(-.78, .6)};
    draw(GL_LINES, K_ve, _co, 6);
}

void L(float _co[3] = def_color)
{
    vertex<float> L_ve[] = {
        vertex<float>(-.87, .9),
        vertex<float>(-.87, .6),
        vertex<float>(-.78, .6)};
    draw(GL_LINE_STRIP, L_ve, _co, 3);
}

void M(float _co[3] = def_color)
{
    vertex<float> M_ve[] = {
        vertex<float>(-.9, .6),
        vertex<float>(-.9, .9),
        vertex<float>(-.85, .73),
        vertex<float>(-.8, .9),
        vertex<float>(-.8, .6)};
    draw(GL_LINE_STRIP, M_ve, _co, 5);
}

void N(float _co[3] = def_color)
{
    vertex<float> N_ve[] = {
        vertex<float>(-.9, .6),
        vertex<float>(-.9, .9),
        vertex<float>(-.8, .6),
        vertex<float>(-.8, .9)};
    draw(GL_LINE_STRIP, N_ve, _co, 4);
}

void O(float _co[3] = def_color)
{
    _(vertex<float>(-.85, .75), .1, _co, .65, 1.5);
}

void P(float _co[3] = def_color)
{
    vertex<float> P_ve[] = {
        vertex<float>(-.85, .6),
        vertex<float>(-.85, .9)};
    draw(GL_LINES, P_ve, _co, 2);
    _(vertex<float>(-.85, .815), .08, _co, .65, 1, false, false, true);
}

void Q(float _co[3] = def_color)
{
    _(vertex<float>(-.85, .75), .1, _co, .65, 1.5);

    vertex<float> Q_ve[] = {
        vertex<float>(-.82, .63),
        vertex<float>(-.78, .57)};
    draw(GL_LINES, Q_ve, _co, 2);
}

void R(float _co[3] = def_color)
{
    _(vertex<float>(-.85, .815), .08, _co, .65, 1, false, false, true);
    vertex<float> R_ve[] = {
        vertex<float>(-.85, .6),
        vertex<float>(-.85, .9),
        vertex<float>(-.82, .758),
        vertex<float>(-.78, .6)};
    draw(GL_LINES, R_ve, _co, 4);
}

void S(float _co[3] = def_color)
{
    _(vertex<float>(-.846, .83), .075, _co, .78, 1.2, false, true, false, false, true, .05, 0, 0, -.072);
    _(vertex<float>(-.874, .66), .075, _co, .78, 1.2, false, false, true, true, false, 0, -.05, .072, 0);
}

void T(float _co[3] = def_color)
{
    vertex<float> T_ve[] = {
        vertex<float>(-.85, .6),
        vertex<float>(-.85, .9),
        vertex<float>(-.93, .9),
        vertex<float>(-.77, .9),
    };
    draw(GL_LINES, T_ve, _co, 4);
}

void U(float _co[3] = def_color)
{
    _(vertex<float>(-.85, .75), .1, _co, .6, 1, false, false, false, true);

    vertex<float> U_ve[] = {
        vertex<float>(-.79, .75),
        vertex<float>(-.79, .9),
        vertex<float>(-.91, .75),
        vertex<float>(-.91, .9)};
    draw(GL_LINES, U_ve, _co, 4);
}

void V(float _co[3] = def_color)
{
    vertex<float> V_ve[] = {
        vertex<float>(-.9, .9),
        vertex<float>(-.85, .6),
        vertex<float>(-.8, .9)};
    draw(GL_LINE_STRIP, V_ve, _co, 3);
}

void W(float _co[3] = def_color)
{
    vertex<float> W_ve[] = {
        vertex<float>(-.92, .9),
        vertex<float>(-.89, .6),
        vertex<float>(-.86, .8),
        vertex<float>(-.83, .6),
        vertex<float>(-.8, .9)};
    draw(GL_LINE_STRIP, W_ve, _co, 5);
}

void X(float _co[3] = def_color)
{
    vertex<float> X_ve[] = {
        vertex<float>(-.925, .9),
        vertex<float>(-.775, .6),
        vertex<float>(-.925, .6),
        vertex<float>(-.775, .9)};
    draw(GL_LINES, X_ve, _co, 4);
}

void Y(float _co[3] = def_color)
{
    vertex<float> Y_ve[] = {
        vertex<float>(-.9, .9),
        vertex<float>(-.85, .75),
        vertex<float>(-.85, .75),
        vertex<float>(-.8, .9),
        vertex<float>(-.85, .75),
        vertex<float>(-.85, .6)};
    draw(GL_LINE_STRIP, Y_ve, _co, 6);
}

void Z(float _co[3] = def_color)
{
    vertex<float> X_ve[] = {
        vertex<float>(-.925, .9),
        vertex<float>(-.775, .9),
        vertex<float>(-.925, .6),
        vertex<float>(-.775, .6)};
    draw(GL_LINE_STRIP, X_ve, _co, 4);
}

void a(float _co[3] = def_color)
{

    _(vertex<float>(-.9, .8), .2, _co, .8, 1, false, true, true, false, true, .8, -.1, 0, 0);

    _(vertex<float>(-.85, .6), .2, _co, .7, .8, false, true, false, false, false, .15);

    vertex<float> a_ve[] = {
        vertex<float>(-.739, .8),
        vertex<float>(-.739, 0.45)};
    draw(GL_LINES, a_ve, _co, 2, false, 7);
}

void b(float _co[3] = def_color)
{

    vertex<float> b_ve[] = {vertex<float>(-.87, 0.55),
                            vertex<float>(-.87, .95)};
    draw(GL_LINES, b_ve, _co, 2, false, 7);

    _(vertex<float>(-.87, .65), .1, _co, .6, 1, false, false, true);
}

void c(float _co[3] = def_color)
{
    _(vertex<float>(-.85, .75), .15, _co, .4, 0.7, false, true, false, false, false, .1);
}

void d(float _co[3] = def_color)
{
    vertex<float> d_ve[] = {vertex<float>(-.3, 0),
                            vertex<float>(-.3, .6)};
    draw(GL_LINES, d_ve, _co, 2, false, 7);

    _(vertex<float>(-.3, .15), .15, _co, .8, 1, false, true, false);
}

void e(float _co[3] = def_color)
{
    _(vertex<float>(-.3, .3), .25, _co, .4, .8, false, true, false, false, false, .2);
    _(vertex<float>(-.3, .3), .25, _co, .4, .8, false, false, true, false, true, 0, 0, 0, .08);

    vertex<float> e_ve[] = {
        vertex<float>(-.2, .35),
        vertex<float>(-.4, .35)};
    draw(GL_LINES, e_ve, _co, 2, false, 7);
}

void f(float _co[3] = def_color)
{
    _(vertex<float>(-.35, .2), .22, _co, .4, 1, false, true, true, false, true, 0, -.2);

    vertex<float> f_ve[] = {
        vertex<float>(-.43, .3),
        vertex<float>(-.43, .05),
        vertex<float>(-.47, .3),
        vertex<float>(-.38, .3)};
    draw(GL_LINES, f_ve, _co, 4, false, 7);
}

void g(float _co[3] = def_color)
{
    _(vertex<float>(0, .2), .1, _co, .7, 1.2, false, true, false, false, false, .05);

    _(vertex<float>(-.02, -.1), .1, _co, .6, 1, false, false, true, true, false, 0, -.08);

    vertex<float> g_ve[] = {
        vertex<float>(.04, -.1),
        vertex<float>(.04, .32)};
    draw(GL_LINES, g_ve, _co, 2, false, 7);
}

void h(float _co[3] = def_color)
{
    _(vertex<float>(0, .2), .15, _co, .5, 1, false, false, true, false, true, 0, -.1);

    vertex<float> h_ve[] = {
        vertex<float>(-.05, .6),
        vertex<float>(-.05, .05),
        vertex<float>(.075, .2),
        vertex<float>(.075, .05)};
    draw(GL_LINES, h_ve, _co, 4, false, 6);
}

void i(float _co[3] = def_color)
{
    vertex<float> i_ve[] = {vertex<float>(0, .2)};
    draw(GL_POINTS, i_ve, _co, 1, false, 5, 8);

    vertex<float> i_ve2[] = {
        vertex<float>(0, .15),
        vertex<float>(0, -.05)};
    draw(GL_LINES, i_ve2, _co, 2, false, 7);
}

void j(float _co[3] = def_color)
{
    _(vertex<float>(-.3, .1), .15, _co, .4, 1, false, false, true, true, false, 0, -.05);

    vertex<float> i_ve[] = {vertex<float>(-.24, .08), vertex<float>(-.24, .4)};
    draw(GL_LINES, i_ve, _co, 2, false, 7);

    vertex<float> i_ve2[] = {vertex<float>(-.24, .45)};
    draw(GL_POINTS, i_ve2, _co, 1, false, 5, 8);
}

void k(float _co[3] = def_color)
{
    vertex<float> k_ve[] = {
        vertex<float>(-.1, -.2),
        vertex<float>(-.1, .2),
        vertex<float>(-.1, -.1),
        vertex<float>(-.03, .15),
        vertex<float>(-.07, 0),
        vertex<float>(-.03, -.2)};
    draw(GL_LINES, k_ve, _co, 6, false, 7);
}

void l(float _co[3] = def_color)
{
    vertex<float> l_ve[] = {
        vertex<float>(-.1, -.2),
        vertex<float>(-.1, .2)};
    draw(GL_LINES, l_ve, _co, 2, false, 7);
}

void m(float _co[3] = def_color)
{
    _(vertex<float>(.015, .2), .15, _co, .3, 1, false, false, false, false, true);

    _(vertex<float>(.105, .2), .15, _co, .3, 1, false, false, false, false, true);

    vertex<float> m_ve[] = {
        vertex<float>(-.029, .35),
        vertex<float>(-.029, .1),
        vertex<float>(.06, .2),
        vertex<float>(.06, .1),
        vertex<float>(.15, .2),
        vertex<float>(.15, .1)};
    draw(GL_LINES, m_ve, _co, 6, false, 6);
}

void n(float _co[3] = def_color)
{
    _(vertex<float>(.015, .2), .15, _co, .3, 1, false, false, false, false, true);

    vertex<float> n_ve[] = {
        vertex<float>(-.029, .35),
        vertex<float>(-.029, .1),
        vertex<float>(.06, .2),
        vertex<float>(.06, .1),
    };
    draw(GL_LINES, n_ve, _co, 4, false, 6);
}

void o(float _co[3] = def_color)
{
    _(vertex<float>(-.3, .3), .135, _co, .65);
}

void p(float _co[3] = def_color)
{
    vertex<float> p_ve[] = {
        vertex<float>(-.3, 0),
        vertex<float>(-.3, .3),
    };
    draw(GL_LINES, p_ve, _co, 2, false, 7);

    _(vertex<float>(-.341, .2), .095, _co, 1, 1.1, false, false, true, false, false, 0, .05);
}

void q(float _co[3] = def_color)
{
    vertex<float> q_ve[] = {
        vertex<float>(-.3, 0),
        vertex<float>(-.3, .3),
    };
    draw(GL_LINES, q_ve, _co, 2, false, 7);

    _(vertex<float>(-.3, .21), .075, _co, 1, 1.1, false, true, false, false, false, 0, .05);
}

void r(float _co[3] = def_color)
{
    vertex<float> r_ve[] = {
        vertex<float>(-.3, 0),
        vertex<float>(-.3, .3),
    };
    draw(GL_LINES, r_ve, _co, 2, false, 7);

    _(vertex<float>(-.25, .23), .045, _co, 1, .6, false, false, false, false, true, 0, .05);
}

void s(float _co[3] = def_color)
{
    _(vertex<float>(-.37, .35), .1225, _co, .7, 1.2, false, true, false, false, true, .098, .49, .49, -.0735, 4);
    _(vertex<float>(-.4, 0), .1225, _co, .7, 1.2, false, false, true, true, false, .49, -.098, .0735, .49, 4);

    vertex<float> s_ve[] = {vertex<float>(-.45, .29), vertex<float>(-.33, .08)};
    draw(GL_LINES, s_ve, _co, 2, false, 7);
}

void t(float _co[3] = def_color)
{
    vertex<float> t_ve[] = {
        vertex<float>(-.3, 0),
        vertex<float>(-.3, .3),
    };
    draw(GL_LINES, t_ve, _co, 2, false, 7);

    vertex<float> t_ve2[] = {
        vertex<float>(-.25, .2),
        vertex<float>(-.35, .2),
    };
    draw(GL_LINES, t_ve2, _co, 2, false, 7);

    _(vertex<float>(-.2857, 0), .015, _co, 1, 1.4, false, false, false, true, false, 0, .05);
}

void u(float _co[3] = def_color)
{
    vertex<float> u_ve[] = {
        vertex<float>(-.3, 0),
        vertex<float>(-.3, .2),
    };
    draw(GL_LINES, u_ve, _co, 2, false, 7);

    vertex<float> u2_ve[] = {
        vertex<float>(-.15, -.15),
        vertex<float>(-.15, .2),
    };
    draw(GL_LINES, u2_ve, _co, 2, false, 7);

    _(vertex<float>(-.225, 0), .08, _co, .93, 1.7, false, false, false, true, false, 0, .05);
}

void v(float _co[3] = def_color)
{
    vertex<float> v_ve[] = {
        vertex<float>(0, .25),
        vertex<float>(.06, 0),
        vertex<float>(.125, .25),
    };
    draw(GL_LINE_STRIP, v_ve, _co, 3);
}

void w(float _co[3] = def_color)
{
    vertex<float> w_ve[] = {vertex<float>(0, .25),
                            vertex<float>(.06, 0),
                            vertex<float>(.125, .25),
                            vertex<float>(.1875, 0),
                            vertex<float>(.25, .25)};
    draw(GL_LINE_STRIP, w_ve, _co, 5);
}

void x(float _co[3] = def_color)
{
    vertex<float> x_ve[] = {vertex<float>(0, .25),
                            vertex<float>(.125, 0)};
    draw(GL_LINE_STRIP, x_ve, _co, 2);

    vertex<float> x_ve2[] = {vertex<float>(.125, .25),
                             vertex<float>(0, 0)};
    draw(GL_LINE_STRIP, x_ve2, _co, 2);
}

void y(float _co[3] = def_color)
{
    vertex<float> y_ve[] = {vertex<float>(-.055, 0),
                            vertex<float>(0, .225)};
    draw(GL_LINE_STRIP, y_ve, _co, 2);

    vertex<float> y2_ve[] = {vertex<float>(-.055, .225),
                             vertex<float>(-.0275, .1125)};
    draw(GL_LINE_STRIP, y2_ve, _co, 2);
    glPointSize(3);
    _(vertex<float>(-.071, 0), .01, _co, 1.5, 1.7, false, false, false, true, false, 0, .05, 0, 0, 4);
}

void z(float _co[3] = def_color)
{
    vertex<float> z_ve[] = {vertex<float>(0, 0),
                            vertex<float>(.175, 0),
                            vertex<float>(0, -.175),
                            vertex<float>(.175, -.175)};
    draw(GL_LINE_STRIP, z_ve, _co, 4);
}

void space(float _co[3] = def_color)
{
}

map<int, function<void(float[3])>>
    letters = {
        {65, A},
        {66, B},
        {67, C},
        {68, D},
        {69, E},
        {70, F},
        {71, G},
        {72, H},
        {73, I},
        {74, J},
        {75, K},
        {76, L},
        {77, M},
        {78, N},
        {79, O},
        {80, P},
        {81, Q},
        {82, R},
        {83, S},
        {84, T},
        {85, U},
        {86, V},
        {87, W},
        {88, X},
        {89, Y},
        {90, Z},
        {97, a},
        {98, b},
        {99, c},
        {100, d},
        {101, e},
        {102, f},
        {103, g},
        {104, h},
        {105, i},
        {106, j},
        {107, k},
        {108, l},
        {109, m},
        {110, n},
        {111, o},
        {112, p},
        {113, q},
        {114, r},
        {115, s},
        {116, t},
        {117, u},
        {118, v},
        {119, w},
        {120, x},
        {121, y},
        {122, z},
        {32, space}};

int letter = 65;

class Letters
{
public:
    char array[500];
    int letter_length = 0;

    void push(char letter)
    {
        array[letter_length++] = letter;
    }
    void pop()
    {
        letter_length = max(letter_length - 1, 0);
    }

    void draw()
    {
        shift_y = 0;
        shift_x = 0;
        for (int i = 0; i < letter_length; i++)
        {

            int letter = array[i];
            letters[letter](def_color);
            // cout << shift_x << "  " << shift_y << endl;
            // if you want it to stop when size is large then add the next commented line
            if ((shift_x + 0.3) * letter_size >= 1.8) // && shift_y > (-1.5 / letter_size)
            {
                shift_y -= 0.5;
                shift_x = 0;
            }
            else if (shift_x < (1.8 / letter_size))
            {
                shift_x += 0.3;
            }
        }
    }
};

Letters letters_obj;

void display()
{

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

    /*
        (-1, 1.0)-----------(-.85, 1.0)-------------(-.7, 1.0)
            |                                           |
            |                                           |
            |                                           |
        (-1, .75)           (-.85, .75)             (-.7, .75)
            |                                           |
            |                                           |
            |                                           |
        (-1, .50)-----------(-.85, .50)-------------(-.7, .50)
    */

    // shift_y = 0;
    // shift_x = 0;
    // float _co[] = {1, 0, 0};
    // vertex<float> ve[] = {
    //     vertex<float>(-1, 1),
    //     vertex<float>(-.7, 1),
    //     vertex<float>(-.7, .5),
    //     vertex<float>(-1, .5)};
    // draw(GL_LINE_STRIP, ve, _co, 4);

    // // rgb(255, 171, 76)
    // float _co2[] = {0, .4, 0};
    // vertex<float> p[] = {
    //     vertex<float>(-.85, 1),
    //     vertex<float>(-.85, .75),
    //     vertex<float>(-.85, .5),
    //     vertex<float>(-1, .75),
    //     vertex<float>(-.7, .75)};
    // draw(GL_POINTS, p, _co2, 5);

    // letters[letter](def_color);
    // shift_x = 0;
    // letters[65](def_color);
    // shift_x = 0.3;
    // letters[66](def_color);
    letters_obj.draw();

    float _co[] = {1, 0, 0};
    vertex<float> ve[] = {

        vertex<float>(-0.95, 0.95),
        vertex<float>(-0.95, .5),
    };
    draw(GL_LINE_STRIP, ve, _co, 2);

    glutSwapBuffers(); //  in Double Buffers => glutSwapBuffers(hDC)
}

double rotate_y = 0, rotate_x = 0;

void display3d()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glRotatef(rotate_x, 1, 0, 0);
    glRotatef(rotate_y, 0, 1, 0);

    glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
    if (key == GLUT_KEY_UP)
    {
        letter_size += 0.1;
    }
    else if (key == GLUT_KEY_DOWN)
    {
        letter_size -= 0.1;
    }
    else if (key == GLUT_KEY_RIGHT)
    {
        // letters_obj.go_right();
    }
    else if (key == GLUT_KEY_LEFT)
    {
        // letters_obj.go_left();
    }

    glutPostRedisplay();
}

void keyboardHandler(unsigned char key, int x, int y)
{
    if (int(key) == 8)
    {
        letters_obj.pop();
    }
    else if (((int(key) >= 65 && int(key) <= 90) || (int(key) >= 97 && int(key) <= 122)) || key == 32)
    {
        letters_obj.push(key);
    }

    glutPostRedisplay();
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);                       //
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); //GLUT_DOUBLE GLUT_DEPTH
                                                 //
    glutInitWindowSize(1200, 740);               //
    glutInitWindowPosition(90, 90);              //
    glutCreateWindow("Project");                 //
    //glEnable(GLUT_DEPTH);

    glutDisplayFunc(display); //  Seting the function that will create the graphics
    glutSpecialFunc(specialKeys);
    glutKeyboardFunc(keyboardHandler);
    glutMainLoop(); // To keep the window running
}
