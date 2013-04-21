var loginValidator = new FormValidator('FormLogin', [{
name: 'EmailID',
rules: 'required|valid_email'
         }, {
           name: 'Password',
          display: 'Password',
               rules: 'required'
         }], function(errors, event) {
       if (errors.length > 0) {
       var errorString;
       for( var i=0, errorLength = errors.length; i < errorLength; i++){
           errorString += errors[i].message ;
        }
        alert(errorString);
         }
            }); /*  if (errors.length > 0) {
         
                                    var errorString;
                                     alert(errors[errors.length].message);
                            
                                    for (var i = 0, errorLength = errors.length; i < errorLength; i++) {
                                                    errorString += errors[i].message + '<br />';
                                                            }
                                                                                getElementById(DivLogin).innerHTML = errorString;
                                                                                alert(errorString);
                                                                                }       
     
});*/
var projectValidator = new FormValidator('FormProject', [{
name: 'ProjectType',
rules: 'required'
         }, {
           name: 'ProjectName',
          display: 'Project Name',
               rules: 'required'
         }], function(errors, event) {
       if (errors.length > 0) {
       var errorString;
       for( var i=0, errorLength = errors.length; i < errorLength; i++){
           errorString += errors[i].message ;
        }
        alert(errorString);
         }
            }); 
 
