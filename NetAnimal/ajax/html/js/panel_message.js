

var panelMsg = new Array();


panelMsg["yl"] = {text:'盈利',num:0};
panelMsg["time"] = {text:'倒计时',num:30};
panelMsg["tms"] = {text:'台面数',num:1000};

function getMsgText(id)
{
	return 	panelMsg[id].text+':'+panelMsg[id].num;
}
function getMsg(id)
{
	return 	'<a href="#" id="'+ id +'">'+getMsgText(id)+'</a>';
}

function refushMsgButton()
{
	for (var key in panelMsg) { 
		$("#"+key).html('<span class="ui-button-text">'+getMsgText(key)+"</span>");
	} 
}


function setYL(num)
{
	panelMsg.yl.num = num;
	refushMsgButton();
}
function getYL() {
    return panelMsg.yl.num;
}
function setAll(yl, time, tms)
{
	panelMsg.yl.num = num;
	panelMsg.time.num = time;
	panelMsg.tms.num = tms;
	refushMsgButton();
}
var isRolling = false;
function roll()
{
	if(isRolling && panelMsg.yl.num > 0)
	{
		panelMsg.yl.num --;
		panelMsg.tms.num ++;
		setTimeout('roll()', 10);
		refushMsgButton();
	}else
	{
		isRolling = false;	
	}
}
function stopRoll()
{
	isRolling = false;
	panelMsg.tms.num += panelMsg.yl.num;
	panelMsg.yl.num = 0;
	refushMsgButton();
	
}
function startRoll()
{
	isRolling = true;
	roll();
}


function setTheTime(time)
{
	panelMsg.time.num = time;
	refushMsgButton();
}




function setupMsgButton()
{
	for (var key in panelMsg) { 
		$( "#" + key, ".demo" ).button();
	} 
}



