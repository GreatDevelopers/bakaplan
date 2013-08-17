/**
 *
 *       \file       seatplan.cc
 *
 *       \brief      Function definition of SeatPlan Class
 *
 *       \version    0.7
 *       \date       Tuesday 02 April 2013 02:44:21  IST\n
 *       Compiler    g++
 *
 *       \author     Mandeep Kaur, meghasimak@gmail.com
 *       License     GNU General Public License
 *       \copyright  Copyright (c) 2013, GreatDevelopers
 *                   https://github.com/GreatDevelopers
 */

/**
 *  include seatplan.h file 
 */
#include "header/seatplan.h"

/**
 *      \class  SeatPlan
 *      \fn     SeatPlan :: SeatPlan()
 *      \brief  Constructor
 */

SeatPlan :: SeatPlan()
{
    // constructor
}

void SeatPlan :: SetRollNo(int strategy, int i)
{ 
    int stra, sss;
    /*if(strategy == 5)
        stra = 1;
    else
        stra = strategy;*/
    
    if(strategy == 6)
        sss = 4;
     else 
        sss = strategy;

    switch(sss)
    {
        case 5:
            stra = 1;
            break;
        case 6:
            stra = 4;
            break;
        default:
            stra = strategy;
            break;
    }

    s = 0;
    
    for(j = 0; j < strategy; j++)
    {
        seatSize[j] = 0;
    }
   
    seatRollNo.resize(strategy);
    for(j = 0; j < totalExams[i]; j++)
    {
        if(s == stra)
            s = 0;
        
        start = seatSize[s];
        index = indexValue[j];
        end = dateSheetRNoSize[i][index];
        seatRollNo[s].resize(start + end);
        for(k = 0; k < end; k++)
        {
            seatRollNo[s][start + k] = dateSheetRNo[i][index][k];
        }
        
        seatSize[s] = start + end;
        s++;
    }
}

void SeatPlan :: SeatingPlan(int strategy, int i)
{  
    int stra;
  
    seatSize.resize(strategy);

    SetRollNo(strategy, i);
    
/*    if(strategy == 5)
        stra = 1;
    else
        stra = strategy;*/
    switch(strategy)
    {
        case 5:
            stra = 1;
            break;
        case 6:
            stra = 4;
            break;
        default:
            stra = strategy;
            break;
    }
   
    size.resize(stra);

    for(j = 0; j < stra; j++)
    {
        size[j] = 0;
    }

    seat.resize(totalCentres[i]);
    for(centre = 0; centre < totalCentres[i]; centre++)
    {
        seat[centre].resize(totalRooms[i][centre]);
        for(room = 0; room < totalRooms[i][centre]; room++)
        {
            seat[centre][room].resize(rows[i][centre][room]);
            for(row = 0; row < rows[i][centre][room]; row++)
            {
                seat[centre][room][row].resize(cols[i][centre][room]);
            }
        }
    }

    for(centre = 0; centre < totalCentres[i]; centre++)
    {
        for(room = 0; room < totalRooms[i][centre]; room++)
        {
            for(row = 0; row < cols[i][centre][room]; row++)
            {
                if((row % 2) != 0)
                {
                    if(strategy == 2 || strategy == 6)
                        s = 1;
                    else if(strategy > 2 && strategy < 5)
                        s = 2;
                    else if(strategy == 5)
                        s = 0;
                }
                else
                    s = 0;
                  
                if(strategy == 5)
                {
                    if((row % 2) != 0)
                    {
                        for(col = rows[i][centre][room]-1; 
                            col >= 0; col--)
                        {
                            if(s == stra)
                                s = 0;
                            seat[centre][room][col][row] = RollNo(s);
                            s++;
                        }
                    }
                    else
                    {
                        for(col = 0; col < rows[i][centre][room]; 
                            col++)
                        {
                            if(s == stra)
                                s = 0;
                            seat[centre][room][col][row] = RollNo(s);
                            s++;
                        }
                    }
                }
                else
                {
                    for(col = 0; col < rows[i][centre][room]; col++)
                    {
                        int ss = strategy;
                        if(strategy == 6)
                            ss = 4;
                        if(s == ss)
                            s = 0;
                        else if(s > ss)
                            s = 1;
                        seat[centre][room][col][row] = RollNo(s);
                        
                        if(strategy == 6)
                        {
                            s = s + 2;
                        }
                        else
                            s++;
                    }
                }
                
            }
        }
    }

    //WriteSeatPlan(projectID, i);
}
 
