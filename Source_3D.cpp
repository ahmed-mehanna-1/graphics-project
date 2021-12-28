#include <iostream>
#include <utility>
#include <GL/glut.h>
#include "GL/gl.h"
#include <math.h>
#include <map>
#include <functional>
using namespace std;

GLfloat rot_angle_x = -12;
GLfloat rot_angle_y = 12;
int x_rotate = 0;
int y_rotate = 0;
int z_rotate = 0;

float letter_size = 1;
float shift_x = 0;
float shift_y = -0.1;


void init() {
	glClearColor(1, 1, 1, 0);
	glColor3f(1, 0, 0);
	glEnable(GL_DEPTH_TEST);
}

void Face(GLenum type, GLfloat v0[], GLfloat v1[], GLfloat v2[], GLfloat v3[]) {
	glBegin(type);
	glVertex3fv(v0);
	glVertex3fv(v1);
	glVertex3fv(v2);
	glVertex3fv(v3);
	glEnd();
}
void Cube(bool isSmall) {
	GLfloat v[12][3];
	if (isSmall == true) {
		GLfloat v[12][3] = {
		{-0.925, 0.85, 0.3},
		{-0.925, 0.5, 0.3},
		{-0.775, 0.5, 0.3},
		{-0.775, 0.85, 0.3},

		{-0.925, 0.85, -0.3},
		{-0.925, 0.5, -0.3},
		{-0.775, 0.5, -0.3},
		{-0.775, 0.85, -0.3},
		};
		glColor3f(0, 0, 0);
		Face(GL_LINE_LOOP, v[0], v[1], v[2], v[3]);
		//glColor3f(0, 0, 1);
		Face(GL_LINE_LOOP, v[4], v[5], v[6], v[7]);
		//glColor3f(0, 1, 0);
		Face(GL_LINE_LOOP, v[4], v[5], v[1], v[0]);
		//glColor3f(0, 1, 1);
		Face(GL_LINE_LOOP, v[4], v[0], v[3], v[7]);
		//glColor3f(1, 0, 0);
		Face(GL_LINE_LOOP, v[3], v[2], v[6], v[7]);
		//glColor3f(1, 0, 1);
		Face(GL_LINE_LOOP, v[1], v[5], v[6], v[2]);
	}
	else {
		GLfloat v[12][3] = {
			{-1, 1, 0.3},
			{-1, 0.5, 0.3},
			{-0.7, 0.5, 0.3},
			{-0.7, 1, 0.3},

			{-1, 1, -0.3},
			{-1, 0.5, -0.3},
			{-0.7, 0.5, -0.3},
			{-0.7, 1, -0.3},
		};
		glColor3f(0, 0, 0);
		Face(GL_LINE_LOOP, v[0], v[1], v[2], v[3]);
		//glColor3f(0, 0, 1);
		Face(GL_LINE_LOOP, v[4], v[5], v[6], v[7]);
		//glColor3f(0, 1, 0);
		Face(GL_LINE_LOOP, v[4], v[5], v[1], v[0]);
		//glColor3f(0, 1, 1);
		Face(GL_LINE_LOOP, v[4], v[0], v[3], v[7]);
		//glColor3f(1, 0, 0);
		Face(GL_LINE_LOOP, v[3], v[2], v[6], v[7]);
		//glColor3f(1, 0, 1);
		Face(GL_LINE_LOOP, v[1], v[5], v[6], v[2]);
	}
}
void DrawBox(GLfloat _w, GLfloat _h, GLfloat _d, GLfloat x_start = -0.85, GLfloat y_start = 0.75) {
	glBegin(GL_QUADS);
	//front
	glColor3f(1, 0, 0);
	


	glVertex3f(x_start, _h + y_start, _d);
	glVertex3f(x_start, y_start, _d);
	glVertex3f(_w + x_start, y_start, _d);
	glVertex3f(_w + x_start, _h + y_start, _d);

	//back
	glColor3f(0, 1, 0);
	glVertex3f(x_start, _h + y_start, 0.f);
	glVertex3f(_w + x_start, _h + y_start, 0.f);
	glVertex3f(_w + x_start, y_start, 0.f);
	glVertex3f(x_start, y_start, 0.f);

	//Top
	glColor3f(0, 0, 1);
	glVertex3f(x_start, _h + y_start, 0.f);
	glVertex3f(x_start, _h + y_start, _d);
	glVertex3f(_w + x_start, _h + y_start, _d);
	glVertex3f(_w + x_start, _h + y_start, 0.f);

	//bottom
	glColor3f(1, 1, 0);
	glVertex3f(x_start, y_start, 0.f);
	glVertex3f(_w + x_start, +y_start, 0.f);
	glVertex3f(_w + x_start, +y_start, _d);
	glVertex3f(x_start, +y_start, _d);

	//left
	glColor3f(0, 1, 1);
	glVertex3f(x_start, _h + y_start, 0.f);
	glVertex3f(x_start, y_start, 0.f);
	glVertex3f(x_start, y_start, _d);
	glVertex3f(x_start, _h + y_start, _d);

	//right
	glColor3f(1, 0, 1);
	glVertex3f(_w + x_start, _h + y_start, _d);
	glVertex3f(_w + x_start, y_start, _d);
	glVertex3f(_w + x_start, y_start, 0.f);
	glVertex3f(_w + x_start, _h + y_start, 0.f);



	glEnd();
}
// DrawBOX(Box_width , Box_height ,Box_depth , starting x point , starting y point)
void D_letter(bool bool_mid_line=false) {
	glPushMatrix();				// - Down
	glTranslatef(-0.925, 0.539, 0);
	glRotatef(0, 0, 0, 1);
	DrawBox(0.1125, -0.04, 0.125, 0, 0);
	glPopMatrix();

	glPushMatrix();				// - Top
	glTranslatef(-0.925, 1, 0);
	glRotatef(0, 0, 0, 1);
	DrawBox(0.1125, -0.04, 0.125, 0, 0);
	glPopMatrix();

	glPushMatrix();				// -\ Top
	glTranslatef(-0.81, 0.99, 0);
	glRotatef(-60, 0, 0, 1);
	DrawBox(0.1125, -0.04, 0.125, 0, 0);
	glPopMatrix();

	glPushMatrix();				// -/ Down
	glTranslatef(-0.85, 0.519, 0);
	glRotatef(58, 0, 0, 1);
	DrawBox(0.121, -0.041, 0.125, 0, 0);
	glPopMatrix();

	if (bool_mid_line) {
		DrawBox(0.0375, 0.5, 0.125, -0.925, 0.5);
		glPushMatrix();				// -| MID
		glTranslatef(-0.79, 0.59, 0);
		glRotatef(90, 0, 0, 1);
		DrawBox(0.305, -0.038, 0.125, 0, 0);
		glPopMatrix();
	}

}

