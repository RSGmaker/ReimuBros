package;
import openfl.display.Sprite;

/**
 * ...
 * @author RSGmaker
 */
class Menu extends Sprite
{
	public var rows:Array<Array<MenuButton>>;
	public var menuwidth:Float=0;
	public var menuheight:Float = 0;
	public var menuoffsetx:Float = 0;
	public var menuoffsety:Float = 0;
	public function new() 
	{
		super();
		rows = new Array<Array<MenuButton>>();
	}
	private function updaterow(index:Int,Y:Float)
	{
		var row = rows[index];
		var X = (menuwidth / (row.length + 1));
		var i = 0;
		var CX = X;
		
		
		CX += menuoffsetx;
		while (i < row.length)
		{
			var M = row[i];
			M.x += CX;
			M.y += Y;
			addChild(M);
			CX += X;
			i++;
		}
	}
	public function addrow():Array<MenuButton>
	{
		var ret = new Array<MenuButton>();
		rows.push(ret);
		return ret;
	}
	public function addbutton(M:MenuButton,row:Int=-1)
	{
		if (rows.length == 0)
		{
			addrow();
		}
		if (row == -1)
		{
			row = rows.length - 1;
		}
		rows[row].push(M);
	}
	public function breakup(totalrows:Int)
	{
		var R = rows[0];
		rows = new Array<Array<MenuButton>>();
		var T:Float = totalrows;
		var C = Math.ceil(R.length / T);
		var i = 0;
		var j = 0;
		var row = addrow();
		while (i < R.length)
		{
			if (row.length >= C)
			{
				row = addrow();
			}
			addbutton(R[i]);
			i++;
		}
	}
	public function finish(totalrows:Int=-1)
	{
		if (totalrows > 0)
		{
			breakup(totalrows);
		}
		var Y:Float = 0;
		var CY:Float = 0;
		//if (false)
		if (totalrows > 0 && rows.length<totalrows)
		{
			Y = (menuheight / (rows.length + 1));
			CY = Y;
		}
		else
		{
			Y = (menuheight / (rows.length));
			CY = 0;
		}
		
		CY += menuoffsety;
		var i = 0;
		while (i < rows.length)
		{
			updaterow(i, CY);
			CY += Y;
			i++;
		}
	}
}