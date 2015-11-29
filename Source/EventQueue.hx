package;

/**
 * ...
 * @author RSGmaker
 */
class EventQueue
{
	public var event:String;
	public var data:Dynamic;
	public var PlayerID:String;
	public var timer:Int;
	//whether or not if this message should be processed directly or sent.
	public var clientside:Bool=true;
	
	public var alive:Bool = true;
	public function new(event:String,data:Dynamic,PlayerID:String,timer:Int=15) 
	{
		this.event = event;
		this.data = data;
		this.PlayerID = PlayerID;
		this.timer = timer;
	}
	public function update()
	{
		if (alive)
		{
			timer--;
			if (timer < 1)
			{
				alive = false;
				if (clientside)
				{
					GameView._this.ProcessEvent(event, PlayerID, data);
				}
				else if (GameView._this.Hoster)
				{
					GameView._this.SendEvent(event, data);
				}
			}
		}
	}
}