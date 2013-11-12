var XMLHttp;

if(navigator.appName == "Microsoft Internet Explorer") 
{
    XMLHttp = new ActiveXObject("Microsoft.XMLHTTP");
} 
else 
{
    XMLHttp = new XMLHttpRequest();
}

function GetUrlVars() {
    var vars = {};
    var parts = window.location.href.replace(/[?&]+([^=&]+)=([^&]*)/gi, 
function(m,key,value) {
        vars[key] = value;
    });
    return vars;
}


/** Check confirmation link */

function ConfirmEmail(key) 
{
    console.log(GetUrlVars()["Key"]); 
    XMLHttp.open

    ("GET", "../cgi-bin/nbp/confirm-user?"

    + "Key=" + GetUrlVars()["Key"]

    ,true);

    XMLHttp.onreadystatechange=function() 
    {
        if(XMLHttp.responseText == "true")
        {
            document.getElementById('msg').innerHTML = "Email Confirmed";
        }
        else
        {
//            window.location.href = "index.html";
            document.getElementById('msg').innerHTML = "Invalid Link" 
                                                       + XMLHttp.responseText;
        }
    }
    XMLHttp.send(null);
//    document.getElementById('msg').innerHTML = "Invalid Link";

}

$( window ).load( ConfirmEmail );