void D(){
	D_letter(true);
}
void A_letter(bool bool_mid_line=true) {
	if (bool_mid_line) {
		glPushMatrix();				// -
		glTranslatef(-0.925, 0.75, 0);
		glRotatef(0, 0, 0, 1);
		DrawBox(0.13, -0.04, 0.125, 0, 0);
		glPopMatrix();
	}
	glPushMatrix();				// 
	glTranslatef(-0.83, 0.99, 0);
	glRotatef(-75, 0, 0, 1);
	DrawBox(0.5, -0.04, 0.125, 0, 0);
	glPopMatrix();

	glPushMatrix();				// /
	glTranslatef(-1, 0.5, 0);
	glRotatef(75, 0, 0, 1);
	DrawBox(0.5, -0.04, 0.125, 0, 0);
	glPopMatrix();
}
void A(){
	A_letter(true);
}

void V() {
	// V = (A + Rotation 180 ) + no Mid Line
	glPushMatrix();
	glTranslatef(-0.85, 0.75, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.85, -0.75, 0);
	A_letter(false);
	glPopMatrix();
}
void F() {
	DrawBox(0.0375, 0.5, 0.125, -0.925, 0.5);
	DrawBox(0.15, -0.04, 0.125, -0.925, 1);
	DrawBox(0.15, -0.04, 0.125, -0.925, 0.75);
}
void B() {
	// B = (D Top  + Scaled ) + (D Bottom + Scaled )

	glPushMatrix();		// (D Top  + Scaled )		

	glTranslatef(-0.85, 1, 0);
	glScalef(0.7, 0.4, 1);
	glTranslatef(0.85, -1, 0);

	D_letter(true);
	glPopMatrix();


	glPushMatrix();		// (D Bottom + Scaled)
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.7, 0.6, 1);
	glTranslatef(0.85, -0.5, 0);
	D_letter(true);
	glPopMatrix();
}
void C() {

	// C = D with rotation(180) + no mid line  
	DrawBox(0.04, 0.3, 0.125, -0.946, 0.6);
	glPushMatrix();				// -
	glTranslatef(-0.85, 0.75, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.85, -0.75, 0);
	D_letter(false);
	glPopMatrix();

}
void E() {
	// E = F + Bottom mid line  
	glPushMatrix();				// -
	F();
	glPopMatrix();

	DrawBox(0.15, -0.04, 0.125, -0.925, 0.539);
}
void G() {
	// G = C + Horizontal ine + Vertical line 

	glPushMatrix();
	C();
	glPopMatrix();

	glPushMatrix();		//	 -
	glTranslatef(-0.785, 0.69, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.785, -0.69, 0);
	DrawBox(0.099, -0.04, 0.125, -0.80, 0.72);
	glPopMatrix();

	glPushMatrix();		// |
	DrawBox(0.0375, 0.2, 0.125, -0.8, 0.5);
	glPopMatrix();
}
void H_letter(bool bool_mid_line=true) {
	DrawBox(0.0375, 0.5, 0.125, -0.925, 0.5);
	if (bool_mid_line) {
		DrawBox(0.0375, 0.5, 0.125, -0.8125, 0.5);
	}
	else {
		DrawBox(0.0375, 0.25, 0.125, -0.8125, 0.5);
	}

	glPushMatrix();				// -
	glTranslatef(-0.925, 0.75, 0);
	glRotatef(0, 0, 0, 1);
	DrawBox(0.1125, -0.04, 0.125, 0, 0);
	glPopMatrix();
}
void H(){
	H_letter(true);
}
void T() {
	glPushMatrix();				// - Top
	glTranslatef(-1, 0.99, 0);

	DrawBox(0.3, -0.04, 0.125, 0, 0);
	glPopMatrix();

	DrawBox(0.0375, 0.49, 0.125, -0.86875, 0.5);
}
void I() {
	// I = T  + Bottom line
	glPushMatrix();				// - Top
	T();
	glPopMatrix();
	// - Bottom
	DrawBox(0.3, 0.04, 0.125, -1, 0.5);

}
void J_letter(bool bool_mid_line=false) {
	// J = ( C + Scaling +Rotation 90 ) + Vertical line  +  horizontal line 
	if (bool_mid_line) {
		glPushMatrix();		//	 -
		glTranslatef(-0.82, 0.86, 0);
		glRotatef(180, 0, 0, 1);
		DrawBox(0.1, 0.0285, 0.125, 0, 0);
		glPopMatrix();
	}
	// | 
	DrawBox(0.0125, 0.2, 0.125, -0.83, 0.65);

	glPushMatrix();		// (C Bottom  + Scaled + Rotation 180 )		

	glTranslatef(-0.86, 0.663, 0);
	glScalef(0.23, 0.7, 1);
	glTranslatef(0.86, -0.663, 0);

	glTranslatef(-0.84, 0.663, 0);
	glRotatef(90, 0, 0, 1);
	glTranslatef(0.84, -0.663, 0);
	C();
	glPopMatrix();

}
void J(){
	J_letter(false);
}
void K() {
	DrawBox(0.0375, 0.5, 0.125, -0.925, 0.5);

	glPushMatrix();				// /
	glTranslatef(-0.925, 0.75, 0);
	glRotatef(60, 0, 0, 1);
	DrawBox(0.3, -0.04, 0.125, 0, 0);
	glPopMatrix();

	glPushMatrix();				//	
	glTranslatef(-0.88, 0.8, 0);
	glRotatef(-65, 0, 0, 1);
	DrawBox(0.3, -0.04, 0.125, 0, 0);
	glPopMatrix();

}

