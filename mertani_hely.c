#include <SDL.h>
#include <SDL2_gfxPrimitives.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Pont {
    int x;
    int y;
} Pont;

double tavolsag(Pont pont1, Pont pont2) {
    double x_kul = fabs(pont1.x - pont2.x);
    double y_kul = fabs(pont1.y - pont2.y);
    return sqrt(x_kul * x_kul + y_kul * y_kul);
}

bool kb_ugyanannyi(double tavolsag, double pontos, double eps) {
    return fabs(tavolsag - pontos) <= eps;
}

int main(int argc, char *argv[]) {
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        SDL_Log("Nem indithato az SDL: %s", SDL_GetError());
        exit(1);
    }

    char* cim = "Szorgalmi feladat";
    int szelesseg = 640, magassag = 480;
    double eps = 1;

    SDL_Window *m_window = SDL_CreateWindow(cim,
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            szelesseg,
                                            magassag,
                                            0);

    if(m_window == NULL) {
        SDL_Log("Nem hozhato letre az ablak: %s", SDL_GetError());
        exit(1);
    }

    SDL_Renderer *m_renderer = SDL_CreateRenderer(m_window,
                                                  -1,
                                                  SDL_RENDERER_SOFTWARE);
    SDL_RenderClear(m_renderer);
    //Piros
    Pont piros_pont;
    piros_pont.x = 320;
    piros_pont.y = 240;

    //Zöld
    Pont zold_pont_1, zold_pont_2;
    zold_pont_1.x = 240;
    zold_pont_1.y = 200;
    zold_pont_2.x = 400;
    zold_pont_2.y = 280;

    //Kék
    Pont kek_pont_1, kek_pont_2;
    kek_pont_1.x = 240;
    kek_pont_1.y = 240;
    kek_pont_2.x = 400;
    kek_pont_2.y = 240;

    //Fehér
    Pont feher_pont;
    feher_pont.x = 320;
    feher_pont.y = 240;

    for(int i = 0; i < szelesseg; ++i) {
        for(int j = 0; j < magassag; ++j) {
            Pont aktualis;
            aktualis.x = i;
            aktualis.y = j;

            double tavolsag_pirostol = tavolsag(piros_pont, aktualis);
            double tavolsag_osszeg_zoldektol = tavolsag(zold_pont_1, aktualis) + tavolsag(zold_pont_2, aktualis);
            double tavolsag_kulonbseg_kekektol = fabs(tavolsag(kek_pont_1, aktualis) - tavolsag(kek_pont_2, aktualis));
            double tavolsag_egyenestol = fabs(400 - i);
            double tavolsag_feher_ponttol = tavolsag(feher_pont, aktualis);

            if(kb_ugyanannyi(tavolsag_pirostol, 200, eps))
                pixelRGBA(m_renderer, aktualis.x, aktualis.y, 255, 0, 0, 255);

            if(kb_ugyanannyi(tavolsag_osszeg_zoldektol, 250, eps))
                pixelRGBA(m_renderer, aktualis.x, aktualis.y, 0, 255, 0, 255);

            if(kb_ugyanannyi(tavolsag_kulonbseg_kekektol, 100, eps))
                pixelRGBA(m_renderer, aktualis.x, aktualis.y, 0, 0, 255, 255);

            if(kb_ugyanannyi(tavolsag_egyenestol, tavolsag_feher_ponttol, eps))
                pixelRGBA(m_renderer, aktualis.x, aktualis.y, 255, 255, 255, 255);
        }
    }

    int jobbrol = 510;
    stringRGBA(m_renderer, jobbrol, 25, "Piros: Kor", 255, 0, 0, 255);
    stringRGBA(m_renderer, jobbrol, 45, "Zold: Ellipszis", 0, 255, 0, 255);
    stringRGBA(m_renderer, jobbrol, 65, "Kek: Hiperbola", 0, 0, 255, 255);
    stringRGBA(m_renderer, jobbrol, 85, "Feher: Parabola", 255, 255, 255, 255);

    SDL_RenderPresent(m_renderer);

    SDL_Event ev;
    while (SDL_WaitEvent(&ev) && ev.type != SDL_QUIT);

    SDL_Quit();

    return 0;
}
