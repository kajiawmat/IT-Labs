var Delay=200;
var Interval=25;
var flag=1;
var Name="Senku_1_";
var Exp=".gif";
var i=1;
var idTimer;
function Start()
{
	flag=1;
	clearTimeout(idTimer);
	Anim();
}

function Anim()
{
	idTimer=setTimeout('Swap()', Delay);
}

function Swap()
{
	if(flag==1)
	{
		document.Senku.src=Name+i+Exp;
		i=i%6+1;
	}
}

function Faster()
{
	if(Delay>100)
	{
		Delay-=Interval;
	}
}

function Slower()
{
	if(Delay<400)
	{
		Delay+=Interval;
	}
}

function Stop()
{
	flag=0;
}