function SetCookie(name, value, year, month, day)
{
	var date_exp = new Date(year,month,day);
	document.cookie=name+"="+escape(value)+"; expires="+date_exp.toGMTString()+";";
}

function GetCookie(name)
{
	var search = name + "=";
	if (document.cookie.length > 0) {
		var offset = document.cookie.indexOf(search)
		if (offset != -1) {
			offset += search.length
			var end = document.cookie.indexOf(";", offset)
			if (end == -1)
				end = document.cookie.length
			return unescape(document.cookie.substring(offset, end))
		}
	}
}

function Check_Cookie(cookie_name)
{
	if(document.cookie.match ( '(^|;) ?' + cookie_name + '=([^;]*)(;|$)' )) return 1;
	else return 0;
}

var limit_return=5;
var cookie_data;
var cookie_username;
var cookie_return;

if(Check_Cookie("username")==0)
{
	var username;
	var msg="Давай познакомимся! Как Вас зовут?";
	username=prompt(msg);
	SetCookie("username",username,2021,10,27);
	SetCookie("return",0,2021,10,27);
	var date = new Date();
	SetCookie("date",date.toGMTString(),2021,10,27);
}

cookie_username=GetCookie("username");
cookie_return=eval(GetCookie("return"));
cookie_data=GetCookie("date");
SetCookie("return",(cookie_return+1),2021,10,27);
var date = new Date();
SetCookie("date",date.toGMTString(),2021,10,27);
document.write("<h1>Cookie</h1>");
document.write("Привет, "+cookie_username+"<BR>");
if(cookie_return>limit_return)
{
	document.write("Количество посещений этой страницы: <spin class='bg'>"+cookie_return+"</spin><br>");
}
else
{
	document.write("Количество посещений этой страницы: <spin>"+cookie_return+"</spin><br>");
}
document.write("Вы были на этой странице: "+cookie_data+"<BR>");