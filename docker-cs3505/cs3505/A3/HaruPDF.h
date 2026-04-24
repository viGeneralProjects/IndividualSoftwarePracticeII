/*
Name: Vi Cao
Course: CS3505
Assignment: Facades and Makefiles
*/

#include "hpdf.h"

class HaruPDF{
    private:
        HPDF_Doc  pdf;
        HPDF_Page page;
        HPDF_Font font;
        char fileName[256];

    public:
        /// @brief Create the PDF, page, initialize text/font, and output filename
        /// @param progname base name for the pdf file
        void CreatePDF (char progname[256]);
        /// @brief places a single character on the page at the given coordinate
        /// @param ch character to draw
        /// @param x x-position on the page
        /// @param y y-position on the page
        void charOntoPage (char ch, float x, float y);
        /// @brief End the text block for the page and saves the file
        void end_page ();
};