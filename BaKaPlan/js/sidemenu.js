
var isMenuOpen= false;
var menu = document.getElementsByClassName('side-menu');
var toggle = document.getElementById('toggle-menu');
var toggleCircle = document.getElementById('toggle-menu-circle');
	toggle.onclick=function(){
	console.log("entered function");
	if (isMenuOpen== true){
		console.log("hell yeah"); 
		isMenuOpen = false;
		menu.item(0).style.left="-200px";	
		toggle.style.left="10px";
		toggleCircle.innerHTML=" Show Menu ";
	}
	else{
		isMenuOpen = true;
		console.log(isMenuOpen);
		console.log("this si it");
		menu.item(0).style.left="0px";
		toggle.style.left="210px";
		toggleCircle.innerHTML=" Hide Menu ";
	}
	
}
