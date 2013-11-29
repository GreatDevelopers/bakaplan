$(function(){
	Opentip.styles.myInputStyle = {
		extends: "dark",
		showOn: "focus",
		hideOn:"null",
		tipJoint:"left",
		group:"inputElements"
	};

	Opentip.styles.myMobileInputStyle = {
		extends:"myInputStyle",
		tipJoint:"top",
		stem:"false",
		target:"#tipTarget"
	};
	Opentip.styles.myErrorStyle = {
		extends:"alert",
		stem:false,
		tipJoint:"bottom",
		target:"#tipTarget",
		hideOn:"null",
		showOn:"click",
		group:"inputElements"
	};

});