void L() {
	DrawBox(0.0375, 0.25, 0.125, -0.925);
	DrawBox(0.15, -0.08, 0.125, -0.925);
}
void Z() {
	glPushMatrix();				// - Top
	glTranslatef(-1, 1, 0);

	DrawBox(0.3, -0.04, 0.125, 0, 0);
	glPopMatrix();

	glPushMatrix();				// /
	glTranslatef(-1, 0.539, 0);
	glRotatef(59, 0, 0, 1);
	DrawBox(0.52, -0.04, 0.125, 0, 0);
	glPopMatrix();

	glPushMatrix();				// - Bottom
	glTranslatef(-1, 0.539, 0);

	DrawBox(0.3, -0.04, 0.125, 0, 0);
	glPopMatrix();
}
void W() {
	// W = (V + Scaling + Translation ) + (V + Scaling + Translation )

	glPushMatrix();			// Left V
	glTranslatef(-0.98, 0.75, 0);
	glScaled(0.5, 1, 1);
	glTranslatef(0.98, -0.75, 0);
	V();
	glPopMatrix();

	glPushMatrix();			// Right V
	glTranslatef(-0.72, 0.75, 0);
	glScaled(0.5, 1, 1);
	glTranslatef(0.72, -0.75, 0);
	V();
	glPopMatrix();

}
void M() {
	// M = ( W + Rotation 180)

	glPushMatrix();
	glTranslatef(-0.85, 0.75, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.85, -0.75, 0);
	W();
	glPopMatrix();
}
void N() {
	// N = (Z + Rotation 90 )	

	glPushMatrix();
	glTranslatef(-0.85, 0.75, 0);
	glScalef(0.4, 1.5, 1);
	glTranslatef(0.85, -0.75, 0);

	glTranslatef(-0.85, 0.75, 0);
	glRotatef(90, 0, 0, 1);
	glTranslatef(0.85, -0.75, 0);

	Z();
	glPopMatrix();
}
void O() {
	// O = ( Left C + Scaled ) + ( C + Rotation 180 + Scaled)

	glPushMatrix();			// Left C
	glTranslatef(-0.87, 0.75, 0);
	glScaled(0.6, 1, 1);
	glTranslatef(0.86, -0.75, 0);
	C();
	glPopMatrix();

	glPushMatrix();			// Right C
	glTranslatef(-0.85, 0.75, 0);
	glScaled(0.6, 1, 1);
	glTranslatef(0.84, -0.75, 0);

	glTranslatef(-0.84, 0.75, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.84, -0.75, 0);
	C();
	glPopMatrix();
}
void P() {
	// P = D + Mid Line
	glPushMatrix();		// (D Top  + Scaled )		
	glTranslatef(-0.85, 1, 0);
	glScalef(0.7, 0.6, 1);
	glTranslatef(0.85, -1, 0);

	D_letter(true);
	glPopMatrix();

	DrawBox(0.0375, 0.5, 0.125, -0.925, 0.5); // MID line copyed from D Mid line
}
void Q() {
	// Q = ( (O + Scaled ) + Bottom line ) 
	glPushMatrix();			// O
	glTranslatef(-0.85, 0.75, 0);
	glScaled(1, 0.5, 1);
	glTranslatef(0.85, -0.75, 0);
	O();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.83, 0.63, 0);
	glRotatef(-40, 0, 0, 1);
	DrawBox(0.0990, 0.03, 0.125, 0, 0);
	glPopMatrix();

}
void R() {
	// R = ( P ) + Rotated Line with angle 
	glPushMatrix();
	P();
	glPopMatrix();
	glPushMatrix();				//	
	glTranslatef(-0.88, 0.75, 0);
	glRotatef(-65, 0, 0, 1);
	DrawBox(0.259, -0.04, 0.125, 0, 0);
	glPopMatrix();
}
void S() {
	// S= (C Top) + ( C Bottom = C + Rotation 180 ))

	glPushMatrix();		// (C Top + Scaled  )
	glTranslatef(-0.89, 1, 0);
	glScalef(0.7, 0.6, 1);
	glTranslatef(0.89, -1, 0);

	C();
	glPopMatrix();

	glPushMatrix();		// (C Bottom  + Scaled + Rotation 180 )		

	glTranslatef(-0.84, 0.663, 0);
	glScalef(0.7, 0.48, 1);
	glTranslatef(0.84, -0.663, 0);

	glTranslatef(-0.84, 0.663, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.84, -0.663, 0);
	C();
	glPopMatrix();
}

