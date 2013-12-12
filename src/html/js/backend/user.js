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

        ("GET", "../cgi-bin/nbp/signup?"

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
    if(validate == "true")
    {
        XMLHttp.open
    
        ("GET", "../cgi-bin/nbp/login?"

        + "email-login=" + document.getElementById('email-login').value

        + "&password-login=" + document.getElementById('password-login').value

        ,true);
    
        XMLHttp.onreadystatechange=function() 
        {
            if(XMLHttp.responseText.trim() == "false")
            {
                var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
  			    theErrorTip.setContent("Incorrect Password or Email ID");//XMLHttp.responseText);
    		    theErrorTip.show();	
            }
            else
            {
                var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
                var link = "../cgi-bin/bp/project-detail?sid="
                                       + XMLHttp.responseText;

  			    theErrorTip.setContent(link);
//    		    theErrorTip.show();	

                window.location.href = link;
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
