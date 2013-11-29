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

    ("GET", "../cgi-bin/nbp/confirm_user?"

    + "Key=" + GetUrlVars()["Key"]

    ,true);
    
    XMLHttp.onreadystatechange=function() 
    {
        if(XMLHttp.responseText == "true")
        {
//            document.getElementById('msg').innerHTML += "Email Confirmed";
            var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
  	    	theErrorTip.setContent("Email Confirmed");
		    theErrorTip.show();	

        }
        else         
        {
            window.location.href = "index.html";
//            document.getElementById('msg').innerHTML = "Invalid Link";
            var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
  	        theErrorTip.setContent("Invalid Link");
		    theErrorTip.show();	
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