void U() {
	// U = ( C + Rotated with angle 90 )  
	glPushMatrix();				//	
	glTranslatef(-0.85, 0.75, 0);
	glScalef(0.4, 2.5, 1);
	glTranslatef(0.85, -0.75, 0);

	glTranslatef(-0.85, 0.75, 0);
	glRotatef(90, 0, 0, 1);
	glTranslatef(0.85, -0.75, 0);
	C();
	glPopMatrix();
}

void X() {
	glPushMatrix();				// /
	glTranslatef(-1, 0.523, 0);
	glRotatef(60, 0, 0, 1);
	DrawBox(0.52, -0.04, 0.125, 0, 0);
	glPopMatrix();

	glPushMatrix();				// /
	glTranslatef(-0.7, 0.523, 0);
	glRotatef(120, 0, 0, 1);
	DrawBox(0.52, 0.04, 0.125, 0, 0);
	glPopMatrix();
}
void Y() {

	// Y = ( V + Scaling ) + Mid Line
	glPushMatrix();				// -
	glTranslatef(-0.85, 0.9, 0);
	glScalef(0.5, 0.8, 1);
	glTranslatef(0.85, -0.75, 0);
	V();
	glPopMatrix();

	DrawBox(0.019, 0.28, 0.125, -0.86, 0.5);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////

// Small Letters

void a() {
	// a = (C (inner) + scaled)+ (C (outer) + scaled + Rotation 180 )
	glPushMatrix();				// C (outer) + scaled + Rotation 180
	glTranslatef(-0.83, 0.5, 0);
	glScalef(0.5, 0.5, 1);
	glTranslatef(0.83, -0.5, 0);

	glTranslatef(-0.85, 0.75, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.85, -0.75, 0);
	C();
	glPopMatrix();

	glPushMatrix();				// (C (inner) + scaled)
	glTranslatef(-0.87, 0.5, 0);
	glScalef(0.5, 0.25, 1);
	glTranslatef(0.87, -0.5, 0);
	C();
	glPopMatrix();
}
void b() {
	// b = ( P + (Rotation  + 180 Z axies)+ (Rotation  + 180 Y axies) )

	glPushMatrix();		// scale
	glTranslatef(-0.85, 0.67, 0);
	glScalef(0.5, 0.6, 1);
	glTranslatef(0.85, -0.67, 0);

	glTranslatef(-0.85, 0.7, 0);		//rotate z 180
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.85, -0.7, 0);

	glTranslatef(-0.85, 0.5, 0);		//rotate y 180
	glRotatef(180, 0, 1, 0);
	glTranslatef(0.85, -0.5, 0);
	P();
	glPopMatrix();
}
void c() {
	// c = ( C + Scaled )

	glPushMatrix();		// scale
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.5, 0.5, 1);
	glTranslatef(0.85, -0.5, 0);

	C();
	glPopMatrix();

}
void d() {
	// d = (b + Rotation + 180 y axies)
	glPushMatrix();
	glTranslatef(-0.85, 0.67, 0);		//rotate y 180
	glRotatef(180, 0, 1, 0);
	glTranslatef(0.85, -0.67, 0);
	b();
	glPopMatrix();
}
void e() {
	// e = ( C + scaled) + (C +scaled + rotation))
	glPushMatrix();
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.5, 0.5, 1);
	glTranslatef(0.85, -0.5, 0);
	C();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-0.83, 0.67, 0);
	glScalef(0.4, 0.25, 1);
	glTranslatef(0.83, -0.67, 0);

	glTranslatef(-0.85, 0.75, 0);		//rotate z 180
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.85, -0.75, 0);
	C();
	glPopMatrix();
}
void f() {
	// f = (J+rotation 180 z axies )  + bott vertical line 

	glPushMatrix();
	glTranslatef(-0.85, 0.71, 0);
	glScalef(0.5, 0.7, 1);
	glTranslatef(0.85, -0.71, 0);

	glTranslatef(-0.85, 0.71, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.85, -0.71, 0);
	J_letter(true);
	DrawBox(0.015, 0.39, 0.125, -0.832, 0.62);
	glPopMatrix();

}

