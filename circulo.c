#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

#define PI      3.141592

void Desenha(void){
    glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT);
    
    glBegin(GL_POINTS);
        float t = 0;

        // EIXO X
        glColor3f(0,0,0);
        for(float x=-20;x<20;x+=0.05){
            glVertex3f(x, 0, 0);
        }

        // EIXO Y
        for(float y=-20;y<20;y+=0.05){
            glVertex3f(0, y, 0);
        }

        
        // CIRCUNFERENCIA
        glColor3f(1,0,0);
        for(t;t<2*PI;t+=0.0001){
            glVertex3f(cos(t)+5,sin(t),0);
        }

    glEnd();

    glFlush();
}

void Teclado(unsigned char key, int x, int y){
    if(key == 27)
        exit(0);
}

void Inicializa(void){
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-20.0,20.0,-20.0,20.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[]){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500,500);
    glutCreateWindow("Trabalho P1");

    glutDisplayFunc(Desenha);
    glutKeyboardFunc(Teclado);
    Inicializa();
    glutMainLoop();

    return 0;
}
