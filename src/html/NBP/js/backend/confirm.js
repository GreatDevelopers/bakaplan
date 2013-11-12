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

function ConfirmEmail(key) 
{
    console.log(GetUrlVars()["Key"]); 
    XMLHttp.open

    ("GET", "../cgi-bin/nbp/confirm-user?"

    + "Key=" + GetUrlVars()["Key"]

    ,true);
    
    XMLHttp.onreadystatechange=function() 
    {
        if(XMLHttp.responseText != "")
        {
            if(XMLHttp.responseText == "true")
            {
//                alert(XMLHttp.responseText);
                document.getElementById('msg').innerHTML = "Email Confirmed";
            }
            else         
            {
                alert(XMLHttp.responseText);
    //            window.location.href = "index.html";
                document.getElementById('msg').innerHTML = "Invalid Link";
            }
        }
    }

    XMLHttp.send(null);
}

function GetUrlVars() 
{
    var vars = {};
    var parts = window.location.href.replace(/[?&]+([^=&]+)=([^&]*)/gi, 
                function(m,key,value) 
                {
                    vars[key] = value;
                });
    return vars;
}

$( window ).load( ConfirmEmail );
