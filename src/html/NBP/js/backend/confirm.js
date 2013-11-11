var XMLHttp;

if(navigator.appName == "Microsoft Internet Explorer") 
{
    XMLHttp = new ActiveXObject("Microsoft.XMLHTTP");
} 
else 
{
    XMLHttp = new XMLHttpRequest();
}

/** Check confirmation link */

function ConfirmEmail() 
{
    console.log("hello"); 
    XMLHttp.open

    ("GET", "../cgi-bin/NBP/backend/bp/confirm?"

    + "Key=" + document.getElementById('Key').value

    ,true);

    XMLHttp.onreadystatechange=function() 
    {
        if(XMLHttp.responseText == "true")
        {
            document.getElementById('msg').innerHTML = "Email Confirmed";
        }
        else
        {
            window.location.href = "index.html";
            document.getElementById('msg').innerHTML = "Invalid Link";
        }
    }
    XMLHttp.send(null);
    document.getElementById('msg').innerHTML = "Invalid Link";

}

$( window ).load( ConfirmEmail );
