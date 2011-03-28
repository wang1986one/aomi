

var panelMsg = new Array();


function getMsgText(id)
{
	return 	panelMsg[id].text+':'+panelMsg[id].num;
}
function getMsg(id)
{
	return 	'<a href="#" id="'+ id +'">'+getMsgText(id)+'</a>';
}



panelMsg["yl"] = {text:'盈利',num:0};
panelMsg["time"] = {text:'倒计时',num:30};
panelMsg["tms"] = {text:'台面数',num:1000};


