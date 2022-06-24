#include <GL/glut.h>
#include <math.h>
#include <iostream>
#include <windows.h>

using namespace std;

#define FPS 120
#define TO_RADIANS 3.14/180.0

//  Anggota Kelompok X
//  Arrhenius Angi Paelongan (672018430)
//  Christofael Natalio Dondan(672020171)
//  Ananda Pasca Dinov (672018268)
//  Ahmad fajar Indrianto (672020287)
//  Charunia Bintang JM Damanik (672020310)

const int width = 1280;
const int height = 720;
int i;
float sudut;
double x_geser, y_geser, z_geser;

float pitch = 0.0, yaw = 0.0;
float camX = 0.0, camZ = 0.0, terbang = 25.0;

void display();
void reshape(int w, int h);
void timer(int);
void passive_motion(int, int);
void camera();
void keyboard(unsigned char key, int x, int y);
void keyboard_up(unsigned char key, int x, int y);

struct Motion {
    bool Forward, Backward, Left, Right, Naik, Turun;
};
Motion motion = { false,false,false,false,false,false };

void init() {
    glClearColor(0.529, 0.807, 0.921, 0.0);
    glutSetCursor(GLUT_CURSOR_NONE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glDepthFunc(GL_LEQUAL);
    glutWarpPointer(width / 2, height / 2);
}

void ground() {
    glBegin(GL_QUADS);
    glColor3f(0.08, 0.36, 0.06);
    glVertex3f(-1000.0, 0, -1000.0);

    glColor3f(0.08, 0.36, 0.06);
    glVertex3f(1000.0, 0, -1000.0);

    glColor3f(0.08, 0.36, 0.06);
    glVertex3f(1000.0, 0, 1000.0);

    glColor3f(0.08, 0.36, 0.06);
    glVertex3f(-1000.0, 0, 1000.0);
    glEnd();
}

void lantai1() {


}

void pagar_lantai1() {

}

void draw() {
    // Mulai tuliskan isi pikiranmu disini
    lantai1();


    //beton depan
    glPushMatrix();
    glTranslatef(-205, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-75.0, 0.0, 300);
    glVertex3f(-75.0, 40.0, 300);
    glVertex3f(485.0, 40.0, 300);
    glVertex3f(485.0, 0.0, 300);
    glEnd();
    glPopMatrix();

    //beton lurus
    glPushMatrix();
    glTranslatef(-280, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.0, 40.0, -140);
    glVertex3f(-0.0, 0.0, -140);
    glVertex3f(0.0, 0.0, 300);
    glVertex3f(0.0, 40.0, 300);
    glEnd();
    glPopMatrix();

    //beton lurus 2
    glPushMatrix();
    glTranslatef(280, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.0, 40.0, -140);
    glVertex3f(-0.0, 0.0, -140);
    glVertex3f(0.0, 0.0, 300);
    glVertex3f(0.0, 40.0, 300);
    glEnd();
    glPopMatrix();

    //beton atas
    glPushMatrix();
    glTranslatef(0, 30, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.38, 0.38);
    glVertex3f(-280.0, 10, 300);
    glVertex3f(-280.0, 10, 220);
    glVertex3f(280.0, 10, 220);
    glVertex3f(280.0, 10, 300);
    glEnd();
    glPopMatrix();

    //anak tangga
    glPushMatrix();
    glTranslatef(-225, 0, 75);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.0, 25.0, 260);
    glVertex3f(-0.0, 0.0, 260);
    glVertex3f(0.0, 0.0, 225);
    glVertex3f(0.0, 25.0, 225);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(225, 0, 75);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.0, 25.0, 260);
    glVertex3f(-0.0, 0.0, 260);
    glVertex3f(0.0, 0.0, 225);
    glVertex3f(0.0, 25.0, 225);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-205, 0, 35);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 0.0, 300);
    glVertex3f(-20.0, 25.0, 300);
    glVertex3f(430.0, 25.0, 300);
    glVertex3f(430.0, 0.0, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 15, 75);
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.38, 0.38);
    glVertex3f(-225.0, 10, 260);
    glVertex3f(-225.0, 10, 225);
    glVertex3f(225.0, 10, 225);
    glVertex3f(225.0, 10, 260);
    glEnd();
    glPopMatrix();

    //anak tangga 2
    glPushMatrix();
    glTranslatef(-225, 0, 105);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.0, 15.0, 260);
    glVertex3f(-0.0, 0.0, 260);
    glVertex3f(0.0, 0.0, 225);
    glVertex3f(0.0, 15.0, 225);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(225, 0, 105);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-0.0, 15.0, 260);
    glVertex3f(-0.0, 0.0, 260);
    glVertex3f(0.0, 0.0, 225);
    glVertex3f(0.0, 15.0, 225);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-205, 0, 65);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-20.0, 0.0, 300);
    glVertex3f(-20.0, 15.0, 300);
    glVertex3f(430.0, 15.0, 300);
    glVertex3f(430.0, 0.0, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 5, 105);
    glBegin(GL_POLYGON);
    glColor3f(0.38, 0.38, 0.38);
    glVertex3f(-225.0, 10, 260);
    glVertex3f(-225.0, 10, 225);
    glVertex3f(225.0, 10, 225);
    glVertex3f(225.0, 10, 260);
    glEnd();
    glPopMatrix();

    //jalan panjang
    glPushMatrix();
    glTranslatef(0, 0, 105);
    glBegin(GL_POLYGON);
    glColor3f(0.53, 0.65, 0.47);
    glVertex3f(-225.0, 5, 260);
    glVertex3f(-225.0, 5, 650);
    glVertex3f(225.0, 5, 650);
    glVertex3f(225.0, 5, 260);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 105);
    glBegin(GL_POLYGON);
    glColor3f(0.53, 0.65, 0.47);
    glVertex3f(-225.0, 0, 260);
    glVertex3f(-225.0, 5, 260);
    glVertex3f(-225.0, 5, 650);
    glVertex3f(-225.0, 0, 650);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 105);
    glBegin(GL_POLYGON);
    glColor3f(0.53, 0.65, 0.47);
    glVertex3f(225.0, 0, 260);
    glVertex3f(225.0, 5, 260);
    glVertex3f(225.0, 5, 650);
    glVertex3f(225.0, 0, 650);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 105);
    glBegin(GL_POLYGON);
    glColor3f(0.53, 0.65, 0.47);
    glVertex3f(225.0, 0, 650);
    glVertex3f(225.0, 5, 650);
    glVertex3f(-225.0, 5, 650);
    glVertex3f(-225.0, 0, 650);
    glEnd();
    glPopMatrix();



    //penutup beton belakang
    glPushMatrix();
    glTranslatef(-205, 0, -40);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(-75.0, 0.0, -100);
    glVertex3f(-75.0, 40.0, -100);
    glVertex3f(485.0, 40.0, -100);
    glVertex3f(485.0, 0.0, -100);
    glEnd();
    glPopMatrix();

    //lantai kuil
    glPushMatrix();
    glTranslatef(0, 30, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.49, 0.34, 0.18);
    glVertex3f(-280.0, 10, 220);
    glVertex3f(-280.0, 10, -140);
    glVertex3f(280.0, 10, -140);
    glVertex3f(280.0, 10, 220);
    glEnd();
    glPopMatrix();


    //lante kuil dalam
    glPushMatrix();
    glTranslatef(0, 30, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.91, 0.09, 0.09);
    glVertex3f(-225.0, 15, -20);
    glVertex3f(-225.0, 15, -140);
    glVertex3f(225.0, 15, -140);
    glVertex3f(225.0, 15, -20);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 30, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-225.0, 15, -20);
    glVertex3f(-225.0, 15, -140);
    glVertex3f(-230.0, 15, -140);
    glVertex3f(-230.0, 15, -20);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 30, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(225.0, 15, -20);
    glVertex3f(225.0, 15, -140);
    glVertex3f(230.0, 15, -140);
    glVertex3f(230.0, 15, -20);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 30, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-230.0, 15, -20);
    glVertex3f(-230.0, 10, -20);
    glVertex3f(230.0, 10, -20);
    glVertex3f(230.0, 15, -20);
    glEnd();
    glPopMatrix();

    //bantalan jendela kanan
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(235.0, 80, 90);
    glVertex3f(235.0, 80, -10);
    glVertex3f(230.0, 80, -10);
    glVertex3f(230.0, 80, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(235.0, 85, 90);
    glVertex3f(235.0, 85, -10);
    glVertex3f(230.0, 85, -10);
    glVertex3f(230.0, 85, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(235.0, 175, 90);
    glVertex3f(235.0, 175, -10);
    glVertex3f(230.0, 175, -10);
    glVertex3f(230.0, 175, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(230.0, 80, -10);
    glVertex3f(230.0, 85, -10);
    glVertex3f(230.0, 85, 90);
    glVertex3f(230.0, 80, 90);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(235.0, 80, 90);
    glVertex3f(235.0, 180, 90);
    glVertex3f(230.0, 180, 90);
    glVertex3f(230.0, 80, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(235.0, 80, 85);
    glVertex3f(235.0, 180, 85);
    glVertex3f(230.0, 180, 85);
    glVertex3f(230.0, 80, 85);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(235.0, 80, 85);
    glVertex3f(235.0, 180, 85);
    glVertex3f(235.0, 180, 90);
    glVertex3f(235.0, 80, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(235.0, 175, -5);
    glVertex3f(235.0, 180, -5);
    glVertex3f(235.0, 180, 90);
    glVertex3f(235.0, 175, 90);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(235.0, 80, -5);
    glVertex3f(235.0, 180, -5);
    glVertex3f(230.0, 180, -5);
    glVertex3f(230.0, 80, -5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(235.0, 80, -10);
    glVertex3f(235.0, 180, -10);
    glVertex3f(235.0, 180, -5);
    glVertex3f(235.0, 80, -5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(235.0, 80, -10);
    glVertex3f(235.0, 180, -10);
    glVertex3f(230.0, 180, -10);
    glVertex3f(230.0, 80, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(235.0, 180, 90);
    glVertex3f(235.0, 180, -10);
    glVertex3f(230.0, 180, -10);
    glVertex3f(230.0, 180, 90);
    glEnd();
    glPopMatrix();

    //bantalan jendela kiri
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-235.0, 80, 90);
    glVertex3f(-235.0, 80, -10);
    glVertex3f(-230.0, 80, -10);
    glVertex3f(-230.0, 80, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-235.0, 85, 90);
    glVertex3f(-235.0, 85, -10);
    glVertex3f(-230.0, 85, -10);
    glVertex3f(-230.0, 85, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-235.0, 175, 90);
    glVertex3f(-235.0, 175, -10);
    glVertex3f(-230.0, 175, -10);
    glVertex3f(-230.0, 175, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-230.0, 80, -10);
    glVertex3f(-230.0, 85, -10);
    glVertex3f(-230.0, 85, 90);
    glVertex3f(-230.0, 80, 90);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-235.0, 80, 90);
    glVertex3f(-235.0, 180, 90);
    glVertex3f(-230.0, 180, 90);
    glVertex3f(-230.0, 80, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-235.0, 80, 85);
    glVertex3f(-235.0, 180, 85);
    glVertex3f(-230.0, 180, 85);
    glVertex3f(-230.0, 80, 85);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-235.0, 80, 85);
    glVertex3f(-235.0, 180, 85);
    glVertex3f(-235.0, 180, 90);
    glVertex3f(-235.0, 80, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-235.0, 175, -5);
    glVertex3f(-235.0, 180, -5);
    glVertex3f(-235.0, 180, 90);
    glVertex3f(-235.0, 175, 90);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-235.0, 80, -5);
    glVertex3f(-235.0, 180, -5);
    glVertex3f(-230.0, 180, -5);
    glVertex3f(-230.0, 80, -5);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-235.0, 80, -10);
    glVertex3f(-235.0, 180, -10);
    glVertex3f(-235.0, 180, -5);
    glVertex3f(-235.0, 80, -5);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-235.0, 80, -10);
    glVertex3f(-235.0, 180, -10);
    glVertex3f(-230.0, 180, -10);
    glVertex3f(-230.0, 80, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-235.0, 180, 90);
    glVertex3f(-235.0, 180, -10);
    glVertex3f(-230.0, 180, -10);
    glVertex3f(-230.0, 180, 90);
    glEnd();
    glPopMatrix();

    //segitiga atap kiri
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.49, 0.33);
    glVertex3f(-230, 200.0, 220);
    glVertex3f(-230, 200.0, -140);
    glVertex3f(-230, 300, 40);
    glEnd();
    glPopMatrix();

    //segitiga atap kanan
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.49, 0.33);
    glVertex3f(230, 200.0, 220);
    glVertex3f(230, 200.0, -140);
    glVertex3f(230, 300, 40);
    glEnd();
    glPopMatrix();

    //atap depan segitiga
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.49, 0.33);
    glVertex3f(-230, 200.0, 220);
    glVertex3f(-230, 300.0, 40);
    glVertex3f(230, 300, 40);
    glVertex3f(230, 200, 220);
    glEnd();
    glPopMatrix();


    //atap blkng segitiga
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.49, 0.33);
    glVertex3f(-230, 200.0, -140);
    glVertex3f(-230, 300.0, 40);
    glVertex3f(230, 300, 40);
    glVertex3f(230, 200, -140);
    glEnd();
    glPopMatrix();

    //dinding lurus 1 kiri min
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(-230, 40.0, 220);
    glVertex3f(-230, 80.0, 220);
    glVertex3f(-230, 80, -140);
    glVertex3f(-230, 40, -140);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(-230, 40.0, 220);
    glVertex3f(-230, 200.0, 220);
    glVertex3f(-230, 200, 90);
    glVertex3f(-230, 40, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(-230, 40.0, -140);
    glVertex3f(-230, 200.0, -140);
    glVertex3f(-230, 200, -10);
    glVertex3f(-230, 40, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(-230, 180, 220);
    glVertex3f(-230, 200.0, 220);
    glVertex3f(-230, 200, -140);
    glVertex3f(-230, 180, -140);
    glEnd();
    glPopMatrix();




    //dinding depan seblah kiri min
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(-230, 40.0, 220);
    glVertex3f(-230, 200.0, 220);
    glVertex3f(-115, 200, 220);
    glVertex3f(-115, 40, 220);
    glEnd();
    glPopMatrix();

    //dinding depan atas
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(-230, 180.0, 220);
    glVertex3f(-230, 200.0, 220);
    glVertex3f(230, 200, 220);
    glVertex3f(230, 180, 220);
    glEnd();
    glPopMatrix();


    //dinding kanan poss
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(230, 40.0, 220);
    glVertex3f(230, 80.0, 220);
    glVertex3f(230, 80, -140);
    glVertex3f(230, 40, -140);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(230, 40.0, 220);
    glVertex3f(230, 200.0, 220);
    glVertex3f(230, 200, 90);
    glVertex3f(230, 40, 90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(230, 40.0, -140);
    glVertex3f(230, 200.0, -140);
    glVertex3f(230, 200, -10);
    glVertex3f(230, 40, -10);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(230, 180, 220);
    glVertex3f(230, 200.0, 220);
    glVertex3f(230, 200, -140);
    glVertex3f(230, 180, -140);
    glEnd();
    glPopMatrix();


    //dinding depan seblah kanan pos
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(230, 40.0, 220);
    glVertex3f(230, 200.0, 220);
    glVertex3f(115, 200, 220);
    glVertex3f(115, 40, 220);
    glEnd();
    glPopMatrix();

    //tutup bagian atas
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(230, 200.0, 220);
    glVertex3f(230, 200.0, -140);
    glVertex3f(-230, 200, -140);
    glVertex3f(-230, 200, 220);
    glEnd();
    glPopMatrix();

    //dinding belakang 
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.67, 0.05, 0.05);
    glVertex3f(230, 40.0, -140);
    glVertex3f(230, 200.0, -140);
    glVertex3f(-230, 200, -140);
    glVertex3f(-230, 40, -140);
    glEnd();
    glPopMatrix();


    //pagar kanan
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 90, 300);
    glVertex3f(125.0, 90, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 90, 300);
    glVertex3f(115.0, 90, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 90, 290);
    glVertex3f(125.0, 90, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 90, 300);
    glVertex3f(125.0, 90, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(115.0, 80, 300);
    glVertex3f(115.0, 80, 300);
    glVertex3f(125.0, 80, 290);
    glVertex3f(125.0, 80, 290);
    glEnd();
    glPopMatrix();

    //pagar kanan ujung
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(280.0, 40, 300);
    glVertex3f(280.0, 90, 300);
    glVertex3f(280.0, 90, 290);
    glVertex3f(280.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(280.0, 40, 300);
    glVertex3f(280.0, 90, 300);
    glVertex3f(270.0, 90, 300);
    glVertex3f(270.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(280.0, 40, 290);
    glVertex3f(280.0, 90, 290);
    glVertex3f(270.0, 90, 290);
    glVertex3f(270.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(270.0, 40, 290);
    glVertex3f(270.0, 90, 290);
    glVertex3f(270.0, 90, 300);
    glVertex3f(270.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(115.0, 80, 300);
    glVertex3f(115.0, 80, 290);
    glVertex3f(280.0, 80, 290);
    glVertex3f(280.0, 80, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(115.0, 90, 300);
    glVertex3f(115.0, 90, 290);
    glVertex3f(280.0, 90, 290);
    glVertex3f(280.0, 90, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(115.0, 80, 300);
    glVertex3f(115.0, 90, 300);
    glVertex3f(280.0, 90, 300);
    glVertex3f(280.0, 80, 300);
    glEnd();
    glPopMatrix();

    //bantalan pintu kanan
    glPushMatrix();
    glTranslatef(-10, 0, -75);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 180, 300);
    glVertex3f(125.0, 180, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 0, -75);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 180, 300);
    glVertex3f(115.0, 180, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 0, -75);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 180, 290);
    glVertex3f(125.0, 180, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-10, 0, -75);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 180, 300);
    glVertex3f(125.0, 180, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //bantalan pintu kiri
    glPushMatrix();
    glTranslatef(-235, 0, -75);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 180, 300);
    glVertex3f(125.0, 180, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-235, 0, -75);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 180, 300);
    glVertex3f(115.0, 180, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-235, 0, -75);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 180, 290);
    glVertex3f(125.0, 180, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-235, 0, -75);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 180, 300);
    glVertex3f(125.0, 180, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //bantalan pintu atas
    glPushMatrix();
    glTranslatef(0, 0, -5);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-115.0, 180, 220);
    glVertex3f(-115.0, 180, 230);
    glVertex3f(115.0, 180, 230);
    glVertex3f(115.0, 180, 220);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, -5);
    glBegin(GL_POLYGON);
    glColor3f(0.7, 0.68, 0.06);
    glVertex3f(-115.0, 170, 220);
    glVertex3f(-115.0, 180, 230);
    glVertex3f(115.0, 180, 230);
    glVertex3f(115.0, 170, 220);
    glEnd();
    glPopMatrix();

    //tiang merah kanan
    glPushMatrix();
    glTranslatef(30, 0, -35);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 188, 300);
    glVertex3f(125.0, 188, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, 0, -35);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 188, 300);
    glVertex3f(115.0, 188, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, 0, -35);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 190, 290);
    glVertex3f(125.0, 190, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, 0, -35);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 188, 300);
    glVertex3f(125.0, 188, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //tiang merah kanan 2
    glPushMatrix();
    glTranslatef(130, -5, -35);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 188, 300);
    glVertex3f(125.0, 188, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, -5, -35);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 188, 300);
    glVertex3f(115.0, 188, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, -5, -35);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 190, 290);
    glVertex3f(125.0, 190, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, -5, -35);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 188, 300);
    glVertex3f(125.0, 188, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //tiang merah kanan 3
    glPushMatrix();
    glTranslatef(130, 0, -145);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 190, 300);
    glVertex3f(125.0, 190, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, 0, -145);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 190, 300);
    glVertex3f(115.0, 190, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, 0, -145);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 190, 290);
    glVertex3f(125.0, 190, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, 0, -145);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 190, 300);
    glVertex3f(125.0, 190, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //tiang merah kanan 4
    glPushMatrix();
    glTranslatef(130, 0, -360);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 190, 300);
    glVertex3f(125.0, 190, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, 0, -360);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 190, 300);
    glVertex3f(115.0, 190, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, 0, -360);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 190, 290);
    glVertex3f(125.0, 190, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(130, 0, -360);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 190, 300);
    glVertex3f(125.0, 190, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //tiang merah kiri 1
    glPushMatrix();
    glTranslatef(-270, 0, -40);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 190, 300);
    glVertex3f(125.0, 190, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-270, 0, -40);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 190, 300);
    glVertex3f(115.0, 190, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-270, 0, -40);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 190, 290);
    glVertex3f(125.0, 190, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-270, 0, -40);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 190, 300);
    glVertex3f(125.0, 190, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //tiang merah kiri 2
    glPushMatrix();
    glTranslatef(-370, 0, -40);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 185, 300);
    glVertex3f(125.0, 185, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-370, 0, -40);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 185, 300);
    glVertex3f(115.0, 185, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-370, 0, -40);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 185, 290);
    glVertex3f(125.0, 185, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-370, 0, -40);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 185, 300);
    glVertex3f(125.0, 185, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //tiang merah kiri 3
    glPushMatrix();
    glTranslatef(-370, 0, -145);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 190, 300);
    glVertex3f(125.0, 190, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-370, 0, -145);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 190, 300);
    glVertex3f(115.0, 190, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-370, 0, -145);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 190, 290);
    glVertex3f(125.0, 190, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-370, 0, -145);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 190, 300);
    glVertex3f(125.0, 190, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //tiang merah kiri 4
    glPushMatrix();
    glTranslatef(-370, 0, -360);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 190, 300);
    glVertex3f(125.0, 190, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-370, 0, -360);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 190, 300);
    glVertex3f(115.0, 190, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-370, 0, -360);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 190, 290);
    glVertex3f(125.0, 190, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-370, 0, -360);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 190, 300);
    glVertex3f(125.0, 190, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();


    //pagar kiri
    glPushMatrix();
    glTranslatef(-235, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 90, 300);
    glVertex3f(125.0, 90, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-235, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 90, 300);
    glVertex3f(115.0, 90, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-235, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 90, 290);
    glVertex3f(125.0, 90, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-235, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 90, 300);
    glVertex3f(125.0, 90, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();



    //pagar ujung kiri
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 40, 300);
    glVertex3f(-280.0, 90, 300);
    glVertex3f(-270.0, 90, 300);
    glVertex3f(-270.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-270.0, 40, 300);
    glVertex3f(-270.0, 90, 300);
    glVertex3f(-270.0, 90, 290);
    glVertex3f(-270.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 40, 300);
    glVertex3f(-280.0, 90, 300);
    glVertex3f(-280.0, 90, 290);
    glVertex3f(-280.0, 40, 290);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 40, 290);
    glVertex3f(-280.0, 90, 290);
    glVertex3f(-270.0, 90, 290);
    glVertex3f(-270.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 90, 300);
    glVertex3f(-280.0, 90, 290);
    glVertex3f(-115.0, 90, 290);
    glVertex3f(-115.0, 90, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 80, 300);
    glVertex3f(-280.0, 80, 290);
    glVertex3f(-115.0, 80, 290);
    glVertex3f(-115.0, 80, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 80, 300);
    glVertex3f(-280.0, 90, 300);
    glVertex3f(-115.0, 90, 300);
    glVertex3f(-115.0, 80, 300);
    glEnd();
    glPopMatrix();

    //pagar kiri blkng
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 40, -140);
    glVertex3f(-280.0, 90, -140);
    glVertex3f(-270.0, 90, -140);
    glVertex3f(-270.0, 40, -140);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 40, -130);
    glVertex3f(-280.0, 90, -130);
    glVertex3f(-270.0, 90, -130);
    glVertex3f(-270.0, 40, -130);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 40, -140);
    glVertex3f(-280.0, 90, -140);
    glVertex3f(-280.0, 90, -130);
    glVertex3f(-280.0, 40, -130);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-270.0, 40, -140);
    glVertex3f(-270.0, 90, -140);
    glVertex3f(-270.0, 90, -130);
    glVertex3f(-270.0, 40, -130);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 90, -140);
    glVertex3f(-270.0, 90, -140);
    glVertex3f(-270.0, 90, 300);
    glVertex3f(-280.0, 90, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 80, -140);
    glVertex3f(-270.0, 80, -140);
    glVertex3f(-270.0, 80, 300);
    glVertex3f(-280.0, 80, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 80, -140);
    glVertex3f(-280.0, 90, -140);
    glVertex3f(-280.0, 90, 300);
    glVertex3f(-280.0, 80, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 90, -140);
    glVertex3f(-280.0, 90, -130);
    glVertex3f(-230.0, 90, -130);
    glVertex3f(-230.0, 90, -140);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 80, -140);
    glVertex3f(-280.0, 80, -130);
    glVertex3f(-230.0, 80, -130);
    glVertex3f(-230.0, 80, -140);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 80, -130);
    glVertex3f(-280.0, 90, -130);
    glVertex3f(-230.0, 90, -130);
    glVertex3f(-230.0, 80, -130);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 80, -140);
    glVertex3f(-280.0, 90, -140);
    glVertex3f(-230.0, 90, -140);
    glVertex3f(-230.0, 80, -140);
    glEnd();
    glPopMatrix();

    //pagar kanan
    glPushMatrix();
    glTranslatef(550, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 40, -140);
    glVertex3f(-280.0, 90, -140);
    glVertex3f(-270.0, 90, -140);
    glVertex3f(-270.0, 40, -140);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(550, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 40, -130);
    glVertex3f(-280.0, 90, -130);
    glVertex3f(-270.0, 90, -130);
    glVertex3f(-270.0, 40, -130);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(550, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 40, -140);
    glVertex3f(-280.0, 90, -140);
    glVertex3f(-280.0, 90, -130);
    glVertex3f(-280.0, 40, -130);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(550, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-270.0, 40, -140);
    glVertex3f(-270.0, 90, -140);
    glVertex3f(-270.0, 90, -130);
    glVertex3f(-270.0, 40, -130);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(550, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 90, -140);
    glVertex3f(-270.0, 90, -140);
    glVertex3f(-270.0, 90, 300);
    glVertex3f(-280.0, 90, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(550, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 80, -140);
    glVertex3f(-270.0, 80, -140);
    glVertex3f(-270.0, 80, 300);
    glVertex3f(-280.0, 80, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(560, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 80, -140);
    glVertex3f(-280.0, 90, -140);
    glVertex3f(-280.0, 90, 300);
    glVertex3f(-280.0, 80, 300);
    glEnd();
    glPopMatrix();


    glPushMatrix();
    glTranslatef(510, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 90, -140);
    glVertex3f(-280.0, 90, -130);
    glVertex3f(-230.0, 90, -130);
    glVertex3f(-230.0, 90, -140);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(510, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 80, -140);
    glVertex3f(-280.0, 80, -130);
    glVertex3f(-230.0, 80, -130);
    glVertex3f(-230.0, 80, -140);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(510, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 80, -130);
    glVertex3f(-280.0, 90, -130);
    glVertex3f(-230.0, 90, -130);
    glVertex3f(-230.0, 80, -130);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(510, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.37, 0.22, 0.01);
    glVertex3f(-280.0, 80, -140);
    glVertex3f(-280.0, 90, -140);
    glVertex3f(-230.0, 90, -140);
    glVertex3f(-230.0, 80, -140);
    glEnd();
    glPopMatrix();

    //atap depan
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.34, 0.09, 0);
    glVertex3f(230.0, 200, 220);
    glVertex3f(-230, 200, 220);
    glVertex3f(-230.0, 180, 300);
    glVertex3f(230.0, 180, 300);
    glEnd();
    glPopMatrix();

    //atap belakang
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.34, 0.09, 0);
    glVertex3f(230.0, 200, -140);
    glVertex3f(-230, 200, -140);
    glVertex3f(-230.0, 180, -220);
    glVertex3f(230.0, 180, -220);
    glEnd();
    glPopMatrix();

    // atap  kiri
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.34, 0.09, 0);
    glVertex3f(-230.0, 200, 220);
    glVertex3f(-230, 200, -140);
    glVertex3f(-310.0, 180, -140);
    glVertex3f(-310.0, 180, 220);
    glEnd();
    glPopMatrix();

    // atap  kanan
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.34, 0.09, 0);
    glVertex3f(230.0, 200, 220);
    glVertex3f(230, 200, -140);
    glVertex3f(310.0, 180, -140);
    glVertex3f(310.0, 180, 220);
    glEnd();
    glPopMatrix();

    //segitiga kiri depan

    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.34, 0.09, 0);
    glVertex3f(-230.0, 180, 300);
    glVertex3f(-310, 180, 220);
    glVertex3f(-230.0, 200, 220);
    glEnd();
    glPopMatrix();

    //segitiga kiri blkng
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.34, 0.09, 0);
    glVertex3f(-310.0, 180, -140);
    glVertex3f(-230, 180, -220);
    glVertex3f(-230.0, 200, -140);
    glEnd();
    glPopMatrix();

    //segitiga kanan depan
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.34, 0.09, 0);
    glVertex3f(230.0, 180, 300);
    glVertex3f(310, 180, 220);
    glVertex3f(230.0, 200, 220);
    glEnd();
    glPopMatrix();

    //segitiga kanan blkng
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.34, 0.09, 0);
    glVertex3f(310.0, 180, -140);
    glVertex3f(230, 180, -220);
    glVertex3f(230.0, 200, -140);
    glEnd();
    glPopMatrix();



    glPushMatrix();
    glTranslatef(-210, 180, -120);
    glColor3f(0.7, 0.68, 0.06);
    glutSolidSphere(10.0, 30, 30);
    glPopMatrix();


    glPushMatrix();
    glTranslatef(220, 175, -130);
    glColor3f(0.7, 0.68, 0.06);
    glutSolidSphere(10.0, 30, 30);
    glPopMatrix();


    //pondasi kayu atap depan
    glPushMatrix();
    glColor3f(0.7, 0.68, 0.06);
    glTranslatef(0, 290, 50);
    gluCylinder(gluNewQuadric(), 10.0f, 10.0f, 800.0f, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 290, 850);
    glColor3f(0.42, 0, 0);
    glutSolidSphere(9.0, 30, 30);
    glPopMatrix();

    //kiri
    glPushMatrix();
    glColor3f(0.7, 0.68, 0.06);
    glTranslatef(-150, 210, 0);
    gluCylinder(gluNewQuadric(), 10.0f, 10.0f, 750.0f, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(150, 210, 750);
    glColor3f(0.42, 0, 0);
    glutSolidSphere(9.0, 30, 30);
    glPopMatrix();


    //kanan
    glPushMatrix();
    glColor3f(0.7, 0.68, 0.06);
    glTranslatef(150, 210, 0);
    gluCylinder(gluNewQuadric(), 10.0f, 10.0f, 750.0f, 32, 32);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-150, 210, 750);
    glColor3f(0.42, 0, 0);
    glutSolidSphere(9.0, 30, 30);
    glPopMatrix();


    //atap kanan
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(0.0, 290, 50);
    glVertex3f(150, 210, 0);
    glVertex3f(150.0, 210, 750);
    glVertex3f(0.0, 290, 855);
    glEnd();
    glPopMatrix();

    //atap kiri
    glPushMatrix();
    glTranslatef(0, 0, 0);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(0.0, 290, 50);
    glVertex3f(-150, 210, 0);
    glVertex3f(-150.0, 210, 750);
    glVertex3f(0.0, 290, 855);
    glEnd();
    glPopMatrix();

    //tiang atap luar kanan
    glPushMatrix();
    glTranslatef(30, -35, 455);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 250, 300);
    glVertex3f(125.0, 250, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -35, 455);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 250, 300);
    glVertex3f(115.0, 250, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -35, 455);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 250, 290);
    glVertex3f(125.0, 250, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -35, 455);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 250, 300);
    glVertex3f(125.0, 250, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //tiang atap luar kiri
    glPushMatrix();
    glTranslatef(-270, -35, 455);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 250, 300);
    glVertex3f(125.0, 250, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-270, -35, 455);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 250, 300);
    glVertex3f(115.0, 250, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-270, -35, 455);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 250, 290);
    glVertex3f(125.0, 250, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-270, -35, 455);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 250, 300);
    glVertex3f(125.0, 250, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();


    //tiang atap luar kiri 2
    glPushMatrix();
    glTranslatef(-255, -35, 75);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 250, 300);
    glVertex3f(125.0, 250, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-255, -35, 75);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 250, 300);
    glVertex3f(115.0, 250, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-255, -35, 75);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 250, 290);
    glVertex3f(125.0, 250, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-255, -35, 75);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 250, 300);
    glVertex3f(125.0, 250, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //tiang atap luar kanan 2
    glPushMatrix();
    glTranslatef(30, -35, 75);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 250, 300);
    glVertex3f(125.0, 250, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -35, 75);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 250, 300);
    glVertex3f(115.0, 250, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -35, 75);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 250, 290);
    glVertex3f(125.0, 250, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -35, 75);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 250, 300);
    glVertex3f(125.0, 250, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //tiang atap luar kanan tengah
    glPushMatrix();
    glTranslatef(30, -35, 265);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 250, 300);
    glVertex3f(125.0, 250, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -35, 265);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 250, 300);
    glVertex3f(115.0, 250, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -35, 265);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 250, 290);
    glVertex3f(125.0, 250, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(30, -35, 265);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 250, 300);
    glVertex3f(125.0, 250, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    //tiang atap luar kiri tengah
    glPushMatrix();
    glTranslatef(-270, -35, 260);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 250, 300);
    glVertex3f(125.0, 250, 300);
    glVertex3f(125.0, 40, 300);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-270, -35, 260);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 300);
    glVertex3f(115.0, 250, 300);
    glVertex3f(115.0, 250, 290);
    glVertex3f(115.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-270, -35, 260);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(115.0, 40, 290);
    glVertex3f(115.0, 250, 290);
    glVertex3f(125.0, 250, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-270, -35, 260);
    glBegin(GL_POLYGON);
    glColor3f(0.42, 0, 0);
    glVertex3f(125.0, 40, 300);
    glVertex3f(125.0, 250, 300);
    glVertex3f(125.0, 250, 290);
    glVertex3f(125.0, 40, 290);
    glEnd();
    glPopMatrix();



    // glTranslatef(x_geser, y_geser, z_geser);

    // glPushMatrix();
    // glTranslatef(x_geser, y_geser, z_geser);
    // gluCylinder(gluNewQuadric(), 10.0f, 10.0f, 20.0f, 32, 32);
    // glPopMatrix();





    ground();
    cout << "X_GESER = " << x_geser << "  Y_GESER = " << y_geser << " Z_GESER = " << z_geser << endl;
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    camera();
    draw();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50, 16.0 / 9.0, 2, 10000);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int) {
    glutPostRedisplay();
    glutWarpPointer(width / 2, height / 2);
    glutTimerFunc(1000 / FPS, timer, 0);
}

