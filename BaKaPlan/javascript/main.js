$(document).ready(function () {
		$('#myPicker').timepicker(
			{
			'step': '20',
			'minTime': '9:00am',
			'maxTime': '12:00pm',
			'timeFormat': 'H:i:s',
			}
		);	

		$('#myTimepicker').on('changeTime', function() {
			$('#mySpan').text($(this).val());
		});		
});