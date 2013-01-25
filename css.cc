#include "css.h"

void HomeCSS :: ContentType()
{
    cout << "Content-type:text/html\n\n";
}

void HomeCSS :: Main()
{
    ContentType();
    cout << "body { background-image:url('../../SeatPlan/images/bg.jpg'); }"
         << "h1 { color: FFF0F5; font-size: 100px;"
         << " font-family:\"Alex Brush\";}"
         << ".center"
         << "{"
         << "margin:auto;"
         << "width:70%;"
//         << "background-color:#b0e0e6;"
         << "}"
         << "table"
         << "{"
         << "border-collapse:collapse;"
         << "}"
         << ".content"
         << "{"
//         << "margin:auto;"
         << "width:100%;"
         << "background-color:white;"
         << "height:1250px;"
         << "margin-top:10px"
         << "}"
         << ".left"
         << "{"
         << "float:left;"
         << "width:30%;"
         << "}"
//         << ".right"
//         << "{"
//         << "float:right;"
//         << "width:30%;"
//         << "margin:5px;"
//         << "}"
         << endl;
}
