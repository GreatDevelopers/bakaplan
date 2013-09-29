var XMLHttp;

if(navigator.appName == "Microsoft Internet Explorer") 
{
    XMLHttp = new ActiveXObject("Microsoft.XMLHTTP");
} 
else 
{
    XMLHttp = new XMLHttpRequest();
}

/** Getting Sign up response */

function GetSignUpResponse() 
{
    XMLHttp.open

    ("GET", "../cgi-bin/NBP/backend/bp/signup?"

    + "email-signup=" + document.getElementById('email-signup').value

    ,true);

    XMLHttp.onreadystatechange=function() 
    {
        if(XMLHttp.responseText != "true")
            document.getElementById('msg').innerHTML = XMLHttp.responseText;
    }
    XMLHttp.send(null);
    
    if(XMLHttp.responseText == "true")
        return true;
    else
        return false;
}

/** Getting Login response */

function GetLoginResponse() 
{
    XMLHttp.open

    ("GET", "../cgi-bin/NBP/backend/bp/login?"

    + "email-login=" + document.getElementById('email-login').value

    + "&password-login=" + document.getElementById('password-login').value

    ,true);

    XMLHttp.onreadystatechange=function() 
    {
        if(XMLHttp.responseText != "true")
            document.getElementById('msg').innerHTML = XMLHttp.responseText;
    }
    XMLHttp.send(null);

    if(XMLHttp.responseText == "true")
        return true;
    else
        return false;
}