void passive_motion(int x, int y) {
    int dev_x, dev_y;
    dev_x = (width / 2) - x;
    dev_y = (height / 2) - y;
    yaw += (float)dev_x / 20.0;
    pitch += (float)dev_y / 20.0;
}

void camera() {
    if (motion.Forward) {
        camX += cos((yaw + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90) * TO_RADIANS) * 2;
    }
    if (motion.Backward) {
        camX += cos((yaw + 90 + 180) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 180) * TO_RADIANS) * 2;
    }
    if (motion.Left) {
        camX += cos((yaw + 90 + 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 + 90) * TO_RADIANS) * 2;
    }
    if (motion.Right) {
        camX += cos((yaw + 90 - 90) * TO_RADIANS) * 2;
        camZ -= sin((yaw + 90 - 90) * TO_RADIANS) * 2;
    }
    if (motion.Naik) {
        terbang -= 2.0;
    }
    if (motion.Turun) {
        terbang += 2.0;
    }

    if (pitch >= 70)
        pitch = 70;
    if (pitch <= -90)
        pitch = -90;


    glRotatef(-pitch, 1.0, 0.0, 0.0);
    glRotatef(-yaw, 0.0, 1.0, 0.0);

    glTranslatef(-camX, -terbang, -350 - camZ);
    if (terbang < 25)
        terbang = 24;
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = true;
        break;
    case 'A':
    case 'a':
        motion.Left = true;
        break;
    case 'S':
    case 's':
        motion.Backward = true;
        break;
    case 'D':
    case 'd':
        motion.Right = true;
        break;
    case 'E':
    case 'e':
        motion.Naik = true;
        break;
    case 'Q':
    case 'q':
        motion.Turun = true;
        break;
    case 'p':
        x_geser += 05.0;
        break;
    case 'i':
        x_geser -= 05.0;
        break;
    case 'o':
        y_geser += 05.0;
        break;
    case 'l':
        y_geser -= 05.0;
        break;
    case ',':
        z_geser -= 05.0;
        break;
    case '.':
        z_geser += 05.0;
        break;
    case '`': // KELUAR DARI PROGRAM
        exit(1);
    }
}

void keyboard_up(unsigned char key, int x, int y) {
    switch (key) {
    case 'W':
    case 'w':
        motion.Forward = false;
        break;
    case 'A':
    case 'a':
        motion.Left = false;
        break;
    case 'S':
    case 's':
        motion.Backward = false;
        break;
    case 'D':
    case 'd':
        motion.Right = false;
        break;
    case 'E':
    case 'e':
        motion.Naik = false;
        break;
    case 'Q':
    case 'q':
        motion.Turun = false;
        break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("TR GRAFKOM KELOMPOK X");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutPassiveMotionFunc(passive_motion);
    glutTimerFunc(0, timer, 0);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboard_up);

    glutMainLoop();
    return 0;
}
