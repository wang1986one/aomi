
function run()
{
	setTimeout('run()', 20);
	update();
}

function update()
{
	
}

var panelDatas = new Array();



panelDatas["zhuang"] = {id:0, text:'装',num:0, rate:2, profit: -1
,image:'<img src="./icon/zhuang.png" width="40" height="40" longdesc="">' };
panelDatas["xian"] = { id: 1, text: '闲', num: 0, rate: 2, profit: -1 
,image:'<img src="./icon/xian.png" width="40" height="40" longdesc="">' };
panelDatas["he"] = { id: 2, text: '和', num: 0, rate: 8, profit: -1 
,image:'<img src="./icon/he.png" width="40" height="40" longdesc="">' };

panelDatas["red_lion"] = { id: 3, text: '红色狮子', num: 0, rate: 46, profit: -1
,image:'<img src="./icon/lion_red.png" width="40" height="40" longdesc="">' };
panelDatas["green_lion"] = { id: 4, text: '绿色狮子', num: 0, rate: 40, profit: -1 
,image:'<img src="./icon/lion_green.png" width="40" height="40" longdesc="">' };
panelDatas["yellow_lion"] = { id: 5, text: '黄色狮子', num: 0, rate: 25, profit: -1 
,image:'<img src="./icon/lion_yellow.png" width="40" height="40" longdesc="">' };

panelDatas["red_panda"] = { id: 5, text: '红色熊猫', num: 0, rate: 23, profit: -1 
,image:'<img src="./icon/panda_red.png" width="40" height="40" longdesc="">' };
panelDatas["green_panda"] = { id: 6, text: '绿色熊猫', num: 0, rate: 20, profit: -1 
,image:'<img src="./icon/panda_green.png" width="40" height="40" longdesc="">' };
panelDatas["yellow_panda"] = { id: 7, text: '黄色熊猫', num: 0, rate: 12, profit: -1 
,image:'<img src="./icon/panda_yellow.png" width="40" height="40" longdesc="">' };

panelDatas["red_monkey"] = { id: 8, text: '红色猴子', num: 0, rate: 13, profit: -1  
,image:'<img src="./icon/monkey_red.png" width="40" height="40" longdesc="">' };
panelDatas["green_monkey"] = { id: 9, text: '绿色猴子', num: 0, rate: 11, profit: -1  
,image:'<img src="./icon/monkey_green.png" width="40" height="40" longdesc="">' };
panelDatas["yellow_monkey"] = { id: 10, text: '黄色猴子', num: 0, rate: 7, profit: -1  
,image:'<img src="./icon/monkey_yellow.png" width="40" height="40" longdesc="">' };

panelDatas["red_rabbit"] = { id: 11, text: '红色兔子', num: 0, rate: 8, profit: -1   
,image:'<img src="./icon/rabblt_red.png" width="40" height="40" longdesc="">'};
panelDatas["green_rabbit"] = { id: 12, text: '绿色兔子', num: 0, rate: 7, profit: -1   
,image:'<img src="./icon/rabblt_green.png" width="40" height="40" longdesc="">'};
panelDatas["yellow_rabbit"] = { id: 13, text: '黄色兔子', num: 0, rate: 4, profit: -1   
,image:'<img src="./icon/rabblt_yellow.png" width="40" height="40" longdesc="">'};

var allTime = 0;
var light = true;
var flashing = false;
var bMarkBegin = false;


function setupButton()
{
	for (var key in panelDatas) { 
		$( "#" + key, ".demo" ).button();
	}
}
function enableButton()
{	
	
	bMarkBegin = true;
	for (var key in panelDatas) { 
		$( "#" + key, ".demo" ).button("enable");
		$( "#" + key, ".demo" ).bind("click", $("#" + key), handle);
	}
}


function lightButton(key, state) {

    $("#" + key).html('<span class="ui-button-text">' + getText(key, state) + "</span>");
      
}
function flashingButton() {

    for (var key in panelDatas) {
        if (panelDatas[key].profit > 0) {
            if (light)
                lightButton(key, 1);
            else {
                lightButton(key, 0);
            }

        } else if (panelDatas[key].profit == 0) {
            if (light)
                $("#" + key, ".demo").button("disable");
            else {
                $("#" + key, ".demo").button("enable");
            }

        }


    }
    if (flashing) {
        setTimeout('flashingButton()', 100);
    }else
    {
       disableButton();
    }
}
function flashButton() {
    for (var key in panelDatas) {
        if (panelDatas[key].profit == -1) {
            continue;
        } else {
        $("#" + key, ".demo").button("enable");
        setYL(getYL() + panelDatas[key].profit)
        }
    }
    flashing = true;
    setTimeout('flashingButton()', 100);
   
}
function disableButton()
{
	bMarkBegin = false;
	for (var key in panelDatas) { 
		$( "#" + key, ".demo" ).button("disable");
		$( "#" + key, ".demo" ).unbind("click");
	} 
	
}


function refushButton()
{
	for (var key in panelDatas) {
	    $("#" + key).html(getText(key, 0) );
	 //	$("#" + key).html(  panelDatas[key].image);
	} 
}


function tText(id, color1, color2, color3) {

    return "<font  color='" + color1 + "'>" + panelDatas[id].rate + panelDatas[id].image + "<font  color='"+color3+"'>" 
	+ panelDatas[id].num + "</font>";
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
	
	_json_data = 123;
	_upload_data = true;
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
//bin.wang 2011.04.17
function setMarkNum(id) 
{
	if(bMarkBegin)
	{
    panelDatas[id].num += 1;
  	if(panelMsg.tms.num > 0)
		{
			panelMsg.tms.num--;
			$("#" + id).html('<span class="ui-button-text">' + getText(id, 0) + "</span>");
			$("#tms").html('<span class="ui-button-text">'+getMsgText("tms")+"</span>");	
		
		}
	}
}

function setState(state) {

    switch(state){
    case 0:
        
    break;
    case 1:
        flashButton();
    break;
    case 2:
        //startRoll();
    break;
//    case 3:
//        flashing = false;
//        stopRoll();
//        clearButton();
    break; 
    }
}