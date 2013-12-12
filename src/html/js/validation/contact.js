	/* Change the position of OpenTip for mobile and tablet */
$(function(){
	if($(window).width() < 720){
		var nameOpenTip = new Opentip("#theName","Write your name",
					{style:"myMobileInputStyle"});
		var emailOpenTip = new Opentip("#theEMail","EMail-ID is required to contact you",
					{style:"myMobileInputStyle"});
	}
	else{
		var nameOpenTip = new Opentip ("#theName","Write your name here",{
					target:"#theName",
					style:"myInputStyle"});
		var emailOpenTip = new Opentip("#theEMail","with your EMail-ID, we can contact you back and answer your queries",{
					target:"#theEMail",
					style:"myInputStyle"});
					
		var FeedbackOpenTip = new Opentip("#theFeedback","Share your suggestions, questions or any other feedback with Us",{
						target:"#theFeedback",
						style:"myInputStyle"} );

	}
	/* Changing the content of OpenTip based on content in input */
	var theName = $("#theName");
	theName.keyup(function(){
		nameOpenTip.setContent( "\"" + theName.val() + "\" is a lovely name");
		if (theName.val() == "") nameOpenTip.setContent("Enter your name"); 
	});

	var theEMail = $("#theEMail");
	theEMail.keyup(function(){
		emailOpenTip.setContent("Make sure " + theEMail.val() +" is your correct Email ID");
		if (theEMail.val() == "") emailOpenTip.setContent("Enter your E-Mail ID");

	});
	
	var theErrorTip = new Opentip("#tipTarget",'',{ style:"myErrorStyle"});
		
	var validator = new FormValidator('contact-form',[{
		name:'theName',
		display:'Name',
		rules:'required'
		},{
		name:'theEMail',
		display:'Email ID',
		rules:'required|valid_email'
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

