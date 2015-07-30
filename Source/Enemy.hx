package;

/**
 * ...
 * @author RSGmaker
 */
class Enemy extends Entity
{
	//if actually dead, if not then the enemy should reappear at the top later.
	
	///whether or not a player touching the enemy will set killed to true.
	public var killable:Bool;
	public var charname:String;
	private var flipped:Int;
	//whether or not the enemy has augmented abilities(the last enemy of the round gets this)
	public var enraged:Bool;
	//makes enemy red without messing with stats.
	public var visuallyEnraged:Bool;
	public var reward:Bool;
	public var rewarditem:String = "Point";
	public var pointvalue:Int;
	///whether or not if this enemy doesnt go back to spawnlist
	public var respawn:Bool;
	
	//the difficulty of the game, every 30 levels it increases by 1.
	public var rank:Int;
	
	public var HP:Int;
	public var started:Bool;
	//the rank currently applied, used for detecting changes to rank and adding the stats
	private var currentrank:Int;
	public var spawns:Int;
	public var needtokill:Bool;
	public function new(ani:String) 
	{
		super(ani);
		type = "Enemy";
		killable = false;
		charname = ani;
		flipped = -1;
		touchable = true;
		reward = true;
		pointvalue = 100;
		respawn = true;
		HP = 0;
		started = false;
		rank = game.rank;
		currentrank = 0;
		visuallyEnraged = false;
		spawns = 0;
		needtokill = true;
	}
	public function getdangerlevel():Int
	{
		return rank;
	}
	//damage this enemy, function should return if the enemy should die now.
	public function attack():Bool
	{
		return invincibility <= 0;
	}
	//call this when enemy recovers from being flipped
	public function powerup()
	{
		if (rank < game.rank + 2)
		{
			rank++;
		}
	}
	public function increaserank()
	{
		
	}
	public function setrank(r:Int)
	{
		r = r - currentrank;
		while (r > 0)
		{
			//apply stats
			increaserank();
			
			r--;
			currentrank++;
		}
		rank = currentrank;
	}
	public function enrage()
	{
		if (rank < game.rank + 2)
		{
			rank = game.rank + 2;
		}
	}
	public function updateanimation(name:String="")
	{
		if (name == "")
		{
			name = charname;
		}
		if (currentrank < rank)
		{
			setrank(rank);
		}
		if (rank < game.rank)
		{
			rank = game.rank;
		}
		var C = name;
		if (flipped >= 1)
		{
			C = C + "flipped";
		}
		var enr = visuallyEnraged || enraged;
		if (rank == game.rank+1)
		{
			if (!enr)
			{
				C = C + "S";
			}
		}
		if (rank > game.rank+1)
		{
			enraged = true;
			enr = true;
		}
		if (enr)
		{
			C = C + "E";
		}
		if (Ldir > 0)
		{
			ChangeAnimation(C,false);
		}
		if (Ldir < 0)
		{
			ChangeAnimation(C+"F",false);
		}
	}
	
}