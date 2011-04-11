


var panelDatas = new Array();



panelDatas["zhuang"] = {id:0, text:'装',num:0, rate:2, profit: -1};
panelDatas["xian"] = { id: 1, text: '闲', num: 0, rate: 2, profit: -1 };
panelDatas["he"] = { id: 2, text: '和', num: 0, rate: 8, profit: -1 };

panelDatas["red_lion"] = { id: 3, text: '红色狮子', num: 0, rate: 46, profit: -1 };
panelDatas["green_lion"] = { id: 4, text: '绿色狮子', num: 0, rate: 40, profit: -1 };
panelDatas["yellow_lion"] = { id: 5, text: '黄色狮子', num: 0, rate: 25, profit: -1 };

panelDatas["red_panda"] = { id: 5, text: '红色熊猫', num: 0, rate: 23, profit: -1 };
panelDatas["green_panda"] = { id: 6, text: '绿色熊猫', num: 0, rate: 20, profit: -1 };
panelDatas["yellow_panda"] = { id: 7, text: '黄色熊猫', num: 0, rate: 12, profit: -1 };

panelDatas["red_monkey"] = { id: 8, text: '红色猴子', num: 0, rate: 13, profit: -1 };
panelDatas["green_monkey"] = { id: 9, text: '绿色猴子', num: 0, rate: 11, profit: -1 };
panelDatas["yellow_monkey"] = { id: 10, text: '黄色猴子', num: 0, rate: 7, profit: -1 };

panelDatas["red_rabbit"] = { id: 11, text: '红色兔子', num: 0, rate: 8, profit: -1 };
panelDatas["green_rabbit"] = { id: 12, text: '绿色兔子', num: 0, rate: 7, profit: -1 };
panelDatas["yellow_rabbit"] = { id: 13, text: '黄色兔子', num: 0, rate: 4, profit: -1 };


function setupButton()
{
	for (var key in panelDatas) { 
		$( "#" + key, ".demo" ).button();
	} 
}
function enableButton()
{
	for (var key in panelDatas) { 
		$( "#" + key, ".demo" ).button("enable");
		$( "#" + key, ".demo" ).bind("click", $("#" + key), handle);
	}
}


var allTime = 0;
var light = true;

function lightButton(key, state) {

    $("#" + key).html('<span class="ui-button-text">' + getText(key, state) + "</span>");
      
}
function flashingButton() {

    for (var key in panelDatas) {
        if (panelDatas[key].profit == 0) {
            if (light)
                lightButton(key, 2);
            else {
                lightButton(key, 0);
            }

        } 
        if (panelDatas[key].profit > 0) {
            if (light)
                lightButton(key, 1);
            else {
                lightButton(key, 0);
            }

        }


    }
    light = !light;
    allTime -= 100;
    if (allTime > 0) {
        setTimeout('flashingButton()', 100);
    } 
}
function flashButton() {
    for (var key in panelDatas) {
        if (panelDatas[key].profit == -1) {
            continue;
        } else {
        $("#" + key, ".demo").button("enable");
       
        }
    }
    allTime = 1000;
    setTimeout('flashingButton()', 100);
}
function disableButton()
{
	for (var key in panelDatas) { 
		$( "#" + key, ".demo" ).button("disable");
		$( "#" + key, ".demo" ).unbind("click");
	} 
	
}


function refushButton()
{
	for (var key in panelDatas) {
	    $("#" + key).html('<span class="ui-button-text">' + getText(key, 0) + "</span>");
	} 
}


function tText(id, color1, color2, color3) {

    return "<font  color='" + color1 + "'>" + panelDatas[id].rate + "</font> <font  color='black'>|</font> <font  color='" + color2 + "'>" + panelDatas[id].text + "</font> <font  color='black'>|</font><font  color='"+color3+"'>" + panelDatas[id].num + "</font>";
}
function getText(id, state) {
    if (state == 1)
        return tText(id, "red", "red", "red");
    if (state == 2)
        return tText(id, "red", "black", "blue");
//
    return tText(id, "green", "black", "blue");
}
function getButton(id)
{
	return 	'<a href="#" id="'+ id +'">'+getText(id, 0)+'</a>';
}

function clearButton()
{
	for (var key in panelDatas) {
	    panelDatas[key].num = 0;
	    panelDatas[key].profit = -1;
	} 
	refushButton();
}
function handle(event)
{
	
	panelDatas[event.data.attr("id")].num += 1;
	
	if(panelMsg.tms.num > 0)
	{
		panelMsg.tms.num--;
		$("#" + event.data.attr("id")).html('<span class="ui-button-text">' + getText(event.data.attr("id"), 0) + "</span>");
		$("#tms").html('<span class="ui-button-text">'+getMsgText("tms")+"</span>");	
		
	}
	
}

function askPanelData()
{
    for (var key in panelDatas) {
        if (panelDatas[key].num != 0 )
		    QtExecute.answerPanelData(panelDatas[key].id, panelDatas[key].num);
	} 
}

function setWinner(id, profit) 
{
    panelDatas[id].profit = profit;
}