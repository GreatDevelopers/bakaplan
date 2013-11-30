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
    document.getElementById("set-password").style.display="none";
    console.log(GetUrlVars()["Key"]); 
    XMLHttp.open

    ("GET", "../cgi-bin/nbp/confirm_user?"

    + "Key=" + GetUrlVars()["Key"]

    ,true);
    
    XMLHttp.onreadystatechange=function() 
    {
        if(XMLHttp.responseText.trim() == "true")
        {
//            document.getElementById('msg').innerHTML += "Email Confirmed";
            var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
  	    	theErrorTip.setContent("Email Confirmed");
		    theErrorTip.show();	
            document.getElementById("set-password").style.display="none";
        }
        else         
        {
//            window.location.href = "index.html";
            var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
  	        theErrorTip.setContent("Invalid Link");
		    theErrorTip.show();	
            document.getElementById("set-password").style.display="none";
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