string SeatPlan :: RollNo(int s)
{
    string rno;
     
    if(seatSize[s] == size[s])
        rno = "-";
    else
    {
        rno = seatRollNo[s][size[s]];
        size[s]++;
    }
    return rno;
    
}

void SeatPlan :: AddRollNoInfo(string projectID, int i)
{

}

void SeatPlan :: WriteSeatPlan(string projectID, int i)
{ 
    stringstream ss;

    ss << (i + 1);

    projectID += "-" + ss.str();
    
    temp = FileName(SEATPLAN, projectID, 0);
    
    outFile.open(temp.c_str());
    
    outFile << totalCentres[i] << endl;
    
    for(centre = 0; centre < totalCentres[i]; centre++)
    {
        outFile << centreName[i][centre] << endl
                << totalRooms[i][centre] << endl;
        
        for(room = 0; room < totalRooms[i][centre]; room++)
        {
            outFile << roomNo[i][centre][room] << endl
                    << rows[i][centre][room] << " "
                    << cols[i][centre][room] << endl;

            for(row = 0; row < rows[i][centre][room]; row++)
            {
                for(col = 0; col < cols[i][centre][room]; col++)
                {
                    outFile << seat[centre][room][row][col] << "\t";
                }
                outFile << "\n";
            }
        }
    }
    outFile.close();
    WriteHTMLFile(projectID, i);
    WritePDFFile(projectID, i);
}

/**
 *      \class  SeatPlan
 *      \fn     SeatPlan :: WriteHTMLFile(string projectID, int i)
 *      \brief  Creating HTML file
 *      \param  projectID   Project Id of seating plan project
 *      \param  i           For creating file accord to datesheet
 */

void SeatPlan :: WriteHTMLFile(string projectID, int i)
{

    temp = "../../SeatPlan/seatplan-" + projectID + ".html";
    
    outFile.open(temp.c_str());
    outFile << "<html><head><title>BaKaPlan</title>"
            << "<style> @media print { div {page-break-before:always} } "
            << "td {font-size:130%; font-weight:bold;}"
            << "h1 {font-size:300%; font-family: }"
            << "body{font-family:\"Open Sans\"; text-align:center;"
            << "margin:10 auto}"
            << "</style> "
            << "<link href='http://fonts.googleapis.com/css?family="
            << "Open+Sans' rel='stylesheet' type='text/css'>"
            
            << "</head>"
            << "<body align = \"center\" > "
            
            << endl;
     
    for(centre = 0; centre < totalCentres[i]; centre++)
    {
        
        for(room = 0; room < totalRooms[i][centre]; room++)
        {
            outFile << "<h1 style = \" line-height:20%; font-family:arial;"
                    << " font-size: 170%;\"> " << examName[i] <<"</h1>"
                    << "<h2 style=\"font-size: 120%;\"> " << examDate[i]
                    << " | at " << examTime[i] << " |&nbsp Venue : " 
                    << examVenue[i]
                    << "</h2>";
                    
            outFile << "<h2 style=\"line-height:20%;\" >Centre : " 
                    << centreName[i][centre] 
                    << "&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp&nbsp"
                    << " Room : " << roomNo[i][centre][room] << "</h2>";
            outFile << "<table align = \"center\" cellpadding = \"2\""
                    << " cellspacing = \"1\" border = \"1\" width = \"800px\">";
                    
             outFile << "<tr>";
             
             j = 65 + cols[i][centre][room];
                for(k = 64; k < j; k++)
                {
                    char a;
                    if (k == 64)
                        a = ' ';
                    else
                        a = k;
                    outFile << "<th width = \"80\" height = \"30\""
                            << " align = \"center\" valign = \"center\">" 
                            << a << "</th>";
                }
                outFile << "</tr>";
                    
            for(row = 0; row < rows[i][centre][room]; row++)
            {
            outFile << "<tr><td width = \"80\" height = \"30\" "
                        << "align = \"center\" valign = \"center\">"
                        << row + 1
                        << "</td>";
                for(col = 0; col < cols[i][centre][room]; col++)
                {
                    outFile << "<td width = \"80\" height = \"30\" "
                            << "align = \"center\" valign = \"center\">" 
                            << seat[centre][room][row][col]
                            << "</td>";
                }
                outFile << "</tr>";
            }
            outFile << "</table>";
            outFile << "<br> Seating Plan generated by "
                << "BaKaPlan(http://freecode.com/projects/bakaplan)";
            outFile << "<div>  </div>";

        }
    }
    outFile << "</body></html>";
    
    outFile.close();
}


