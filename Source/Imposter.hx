package;

/**
 * ...
 * @author RSGmaker
 */
class Imposter extends Enemy
{

	public var accel:Float;
	
	public var mxspd:Float;
	
	//public var controller:Array<Bool>;
	
	public var rng:MersenneTwister;
	public var rename:String;
	public var frames:Int;
	public var unlock:Int;
	public var have:Bool;
	public var alternate:Bool;
	public var hidden:Bool;
	
	
	public var timer:Int;
	//public var rng:MersenneTwister;
	//whether or not platform is suitable for freezing
	//countdown to platform freeze
	public var countdown:Int;
	public var mxcountdown:Int;
	public var mxtimer:Int;
	//public var myMyon:MyonItem;
	//public var HP = 1;
	public var maxHP = 0;
	
	public function new() 
	{
		//super(main, "RedFairy");
		super("Imposter");
		//this.charname = "RedFairy";
		accel = 0.5;
		deccel = 0.1;
		mxspd = 5;
		Ldir = 1;
		killed = false;
		flipped = -1;
		HP = 0;
		maxHP = 0;
		rename = "reimu";
		frames = 0;
		alternate = false;
		pointvalue = 500;
		mxcountdown = 35;
		//mxtimer = 15;
		countdown = mxcountdown;
		mxtimer = 300;
		//myMyon = null;
	}
	
