#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double PI = 3.14159265358979;

double getX(double ido, double max) {
    double alfa = ido / max * 2 * PI;
    return cos(alfa - PI / 2);
}

double getY(double ido, double max) {
    double alfa = ido / max * 2 * PI;
    return sin(alfa - PI / 2);
}

void openSVG(double width, double height, FILE* f) {
    char buffer[200];
    sprintf(buffer, "<svg width=\"%lf\" height=\"%lf\" xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">\n", width, height);
    fputs(buffer, f);
}

void line(double x1, double y1, double x2, double y2, double stroke_width, FILE* f) {
    char buffer[200];
    sprintf(buffer, "<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" stroke-width=\"%lf\" />", x1, y1, x2, y2, stroke_width);
    fputs(buffer, f);
}

void closeSVG(FILE* f) {
    fputs("</svg>", f);
}

int main()
{
    double ora, perc, masodperc;
    scanf("%lf %lf %lf", &ora, &perc, &masodperc);

    double width = 200;
    double height = 200;

    double oraX = getX(ora + perc / 60 + masodperc / 3600, 12) * 0.5;
    double oraY = getY(ora + perc / 60 + masodperc / 3600, 12) * 0.5;

    double percX = getX(perc + masodperc / 60, 60) * 0.7;
    double percY = getY(perc + masodperc / 60, 60) * 0.7;

    double masodpercX = getX(masodperc, 60) * 0.7;
    double masodpercY = getY(masodperc, 60) * 0.7;

    FILE* f = fopen("./ora.svg", "w");

    openSVG(width, height, f);

    line(width / 2, height / 2, width / 2 * (1 + masodpercX), height / 2 * (1 + masodpercY), 0.5, f);
    line(width / 2, height / 2, width / 2 * (1 - masodpercX / 3), height / 2 * (1 - masodpercY / 3), 0.5, f);

    line(width / 2, height / 2, width / 2 * (1 + percX), height / 2 * (1 + percY), 2, f);
    line(width / 2, height / 2, width / 2 * (1 - percX / 4), height / 2 * (1 - percY / 4), 2, f);

    line(width / 2, height / 2, width / 2 * (1 + oraX), height / 2 * (1 + oraY), 4, f);
    line(width / 2, height / 2, width / 2 * (1 - oraX / 4), height / 2 * (1 - oraY / 4), 4, f);

    for(int i = 0; i <= 11; i++) {
        double currX = getX(i, 12);
        double currY = getY(i, 12);
        line(width / 2 * (1 + currX * 0.85),
             height / 2 * (1 + currY * 0.85),
             width / 2 * (1 + currX),
             height / 2 * (1 + currY),
             3, f);
    }
    for(int i = 0; i <= 59; i++) {
        if(i % 5 == 0) continue;
        double currX = getX(i, 60);
        double currY = getY(i, 60);
        line(width / 2 * (1 + currX * 0.9),
             height / 2 * (1 + currY * 0.9),
             width / 2 * (1 + currX * 0.95),
             height / 2 * (1 + currY * 0.95),
             1, f);
    }

    closeSVG(f);

    fclose(f);
    return 0;
}
