#include <cstdlib>
#include <iostream>
#include <OpenGl/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/GLUT.h>
#include <wchar.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
#include <unistd.h>
 
void init(){
    glClearColor(0.0 , 0.0 , 0.0 , 1.0);
    glEnable(GL_DEPTH_TEST);
}

 
void reshapeFunc(int w, int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective (40.0, (GLdouble)w / (GLdouble)h, 0.5, 20.0); //perspective mode instead of ortho2d
    glMatrixMode(GL_MODELVIEW);
}
 
float angle = 0;
float x = 0;
float y = 0;

 
 
 
void cartLink(){
    //cart-link
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(10.0);
    glBegin(GL_LINES);
    glVertex3f(-10.0, 0.0, 0.0 );
    glVertex3f(0.5, 0.2 , 0.0 );
    glEnd();
    
}

void shipSail(){
    glBegin (GL_QUADS) ;

    glColor3f(1.0,1.0,1.0);
    glVertex3f(-2.0,2.0,1.0);
    glVertex3f(-2.0,1.0,1.0);
    glVertex3f(3.0,1.0,1.0);
    glVertex3f(3.0,2.0,1.0);

    glColor3f(1.0,1.0,1.0);
    glVertex3f(2.0,3.0,-1.0);
    glVertex3f(2.0,0.0,-1.0);
    glVertex3f (-1.0,0.0,-1.0);
    glVertex3f(-3.0,3.0,-1.0);
    
    glColor3f(1.0,1.0,1.0);
    glVertex3f(3.0,1.0,1.0);
    glVertex3f(4.0,0.0,1.0);
    glVertex3f(5.0,0.0,-1.0);
    glVertex3f(2.0,4.0,-1.0);

    glColor3f(1.0,1.0,1.0);
    glVertex3f(-1.0,2.0,-1.0);
    glVertex3f(-3.0,0.0,-1.0);
    glVertex3f(-4.0,0.0,1.0);
    glVertex3f(-5.0,1.0,1.0);

    glColor3f(1.0,1,1.0);
    glVertex3f (-1.0,2.0,-1.0);
    glVertex3f (-3.0,1.0,1.0);
    glVertex3f(4.0,3.0,1.0);
    glVertex3f(5.0,1.0,-1.0);
    
    glColor3f(1.0,1.0,1.0);
    glVertex3f (-1.0,0.0,-1.0);
    glVertex3f(-4.0,0.0,1.0);
    glVertex3f(2.0,1.0,1.0);
    glVertex3f(4.0,0.0,-1.0);
    glEnd();
}
void shipBody(){
    glBegin (GL_QUADS) ;

    glColor3f(1,1,1);
    glVertex3f(-6.0,1.0,1.0);
    glVertex3f(-6.0,0.0,1.0);
    glVertex3f(6.0,0.0,1.0);
    glVertex3f(6.0,1.0,1.0);
   
    glColor3f(1.0,1,1.0);
    glVertex3f(6.0,1.0,-1.0);
    glVertex3f(6.0,0.0,-1.0);
    glVertex3f (-6.0,0.0,-1.0);
    glVertex3f(-6.0,1.0,-1.0);

    glColor3f(1.0,1,1.0);
    glVertex3f(6.0,1.0,1.0);
    glVertex3f(6.0,0.0,1.0);
    glVertex3f(6.0,0.0,-1.0);
    glVertex3f(6.0,1.0,-1.0);

    glColor3f(1.0,1.0,1.0);
    glVertex3f(-6.0,1.0,-1.0);
    glVertex3f(-6.0,0.0,-1.0);
    glVertex3f(-6.0,0.0,1.0);
    glVertex3f(-6.0,1.0,1.0);
 
    glColor3f(1.0,1.0,1.0);
    glVertex3f (-6.0,1.0,-1.0);
    glVertex3f (-6.0,1.0,1.0);
    glVertex3f(6.0,1.0,1.0);
    glVertex3f(6.0,1.0,-1.0);

    glColor3f(1.0,1.0,1.0);
    glVertex3f (-6.0,0.0,-1.0);
    glVertex3f(-6.0,0.0,1.0);
    glVertex3f(6.0,0.0,1.0);
    glVertex3f(6.0,0.0,-1.0);
    glEnd();
}
float step=0;
void ship(){
    glTranslatef(0 +x, -10.8 +y, 16+step);
    glRotatef(40 , 1.0 , 0.5  , 0.0 );
    glRotatef(10 , 1.0, 0.0, 1.0 );

    shipBody();
    cartLink();
    shipSail();
}

float  zRotated = 0.0;
void clouds(){
    glPushMatrix();
    glTranslatef(-1 ,6 ,-11);
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0,1.0,1.0); // scaling transfomation
    glutSolidSphere(1,20,5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-2,5.7 ,-11);
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0,1.0,1.0); // scaling transfomation
    glutSolidSphere(1,20,5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0,5.7 ,-11);
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0,1.0,1.0); // scaling transfomation
    glutSolidSphere(1,20,5);
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(-1 ,5 ,-11);
    glColor3f(1.0, 1.0, 1.0);
    glScalef(1.0,1.0,1.0); // scaling transfomation
    glutSolidSphere(1,20,5);
    glPopMatrix();
}
void tree(){
                glPushMatrix();
                glTranslatef(0.0,-1.0+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated,0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.555,0.9,20,20);//draw cone
                glPopMatrix();

                
                glPushMatrix();
                glTranslatef(0.0,-0.62+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.45,0.9,20,20);//draw cone
                glPopMatrix();

                
                glPushMatrix();
                glTranslatef(0.0,-0.25+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.35,0.9,20,20);//draw cone
                glPopMatrix();

                
                glPushMatrix ();
                glTranslatef(0.0,0.1+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.29,0.7,20,20);//draw cone
                glPopMatrix ();
}

