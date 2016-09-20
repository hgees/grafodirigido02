/***************************************************************************
 *   Copyright (C) 2005, 2015 by Dr.Beco                                   *
 *   rcb@beco.cc                                                           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *   ********************************************************************* *
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 *                                                                         *
 *   Marina Collier de Albuquerque Melo                                    *
 *   Email: marinacollieramelo@gmail.com                                   *
 *   Webpage: www.upe.com                                                  *
 *   Phone: +55 (81) 99492-3617                                            *
 *                                                                         *
 *   Hericles Gabriel Escoteiro e Silva                                    *
 *   Email: hhericles@hotmail.com                                          *
 *   Webpage: www.upe.com                                                  *
 *   Phone: +55 (81) 98696-1168                                            *
 *                                                                         *
 *   Milena Maria Costa Pininga                                            *
 *   Email: milena.pininga@gmail.com                                       *
 *   Webpage: www.upe.com                                                  *
 *   Phone: +55 (81) 99834-5265                                            *
 *                                                                         *
 *   Ricardo Henrique Simplicio Dimas                                      *
 *   Email: rhenrique.dimas@gmail.com                                      *
 *   Webpage: www.upe.br                                                   *
 *   Phone: +55 (81) 99730-4919                                            *
 *                                                                         *
 *   Priscila de Sousa Silva                                               *
 *   Email: cila_007@hotmail.com                                           *
 *   Webpag: www.upe.br                                                    *
 *   Phone: +55 (81) 99517-7189                                            *
 *                                                                         *
 *   Dennis Miller Fidelis da Silva                                        *
 *   Email: dmiller.f10@gmail.com                                          *
 *   Webpage: www.upe.br                                                   *
 *   Phone: +55 (81) 98803-0404                                            *
 ***************************************************************************/

/* Template para programa basico Allegro
 * que salva uma imagem em arquivo
 *
 * Para compilar use:
 *     $gcc salvalle.c -o salvalle.x -Wall `allegro-config --cflags --libs`
 */


/* Definicoes de algumas cores */

#define CORBRANCO (makecol(255,255,255))
#define CORPRETO 1
#define CORCINZA (makecol(160,160,160))
#define CORAZUL (makecol(0, 0, 255))
#define CORVERDE (makecol(0, 255, 0))
#define CORAMARELO (makecol(255,255,100))
#define CORVERMELHO (makecol(255, 0, 0))
#define CIRCULOMAIOR 100
#define CIRCULOMENOR 40

#define IMAGENAME "teste.bmp" /* nome do arquivo de imagem */

#include <stdio.h>
#include <allegro.h>

int main(void)
{
    BITMAP *buff;
    PALETTE pal;

    if(install_allegro(SYSTEM_NONE, &errno, atexit)!=0)
        exit(EXIT_FAILURE);

    set_color_depth(16);
    get_palette(pal);

    // Create a buffer for smooth animation.
    buff = create_bitmap(320,240);
    if(buff == NULL)
    {
        printf("Could not create buffer!\n");
        exit(EXIT_FAILURE);
    }

    /* Seu codigo aqui */
    circlefill(buff,CIRCULOMAIOR-40,CIRCULOMAIOR, 10, CORAZUL);/*desenhar e pintar circulo da direita*/
    circlefill(buff,CIRCULOMAIOR,CIRCULOMAIOR+40, 10, CORAZUL);/*desenhar e pintar circulo da direita*/
    arc(buff,CIRCULOMAIOR,CIRCULOMAIOR, itofix(-120), itofix(180), 40, CORVERMELHO);
    triangle(buff, 60, 110, 55, 120, 65, 120, CORVERMELHO);
    //rect(buff, 0, 0, 320, 240, CORBRANCO);
    
    save_bitmap(IMAGENAME, buff, pal);
    destroy_bitmap(buff);
    allegro_exit();

    printf("Imagem %s salva com sucesso!\n", IMAGENAME);

    return EXIT_SUCCESS;
}
END_OF_MAIN()

