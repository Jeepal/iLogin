(function($){


if( window.opener ) {
	window.close(window.self);
	window.opener.location.reload();
}

$(document).ready(function(){

	$('a.ilogin').click(function(){
		var href = $(this).attr('link');
		var top=(document.body.clientHeight-420)/2;
		var left=(document.body.clientWidth-520)/2;

		window.open(href,'ilogin_window', 'height=420, width=560, toolbar =no, menubar=no, scrollbars=yes, resizable=no,top='+top+',left='+left+', location=no, status=no');
	});

});

})(jQuery);