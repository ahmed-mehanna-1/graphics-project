#include<gl/glut.h>
GLfloat t = 0;
int x_rotate = 0;
int y_rotate = 0;
int z_rotate = 0;
void init() {
	glClearColor(1, 1, 1, 0);
	glColor3f(1, 0, 0);
	glEnable(GL_DEPTH_TEST);
}
void specFunc(int key, int x, int y) {
	x_rotate = 0;
	y_rotate = 0;
	z_rotate = 0;
	if (key == GLUT_KEY_UP || key == GLUT_KEY_DOWN) {
		x_rotate = 1;
		if (key == GLUT_KEY_UP) {
			t = t + 2;
		}
		else {
			t = t - 2;
		}
		if (t > 360) {
			t = 0;
		}
	}
	else if (key == GLUT_KEY_RIGHT || key == GLUT_KEY_LEFT) {
		y_rotate = 1;
		if (key == GLUT_KEY_RIGHT) {
			t = t + 2;
		}
		else {
			t = t - 2;
		}
		if (t > 360) {
			t = 0;
		}

	}

	glutPostRedisplay();
}
void Face(GLenum type, GLfloat v0[], GLfloat v1[], GLfloat v2[], GLfloat v3[]) {
	glBegin(type);
	glVertex3fv(v0);
	glVertex3fv(v1);
	glVertex3fv(v2);
	glVertex3fv(v3);
	glEnd();
}
void Cube() {
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
void D(bool bool_mid_line) {
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
void A(bool bool_mid_line) {
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
void V() {
	// V = (A + Rotation 180 ) + no Mid Line
	glPushMatrix();
	glTranslatef(-0.85, 0.75, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.85, -0.75, 0);
	A(false);
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

	D(true);
	glPopMatrix();


	glPushMatrix();		// (D Bottom + Scaled)
	glTranslatef(-0.85, 0.5, 0);
	glScalef(0.7, 0.6, 1);
	glTranslatef(0.85, -0.5, 0);
	D(true);
	glPopMatrix();
}
void C() {

	// C = D with rotation(180) + no mid line  
	DrawBox(0.04, 0.3, 0.125, -0.946, 0.6);
	glPushMatrix();				// -
	glTranslatef(-0.85, 0.75, 0);
	glRotatef(180, 0, 0, 1);
	glTranslatef(0.85, -0.75, 0);
	D(false);
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
void H() {
	DrawBox(0.0375, 0.5, 0.125, -0.925, 0.5);
	DrawBox(0.0375, 0.5, 0.125, -0.8125, 0.5);

	glPushMatrix();				// -
	glTranslatef(-0.925, 0.75, 0);
	glRotatef(0, 0, 0, 1);
	DrawBox(0.1125, -0.04, 0.125, 0, 0);
	glPopMatrix();
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
void J() {
	// J = ( C + Scaling +Rotation 90 ) + Vertical line  +  horizontal line 
	glPushMatrix();		//	 -
	glTranslatef(-0.82, 0.86, 0);
	glRotatef(180, 0, 0, 1);
	DrawBox(0.1, 0.0285, 0.125, 0, 0);
	glPopMatrix();

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
	glTranslatef(-1, 0.75, 0);
	glScaled(0.5, 1, 1);
	glTranslatef(1, -0.75, 0);
	V();
	glPopMatrix();

	glPushMatrix();			// Right V
	glTranslatef(-0.7, 0.75, 0);
	glScaled(0.5, 1, 1);
	glTranslatef(0.7, -0.75, 0);
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

	D(true);
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
void Draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPointSize(6.0);
	glLineWidth(5);
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
	glColor3f(1, 0, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(t, x_rotate, y_rotate, z_rotate);
	C();
	Cube();

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
	glutMainLoop();
	return 5;
}