/*
Name: Vi Cao
Course: CS3505
Assignment: Facades and Makefiles
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "HaruPDF.h"
#include "hpdf.h"

void HaruPDF::CreatePDF (char progname[256]){
        strcpy (fileName, progname);
        strcat (fileName, ".pdf");
           pdf = HPDF_New (NULL, NULL);
    page = HPDF_AddPage (pdf);
    HPDF_Page_SetSize (page, HPDF_PAGE_SIZE_A5, HPDF_PAGE_PORTRAIT);
    HPDF_Page_BeginText (page);
    font = HPDF_GetFont (pdf, "Courier-Bold", NULL);
    HPDF_Page_SetTextLeading (page, 20);
    HPDF_Page_SetGrayStroke (page, 0);
    HPDF_Page_SetFontAndSize (page, font, 22);
    }

    void HaruPDF::charOntoPage (char ch, float x, float y){
        char buf[2];
        HPDF_Page_SetTextMatrix (page,
                                1, 0, 0, 1,
                                x, y);
        buf[0] = ch;
        buf[1] = 0;
        HPDF_Page_ShowText (page, buf);
    }

    // End the text block for the page
    void HaruPDF::end_page (){
        HPDF_Page_EndText (page);
        HPDF_SaveToFile (pdf, fileName);
        HPDF_Free (pdf);
    }