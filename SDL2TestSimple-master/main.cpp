
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<SDL2/SDL_ttf.h>
#include<iostream>
#include<vector>

using namespace std;

SDL_Window* window;
SDL_Renderer* renderer;
SDL_Event Event;
SDL_Texture *background,*character;
SDL_Rect rect_background,rect_character;


std::string toString(int number)
{
    if (number == 0)
        return "0";
    if(number < 0)
        return "-"+toString(-number);
    std::string temp="";
    std::string returnvalue="";
    while (number>0)
    {
        temp+=number%10+48;
        number/=10;
    }
    for (int i=0; i<(int)temp.length(); i++)
        returnvalue+=temp[temp.length()-i-1];
    return returnvalue;
}

//void menu()
//{
//    while()
//    {
//        if(enter)
//            juego()
//    }
//}
//
//void juego()
//{
//    while()
//    {
//        if(escape)
//            return;
//    }
//}

int main( int argc, char* args[] )
{
    for(int i=0; i<10; i++)
    {
        cout<<rand()%2<<endl;
    }
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window
    if((window = SDL_CreateWindow("Image Loading", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    if( TTF_Init() == -1 )
    {
        return 40;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = w;
    rect_background.h = h;

    character = IMG_LoadTexture(renderer, "personaje.png");
    SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = w;
    rect_character.h = h;

    SDL_Texture* rojo = IMG_LoadTexture(renderer,"rojo.png");
    SDL_QueryTexture(rojo, NULL, NULL, &w, &h);
    SDL_Rect rectangulo_rojo;
    rectangulo_rojo.x = 10;
    rectangulo_rojo.y = 20;
    rectangulo_rojo.w = w;
    rectangulo_rojo.h = h;

    SDL_Texture* azul = IMG_LoadTexture(renderer,"azul.png");
    SDL_QueryTexture(azul, NULL, NULL, &w, &h);
    SDL_Rect rectangulo_azul;
    rectangulo_azul.x = 20;
    rectangulo_azul.y = 20;
    rectangulo_azul.w = w;
    rectangulo_azul.h = h;

    SDL_Texture* menu = IMG_LoadTexture(renderer,"menu.png");
    SDL_QueryTexture(menu, NULL, NULL, &w, &h);
    SDL_Rect rectangulo_menu;
    rectangulo_menu.x = 0;
    rectangulo_menu.y = 0;
    rectangulo_menu.w = w;
    rectangulo_menu.h = h;

    bool menu_flag=true;

    vector<SDL_Texture*>texturas;
    texturas.push_back(IMG_LoadTexture(renderer,"pelota/1.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"pelota/2.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"pelota/3.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"pelota/4.png"));
    texturas.push_back(IMG_LoadTexture(renderer,"pelota/5.png"));
    SDL_Rect rect_pelotas;
    SDL_QueryTexture(texturas[0], NULL, NULL, &w, &h);
    rect_pelotas.x = 20;
    rect_pelotas.y = 20;
    rect_pelotas.w = w;
    rect_pelotas.h = h;

    //Main Loop
    int num = 0;
    int imagen_actual=0;
    int imagen_actual_aux=0;

    SDL_Color textColor = { 255, 0, 0 };
    TTF_Font *gFont = TTF_OpenFont( "lazy.ttf", 300 );
    SDL_Surface* temp = TTF_RenderText_Solid( gFont, toString(576).c_str(), textColor );
    SDL_Texture* texto = SDL_CreateTextureFromSurface( renderer, temp );

    while(true)
    {
        while(SDL_PollEvent(&Event))
        {
            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_character.x++;

                if(Event.key.keysym.sym == SDLK_r)
                {
                    num=rand()%2;
                }

                if(Event.key.keysym.sym == SDLK_RETURN)
                {
                    menu_flag=!menu_flag;
                }
            }
        }

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);

//        if(num==0)
//            SDL_RenderCopy(renderer,rojo,NULL,&rectangulo_rojo);
//
//        if(num==1)
//            SDL_RenderCopy(renderer,azul,NULL,&rectangulo_azul);


        rect_pelotas.x+=1;
        if(rect_pelotas.x>=200)
            rect_pelotas.x=0;
        SDL_RenderCopy(renderer,texturas[imagen_actual],NULL,&rect_pelotas);
        imagen_actual_aux++;
        if(imagen_actual_aux==60)
        {
            imagen_actual++;
            if(imagen_actual==5)
                imagen_actual=0;
            imagen_actual_aux=0;
        }

        if(menu_flag)
        {
            SDL_RenderCopy(renderer, menu, NULL, &rectangulo_menu);
        }

        temp = TTF_RenderText_Solid( gFont, toString(imagen_actual).c_str(), textColor );
        texto = SDL_CreateTextureFromSurface( renderer, temp );

        SDL_RenderCopy(renderer, texto, NULL, &rectangulo_menu);

        SDL_RenderPresent(renderer);

        delete temp;
        SDL_DestroyTexture( texto );

        SDL_Delay(17);
    }

    return 0;
}











