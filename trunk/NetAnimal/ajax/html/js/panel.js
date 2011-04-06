


var panelDatas = new Array();



panelDatas["zhuang"] = {id:0, text:'装',num:0, rate:2};
panelDatas["xian"] = {id:1, text:'闲',num:0, rate:2};
panelDatas["he"] = {id:2, text:'和',num:0, rate:8};

panelDatas["red_lion"] = {id:3, text:'红色狮子',num:0, rate:46};
panelDatas["green_lion"] = {id:4, text:'绿色狮子',num:0, rate:40};
panelDatas["yellow_lion"] = {id:5, text:'黄色狮子',num:0, rate:25};

panelDatas["red_panda"] = {id:5, text:'红色熊猫',num:0, rate:23};
panelDatas["green_panda"] = {id:6, text:'绿色熊猫',num:0, rate:20};
panelDatas["yellow_panda"] = {id:7, text:'黄色熊猫',num:0, rate:12};

panelDatas["red_monkey"] = {id:8, text:'红色猴子',num:0, rate:13};
panelDatas["green_monkey"] = {id:9, text:'绿色猴子',num:0, rate:11};
panelDatas["yellow_monkey"] = {id:10, text:'黄色猴子',num:0, rate:7};

panelDatas["red_rabbit"] = {id:11, text:'红色兔子',num:0, rate:8};
panelDatas["green_rabbit"] = {id:12, text:'绿色兔子',num:0, rate:7};
panelDatas["yellow_rabbit"] = {id:13, text:'黄色兔子',num:0, rate:4};


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
		$("#"+key).html('<span class="ui-button-text">'+getText(key)+"</span>");
	} 
}



function getText(id)
{
	return 	'<font  color="0xFF0000">'+ panelDatas[id].rate+'|</font>'+panelDatas[id].text+'<font  color="0xFFFFFF">|'+panelDatas[id].num+"</font>";
}
function getButton(id)
{
	return 	'<a href="#" id="'+ id +'">'+getText(id)+'</a>';
}

function clearButton()
{
	for (var key in panelDatas) { 
		panelDatas[key].num = 0;
	} 
	refushButton();
}
function handle(event)
{
	//alert(event.data.html());
	//alert(panelDatas["red_panda"].foo2);
	
	panelDatas[event.data.attr("id")].num += 1;
	
	if(panelMsg.tms.num > 0)
	{
		panelMsg.tms.num--;
		$("#"+event.data.attr("id")).html('<span class="ui-button-text">'+getText(event.data.attr("id"))+"</span>");
		$("#tms").html('<span class="ui-button-text">'+getMsgText("tms")+"</span>");	
		
	}
	
}

function askPanelData()
{

	for (var key in panelDatas) { 
		QtExecute.answerPanelData(panelDatas[key].id, panelDatas[key].num);
	} 
}

