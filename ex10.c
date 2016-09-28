/* ************************************************************************ *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *    Copyright (C) 2016 by Marina Collier de Albuquerque Melo              *
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
 *    Marina Collier de Albuquerque Melo <marinacollieramelo@gmail.com>     *
 *    Webpage: http://www.poli.com                                          *
 *    Phone: 55 81 99492-3617                                               * 
 *                                                                          *
 *    To contact the author, please write to:                               *
 *    Priscila de Sousa Silva <cila_007@hotmail.com>                        *
 *    Webpage: http://www.poli.com                                          *
 *    Phone: 55 81 99517-7189                                               *
 *                                                                          *
 *    To contact the author, please write to:                               *
 *    Thiago Rodrigo de Oliveira Queiroz <thiago_queiroz94@outlook.com.br>  *
 *    Webpage: http://ww.poli.com                                           *
 *    Phone: 55 81 97902-2171                                               * 
 *                                                                          *
 *    To contact the author, please write to:                               *
 *    Dennis Miller Fidelis da Silva <dmiller.f10@gmail.com>                *
 *    Webpage: http://www.poli.com                                          *
 *    Phone: 55 81 98803-0404                                               * 
 *                                                                          *
 * ************************************************************************ *
 * 
 */

#include <stdio.h>
#include <stdlib.h>

void  main ()
{
    int opt,
        k=0;


    FILE *ldc;/*ponteiro para o arquivo*/
    /*ldc=lista de caminhos*/
    ldc = fopen("listadecaminhos.txt","r"); /*abertura de arquico*/

    if((ldc = fopen("listadecaminhos.txt","r"))==NULL)
    {
        printf("Arquivo não pode ser executado");
        exit(1);
    }

    printf("Bem vindo o teste de caminhos e circuitos");
    /*printf("Para finalizar aperte 'x'");*/

    while(fscanf(listadecaminhos,"%c %c\n",&lista[k][0], &lista[k][1]) !=EOF);
    k++;

    scanf("%d",&opt);

    switch(opt)
    {
        case 1:
            printf("Procura por caminho\n");
            pesquisadecaminhos();/*codigo para procura de caminho*/
            break;
        case 2:
            printf("Procura por circuito\n");
            /*codigo para procurar de circuito*/
            break;
        case 3:
            printf("Ate a proxima!");
            exit(1);
            break;
        default:
            printf("ERRO.\n");
            printf("Voce digitou algo fora das opcoes determinadas\n");
    }

    fclose(lcp); /*fechamento de arquivo*/
}

int pesquisadecaminhos(int *k)
{
    int numero1, numero2, x, y;

    printf("Digite o possivel caminho\n");
    scanf("%d",&numero1);
    scanf("%d",&numero2);

    for(x=0;x<2;x++)
    {
        if(lista[x][0]=numero1)
        {
            for(y=0;y<k;y++)
            {
                if(lista[y][1]=numero2)
                    printf("Existe um caminho de %d para %d",&numero1,&numero2);
            }
        }
    }

}
