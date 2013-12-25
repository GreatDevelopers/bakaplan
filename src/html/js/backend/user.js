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
    if(validate == "true")
    {
        XMLHttp.open

        ("GET", "/bp/signup?"

        + "email-signup=" + document.getElementById('email-signup').value

        ,true);

        XMLHttp.onreadystatechange=function() 
        {
            if(XMLHttp.responseText.trim() != "true")
            {
//            document.getElementById('msg').innerHTML = "<br>" + XMLHttp.responseText;

                var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
  	    		theErrorTip.setContent(XMLHttp.responseText);
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

/** Getting Login response */

function GetLoginResponse() 
{
    var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});

    if(validate == "true")
    {
        XMLHttp.open
    
        ("GET", "/bp/login?"

        + "email-login=" + document.getElementById('email-login').value

        + "&password-login=" + document.getElementById('password-login').value

        ,true);
    
        XMLHttp.onreadystatechange=function() 
        {
            if(XMLHttp.responseText.trim() == "false")
            {
  			    theErrorTip.setContent("Incorrect Password or Email ID");//XMLHttp.responseText);
    		    theErrorTip.show();	
            }
            else if(XMLHttp.responseText.trim() == "true")
            {
//                var link = "../cgi-bin/bp/project-detail?sid="
//                                       + XMLHttp.responseText;

  			    theErrorTip.setContent("Valid User Info" + XMLHttp.responseText);
    		    theErrorTip.show();	

//                window.location.href = link;
            }
            else
            {
                theErrorTip.setContent(XMLHttp.responseText);
    		    theErrorTip.show().delay(5000).hide(0);
            }
        }
        XMLHttp.send(null);

        if(XMLHttp.responseText.trim() == "true")
            return true;
        else
            return false;
    }
    else
        return false;
}
