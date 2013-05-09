// Function for adding row in table
function addRows(tableID, totalID, field) 
{
    try
    {
//        if (typeof tableNo == 'undefined')
//                tableNo = 0;

        var table = document.getElementById(tableID);
        var total = document.getElementById(totalID).value;
        var classField = new Array("ClassName", "SubjectName", 
                                   "SubjectCode", "Delete");
        var dateField = new Array("Date", "ExamCode");
/*        var RoomField = new Array("CentreName", "RoomNo", 
                                  "Rows", "Columns");
        var ExamField = new Array("ExamName", "ExamSession",
                                  "ExamVenue", "ExamTime");
        var StrategyFiels = new Array("Strategy");
*/
        var newTotal = parseInt(total) + 1;
 
        var rowCount = table.rows.length;
        var row = table.insertRow(rowCount);
 
        var colCount = table.rows[0].cells.length;
 
        for(var i=0; i<colCount; i++) 
        {
            var newcell = row.insertCell(i);
 
            newcell.innerHTML = table.rows[1].cells[i].innerHTML;
            //alert(newcell.childNodes);
            switch(newcell.childNodes[0].type) 
            {
                case "text":
                    newcell.childNodes[0].value = "";
                    if(field == "class")
                    {
                        newcell.childNodes[0].name = classField[i] 
                                                     + newTotal;
                        newcell.childNodes[0].id = classField[i] 
                                                     + newTotal;
                    }
                    else if(field == "date")
                    {
                        newcell.childNodes[0].name = dateField[i] 
                                                     + newTotal;
                        newcell.childNodes[0].id = dateField[i] 
                                                     + newTotal;
                    }
/*                    else if(field == "room")
                    {
                        var fn = classField[i] + tableID + newTotal;
                        newcell.childNodes[0].name = fn;
                        newcell.childNodes[0].id = fn; 

                    }*/
                    else
                    {

                    }
                    break;
                case "checkbox":
                    newcell.childNodes[0].checked = false;
                    break;
                case "select-one":
                    newcell.childNodes[0].selectedIndex = 0;
                    break;
            }
         }
         document.getElementById(totalID).value = newTotal;
    }
    catch(e)
    {
        alert(e);
    }
}

// Function for adding row in table
function addRow(tableID, totalID, field, tableNo) 
{
    try
    {
//        if (typeof tableNo == 'undefined')
//                tableNo = 0;

        var table = document.getElementById(tableID);
        var total = document.getElementById(totalID).value;
/*        var classField = new Array("ClassName", "SubjectName", 
                                   "SubjectCode");
        var DateField = new Array("Date", "ExamCode");*/
        var RoomField = new Array("CentreName", "RoomNo", 
                                  "Rows", "Columns");
        var ExamField = new Array("ExamName", "ExamSession",
                                  "ExamVenue", "ExamTime");
        var StrategyFiels = new Array("Strategy");

        var newTotal = parseInt(total) + 1;
 
        var rowCount = table.rows.length;
        var row = table.insertRow(rowCount);
 
        var colCount = table.rows[0].cells.length;
 
        for(var i=0; i<colCount; i++) 
        {
            var newcell = row.insertCell(i);
 
            newcell.innerHTML = table.rows[1].cells[i].innerHTML;
            //alert(newcell.childNodes);
            switch(newcell.childNodes[0].type) 
            {
                case "text":
                    newcell.childNodes[0].value = "";
/*                    if(field == "class")
                    {
                        newcell.childNodes[0].name = classField[i] 
                                                     + newTotal;
                        newcell.childNodes[0].id = classField[i] 
                                                     + newTotal;
                    }
                    else if(field == "date")
                    {
                        newcell.childNodes[0].name = DateField[i] 
                                                     + newTotal;
                        newcell.childNodes[0].id = DateField[i] 
                                                     + newTotal;
                    }*/
                    if(field == "room")
                    {
                        var fn = RoomField[i] + tableNo + newTotal;
                        newcell.childNodes[0].name = fn;
                        newcell.childNodes[0].id = fn; 

                    }
                    else
                    {

                    }
                    break;
                case "checkbox":
                    newcell.childNodes[0].checked = false;
                    break;
                case "select-one":
                    newcell.childNodes[0].selectedIndex = 0;
                    break;
            }
         }
         document.getElementById(totalID).value = newTotal;
    }
    catch(e)
    {
        alert(e);
    }
}
// Function for deleting row from table
function deleteRow(tableID, totalID)
{
    try
    {        
        var tbl = document.getElementById(tableID);
        var lastRow = tbl.rows.length;
        var total = document.getElementById(totalID).value;

        if (lastRow > 2)
        {
            var newTotal = parseInt(total) - 1;
            document.getElementById(totalID).value = newTotal;       
            tbl.deleteRow(lastRow - 1);
        }
    }
    catch(e)
    {
        alert(e);
    }
}

// function for delete current row
function delRow(totalID)
{
    try
    {
        var total = document.getElementById(totalID).value;

        var current = window.event.srcElement;
        //here we will delete the line
        while ( (current = current.parentElement) && 
                current.tagName !="TR");
            current.parentElement.removeChild(current);
        var newTotal = parseInt(total) - 1;
        document.getElementById(totalID).value = newTotal;       

    }
    catch(e)
    {
        alert(e);
    }
}

/** Function for checking subject detail on class page */

function validateForm(totalID)
{
    try
    {
        var total = document.getElementById(totalID).value;

        var returnFalse, returnEmpty;

        var msg = document.getElementById("Error");
        msg.innerHTML = " ";

//    msg.innerHTML += "Total Classes " + total + "<br>";

        for( var i = 1; i <= parseInt(total); i++)
        {
            subName = "SubjectName" + i;
            subCode = "SubjectCode" + i;
            className = "ClassName" + i;

            returnFalse = compareSubjects(subName, subCode);
            returnEmpty = isEmpty(subName, subCode, className);
        }
        if (returnFalse == false || returnEmpty == false)
        {
            return false;
        }
    }
    catch( e )
    {
        alert(e);
        return false;
    }
}

/** comparing subject name nd subject code size */

function compareSubjects(subName, subCode)
{
    var subjectName = document.getElementById(subName).value;
    var subjectCode = document.getElementById(subCode).value;

    var splitName = subjectName.split(",");
    var splitCode = subjectCode.split(",");

    var msg = document.getElementById("Error");
    
//    msg.innerHTML += splitName.length + "<br>" + splitCode.length;

    if(splitName.length != splitCode.length)
    {
        msg.innerHTML += "Check Subject Name and Subject Code";
        document.getElementById(subName).style.borderColor = "red";
        document.getElementById(subCode).style.borderColor = "red";
        return false;
    }
    else
    {
        document.getElementById(subName).style.borderColor = "";
        document.getElementById(subCode).style.borderColor = "";
//        msg.innerHTML += "Subjects no. matched";
//        document.FormClass.submit();
    }
}

/** function for checking empty fields */

function isEmpty()
{ 
    for(var j = 0; j < arguments.length; j++)
    {
//        alert(arguments[j]);
        var fieldValue = document.getElementById(arguments[j]).value;
        if( fieldValue.length == 0);
        {
            document.getElementById(arguments[j]).style.borderColor = "red";
            return false;
        }
/*        else
        {
            document.getElementById(arguments[j]).style.borderColor = "";
        }*/
    }
}