	/*public override function enrage()
	{
		//accel = 0.7;
		//mxspd = 6;
	}*/
	public override function increaserank()
	{
			accel += 0.1;
			mxspd += 0.5;
			pointvalue += 300;
			mxcountdown -= 5;
			mxtimer -= 60;
			if (mxcountdown < 15)
			{
				mxcountdown = 15;
			}
			if (mxtimer < 150)
			{
				mxtimer = 150;
			}
			timer -= 30;
			if (timer < 0)
			{
				timer = 0;
			}
	}
	public override function update()
	{
		if (rng == null)
		{
			//mxtimer -= rank * 5;
			rng = new MersenneTwister();
			var seed:UInt = Math.floor(UID * 100000);
			rng.seed = seed;
			timer = 60 + mxcountdown + (rng.twist(rng.seed, 1, mxtimer)[0]);
			/*if (game.RoundType == GameView.TypeofRound.Cirno || game.RoundType == GameView.TypeofRound.Nue || game.RoundType == GameView.TypeofRound.Yukari || game.RoundType == GameView.TypeofRound.Seija || game.RoundType == GameView.TypeofRound.Rumia)
			{
				hidden = true;
				if (game.RoundType == GameView.TypeofRound.Cirno)
				{
					rename = "cirno";
					unlock = 4;
				}
				if (game.RoundType == GameView.TypeofRound.Nue)
				{
					rename = "nue";
					unlock = 5;
				}
				if (game.RoundType == GameView.TypeofRound.Seija)
				{
					rename = "seija";
					unlock = 2;
				}
				if (game.RoundType == GameView.TypeofRound.Rumia)
				{
					rename = "rumia";
					unlock = 3;
				}
				if (game.RoundType == GameView.TypeofRound.Yukari)
				{
					var A = rng.twist(rng.seed, 1, 3)[0];
					if (A == 0)
					{
						rename = "yukari";
						unlock = 1;
					}
					if (A == 1)
					{
						rename = "ran";
						unlock = 7;
					}
					if (A == 2)
					{
						rename = "chen";
						unlock = 6;
					}
				}
				have = Main._this.savedata.data.hidden[unlock];
			}
			else*/
			{
				var tmp = game.GetImposterList();
				unlock = rng.twist(rng.seed, 1, tmp.length)[0];
			//unlock = rng.twist(rng.seed, 1, Player.characters.length)[0];
			//unlock = Player.characters.indexOf("orin");
			rename = tmp[unlock];
			unlock = Player.characters.indexOf(rename);
			if (rng.twist(rng.seed, 1, 100)[0] < 30)
			{
				var A = game.AL.GetAnimation(rename+"ALT");
				if (A != null && A.length > 0)
				{
					rename = rename+"ALT";
					alternate = true;
				}
			}
			have = Main._this.savedata.data.unlock[unlock];
			if (!have && alternate)
			{
				have = Main._this.savedata.data.alts[unlock];
			}
			}
			if (((rng.twist(rng.seed, 1, 100)[0]) > 75 || rename=="youmu" || rename=="reimu" || rename == "marisa" || rename == "orin") && spawns<=1 && game.Hoster)
			{
				var D:Dynamic = { };
					D.UID = UID;
				if (rename == "orin" || rng.twist(rng.seed, 1, 100)[0] > 94)
				{
					//game.SendEvent("AttachZombieFairy", UID);
					game.SendEvent("AttachZombieFairy", D);
				}
				else
				{
					//game.SendEvent("AttachMyon", UID);
					game.SendEvent("AttachMyon", D);
				}
				
			}
		}
		if (myMyon != null && maxHP == 0)
		{
			maxHP = 1;
			HP = 1;
		}
		var active = false;
		if (rank>0 && flipped < 1)
		{
			if (timer > 0)
			{
				timer--;
			}
			else
			{
				if (x > 0 && x < 760 && ground != null)
				{
				if (countdown > 0)
				{
					countdown--;
					active = true;
				}
				else
				{
					countdown = mxcountdown;
					timer = 60 + mxcountdown + (rng.twist(rng.seed, 1, mxtimer)[0]);
					if (game.Hoster)
					{
						var P = nearestplayer();
						
						var D:Dynamic = { };
						D.x = x;
						D.y = y;
						D.gravX = 0;
						D.gravY = 0;
						D.image = "bullet";
						//var degradian = Math.atan2(y, x) - Math.atan2(P.y, P.x);
						var degradian = Math.atan2((P.y + (30))-y, P.x-x);
						D.Hspeed = Math.cos(degradian) * 6;
						D.Vspeed = Math.sin(degradian) * 6;
						game.SendEvent("ShootBullet", D);
					}
				}
				 }
				//timer = 90 + (rng.twist(rng.seed, 1, 300)[0]);
				//game.Hoster
			}
		}
		else
		{
			countdown = mxcountdown;
		}
		frames++;
		var S = rename;
		visuallyEnraged = false;
		if (active && frames & 1 < 1)
		{
			//S = S + "E";
			if (enraged)
			{
				S = S + "S";
			}
			else
			{
				visuallyEnraged = true;
			}
			Hspeed = 0;
		}
		else if (frames & 1 > 0 && !have)
		{
			//enraged = !enraged;
			S = S + "U";
		}
		else if (have)
		{
			S = S + "U";
		}
		enraged = false;
		
		//y += 1;
		if (!killed)
		{
		var dir = Ldir;
		if (flipped > 0)
		{
			flipped -= 1;
			dangerous = false;
			if (flipped == 0)
			{
				flipped = -1;
				powerup();
			}
		}
		else
		{
			dangerous = true;
		}
		if (!active)
		{
		if (Hspeed < mxspd && dir==1 && flipped < 1)
		{
			Hspeed += accel;
			if (Hspeed > mxspd)
			{
				Hspeed = mxspd;
			}
		}
		if (Hspeed > -mxspd && dir==-1 && flipped < 1)
		{
			Hspeed -= accel;
			if (Hspeed < -mxspd)
			{
				Hspeed = -mxspd;
			}
		}
		}
		var F = flipped;
		flipped = 0;
		updphysics();
		//updateanimation(rename);
		updateanimation(S);
		flipped = F;
		if (flipped > 0)
		{
			this.rotation = 90;
			/*if (Hspeed > 0)
			{
				this.rotationZ = 270;
			}
			else if (Hspeed<0)
			{
				this.rotationZ = 90;
			}
			else if (this.rotationZ == 0)
			{
				this.rotationZ = 180;
			}*/
		}
		else
		{
			this.rotation = 0;
		}
		this.scaleX = 0.8;
		this.scaleY = 0.8;
		if (ground != null)
		{
			//if (ground.bonked > -1000 && game.Hoster && game.myplayer == ground.bonkedby)
			if (ground.bonked > -1000 && Vspeed>=0)
			{
				//if (game.ismyplayer(ground.bonkedby) && game.Hoster)
				if (game.myplayer == ground.bonkedby)
				{
				//Vspeed = -4;
				//flipped = 30 * 10;
				var D:Dynamic = { };
				D.UID = UID;
				D.x = x;
				D.y = y;
				D.Hspeed = Hspeed;
				D.Vspeed = -10;
				//game.SendEvent("Bump", this.UID);
				game.SendEvent("Bump", D);
				}
			}
			else
			{
				//if ((controller[1]) && Vspeed == 0)
				if (flipped>0 && flipped < 60)
				{
					//bounce to indicate about to recover
					Vspeed = -4;
					HP = 0;
					//Vspeed = -13;
				}
			}
			
		}
			if ((y > 408 && wrapped) || y>800)
			{
				alive = false;
				visible = false;
			}
		killable = flipped > 0;
	}
	else
	{
		y += 15;
	if (y > 600)
	{
	alive = false;
	}
	}
	}
	public override function bump()
	{
		//Vspeed = -4;
		if (HP > 0)
		{
			HP--;
		}
		else
		{
		if (flipped < 1)
		{
			if (enraged)
			{
				flipped = 30 * 4;
			}
			else
			{
				flipped = 30 * 7;
			}
		}
		else
		{
			flipped = 0;
			HP = 0;
		}
		}
	}
	
}