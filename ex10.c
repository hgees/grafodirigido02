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
 *    Marina Collier de Albuquerque Melo <marinacollieramelo@gmail.com      *
 *    Webpage: http://www.poli.com                                          *
 *    Phone: 55 81 994923617                                                *
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
    }

    fclose(lcp); /*fechamento de arquivo*/
}
