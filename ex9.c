/* ************************************************************************ *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *    Copyright (C) 2015 by Fernando Angelim Aragao                         *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *    To contact the author, please write to:                               *
 *    Fernando Angelim Aragao <bituco99@gmail.com>                          *
 *    Webpage: http://www.upe.br                                            *
 *    Phone: +55 (81) 99710-7784                                            *
 *                                                                          *
 *    Milena Maria Costa Pininga <milena.pininga@gmail.com                  *
 *    Webpage: http://www.upe.br                                            *
 *    Phone: +55 (81) 99834-5265                                            *
 *                                                                          *
 *    Ricardo Henrique Simplicio Dimas <rhenrique.dimas@gmail.com           *
 *    Webpage: http://www.upe.br                                            *
 *    Phone: +55 (81) 99730-4919                                            *
 *                                                                          *
 * ************************************************************************ *
 * 
 */

/*Para executar utilizar  $./ex9.x entrada.txt*/

#define CORBRANCO (makecol(255,255,255))
#define CORPRETO 1
#define CORCINZA (makecol(160,160,160))
#define CORAZUL (makecol(0, 0, 255))
#define CORVERDE (makecol(0, 255, 0))
#define CORAMARELO (makecol(255,255,100))
#define CORVERMELHO (makecol(255, 0, 0))
#define CIRCULO 10

#define IMAGENAME "ex9.bmp" /* nome do arquivo de imagem */

#include <stdio.h>
#include <allegro.h>

int main(int argc, char *argv[])
{
    BITMAP *buff;
    PALETTE pal;

    if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
        exit(EXIT_FAILURE);

    set_color_depth(16);
    get_palette(pal);

    // Create a buffer for smooth animation.
    buff = create_bitmap(640,480);
    if(buff == NULL)
    {
        printf("Could not create buffer!\n");
        exit(EXIT_FAILURE);
    }

    /* Seu codigo aqui */
    int i = 0, j = 0;
    char letra, circulos[2][10];
    FILE *file;

    file = fopen(argv[1], "r");
    if(argc != 2) 
    {
        printf("ERRO. Falha ao abrir o arquivo\n");
        return 0;
    } 
    else 
    {
        while((letra = fgetc(file)) != EOF)
            if(letra != '\n' && letra != ' ')
            {
                circulos[i][j] = letra;
                if(j == 0)
                    j = 1;
                else
                {
                    i++;
                    j = 0;
                }
            }
    }

    // printf("Existem %d linhas no arquivo\n", num); // descomente para testar o numero de linhas
    fclose(file);
    
    for(i = 0; i < 10; i++)
        for(j = 0; j < 2; j++)
            circle(buff, 60*(circulos[i][j] - 'a' + 1), 240, CIRCULO, CORVERMELHO);

    for(i = 0; i < 10; i++)
        for(j = 1; j < 10; j++)
            arc(buff, (60*(circulos[i][j] - 'a')) + 30, 255, itofix(32), itofix(96), 40, CORAZUL);
          
    for(i = 0; i < 10; i++)
        for(j = 1; j < 10; j++)
            triangle(buff, 60*(circulos[i][j] - 'a'), 230, (60*(circulos[i][j] - 'a') + 4) , 225, (60*(circulos[i][j] - 'a') - 4) , 225, CORVERDE);
       
    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();

    for(i = 0; i < 10; i++)
        printf("%s\n", circulos[i]);
    printf("Imagem %s salva com sucesso!\n", IMAGENAME);

    return EXIT_SUCCESS;
}
