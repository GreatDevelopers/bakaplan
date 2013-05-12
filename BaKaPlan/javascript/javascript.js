// Function for adding row in table
function AddRows(tableID, totalID, field) 
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

        var lastRow = parseInt(document.getElementById('LastRow').value) 
                      + 1;
 
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
                                                     + lastRow;
                        newcell.childNodes[0].id = classField[i] 
                                                     + lastRow;
                    }
                    else if(field == "date")
                    {
                        newcell.childNodes[0].name = dateField[i] 
                                                     + lastRow;
                        newcell.childNodes[0].id = dateField[i] 
                                                     + lastRow;
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

                case "button":
                    newcell.childNodes[0].id = lastRow;
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
         alert(newTotal);
         document.getElementById('LastRow').value = lastRow;
         document.getElementById('RowIndex').value += "," + lastRow;
    }
    catch(e)
    {
        alert(e);
    }
}

// Function for adding row in table
function AddRow(tableID, totalID, field, tableNo) 
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
        var fieldRow = "LastRow" + tableNo;
        var lastRow = parseInt(document.getElementById(fieldRow).value) 
                      + 1;
        alert(lastRow);
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
                        var fieldName = RoomField[i] + tableNo + lastRow;
                        newcell.childNodes[0].name = fieldName;
                        newcell.childNodes[0].id = fieldName; 

                    }
                    else
                    {

                    }
                    break;
                case "button":
                    newcell.childNodes[0].id = lastRow;
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
         alert(newTotal);
         document.getElementById(("LastRow" + tableNo)).value = lastRow;
         document.getElementById(("RowIndex" + tableNo)).value += "," + lastRow;
    }
    catch(e)
    {
        alert(e);
    }
}
// Function for deleting row from table
function DeleteRow(tableID, totalID)
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
function DelRow(indexField, totalID, e)
{
    try
    {
        var total = document.getElementById(totalID).value;
        var evt = e || window.event; // this assign evt with the event object

        var current = evt.target || evt.srcElement;
        rowId = current.id;
        alert(rowId);
        
        //here we will delete the line
        while ( (current = current.parentElement) && 
                current.tagName !="TR");
        {
//            alert(current.rowIndex);
            if(current.rowIndex != 1)
                current.parentElement.removeChild(current);
        }
        var newTotal = parseInt(total) - 1;
        document.getElementById(totalID).value = newTotal;
//        alert(indexField);
        RemoveItem(indexField, rowId);
    }
    catch(e)
    {
        alert(e);
    }
}

/** Remove element from array */

function RemoveItem(indexField, rowId)
{
    var rowIndex = document.getElementById(indexField).value;
    var index = rowIndex.split(",");
    index.splice(index.indexOf(rowId), 1);
    rowIndex = "";
    for(var i = 0; i < index.length; i++)
    {
        if(index[i] != rowId)
        {
            rowIndex += index[i];
            if(i != index.length-1)
                rowIndex += ",";
        }
    }
    document.getElementById(indexField).value = rowIndex;
}

/** Function for checking subject detail on class page */

function ValidateClassForm(totalID)
{
    try
    {
        var total = document.getElementById(totalID).value;

        var returnFalse, emptyMsg = "";

        var msg = document.getElementById("Error");
        msg.innerHTML = " ";

        var fieldName = new Array("ClassName", "SubjectName", 
                                  "SubjectCode");

        var rowIndex = document.getElementById('RowIndex').value;
        var index = rowIndex.split(',');

        for( var i = 0; i < parseInt(total); i++)
        {
            className = fieldName[0] + index[i];
            subName = fieldName[1] + index[i];
            subCode = fieldName[2] + index[i];

            var temp = CompareSubjects(subName, subCode);

            if(temp == false)
                returnFalse = false;

            // Checking field is empty or not
            for (j = 0; j < fieldName.length; j++)
            {
                if(document.getElementById(
                    (fieldName[j] + index[i])).value.length == 0)
                {
                    emptyMsg = "<br> Fill Empty Fields!";
                    returnFalse = false;
                    ChangeBorder((fieldName[j] + index[i]), "red");
                }
                else
                {
                    if(j == 0)
                        ChangeBorder((fieldName[j] + index[i]), "");
                }
            }
        }
        if (returnFalse == false)
        {
            msg.innerHTML += emptyMsg;
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

function CompareSubjects(subName, subCode)
{
    var subjectName = document.getElementById(subName).value;
    var subjectCode = document.getElementById(subCode).value;

    var splitName = subjectName.split(",");
    var splitCode = subjectCode.split(",");

    var msg = document.getElementById("Error");
    
    if(splitName.length != splitCode.length)
    {
        msg.innerHTML = "Check Subject Name and Subject Code";
        ChangeBorder(subName, "red");
        ChangeBorder(subCode, "red");
        return false;
    }
    else
    {
        ChangeBorder(subName, "");
        ChangeBorder(subCode, "");
    }
}

/** Function for validation roll no form */

function ValidateRollNoForm(totalID)
{
    try
    {
        var total = document.getElementById(totalID).value;

        var returnFalse, emptyMsg = "";

        var msg = document.getElementById("Error");
        msg.innerHTML = " ";

        var fieldName = new Array("Prefix", "StartRollNo", 
                                  "EndRollNo");//, "NotIncluded");

        for( var i = 1; i <= parseInt(total); i++)
        {
            startField = fieldName[1] + i;
            endField = fieldName[2] + i;

            var temp = CheckRollNo(startField, endField);

            if(temp == false)
                returnFalse = false;

            // Checking field is empty or not
            for (j = 0; j < fieldName.length; j++)
            {
//                alert((fieldName[j] + i));
                if(document.getElementById(
                    (fieldName[j] + i)).value.length == 0)
                {
                    emptyMsg = "<br> Fill Empty Fields!<br>";
                    returnFalse = false;
                    ChangeBorder((fieldName[j] + i), "red");
                }
                else
                {
                    if(j == 0 || j > 2 )
                        ChangeBorder((fieldName[j] + i), "");
                }
            }
        }
        if (returnFalse == false)
        {
            msg.innerHTML += emptyMsg;
            return false;
        }
//        return false;
    }
    catch( e )
    {
        alert(e);
        return false;
    }
}

/** Function for checking range of roll no i.e. starting roll no
 *  should be less than ending roll no 
 */

function CheckRollNo(startField, endField)
{
    var startRNo = document.getElementById(startField).value;
    var endRNo = document.getElementById(endField).value;
    var msg = document.getElementById("Error");
//    msg = "";
//    alert(parseInt(startRNo));
    if(parseInt(startRNo) >= parseInt(endRNo))
    {
//        alert("hello");
        msg.innerHTML += "<br>Check Starting and ending Roll No<br>";
        ChangeBorder(startField, "red");
        ChangeBorder(endField, "red");
        return false;
    }
    else
    {
        ChangeBorder(startField, "");
        ChangeBorder(endField, "");
    }
}

/** function for changing border color of I/p field */

function ChangeBorder(field, color)
{ 
    document.getElementById(field).style.borderColor = color;
}
