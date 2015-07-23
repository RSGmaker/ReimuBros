package;

/**
 * ...
 * @author RSGmaker
 */
class FlagManager
{
	//do not use UInts they just don't work, resort to wasting half the integer(still better than other methods)
	public var data:Array<Int>;
	public function new(size:Int) 
	{
		var i = 0;
		data = new Array<Int>();
		while (i < size)
		{
			data[i] = 0;
			i++;
		}
	}
	public function add(flags:FlagManager)
	{
		var i = 0;
		/*while (data.length > flags.data.length)
		{
			data.remove(data[0]);
		}*/
		while (i < flags.data.length)
		{
			data[i] = data[i] | flags.data[i];
			i++;
		}
	}
	public function copy(flags:FlagManager)
	{
		var i = 0;
		while (data.length > flags.data.length)
		{
			data.remove(data[0]);
		}
		while (i < flags.data.length)
		{
			data[i] = flags.data[i];
			i++;
		}
	}
	public function clone():FlagManager
	{
		var ret = new FlagManager(data.length);
		var i = 0;
		while (i < data.length)
		{
			ret.data[i] = data[i];
			i++;
		}
		return ret;
	}
	//sets all flags to false
	public function clearall()
	{
		var i = 0;
		while (i < data.length)
		{
			data[i] = 0;
			i++;
		}
	}
	public function isempty():Bool
	{
		var currentdata:Int = 0;
		while (currentdata < data.length)
		{
			var dat = data[currentdata];
			if (dat != 0)
			{
				return false;
			}
			currentdata++;
		}
		return true;
	}
	public function getactiveflags():Array<Int>
	{
		var ret = new Array<Int>();
		var currentdata:Int = 0;
		var i = 0;
		var index = 0;
		var cindex = 0;
		while (currentdata < data.length)
		{
			var dat = data[currentdata];
			if (dat & (1 << i) > 0)
			{
				ret[ret.length] = cindex;
			}
			index++;
			cindex++;
			i++;
			if (i > 15)
			{
				i -= 15;
				currentdata++;
				index = 0;
			}
		}
		return ret;
	}
	
	public function get(index:Int):Bool
	{
		var ind:UInt = index;
		//var position = Math.floor(index / 32);
		var position = index >> 4;
		var J = data[position];
		//var i = 1 << (index - (position * 32));
		var i:UInt = 1 << (ind - (position << 4));
		var test = 3 & 1;
		var test2 = 3 & 2;
		var test3 = 3 & 4;
		//var test4 = (2147483648 + 1) & 2147483648;
		if (J & i > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	public function set(index:Int, value:Bool)
	{
		var ind:UInt = index;
		//var position = Math.floor(index / 32);
		var position = index >> 4;
		var J = data[position];
		//var i = 1 << (index - (position * 32));
		var i:UInt = 1 << (ind - (position << 4));
		if (J & i > 0)
		{
			if (!value)
			{
				J -= i;
			}
		}
		else
		{
			if (value)
			{
				//J += i;
				//J = J | i;
				J += i;
			}
		}
		data[position] = J;
	}
	/*public var data:Array<UInt>;
	public function new(size:Int) 
	{
		var i = 0;
		data = new Array<UInt>();
		while (i < size)
		{
			data[i] = 0;
			i++;
		}
	}
	//sets all flags to false
	public function clearall()
	{
		var i = 0;
		while (i < data.length)
		{
			data[i] = 0;
			i++;
		}
	}
	public function isempty():Bool
	{
		var currentdata:Int = 0;
		while (currentdata < data.length)
		{
			var dat = data[currentdata];
			if (dat != 0)
			{
				return false;
			}
			currentdata++;
		}
		return true;
	}
	public function getactiveflags():Array<Int>
	{
		var ret = new Array<Int>();
		var currentdata:Int = 0;
		var i = 0;
		var index = 0;
		var cindex = 0;
		while (currentdata < data.length)
		{
			var dat = data[currentdata];
			if (dat & (1 << i) > 0)
			{
				ret[ret.length] = cindex;
			}
			index++;
			cindex++;
			i++;
			if (i > 31)
			{
				i -= 31;
				currentdata++;
				index = 0;
			}
		}
		return ret;
	}
	
	public function get(index:Int):Bool
	{
		var ind:UInt = index;
		//var position = Math.floor(index / 32);
		var position = index >> 5;
		var J = data[position];
		//var i = 1 << (index - (position * 32));
		var i:UInt = 1 << (ind - (position << 5));
		var test = 3 & 1;
		var test2 = 3 & 2;
		var test3 = 3 & 4;
		//var test4 = (2147483648 + 1) & 2147483648;
		if (J & i > 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	public function set(index:Int, value:Bool)
	{
		var ind:UInt = index;
		//var position = Math.floor(index / 32);
		var position = index >> 5;
		var J = data[position];
		//var i = 1 << (index - (position * 32));
		var i:UInt = 1 << (ind - (position << 5));
		if (J & i > 0)
		{
			if (!value)
			{
				J -= i;
			}
		}
		else
		{
			if (value)
			{
				//J += i;
				//J = J | i;
				J += i;
			}
		}
		data[position] = J;
	}*/
}