/* Change the position of OpenTip for mobile and tablet */

var validate = '';

$(function()
{

    var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
		
    var validator = new FormValidator('accordion-signup',[{
		name:'email-signup',
		display:'Email ID',
		rules:'required|valid_email'
		}
       ],function(errors, event){
			var errorString = '';
			for (var i = 0, errorLength = errors.length; i < errorLength; i++) {
           			errorString += errors[i].message + '<br />';
        		}
            if(errorString == '')
            {
                validate = "true"
			    theErrorTip.hide();	
            }
            else
            {
    			theErrorTip.setContent(errorString);
			    theErrorTip.show();	
                validate = "false";
            }
		}
	);
//    validate = ''; 
    /** Login Form Validation function */
	var loginValidator = new FormValidator('accordion-login',[{
		name:'email-login',
		display:'Email ID',
		rules:'required|valid_email'
		},{
        name:'password-login',
        display:'Password',
        rules:'required|min_length[8]'
        }
       ],function(errors, event){
			var errorString = '';
			for (var i = 0, errorLength = errors.length; i < errorLength; i++) {
           			errorString += errors[i].message + '<br />';
        		}
            if(errorString == '')
            {
                validate = "true"
			    theErrorTip.hide();	
            }
            else
            {
    			theErrorTip.setContent(errorString);
			    theErrorTip.show();	
                validate = "false";
            }
		}
	);

});

