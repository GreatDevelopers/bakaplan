BaKa Plan
============

This software creates seating plan for examinations. It provides four different
strategies to create seat plan.

REQUIREMENTS:
----------------------------
1) GNU G++ Compiler

2) Configure public_html/cgi-bin folder for executing files on browser.

3) CGICC Library
    Download 3rd last package from ftp://ftp.gnu.org/gnu/cgicc/
    
    Then run following commands in terminal
    
    1) $tar xzf cgicc-X.X.X.tar.gz 
    
    2) $cd cgicc-X.X.X/ 
    
    3) $./configure --prefix=/usr 
    
    4) $make
    
    5) $make install


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

Centre Name : Centre 1

Total Rooms : 2

<table>
    <tr> <th> Room No. </th> <th> Rows</th> <th> Cols</th>
    </tr>
    <tr> <td> Room 1 </td> <td> 6</td> <td>6 </td>
    </tr>
    <tr> <td> Room 2 </td> <td> 8</td> <td>8 </td>
    </tr>

</table>

Centre Name : Centre 2

Total Rooms : 1

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
    <tr> <td>Subject Code 1 </td> <td>Subject Code 1</td> <td>Subject Code  1</td> 
    <td>Subject Code 1</td>
    </tr>
    <tr> <td>Subject Code 1</td> <td>Subject Code 2</td> <td>Subject Code  2</td> 
    <td>Subject Code 2</td>
    </tr>
    <tr> <td>Subject Code 1</td> <td>Subject Code 1</td> <td>Subject Code  3</td> 
    <td>Subject Code 3</td>
    </tr>
    <tr> <td>Subject Code 1</td> <td>Subject Code 2</td> <td> Code  1</td> 
    <td>Subject Code 4</td>
    </tr>

</table>

Select strategy : B

Then conditions for strategy is checked. And validation page is shown to user 
to add more rooms if condition is invalid or move on to next page if condition 
is valid.

Validation Page:

Total Seats = value

Total Students = value

Total Group Seats = value

Max Group Students = value

condition is valid or invalid


Here Total group seats and students defines the size of one group in selected 
strategy. If group seats less than group students then condition is invalid
and user has to add more rooms for that.

If condition is valid then user moves on to next page and fill examination 
details. In which user fill examination name, date, time and venue.
And then he/she can download seating plan for examination using this software.

USAGE:
----------------------------
Download this repository bakaplan. This has all files for front end and backend 
processing code.

Then place it in cgi-bin/ folder and do as following

1) $ cd cgi-bin/bakaplan

2) $ make

3) $ cd SeatPlan

4) $ make

After this you have to download another repository which has its landing page
and images. 

Download it from

https://github.com/megha55/BaKaPlan

Now place this folder in ~/public_html folder.

After all above steps open browser and open following link:

http://localhost/~username/BaKaPlan

NOTE:    Be sure that you must have write permission in the directory
         (~/public_html/cgi-bin/bakaplan/ and ~/public_html/)
         where outputfile is to be generated.

AUTHORS:
----------------------------
Mandeep Kaur

Website: http://mandeepsimak.wordpress.com

Email: meghasimak@gmail.com

Inderpreet Singh

Website: http://inderplus.ishwerdas.com/

Email: indrplus@gmail.com
