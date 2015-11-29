package;
import openfl.geom.Point;

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
	public var flipped:Int;
	//whether or not the enemy has augmented abilities(the last enemy of the round gets this)
	public var enraged:Bool;
	//makes enemy red without messing with stats.
	public var visuallyEnraged:Bool;
	public var reward:Bool;
	public var rewarditem:String = "Point";
	public var pointvalue:Int;
	///whether or not if this enemy doesnt go back to spawnlist
	public var respawn:Bool;
	
	//the base rank is the difficulty rank of the game(every 30 levels=1 rank), enemy rank can 2 higher than the base rank.
	public var rank:Int;
	
	public var HP:Int;
	public var started:Bool;
	//the rank currently applied, used for detecting changes to rank and adding the stats
	private var currentrank:Int;
	public var spawns:Int;
	public var needtokill:Bool;
	//if false, the system won't send enrage messages.
	public var enrageable:Bool = true;
	//makes enemy flicker red.
	public var doingability:Bool = false;
	//used during flicker
	private var lastabilityframe:Bool = false;
	//if true customspawn is called and its coordinates are applied on spawn.
	public var hascustomspawn:Bool = false;
	//if false they use "dropped" instead of "flipped", which keeps them from pulling an expression, when flipped.
	public var expressive:Bool = true;
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
		HP = -1;
		started = false;
		rank = game.rank;
		currentrank = 0;
		visuallyEnraged = false;
		spawns = 0;
		needtokill = true;
		removeonlevelend = true;
	}
	public function customspawn():Dynamic
	{
		var ret:Dynamic = { };
		return ret;
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
	//when a player touches the enemy when it isnt dangerous(vulnerable)
	public function kick()
	{
		game.SendEvent("Kill", UID);
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
			if (expressive)
			{
				C = C + "flipped";
			}
			else
			{
				C = C + "dropped";
			}
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
		var en = 0;
		if (enr)
		{
			en++;
		}
		if (doingability && !lastabilityframe)
		{
			en++;
		}
		if (en == 1)
		{
			C = C + "E";
		}
		else if (en == 2)
		{
			C = C + "]";
		}
		/*if (!doingability || !lastabilityframe)
		{
		if (enr)
		{
			C = C + "E";
		}
		}
		else if (doingability)
		{
			C = C + "]";
		}*/
		if (doingability)
		{
			lastabilityframe = !lastabilityframe;
		}
		else
		{
			lastabilityframe = false;
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