void g() {
	// g = ( e + rotation y axies 180 )

	glPushMatrix();		// T
	glTranslatef(-0.85, 0.75, 0);		//rotate y 180
	glRotatef(180, 0, 1, 0);
	glTranslatef(0.85, -0.75, 0);
	e();
	glPopMatrix();
}

void h() {
	// h = (H + scaling ) - top line

	glPushMatrix();		// scale H - Topline
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.7, 0.6, 1);
	glTranslatef(0.85, -0.5, 0);
	H_letter(false);
	glPopMatrix();
}
void l() {
	// l = mid line 
	glPushMatrix();		// scale mid line
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.4, 0.45, 1);
	glTranslatef(0.85, -0.5, 0);
	DrawBox(0.0375, 0.49, 0.125, -0.86875, 0.5);
	glPopMatrix();

}
void i() {
	// i = ( l )  + (o on top + scaled) 

	glPushMatrix();		// l
	l();
	glPopMatrix();

	glPushMatrix();		// scale O
	glTranslatef(-0.85, 0.80, 0);
	glScalef(0.2, 0.15, 1);
	glTranslatef(0.85, -0.8, 0);
	O();
	glPopMatrix();
}
void j() {
	// j = (J +scaling )+ ( O on Top + scaling )
	glPushMatrix();		// scale mid line
	glTranslatef(-0.81, 0.2, 0);
	glScalef(0.7, 0.8, 1);
	glTranslatef(0.81, -0.2, 0);
	J_letter(true);
	glPopMatrix();

	glPushMatrix();		// scale O
	glTranslatef(-0.83, 0.8, 0);
	glScalef(0.2, 0.15, 1);
	glTranslatef(0.83, -0.8, 0);
	O();
	glPopMatrix();
}

