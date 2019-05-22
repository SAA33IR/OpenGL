#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<bits/stdc++.h>

#define factor 3.1416/180.0
int inKey;
int grid;
int gridVisited[9];
int stat;
int player;
int over;

void Circle(float x, float y)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(1,0,1);
    for(int i=0; i<360; i+=1)
    {
        glVertex2f(x+0.1 *cos(i*factor),y+0.1*sin(i*factor));
    }
    glEnd();
}

void Cross(float x, float y)
{
    glBegin(GL_LINES);
    glColor3f(0,1,1);
    glVertex2f(x+0.1, y+0.1);
    glVertex2f(x-0.1, y-0.1);
    glVertex2f(x+0.1, y-0.1);
    glVertex2f(x-0.1, y+0.1);
    glEnd();
}

void Winner(int x)
{
    glBegin(GL_LINE_LOOP);
    glColor3f(0,1,0);
    glVertex2f(-0.44,0.6);
    glVertex2f(-0.45,0.6);
    glVertex2f(-0.45,0.8);
    glVertex2f(-0.37,0.8);
    glVertex2f(-0.35,0.77);
    glVertex2f(-0.35,0.73);
    glVertex2f(-0.37,0.7);
    glVertex2f(-0.45,0.7);
    glEnd();
    if(x == 2)
    {
        glBegin(GL_LINES);
        glColor3f(0,1,0);
        glVertex2f(-0.25,0.6);
        glVertex2f(-0.25,0.8);
        glVertex2f(-0.25,0.8);
        glVertex2f(-0.28,0.77);
        glEnd();
    }
    else
    {
        glBegin(GL_LINES);
        glColor3f(0,1,0);
        glVertex2f(-0.3,0.8);
        glVertex2f(-0.2,0.8);
        glVertex2f(-0.2,0.8);
        glVertex2f(-0.2,0.7);
        glVertex2f(-0.2,0.7);
        glVertex2f(-0.3,0.7);
        glVertex2f(-0.3,0.7);
        glVertex2f(-0.3,0.6);
        glVertex2f(-0.3,0.6);
        glVertex2f(-0.2,0.6);
        glEnd();
    }
    glBegin(GL_LINES);
    glColor3f(0,1,0);
    glVertex2f(-0.05,0.8);
    glVertex2f(-0.015,0.6);
    glVertex2f(-0.015,0.6);
    glVertex2f(0.02,0.7);
    glVertex2f(0.02,0.7);
    glVertex2f(0.055,0.6);
    glVertex2f(0.055,0.6);
    glVertex2f(0.09,0.8);
    glVertex2f(0.15,0.6);
    glVertex2f(0.15,0.8);
    glVertex2f(0.21,0.6);
    glVertex2f(0.21,0.8);
    glVertex2f(0.21,0.8);
    glVertex2f(0.31,0.6);
    glVertex2f(0.31,0.6);
    glVertex2f(0.31,0.8);
    glVertex2f(0.47,0.8);
    glVertex2f(0.37,0.8);
    glVertex2f(0.37,0.8);
    glVertex2f(0.37,0.7);
    glVertex2f(0.37,0.7);
    glVertex2f(0.47,0.7);
    glVertex2f(0.47,0.7);
    glVertex2f(0.47,0.6);
    glVertex2f(0.47,0.6);
    glVertex2f(0.37,0.6);
    glEnd();
}

void Line(float a, float b, float c, float d, float x)
{
    over = 1;
    glBegin(GL_LINES);
    glColor3f(0,1,0);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glEnd();
    Winner(x);
}

float interSecPointX[9] = {-0.3, 0, 0.3, -0.3, 0, 0.3, -0.3, 0, 0.3};
float interSecPointY[9] = {0.3, 0.3, 0.3, 0, 0, 0, -0.3, -0.3, -0.3};
void draw()
{
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex2f(-0.45,0.15);
    glVertex2f(0.45,0.15);
    glVertex2f(-0.45,-0.15);
    glVertex2f(0.45,-0.15);
    glVertex2f(0.15,0.45);
    glVertex2f(0.15,-0.45);
    glVertex2f(-0.15,0.45);
    glVertex2f(-0.15,-0.45);
    glEnd();
    if(over == 0)
    {
        if(stat == 1)
        {
            stat = 0;
            if(player%2 == 0)
            {
                if(gridVisited[grid-1] == 0)
                {
                    Circle(interSecPointX[grid-1],interSecPointY[grid-1]);
                    player++;
                    gridVisited[grid-1] = 2;
                }
            }
            else if(player%2 == 1)
            {
                if(gridVisited[grid-1] == 0)
                {
                    Cross(interSecPointX[grid-1],interSecPointY[grid-1]);
                    player++;
                    gridVisited[grid-1] = 1;
                }
            }
            if(gridVisited[0] == gridVisited[1] && gridVisited[2] == gridVisited[1] && gridVisited[1] != 0)
            {
                Line(-0.5,0.3,0.5,0.3,gridVisited[0]);
            }
            else if(gridVisited[3] == gridVisited[4] && gridVisited[5] == gridVisited[4] && gridVisited[4] != 0)
            {
                Line(-0.5,0,0.5,0,gridVisited[3]);
            }
            else if(gridVisited[6] == gridVisited[7] && gridVisited[8] == gridVisited[7] && gridVisited[7] != 0)
            {
                Line(-0.5,-0.3,0.5,-0.3,gridVisited[6]);
            }
            else if(gridVisited[0] == gridVisited[3] && gridVisited[6] == gridVisited[3] && gridVisited[3] != 0)
            {
                Line(-0.3,0.5,-0.3,-0.5,gridVisited[0]);
            }
            else if(gridVisited[1] == gridVisited[4] && gridVisited[7] == gridVisited[4] && gridVisited[4] != 0)
            {
                Line(0,0.5,0,-0.5,gridVisited[1]);
            }
            else if(gridVisited[2] == gridVisited[5] && gridVisited[8] == gridVisited[5] && gridVisited[5] != 0)
            {
                Line(0.3,0.5,0.3,-0.5,gridVisited[2]);
            }
            else if(gridVisited[0] == gridVisited[4] && gridVisited[8] == gridVisited[4] && gridVisited[4] != 0)
            {
                Line(-0.5,0.5,0.5,-0.5,gridVisited[0]);
            }
            else if(gridVisited[2] == gridVisited[4] && gridVisited[6] == gridVisited[4] && gridVisited[4] != 0)
            {
                Line(0.5,0.5,-0.5,-0.5,gridVisited[2]);
            }
        }
    }
    glFlush();
}

void mouse(int button, int state, int x, int y)
{
    stat = state;
    if(x < 255)
    {
        if(y > 345)
        {
            grid = 7;
        }
        else if(y < 255)
        {
            grid = 1;
        }
        else
        {
            grid = 4;
        }
    }
    else if (x > 345)
    {
        if(y > 345)
        {
            grid = 9;
        }
        else if(y < 255)
        {
            grid = 3;
        }
        else
        {
            grid = 6;
        }
    }
    else
    {
        if(y > 345)
        {
            grid = 8;
        }
        else if(y < 255)
        {
            grid = 2;
        }
        else
        {
            grid = 5;
        }
    }
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitWindowSize(600,600);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("SAA");
    glutDisplayFunc(draw);
    glutIdleFunc(draw);
    glutMouseFunc(mouse);
    glutMainLoop();
}
