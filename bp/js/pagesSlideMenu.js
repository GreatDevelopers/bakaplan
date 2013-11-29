/****************************************
*File:pageSlideMenu.js
-
*Brief: Handles side push menus in page layout 
-
*Version:1
-
*author: Inderpreet Singh (ishwerdas.com)
-
*License: GPL V3.0
-
****************************************/
var menu = document.getElementsByClassName("side-menu");
var togglemenu = document.getElementById("toggle-menu");
togglemenu.onClick = function(){
menu.item(0).style.left="0px";
}