void tree2(){
                glPushMatrix ();
                glTranslatef(0.4,-1.0+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated,0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.555,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(0.4,-0.62+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.45,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(0.4,-0.25+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.35,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(0.4,0.1+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.29,0.7,20,20);//draw cone
                glPopMatrix ();
}

void tree3(){
                glPushMatrix ();
                glTranslatef(1.2,-1.0+2,-9.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated,0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.555,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(1.2,-0.62+2,-9.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.45,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(1.2,-0.25+2,-9.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.35,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(1.2,0.1+2,-9.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.29,0.7,20,20);//draw cone
                glPopMatrix ();
}
void tree4(){
                glPushMatrix ();
                glTranslatef(-1.2,-1.0+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated,0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.555,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-1.2,-0.62+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.45,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-1.2,-0.25+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.35,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-1.2,0.1+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.29,0.7,20,20);//draw cone
                glPopMatrix();
}

void tree5(){
                glPushMatrix ();
                glTranslatef(-2.0,-1.0+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated,0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.555,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-2.0,-0.62+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.45,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-2.0,-0.25+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.35,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-2.0,0.1+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.29,0.7,20,20);//draw cone
                glPopMatrix();
}

void tree6(){
                glPushMatrix ();
                glTranslatef(-3.0,-1.0+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated,0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.555,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-3.0,-0.62+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.45,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-3.0,-0.25+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.35,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-3.0,0.1+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.29,0.7,20,20);//draw cone
                glPopMatrix();
}

void tree7(){
                glPushMatrix ();
                glTranslatef(-6.0,-1.0+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated,0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.555,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-6.0,-0.62+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.45,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-6.0,-0.25+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.35,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-6.0,0.1+2,-8.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.29,0.7,20,20);//draw cone
                glPopMatrix();
}

void tree8(){
                glPushMatrix ();
                glTranslatef(4.0,-1.0+2,-10.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated,0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.555,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(4.0,-0.62+2,-10.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.45,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(4.0,-0.25+2,-10.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.35,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(4.0,0.1+2,-10.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.29,0.7,20,20);//draw cone
                glPopMatrix();
}
void tree9(){
                glPushMatrix ();
                glTranslatef(-5.0,-1.0+2,-10.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated,0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.555,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-5.0,-0.62+2,-10.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.45,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-5.0,-0.25+2,-10.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.35,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-5.0,0.1+2,-10.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.29,0.7,20,20);//draw cone
                glPopMatrix();
}
void tree10(){
                glPushMatrix ();
                glTranslatef(-3.5,-1.0+2,-7.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated,0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.555,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-3.5,-0.62+2,-7.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.45,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-3.5,-0.25+2,-7.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.35,0.9,20,20);//draw cone
                glPopMatrix ();

                
                glPushMatrix ();
                glTranslatef(-3.5,0.1+2,-7.5);//set  position
                glColor3f(0.0, 0.5, 0.0);
                glRotatef(-90.0, 1,0,0);
                glRotatef(zRotated, 0,0,1);
                glScalef(1.0,1.0,1.0);
                glutSolidCone(0.29,0.7,20,20);//draw cone
                glPopMatrix();
}
void translatee(){
    glTranslatef(0,0,-8.5);
    glColor3f(1.0, 1.0, 1.0);
    glLineWidth(5.0);
   
}
 
void sun(float a, float b, float c){
 
    glTranslatef(-5 ,6 ,-12);
 
    glColor3f(a, b, c);
    glScalef(1.0,1.0,1.0); // scaling transfomation
    glutSolidSphere(1,20,5);
 
}
bool state = true;
void keyboard(unsigned char key, int x, int y){
    // we'll switch between night sky and morning sky when the user presses a key:
    GLfloat colors[][3] = {
        { 0.6f, 0.9f, 1.0f},
        {0.0f, 0.0f, 0.1f }
    };
    static int back;
   
    switch (key) {
    case '1':
            state = false;
    default:
        state = true;
        back ^= 1;
        glClearColor(colors[back][0], colors[back][1], colors[back][2], 1.0f);
        glutPostRedisplay();
    }
}
float a,b,c;
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity ();
    if(state){
        a = 0.9;
        b = 0.5;
        c = 0.1;
    }
    else{
        a = 1;
        b = 0.9;
        c = 1;
    }
    translatee();
    clouds();
    tree();
    tree2();
    tree3();
    tree4();
    tree5();
    tree6();
    tree7();
    tree8();
    tree9();
    tree10();
    sun(a,b,c);
    ship();
 
  
 
    glutSwapBuffers();
}
 
void idleFunc(){
    zRotated += 1;
    glutPostRedisplay();
}
 
void textures(){
const GLfloat light_ambient[]  = { 4.0f, 0.0f, 2.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 2.0f };
const GLfloat light_specular[] = { 5.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };
 
const GLfloat mat_ambient[]    = { 1.4f, 0.7f, 0.7f, 3.0f };
const GLfloat mat_diffuse[]    = { 0.2f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.2f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };
 
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
 
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
 
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
 
    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
 
    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
 
}

void scene(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/25,scene,0);
 
    angle += 0.8;
    if( angle > 360.0){
        angle -= 360.0 ;
    }

    x += 0.13;
    y += 0.05;
    step -= 0.15;
 
}
 
 
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // buffer mode
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(700, 200);
    glutCreateWindow("20101912");
    init();
    glutKeyboardFunc(keyboard);
    glutDisplayFunc (display);
    glutReshapeFunc (reshapeFunc);
    glutTimerFunc(800, scene, 0);
    glutIdleFunc(idleFunc);
    glClearColor(0,0,0,1);
    textures();
 
 
    glutMainLoop();
}
