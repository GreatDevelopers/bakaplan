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
<b>Input from user</b> is divided into 3 parts:

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
        <td>CSE 121 </td>
    </tr>


</table>

Input format for Roll No. details:

Total Branches : 2

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
        <td>202</td> <td> 210 </td> <td>0 </td>
    </tr>


</table>


Input format for room details:

Total Centres : 2

Centre Name : Centre 1              Total Rooms : 2

<table>
    <tr> <th> Room No. </th> <th> Rows</th> <th> Cols</th>
    </tr>
    <tr> <td> Room 1 </td> <td> 6</td> <td>6 </td>
    </tr>
    <tr> <td> Room 2 </td> <td> 8</td> <td>8 </td>
    </tr>

</table>

Centre Name : Centre 2              Total Rooms : 1

<table>
    <tr> <th> Room No. </th> <th> Rows</th> <th> Cols</th>
    </tr>
    <tr> <td> Room 1 </td> <td> 6</td> <td>6 </td>
    </tr>

</table>

After this User has to select strategy. There are 4 strategies as shown below:

<table>

    <tr> <th>A	 </th> <th>  B	 </th> <th>  C	 </th> <th>  D</th>
    </tr>
    <tr> <th>Subject Code 1 </th> <th>Subject Code 1</th> <th>Subject Code  1</th> 
    <th>Subject Code 1</th>
    </tr>
    <tr> <th>Subject Code 1</th> <th>Subject Code 2</th> <th>Subject Code  2</th> 
    <th>Subject Code 2</th>
    </tr>
    <tr> <th>Subject Code 1</th> <th>Subject Code 1</th> <th>Subject Code  3</th> 
    <th>Subject Code 3</th>
    </tr>
    <tr> <th>Subject Code 1</th> <th>Subject Code 2</th> <th>Subject Code  1</th> 
    <th>Subject Code 4</th>
    </tr>

</table>

Select strategy : B

Then

UASGE:
----------------------------


AUTHORS:
----------------------------
Mandeep Kaur

Website: http://mandeepsimak.wordpress.com

Email: meghasimak@gmail.com

