BaKa Plan
============

This software creates seating plan for examinations. It provides four different
strategies to create saet plan.

REQUIREMENTS:
----------------------------
1) GNU G++ Compiler

2) Configure public_html/cgi-bin folder for executing files on browser.


INPUT FORMAT:
----------------------------
Input from user is divided intu 3 parts:

1) Branch Details

2) Roll No. Details

3) Room Details

Input format for branch details:

<table>
    <tr> <th> Branch Name </th> <th> Total subjects</th> <th> Subject Name</th>
        <th>Subject Code </th>
    </tr>
     <tr> <td> Information Technology </td> <td> 2</td> <td> DBMS, SAD</td>
        <td>IT-121, IT 201</td>
    </tr>
     <tr> <td> Comp. Engg. </td> <td> 1</td> <td> CG</td>
        <th>CSE 121 </th>
    </tr>


</table>

Input format for Roll No. details:

<table>
    <tr> <th> Branch Name </th> <th> Subject Code</th> <th>Prefix</th> <th> Start Roll No.</th>
        <th>End Roll No. </th> <th> Not Included </th>
    </tr>
     <tr> <td> Information Technology </td> <td> IT-121</td> <td>10037 </td>
        <td>102</td> <td> 130 </td> <td> 109 122 </td>
    </tr>
     <tr> <td> Information Technology </td> <td> IT 201</td> <td>10038 </td>
        <td>102</td> <td> 130 </td> <td> 109 122 </td>
    </tr>
    </tr>
     <tr> <td> Comp. Engg. </td> <td> CSE 121</td> <td>CSE </td>
        <td>202</td> <td> 210 </td> <td>   </td>
    </tr>


</table>


Input format for branch details:

<table>
    <tr> <th> Branch Name </th> <th> Total subjects</th> <th> Subject Name</th>
        <th>Subject Code </th>
    </tr>
     <tr> <th> Information Technology </th> <th> 2</th> <th> DBMS, SAD</th>
        <th>IT-121, IT 201</th>
    </tr>
     <tr> <th> Comp. Engg. </th> <th> 1</th> <th> CG</th>
        <th>CSE 121 </th>
    </tr>


</table>
UASGE:
----------------------------


AUTHORS:
----------------------------
Mandeep Kaur
Website: http://mandeepsimak.wordpress.com
Email: meghasimak@gmail.com
