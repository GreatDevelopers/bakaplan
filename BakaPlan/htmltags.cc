#include "htmltags.h"

HTMLTags :: HTMLTags()
{
    // branch field names
    branch_name     =    "BranchName";
    total_subjects  =    "TotalSubjects";
    subject_code    =    "SubjectCode";
    subject_name    =    "SubjectName";
    total_branches  =    "TotalBranches";
    
    // table header branch field names
    h_branch_name     =    "Branch Name";
    h_total_subjects  =    "Total Subjects";
    h_subject_code    =    "Subject Code";
    h_subject_name    =    "Subject Name";
    h_total_branches  =    "Total Branches";
    
    // rollno field names
    prefix          =    "Prefix";
    start_rollno    =    "StartRollNo";
    end_rollno      =    "EndRollNo";
    not_included    =    "NotIncluded";
    
    // room field names
    total_centres   =    "TotalCentres";
    centre_no       =    "CentreNo";
    total_rooms     =    "TotalRooms";
    room_no         =    "RoomNo";
    rows            =    "Rows";
    cols            =    "Cols";
    
    // Strategy option
    strategy        =    "Strategy";
    
    // Exam Details
    exam_name       =    "ExamName";
    exam_time       =    "ExamTime";
    exam_date       =    "ExamDate";
    exam_venue      =    "ExamVenue";
       
}

void HTMLTags :: ContentType()
{
    cout << "Content-type:text/html\n\n";
}

void HTMLTags :: HTMLStart()
{
    cout << "<html>" << endl;
}

void HTMLTags :: HTMLEnd()
{
    cout << "</html>" << endl;
}

void HTMLTags :: HeadStart()
{
    cout << "<head>" << endl;
    
    cout << "<link href='http://fonts.googleapis.com/css?family=Quicksand|Julius+Sans+One' rel='stylesheet' type='text/css'>";
    
    cout << "<script src=\"https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js\"></script>"
         << "<!-- jQuery for navigation -->	"
         << "<script> "
         << "$(function() {				var pull 	= $('#pull');				var menu 		= $('nav ul');				var menuHeight	= menu.height();			$(pull).on('click', function(e) {				e.preventDefault();			menu.slideToggle();			});			$(window).resize(function(){        		var w = $(window).width();        		if(w > 600 && menu.is(':hidden')) {        			menu.removeAttr('style');        	}    		});		}); </script>";
    
}

void HTMLTags :: HeadEnd()
{
    cout << "</head>" << endl;
}

void HTMLTags :: BodyStart()
{
    cout << "<body>" << endl;
    cout << ""
         << "<header>"
         << "<nav class=\"clearfix fullwidth\">"
	     << "<ul class=\"clearfix\">"
		 << " <li><a href=\"#\">About</a></li>"
		 << "<li><a href=\"https://github.com/GreatDevelopers/bakaplan#readme\">How to use?</a></li>"
		 << "<li><a href=\"https://github.com/GreatDevelopers/bakaplan/issues/new#\">Add Feature/Bug</a></li>"
		 << "<li><a href=\"https://github.com/GreatDevelopers/bakaplan#authors\">Contact</a></li>"
		
		 << "	</ul>	<a href=\"#\" id=\"pull\">Menu</a></nav></header>";
}

void HTMLTags :: BodyEnd()
{
    cout << "</div>";
//    cout << "<footer><div id=\"details\"> Brought to you by <a href=\"https://github.com/GreatDevelopers/bakaplan#authors\">GreatDevelopers </a> under <a href=\"https://github.com/GreatDevelopers/bakaplan/blob/master/LICENSE\"> GPL</a> </div> </footer>";
    cout << "</body>" << endl;
}

void HTMLTags :: Title(string title)
{
    ProjectName = "BaKa Plan-Beta";
    cout << "<title>" << ProjectName << ": " << title << "</title>";
}

void HTMLTags :: CSS()
{
    cout << "<link href=\"../../../BaKaPlan/styles.css\""
         << " rel=\"stylesheet\" media=\"screen\">" 
//    cout << "<link rel=\"stylesheet\" type=\"text/css\" href=\"home.css\">" 
         << endl;
}


void HTMLTags :: Header()
{
    cout << "<div id = \"wrapper\">";
    cout << "<div id = \"slogo\" class = \"logo\">" << endl
//         << "<a class=\"brand\" href=\"#\"> Baka Plan<sup>Beta</sup> </a>"
         << " Baka Plan<sup>Beta</sup>" << endl
         << "</div>" << endl;
}