void k() {
	// k = ( K + scaling )

	glPushMatrix();		// scale K
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.5, 0.6, 1);
	glTranslatef(0.85, -0.5, 0);
	K();
	glPopMatrix();
}


void n() {
	glPushMatrix();		//  c + scaled+ rotation -90 z axeis
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.38, 1.5, 1);
	glTranslatef(0.85, -0.52, 0);

	glTranslatef(-0.878, 0.59, 0);
	glRotatef(-90, 0, 0, 1);
	glTranslatef(0.878, -0.59, 0);
	c();
	glPopMatrix();

	glPushMatrix();		// scale mid line
	glTranslatef(-0.87, 0.5, 0);
	glScalef(0.3, 0.6, 1);
	glTranslatef(0.87, -0.5, 0);
	DrawBox(0.0375, 0.29, 0.125, -0.95, 0.5);
	glPopMatrix();
}
void u() {
	// u = n rotation + 180 z axies
	glPushMatrix();		///rotate y 180
	glTranslatef(-0.85, 0.59, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.85, -0.59, 0);
	n();
	glPopMatrix();

}

void m() {
	// m = ( c + scaled+ rotation -90 z axeis + (c + scaled+ rotation -90 z axeis) + mid line

	glPushMatrix();	//  c + scaled+ rotation -90 z axeis

	glTranslatef(-0.87, 0.59, 0);
	glScalef(0.6, 1, 1);
	glTranslatef(0.87, -0.59, 0);

	glTranslatef(-0.87, 0.59, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.87, -0.59, 0);
	u();
	glPopMatrix();

	glPushMatrix();	//  c + scaled+ rotation -90 z axeis

	glTranslatef(-0.825, 0.6, 0);
	glScalef(0.22, 1.62, 1);
	glTranslatef(0.825, -0.6, 0);

	glTranslatef(-0.878, 0.6, 0);
	glRotatef(-90, 0, 0, 1);
	glTranslatef(0.878, -0.6, 0);
	c();
	glPopMatrix();
}
void o() {
	// o = O scaled 

	glPushMatrix();
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.6, 0.5, 1);
	glTranslatef(0.85, -0.5, 0);
	O();
	glPopMatrix();
}
void p() {
	// p = d + rotation 180 z axies
	glPushMatrix();
	glTranslatef(-0.85, 0.65, 0);
	glRotatef(180, 0, 0, 1);		//rotate z 180
	glTranslatef(0.85, -0.65, 0);
	d();
	glPopMatrix();
}
void q() {
	// q = p rotation 180 y axies

	glPushMatrix();
	glTranslatef(-0.85, 0.68, 0);
	glRotatef(180, 0, 1, 0);		//rotate y 180
	glTranslatef(0.85, -0.68, 0);
	p();
	glPopMatrix();
}
void r() {
	// r = l + ( c rotation + scaled )
	glPushMatrix();		// scale mid line
	glTranslatef(-0.925, 0.5, 0);
	glScalef(0.4, 0.45, 1);
	glTranslatef(0.925, -0.5, 0);
	DrawBox(0.0375, 0.49, 0.125, -0.86875, 0.5);
	glPopMatrix();

	glPushMatrix();		// scale

	glTranslatef(-0.865, 0.5, 0);
	glScalef(0.2, 0.7, 1);
	glTranslatef(0.865, -0.5, 0);

	glTranslatef(-0.85, 0.68, 0);
	glRotatef(-90, 0, 0, 1);		//rotate z -90
	glTranslatef(0.85, -0.68, 0);
	C();
	glPopMatrix();
}
void s() {
	// s = S scaled 
	glPushMatrix();		// scale 
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.5, 0.6, 1);
	glTranslatef(0.85, -0.5, 0);
	S();
	glPopMatrix();
}
void t() {
	// t = ( J rotate y 180 + scaling ) + vertical line 
	glPushMatrix();
	glTranslatef(-0.85, 0.35, 0);
	glScalef(0.5, 0.7, 1);
	glTranslatef(0.85, -0.35, 0);

	glTranslatef(-0.85, 0.55, 0);
	glRotatef(-180, 0, 1, 0);		//rotate y -180
	glTranslatef(0.85, -0.55, 0);
	J_letter(true);
	// | 
	DrawBox(0.0125, 0.3, 0.125, -0.83, 0.65);
	glPopMatrix();
}
void v() {
	// v = ( V + scaled )

	glPushMatrix();
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.5, 0.5, 1);
	glTranslatef(0.85, -0.5, 0);
	V();
	glPopMatrix();
}
void w() {
	// w = W + Scaled 
	glPushMatrix();
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.5, 0.6, 1);
	glTranslatef(0.85, -0.5, 0);
	W();
	glPopMatrix();
}
void x() {
	// x = X + scaled 
	glPushMatrix();
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.5, 0.6, 1);
	glTranslatef(0.85, -0.5, 0);
	X();
	glPopMatrix();
}
void y() {
	// y =  (v+scaled)	+ J

	// J
	glPushMatrix();
	glTranslatef(-0.85, 0.35, 0);
	glScalef(0.5, 0.8, 1);
	glTranslatef(0.85, -0.35, 0);
	J_letter(false);
	glPopMatrix();

	// v
	glPushMatrix();
	glTranslatef(-0.845, 0.89, 0);
	glScalef(0.4, 0.5, 1);
	glTranslatef(0.845, -0.89, 0);

	glTranslatef(-0.84, 0.61, 0);
	glRotatef(12, 0, 0, 1);
	glTranslatef(0.84, -0.61, 0);
	v();
	glPopMatrix();
}

