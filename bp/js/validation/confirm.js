	/* Change the position of OpenTip for mobile and tablet */
$(function(){
	if($(window).width() < 720){
		var passOpenTip = new Opentip("#password","Fill Password",
					{style:"myMobileInputStyle"});
		var retypePassOpenTip = new Opentip("#retype-password","Fill Retype Password",
					{style:"myMobileInputStyle"});
	}
	else{
		var passOpenTip = new Opentip ("#password","Fill  Password",{
					target:"#password",
					style:"myInputStyle"});
		var retypePassOpenTip = new Opentip("#retype-password","Fill Retype Password",{
					target:"#retype-password",
					style:"myInputStyle"});
					
	}
	/* Changing the content of OpenTip based on content in input */
	var password = $("#password");
	password.keyup(function(){
//		passOpenTip.setContent( "\"" + password.val() + "\" is a lovely name");
		if (password.val() == "") passOpenTip.setContent("Fill Password"); 
	});

	var retypePass = $("#retype-password");
	retypePass.keyup(function(){
//		retypePassOpenTip.setContent("Make sure " + theEMail.val() +" is your correct Email ID");
		if (retypePass.val() == "") retypePassOpenTip.setContent("Retype Password");

	});
	
	var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
	
    var validator = new FormValidator('set-password',[{
		name:'password',
		display:'Password',
		rules:'required|min_length[8]'
		},{
		name:'retype-password',
		display:'Retype Password',
		rules:'required|min_length[8]|matches[password]'
		},{
		name:'theFeedback',
		display:'Feedback',
		rules:'required'
		}],function(errors, event){
			var errorString = '';
			for (var i = 0, errorLength = errors.length; i < errorLength; i++) {
           			errorString += errors[i].message + '<br />';
        		}
			theErrorTip.setContent(errorString);
			theErrorTip.show();	
		}
	);	
});


