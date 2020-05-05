#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

#define PI 3.141592
GLfloat raio = 1;
GLfloat xcentro = 5;
GLfloat ycentro = 0;

void Desenha(void){
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
        glColor3f(0,0,0);
        //eixos x e y
        for(float x=-20;x<20;x+=0.01){
            glVertex3f(x, 0, 0);
        }
        for(float y=-20;y<20;y+=0.01){
            glVertex3f(0, y, 0);
        }
        //circulo
        glColor3f(0,0,1);
        for(float t=0;t<2*PI;t+=0.01){
            glVertex3f((raio*cos(t)+xcentro),(raio*sin(t)+ycentro),0);
        }
    glEnd();
    glFlush();
}

void Keyboard(unsigned char key, int x, int y){
    if(key == 27)
        exit(0);
}

void Inicializa(void){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20,20,-20,20);
    glMatrixMode(GL_MODELVIEW);
}

void Rotacao(int valor){
    float r = valor*0.01;
    xcentro = 5*sin(r);
    ycentro = 5*cos(r);
    valor++;
    glutPostRedisplay();
    glutTimerFunc(10,Rotacao,valor);
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Trabalho P1");
    glutDisplayFunc(Desenha);
    glutTimerFunc(10,Rotacao,0.0);
    glutKeyboardFunc(Keyboard);
    Inicializa();
    glutMainLoop();

    return 0;
}