void z() {
	// z = Z + Scaled 
	glPushMatrix();
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.5, 0.6, 1);
	glTranslatef(0.85, -0.5, 0);
	Z();
	glPopMatrix();
}

void space()
{
}

map<int, function<void()> >
    letters = {
        {65, A},//
        {66, B},
        {67, C},
        {68, D},
        {69, E},
        {70, F},//asd
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
        {32, space},};

int letter = 97;



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
        shift_y = -0.1;
        shift_x = 0;
        for (int i = 0; i < letter_length; i++)
        {

            int letter = array[i];
			
			glTranslatef(shift_x,shift_y,0);
			// glTranslatef(-0.925,0.825,0);
			// glScalef(letter_size,letter_size,1);
			// glTranslatef(0.925,-0.825,0);
            letters[letter]();
			glTranslatef(-shift_x,-shift_y,0);
			// glTranslatef(-0.925,0.825,0);
			// glScalef(-letter_size,-letter_size,1);
			// glTranslatef(0.925,-0.825,0);
			
            // cout << shift_x << "  " << shift_y << endl;
            // if you want it to stop when size is large then add the next commented line

			float capital_letter_padding =  letter >= 65 && letter<=90 ? 0.1 : 0;

            if ((shift_x + 0.3) * letter_size >= 1.8) // && shift_y > (-1.5 / letter_size)
            {
                shift_y -= 0.6;
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

void specFunc(int key, int x, int y) {
	// x_rotate = 0;
	// y_rotate = 0;
	// z_rotate = 0;
	if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN) {
		// x_rotate = 1;
		if (key == GLUT_KEY_UP) {
			rot_angle_x = rot_angle_x + 2;
		}
		else {
			rot_angle_x = rot_angle_x - 2;
		}
		if (rot_angle_x > 360) {
			rot_angle_x = 0;
		}
	}
	else if (key == GLUT_KEY_RIGHT || key == GLUT_KEY_LEFT) {
		// y_rotate = 1;
		if (key == GLUT_KEY_RIGHT) {
			rot_angle_y = rot_angle_y + 2;
		}
		else {
			rot_angle_y = rot_angle_y - 2;
		}
		if (rot_angle_y > 360) {
			rot_angle_y = 0;
		}

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
	else if ( int(key) == 49 )
    {
        letter_size+=0.1;
    }
	else if ( int(key) == 50 )
    {
        letter_size-=0.1;
    }

    glutPostRedisplay();
}


void Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(6.0);
	glLineWidth(5);
	/*
	* Capital letters
		(-1, 1.0)-----------(-0.85, 1.0)-------------(-0.7, 1.0)
			|                                           |
			|                                           |
			|                                           |
		(-1, 0.75)           (-0.85, 0.75)             (-0.7, 0.75)
			|                                           |
			|                                           |
			|                                           |
		(-1, 0.50)-----------(-0.85, 0.50)-------------(-0.7, 0.50)
	*/
	/*
	* Small letters
		(-0.925, 0.85)-----------(-0.85, 0.85)-------------(-0.7, 0.85)
			|                                           |
			|                                           |
			|                                           |
		(-0.925, 0.675)           (-0.85, 0.675)             (-0.775, 0.675)
			|                                           |
			|                                           |
			|                                           |
		(-0.925, 0.50)-----------(-0.85, 0.50)-------------(-0.775, 0.50)
	*/
	glColor3f(1, 0, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(rot_angle_x, 1, 0, 0);
	glRotatef(rot_angle_y, 0, 1, 0);
	// A();

	glTranslatef(-0.925,0.85,0);
	glScalef(letter_size,letter_size,1);
	glTranslatef(0.925,-0.85,0);
	letters_obj.draw();
	// Cube(false);

	glutSwapBuffers();
}
int main(int x, char* v[]) {

	glutInit(&x, v);
	glutInitWindowSize(1200, 740);
	glutInitWindowPosition(90, 90);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

	glutCreateWindow("3D Capital Letters");

	init();
	glutDisplayFunc(Draw);
	glutSpecialFunc(specFunc);
	glutKeyboardFunc(keyboardHandler);
	glutMainLoop();
	return 5;
}