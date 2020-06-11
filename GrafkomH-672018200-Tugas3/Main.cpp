#include<GL/freeglut.h> 


void display(void) {
	glPointSize(8.0);
	float ax = 50, ay = 50, bx = 150, by = 200, cx = 50, cy = 200, dx = 150, dy = 50, ex = 100, ey = 50, fx = 200, fy = 200, gx = 100, gy = 200, hx = 200, hy = 50, Mab, Mcd, Cab, Ccd, Mef, Cef, Cgh, px, py, pz, pi, Mgh, px1, px2, px3, px4, px5, py1, py2, py3, py4, py5;
	glClear(GL_COLOR);

	glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 0.0);
		glVertex2f(ax, ay);
		glVertex2f(bx, by);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(cx, cy);
		glVertex2f(dx, dy);
		glEnd();

	glBegin(GL_LINES);
		glColor3f(0.0, 1.0, 0.0);
		glVertex2f(ex, ey);
		glVertex2f(fx, fy);
	glEnd();

	glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex2f(gx, gy);
		glVertex2f(hx, hy);
	glEnd();	


	glBegin(GL_LINE_LOOP);
	glColor3f(0.0, 0.0, 0.0);
		glVertex2f(ax, ay);
		glVertex2f(hx, hy);
		glVertex2f(fx, fy);
		glVertex2f(cx, cy);
	glEnd();

	Mab = (by - ay) / (bx - ax);
	Mcd = (dy - cy) / (dx - cx);
	Mef = (fy - ey) / (fx - ex);
	Mgh = (hy - gy) / (hx - gx);
	Cab = ay - (ax * Mab);
	Ccd = cy - (cx* Mcd);
	Cef = ey - (ex * Mef);
	Cgh = gy - (gx * Mgh);
	
	
	px1 = (Ccd - Cab) / (Mab - Mcd);
	py1 = (Mab * px1) + Cab;
	px2 = (Cgh - Cab) / (Mab - Mgh);
	py2 = (Mgh * px2) + Cgh;
	px3 = (Cef - Ccd) / (Mcd - Mef);
	py3 = (Mef * px3) + Cef;
	px4 = (Cgh - Cef) / (Mef - Mgh);
	py4 = (Mgh * px4) + Cgh;


	
	glBegin(GL_POINTS);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(px1, py1);
	glEnd();

	glBegin(GL_POINTS);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(px2, py2);
	glEnd();

	glBegin(GL_POINTS);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(px3, py3);
	glEnd();

	glBegin(GL_POINTS);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(px4, py4);
	glEnd();

	glFlush();
}

void init(void) {
	glColor3f(0.0, 0.0, 0.0);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glLineWidth(4.0f);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("titik perpotongan");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}