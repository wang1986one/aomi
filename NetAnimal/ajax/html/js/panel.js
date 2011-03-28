function getButton(id, text, num)
{
	return 	'<a href="#" id="'+ id +'" class="ui-state-default ui-corner-all"><span class="ui-icon ui-icon-newwin"></span>'+text+':<b id="num">'+num+'</b></a>';
}


function handle(event)
{
	tms = $("#tms>#num").html() -0;
	if(tms > 0)
	{
		$("#tms>#num").html(tms -1);
		$("#"+event.data.attr('id')+">#num").html($("#"+event.data.attr('id')+">#num").html() -0 +1);
	}
	
}

