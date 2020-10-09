#include <gl/glut.h>
#include <iostream>


float sudut = 0.0;
float sudut1 = 0.0;
float sudut2 = 0.0;
float sudut3 = 0.0;
float sudut4 = 0.0;

typedef struct {
	float x;
	float y;
} Point2D_t;

typedef struct {
	float r;
	float g;
	float b;
} Color_t;

void setColor(Color_t col)
{
	glColor3f(col.r, col.g, col.b);
}

void drawLine(Point2D_t pnt[], int n, Color_t color)
{
	int i;
	setColor(color);
	glBegin(GL_LINES);
	for (i = 0; i < n; i++) {
		glVertex2f(pnt[i].x, pnt[i].y);
	}
	glEnd();
}

void drawPolygon(Point2D_t pnt[], int n, Color_t color)
{
	int i;
	setColor(color);
	glBegin(GL_POLYGON);
	for (i = 0; i < n; i++) {
		glVertex2f(pnt[i].x, pnt[i].y);
	}
	glEnd();
}

void drawPolyline(Point2D_t pnt[], int n, Color_t color)
{
	int i;
	setColor(color);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < n; i++) {
		glVertex2f(pnt[i].x, pnt[i].y);
	}
	glEnd();
}

void drawDot(int x, int y) {
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

void sumbu_koordinat() {
	Point2D_t sumbuX[2] = { {-200.0, 0.0}, {200.0, 0.0} };
	Point2D_t sumbuY[2] = { {0.0, -200.0}, {0.0, 200.0} };
	Color_t col = { 1.0, 1.0, 1.0 };
	drawLine(sumbuX, 2, col);
	drawLine(sumbuY, 2, col);
}

void lingkaran()
{
	Point2D_t lingkaran1[360];
	Point2D_t lingkaran2[360];
	Point2D_t lingkaran3[360];
	Point2D_t lingkaran4[360];
	Point2D_t lingkaran5[360];
	Color_t col2 = { 1.0, 0.0, 1.0 };
	Color_t col = { 1.0, 0.0, 0.0 };
	float r = 50.0;
	for (int i = 0; i < 360; i++) {
		lingkaran1[i].x = (float)(r * cos(i * 3.14 / 100));
		lingkaran1[i].y = (float)(r * sin(i * 3.14 / 100));
	}
	for (int i = 0; i < 360; i++) {
		lingkaran2[i].x = (float)(r * cos(i * 3.14 / 100)) + 100;
		lingkaran2[i].y = (float)(r * sin(i * 3.14 / 100)) + 100;
	}
	for (int i = 0; i < 360; i++) {
		lingkaran3[i].x = (float)(r * cos(i * 3.14 / 100)) - 100;
		lingkaran3[i].y = (float)(r * sin(i * 3.14 / 100)) - 100;
	}

	for (int i = 0; i < 360; i++) {
		lingkaran4[i].x = (float)(r * cos(i * 3.14 / 100)) + 100;
		lingkaran4[i].y = (float)(r * sin(i * 3.14 / 100)) - 100;
	}

	for (int i = 0; i < 360; i++) {
		lingkaran5[i].x = (float)(r * cos(i * 3.14 / 100)) - 100;
		lingkaran5[i].y = (float)(r * sin(i * 3.14 / 100)) + 100;
	}

	drawPolyline(lingkaran1, 360, col);
	drawPolyline(lingkaran2, 360, col2);
	drawPolyline(lingkaran3, 360, col2);
	drawPolyline(lingkaran4, 360, col2);
	drawPolyline(lingkaran5, 360, col2);
}

void titik_berputar(int r)
{
	float teta = (float)(sudut / 57.3);
	int x = (int)(r * cos(teta));
	int y = (int)(r * sin(teta));
	drawDot(x, y);
	sudut = sudut + 1;
	if (sudut <= -360) sudut = 0.0;
}

void titik_berputar1(int r)
{
	float teta = (float)(sudut1 / 57.3);
	int x = (int)(r * cos(teta) + 100);
	int y = (int)(r * sin(teta) + 100);
	drawDot(x, y);
	sudut1 = sudut1 + 0.5;
	if (sudut1 <= -360) sudut1 = 0.0;
}

void titik_berputar2(int r)
{
	float teta = (float)(sudut2 / 57.3);
	int x = (int)(r * cos(teta) - 100);
	int y = (int)(r * sin(teta) - 100);
	drawDot(x, y);
	sudut2 = sudut2 - 0.3;
	if (sudut2 <= -360) sudut2 = 0.0;
}

void titik_berputar3(int r)
{
	float teta = (float)(sudut3 / 57.3);
	int x = (int)(r * cos(teta) + 100);
	int y = (int)(r * sin(teta) - 100);
	drawDot(x, y);
	sudut3 = sudut3 + 2;
	if (sudut3 <= -360) sudut3 = 0.0;
}

void titik_berputar4(int r)
{
	float teta = (float)(sudut4 / 57.3);
	int x = (int)(r * cos(teta) - 100);
	int y = (int)(r * sin(teta) + 100);
	drawDot(x, y);
	sudut4 = sudut4 + 0.7;
	if (sudut4 <= -360) sudut4 = 0.5;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	sumbu_koordinat();
	lingkaran();
	titik_berputar(50);
	titik_berputar1(50);
	titik_berputar2(50);
	titik_berputar3(50);
	titik_berputar4(50);
	glFlush();
}


void Initialize()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-200.0, 200.0, -200.0, 200.0);
}

void timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(10, timer, 0);
}


int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200, 200);
	glutInitWindowSize(400, 400);
	glutCreateWindow("2103181045 - Rosyidah Amini Suci");
	Initialize();
	glutDisplayFunc(display);
	glutTimerFunc(10, timer, 0);
	glutMainLoop();
	return 0;
}