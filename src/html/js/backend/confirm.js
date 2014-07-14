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

    ("GET", "cgi/confirm_user?"

    + "Key=" + GetUrlVars()["Key"]

    ,true);
    
    XMLHttp.onreadystatechange=function() 
    {
        if(XMLHttp.responseText.trim() != "false" &&  XMLHttp.responseText.trim() != "" )
        {
            var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
  	    	theErrorTip.setContent("Email Confirmed");
		    theErrorTip.show();
            document.getElementById('RegID').value = XMLHttp.responseText;
        }
        else         
        {
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

/** Set Password for new user */

function SetPassword() 
{

    if(validate == "true")
    {
    XMLHttp.open

        ("GET", "cgi/set_password?"

        + "RegID=" + document.getElementById('RegID').value
        + "&Password=" + document.getElementById('password').value
        + "&RetypePassword=" + document.getElementById('retype-password').value
    
        ,true);
    
        XMLHttp.onreadystatechange=function() 
        {
        
            if(XMLHttp.responseText.trim() != "false")
            {
                var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
  	    	    theErrorTip.setContent("Password Changed");
    		    theErrorTip.show();	
                document.getElementById("set-password").style.display="none";
                window.setTimeout(function()
                {
                    window.location.href = "index.html";
                }, 100);
            }
            else         
            {
                var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
  	            theErrorTip.setContent("Password not set");
		        theErrorTip.show();	
            }
           }

        XMLHttp.send(null);
        if(XMLHttp.responseText == "true")
            return true;
        else
            return false;
    }
    else
        return false;
}