//PDF addition

jmp_buf env;

#ifdef HPDF_DLL
void  __stdcall
#else
void
#endif
error_handler (HPDF_STATUS   error_no,
               HPDF_STATUS   detail_no,
               void         *user_data)
{
    printf ("ERROR: error_no=%04X, detail_no=%u\n", (HPDF_UINT)error_no,
                (HPDF_UINT)detail_no);
    longjmp(env, 1);
}

/**
 *      \class  Seatplan
 *      \fn     Seatplan :: WritePDFFile(string projectID, int i)
 *      \brief  Creating PDF Files 
 *      \param  projectID  Project ID of seating plan project
 *      \param  i          For creating file according to datesheet
 */

void SeatPlan :: WritePDFFile(string projectID, int i)
{
  
    HPDF_Doc  pdf;
    HPDF_Font font;
    HPDF_Page page[10][50];
    char text[100];
    
    temp = "../../SeatPlan/seatplan-" + projectID + ".pdf";

    
    pdf = HPDF_New (error_handler, NULL);
    if  (!pdf) {
        printf ("error: cannot create PdfDoc object\n");
        //return 1;
    }

    if  (setjmp(env)) {
        HPDF_Free (pdf);
        //return 1;
    }

    
    HPDF_SetCompressionMode (pdf, HPDF_COMP_ALL);

    /* create default-font */
    font = HPDF_GetFont (pdf, "Helvetica", NULL);
    
    HPDF_Page_SetFontAndSize(page[centre][room], font, 15);
    //int tw;
    //strcpy(text,seat[0][0][0][0].c_str());
    //textWidth1 = HPDF_Page_TextWidth (page[centre][room],
                         //          seat[0][0][0][1].c_str());
    
   /* for(row = 0; row < rows[i][centre][room]; row++)
    {   
         for(room = 0; room < totalRooms[i][centre]; room++)
         {
             for(row = 0; row < rows[i][centre][room]; row++)
             {
                 for(col = 1; col < cols[i][centre][room]; col++)
                 {     
                     tw=HPDF_Page_TextWidth (page[centre][room],
                                   seat[centre][room][row][col].c_str());
                     if( textWidth1 < tw )
                       textWidth1 =  tw;
                  }
              }
          }
      }*/

    for(centre = 0; centre < totalCentres[i]; centre++)
     {   
         for(room = 0; room < totalRooms[i][centre]; room++)
         {
             y=430,
	         width=70;
	         height=25;

             rectWidth = cols[i][centre][room]*width; 
     
             page[centre][room] = HPDF_AddPage (pdf);                        
             HPDF_Page_SetSize (page[centre][room], HPDF_PAGE_SIZE_A4,
                                                 HPDF_PAGE_LANDSCAPE);
             HPDF_SetPageMode(pdf, HPDF_PAGE_MODE_USE_OUTLINE);
             
             HPDF_Page_BeginText (page[centre][room]);
             HPDF_Page_MoveTextPos (page[centre][room], 5,
                        HPDF_Page_GetHeight(page[centre][room]) - 25);

             HPDF_Page_SetFontAndSize(page[centre][room], font, 25);
              
             textWidth = HPDF_Page_TextWidth (page[centre][room],
                                             examName[i].c_str());
             
             HPDF_Page_TextOut (page[centre][room], (HPDF_Page_GetWidth
                                 (page[centre][room]) - textWidth) / 2,
             HPDF_Page_GetHeight (page[centre][room]) - 25, 
                                    examName[i].c_str());
            
             HPDF_Page_SetFontAndSize(page[centre][room], font, 16);
            
             HPDF_Page_EndText (page[centre][room]);
             HPDF_Page_BeginText (page[centre][room]);
             
             strcpy(text,examDate[i].c_str());
             strcat(text," | at  ");
             strcat(text,examTime[i].c_str());
             strcat(text," |  Venue : ");
             strcat(text,examVenue[i].c_str());
             
             textWidth = HPDF_Page_TextWidth (page[centre][room], text);
            
             HPDF_Page_TextOut (page[centre][room], (HPDF_Page_GetWidth
                                (page[centre][room]) - textWidth) / 2,
             HPDF_Page_GetHeight (page[centre][room]) - 50 , text);
   
             
             strcpy(text,"Centre : ");
             strcat(text,centreName[i][centre].c_str());
             strcat(text,"                     Room : ");
             strcat(text,roomNo[i][centre][room].c_str());
             
             textWidth = HPDF_Page_TextWidth (page[centre][room], text);
            
             HPDF_Page_TextOut (page[centre][room], (HPDF_Page_GetWidth
                                (page[centre][room]) - textWidth) / 2,
             HPDF_Page_GetHeight (page[centre][room]) - 75 , text);
                

             for(row = 0; row < rows[i][centre][room]; row++)
             {
                 x = (HPDF_Page_GetWidth(page[centre][room]) - rectWidth) / 2;
                 for(col = 0; col < cols[i][centre][room]; col++)
                 {     
                     HPDF_Page_EndText (page[centre][room]);
                     HPDF_Page_Rectangle (page[centre][room], x , y, 
                                          width,height);	
	                 HPDF_Page_Stroke (page[centre][room]);
		              
                     HPDF_Page_BeginText (page[centre][room]);
                      
                     if(strlen(seat[centre][room][row][col].c_str())<=7)
                     HPDF_Page_SetFontAndSize(page[centre][room],font,15);        
                     else
                     if(strlen(seat[centre][room][row][col].c_str())<=9)
                     HPDF_Page_SetFontAndSize(page[centre][room],font,13);        
                     else 
                     if(strlen(seat[centre][room][row][col].c_str())<=11)
                     HPDF_Page_SetFontAndSize(page[centre][room],font,11);        
                     else
                     if(strlen(seat[centre][room][row][col].c_str())<=13)
                     HPDF_Page_SetFontAndSize(page[centre][room],font,10);        
                     else
                     if(strlen(seat[centre][room][row][col].c_str())<=15)
                     HPDF_Page_SetFontAndSize(page[centre][room],font,9);        
                     else
                     HPDF_Page_SetFontAndSize(page[centre][room],font,8);        
            
                     HPDF_Page_TextRect (page[centre][room], x , y+height
                     , x+width, y,seat[centre][room][row][col].c_str(),
                     HPDF_TALIGN_CENTER, NULL);
                   
                     x=x+width;
                 }
                
                 y=y-height; 
               
             }
                 HPDF_Page_SetFontAndSize(page[centre][room],font,15);
                 strcpy(text,"Seating Plan generated by BaKaPlan(http:");
                 strcat(text,"//freecode.com/projects/bakaplan)");
                 textWidth = HPDF_Page_TextWidth (page[centre][room], text);
                 HPDF_Page_TextOut (page[centre][room], 
                 (HPDF_Page_GetWidth(page[centre][room]) - textWidth) / 2,
                 y-30 , text);

         }
     }   

     HPDF_SaveToFile (pdf, temp.c_str());
     HPDF_Free (pdf);

}


/**
 *      \class  SeatPlan
 *      \fn     SeatPlan :: ~SeatPlan()
 *      \brief  DEstructor
 */

SeatPlan :: ~SeatPlan()
{
    // destructor
}
