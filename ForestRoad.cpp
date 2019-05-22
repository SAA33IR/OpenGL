#include<windows.h>
#include <GL/glut.h>
#include<stdio.h>
#include <math.h>

float positionZ = 1.0f;
float deltaMove = 0.0f;

void ChangeSize(int w, int h)
{
    if (h == 0)
        h = 1;
    float rat =  w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0f, rat, 0.1f, 150.0f);
    glMatrixMode(GL_MODELVIEW);
}

void Tree1()
{
    // Base
    glColor3f(0.5f, 0.3f, 0.0f);
    glRotatef(-90.0f,1.0f, 0.0f, 0.0f);
    GLUquadricObj *obj = gluNewQuadric();
    gluCylinder(obj, 0.5f, 0.4f, 4.0f, 30, 2);
    glColor3f(0.5f, 0.28f, 0.0f);
    glTranslatef(0.0f, 0.0f, 2.0f);
    glRotatef(-45.0f,0.0f, 1.0f, 0.0f);
    gluCylinder(obj, 0.2f, 0.1f, 2.0f, 10, 2);
    glTranslatef(0.25f, 0.0f, 0.25f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(obj, 0.2f, 0.1f, 2.0f, 10, 2);

    // Leaf
    glColor3f(0.0f, 0.7f, 0.0f);
    glTranslatef(0.0f, 0.0f, 2.0f);
    glScalef(0.5f,0.5f,0.5f);
    glutSolidDodecahedron();
    glScalef(2.0f,2.0f,2.0f);
    glTranslatef(-1.75f, 0.0f, -2.25f);
    glScalef(0.5f,0.5f,0.5f);
    glutSolidDodecahedron();
    glScalef(2.0f,2.0f,2.0f);
    glColor3f(0.0f, 0.8f, 0.0f);
    glTranslatef(0.0f, 0.0f, 2.00f);
    glutSolidDodecahedron();
    glColor3f(0.0f, 0.75f, 0.0f);
    glRotatef(45.0f, 0.3f, 0.6f, 1.0f);
    glutSolidDodecahedron();
}

void Tree2()
{
    // Base
    glColor3f(0.5f, 0.3f, 0.0f);
    glRotatef(-90.0f,1.0f, 0.0f, 0.0f);
    GLUquadricObj *obj = gluNewQuadric();
    gluCylinder(obj, 0.5f, 0.4f, 4.0f, 30, 2);

    // Leaf
    glColor3f(0.0f, 0.5f, 0.0f);
    glTranslatef(0.0f, 0.0f, 2.0f);
    glutSolidCone(2.0f, 4.0f, 8, 2);
    glColor3f(0.0f, 0.55f, 0.0f);
    glTranslatef(0.0f, 0.0f, 1.0f);
    glutSolidCone(1.8f, 4.5f, 8, 2);
    glColor3f(0.0f, 0.6f, 0.0f);
    glTranslatef(0.0f, 0.0f, 1.0f);
    glutSolidCone(1.6f, 5.0f, 8, 2);
    glColor3f(0.0f, 0.65f, 0.0f);
    glTranslatef(0.0f, 0.0f, 1.0f);
    glutSolidCone(1.5f, 6.0f, 8, 2);
}

void Tree3()
{
    // Base
    glColor3f(0.5f, 0.3f, 0.0f);
    glRotatef(-90.0f,1.0f, 0.0f, 0.0f);
    GLUquadricObj *obj = gluNewQuadric();
    gluCylinder(obj, 0.5f, 0.4f, 4.0f, 30, 2);
    glColor3f(0.5f, 0.28f, 0.0f);
    glTranslatef(0.0f, 0.0f, 2.0f);
    glRotatef(-45.0f,0.0f, 1.0f, 0.0f);
    gluCylinder(obj, 0.2f, 0.1f, 2.0f, 10, 2);
    glTranslatef(0.25f, 0.0f, 0.25f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gluCylinder(obj, 0.2f, 0.1f, 2.0f, 10, 2);
    glColor3f(0.0f, 0.9f, 0.0f);
    glRotatef(45.0f,0.0f, 1.0f, 0.0f);
    glTranslatef(-2.0f, 0.0f, 0.0f);
    glScalef(0.8f,1.0f,1.0f);
    glutSolidCube(3.0f);
    glColor3f(0.0f, 0.8f, 0.0f);
    glTranslatef(-0.5f, 1.0f, 1.0f);
    glutSolidCube(2.0f);
    glColor3f(0.0f, 0.75f, 0.0f);
    glTranslatef(1.0f, -2.0f, -1.0f);
    glutSolidCube(2.0f);
    glColor3f(0.0f, 0.7f, 0.0f);
    glTranslatef(0.5f, 1.0f, -1.0f);
    glutSolidCube(2.0f);
}

void Fence()
{
    glColor3f(0.6f, 0.4f, 0.2f);
    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.2f, 0.0f);
    glVertex3f(0.0f, 0.4f, 0.0f);
    glVertex3f(0.0f, 0.4f, 6.0f);
    glVertex3f(0.0f, 0.2f, 6.0f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex3f(0.0f, 0.7f, 0.0f);
    glVertex3f(0.0f, 0.9f, 0.0f);
    glVertex3f(0.0f, 0.9f, 6.0f);
    glVertex3f(0.0f, 0.7f, 6.0f);
    glEnd();

    for(int i=0; i<6; i++)
    {
        glBegin(GL_POLYGON);
        glVertex3f(0.0f, 0.0f, i+0.0f);
        glVertex3f(0.0f, 1.2f, i+0.0f);
        glVertex3f(0.0f, 1.3f, i+0.2f);
        glVertex3f(0.0f, 1.2f, i+0.4f);
        glVertex3f(0.0f, 0.0f, i+0.4f);
        glEnd();
    }
}

void Cloud()
{
    glColor3f(1.0f, 1.0f, 1.0f);
    glTranslatef(0.0f, 3.0f, 10.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i<18; i++)
    {
        glVertex3f(cos(i*20*0.0174533), sin(i*20*0.0174533), 0.0f);
    }
    glEnd();

    glTranslatef(1.f, -0.40f, 0.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i<18; i++)
    {
        glVertex3f(0.8*cos(i*20*0.0174533), 0.8*sin(i*20*0.0174533), 0.0f);
    }
    glEnd();

    glTranslatef(-2.2f, -0.05f, 0.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i<18; i++)
    {
        glVertex3f(0.8*cos(i*20*0.0174533), 0.8*sin(i*20*0.0174533), 0.0f);
    }
    glEnd();

    glTranslatef(-0.8f, -0.5f, 0.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i<18; i++)
    {
        glVertex3f(0.8*cos(i*20*0.0174533), 0.6*sin(i*20*0.0174533), 0.0f);
    }
    glEnd();

    glTranslatef(3.5f, 0.01f, 0.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i<18; i++)
    {
        glVertex3f(0.7*cos(i*20*0.0174533), 0.6*sin(i*20*0.0174533), 0.0f);
    }
    glEnd();

    glTranslatef(-1.0f, -0.1f, 0.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i<18; i++)
    {
        glVertex3f(cos(i*20*0.0174533),sin(i*20*0.0174533), 0.0f);
    }
    glEnd();

    glTranslatef(-1.7f, -0.2f, 0.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i<18; i++)
    {
        glVertex3f(cos(i*20*0.0174533),sin(i*20*0.0174533), 0.0f);
    }
    glEnd();

    glTranslatef(0.9f, -0.3f, 0.0f);
    glBegin(GL_POLYGON);
    for(int i=0; i<18; i++)
    {
        glVertex3f(0.6*cos(i*20*0.0174533),0.6*sin(i*20*0.0174533), 0.0f);
    }
    glEnd();
}

void Scene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    positionZ += deltaMove*0.1f;
    gluLookAt(0.0f, 1.0f, positionZ, 0.0f, 1.0f,  positionZ+0.01f, 0.0f, 1.0f,  0.0f);

    // Ground
    glColor3f(0.0f, 0.8f, 0.0f);
    glBegin(GL_QUADS);
    glVertex3f(-100.0f, 0.0f, -100.0f);
    glVertex3f(-100.0f, 0.0f, 100.0f);
    glVertex3f( 100.0f, 0.0f, 100.0f);
    glVertex3f( 100.0f, 0.0f, -100.0f);
    glEnd();

    // Road
    glColor3f(0.5f, 0.5f, 0.4f);
    glBegin(GL_QUADS);
    glVertex3f(-3.7f, 0.01f, -100.0f);
    glVertex3f(-3.7f, 0.01f, 100.0f);
    glVertex3f( 3.7f, 0.01f, 100.0f);
    glVertex3f( 3.7f, 0.01f, -100.0f);
    glEnd();

    // Fence
    for(int i=0; i<17; i++)
    {
        glPushMatrix();
        glTranslatef(4.0f, 0, i*6.0);
        Fence();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-4.0f, 0, i*6.0);
        Fence();
        glPopMatrix();
    }

    // Tree
    for(int i=0; i<9; i++)
    {
        glPushMatrix();
        glTranslatef(6.0, 0, i*6.0);
        glRotatef(i*100.0f, 0.0f, 1.0f, 0.0f);
        Tree1();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-6.0, 0, i*6.0);
        glRotatef(i*100.0f, 0.0f, 1.0f, 0.0f);
        Tree1();
        glPopMatrix();
    }
    for(int j=2; j<=3; j++)
    {
        for(int i=0; i<7; i++)
        {
            glPushMatrix();
            glTranslatef(j*6.0, 0, i*8.0);
            glRotatef(i*100.0f, 0.0f, 1.0f, 0.0f);
            Tree3();
            glPopMatrix();
            glPushMatrix();
            glTranslatef(j*-6.0, 0, i*8.0);
            glRotatef(i*100.0f, 0.0f, 1.0f, 0.0f);
            Tree3();
            glPopMatrix();
        }
    }

    for(int i=9; i<17; i++)
    {
        glPushMatrix();
        glTranslatef(6.0, 0, i*6.0);
        Tree2();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(-6.0, 0, i*6.0);
        Tree2();
        glPopMatrix();
    }
    for(int j=2; j<=3; j++)
    {
        for(int i=7; i<13; i++)
        {
            glPushMatrix();
            glTranslatef(j*6.0, 0, i*8.0);
            Tree2();
            glPopMatrix();
            glPushMatrix();
            glTranslatef(j*-6.0, 0, i*8.0);
            Tree2();
            glPopMatrix();
        }
    }

    // Cloud
    for(int i=-3; i<0; i++)
    {
        glPushMatrix();
        glTranslatef(10+i*10.0, 30.0f, 100.0);
        glScalef(i/1.2, abs(i/1.2), abs(i/1.2));
        Cloud();
        glPopMatrix();
    }

    for(int i=0; i<4; i++)
    {
        glPushMatrix();
        glTranslatef(-20+i*14.0, 28.0f, 100.0);
        glScalef(i/1.2, abs(i/1.2), abs(i/1.2));
        Cloud();
        glPopMatrix();
    }
    glutSwapBuffers();
}

void KeyDown(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP :
        deltaMove = 0.5f;
        break;
    case GLUT_KEY_DOWN :
        deltaMove = -0.5f;
        break;
    }
}

void KeyUp(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP :
    case GLUT_KEY_DOWN :
        deltaMove = 0;
        break;
    }
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
    glEnable(GL_DEPTH_TEST);
    glutInitWindowSize(800,600);
    glutCreateWindow("Landscape");
    glClearColor(0.36f, 0.66f, 1.0f, 1.5f);

    glutDisplayFunc(Scene);
    glutReshapeFunc(ChangeSize);
    glutIdleFunc(Scene);
    glutSpecialFunc(KeyDown);
    glutSpecialUpFunc(KeyUp);
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
