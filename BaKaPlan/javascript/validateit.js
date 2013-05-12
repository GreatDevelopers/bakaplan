/** Login Page Validation */

var loginValidator = new FormValidator('FormLogin', 
[
    {
        name: 'EmailID',
        display: 'Email ID',
        rules: 'required|valid_email'
    }, 
    {
        name: 'Password',
        display: 'Password',
        rules: 'required'
    }
], 
function(errors, event) 
{
    msg = document.getElementById("Error");
    msg.innerHTML = "";

    if (errors.length > 0) 
    {
        var errorString;
        for( var i = 0, errorLength = errors.length; i < errorLength; i++)
        {
            msg.innerHTML += errors[i].message + "<br>";            
        }
        msg.innerHTML += "<br>";
    }
}); 

/** Validation for Project Detail Page*/

var projectValidator = new FormValidator('FormProject', 
[
{
    name: 'ProjectType',
    display: 'Project Type',
    rules: 'required'
}, 
{
    name: 'ProjectName',
    display: 'Project Name',
    rules: 'required'
}
], 
function(errors, event) 
{
    msg = document.getElementById("Error");
    msg.innerHTML = "";

    if (errors.length > 0) 
    {
        var errorString;
        for( var i = 0, errorLength = errors.length; i < errorLength; i++)
        {
            msg.innerHTML += errors[i].message + "<br>";            
        }
        msg.innerHTML += "<br>";
    }
}); 

/** Validation for Registration Page*/

var registerValidator = new FormValidator('FormRegister', 
[
{
    name: 'EmailID',
    display: 'Email ID',
    rules: 'required|valid_email'
} 
], 
function(errors, event) 
{
    msg = document.getElementById("Error");
    msg.innerHTML = "";

    if (errors.length > 0) 
    {
        var errorString;
        for( var i = 0, errorLength = errors.length; i < errorLength; i++)
        {
            msg.innerHTML += errors[i].message + "<br>";            
        }
        msg.innerHTML += "<br>";
    }
}); 

/** Password Setting Page Validation */

var confirmValidator = new FormValidator('FormConfirm', 
[
    {
        name: 'Password',
        display: 'Password',
        rules: 'required|min_length[8]'
    },
    {
        name: 'RetypePassword',
        display: 'Re-type Password',
        rules: 'required|min_length[8]|matches[Password]'
    } 
], 
function(errors, event) 
{
    msg = document.getElementById("Error");
    msg.innerHTML = "";

    if (errors.length > 0) 
    {
        var errorString;
        for( var i = 0, errorLength = errors.length; i < errorLength; i++)
        {
            msg.innerHTML += errors[i].message + "<br>";            
        }
        msg.innerHTML += "<br>";
    }
}); 

/** Validation for Datesheet Page*/

var datesheetValidator = new FormValidator('FormDateSheet', 
[
{
    name: 'SameDetail',
    display: 'Same Detail',
    rules: 'required'
}
], 
function(errors, event) 
{
    msg = document.getElementById("Error");
    msg.innerHTML = "";

    if (errors.length > 0) 
    {
        var errorString;
        for( var i = 0, errorLength = errors.length; i < errorLength; i++)
        {
            msg.innerHTML += errors[i].message + "<br>";            
        }
        msg.innerHTML += "<br>";
    }
}); 


