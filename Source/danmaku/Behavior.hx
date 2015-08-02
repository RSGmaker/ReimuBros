package danmaku;
import haxe.Serializer;
import haxe.Unserializer;
//import haxe.ds.IntMap;
//import haxe.ds.HashMap;

enum BehaviorType
{
	//sets entities alive to false and release DanmakuBullets in 8 directions.
	StarDanmakuBulletExplosion;
	//rotating/spiraling DanmakuBullet will reverse rotation rate.
	ReverseDanmakuBulletRotation;
	//change entities image to data.animation
	AnimationChange;
	//sets alive to false on activation.
	Die;
	//add data.accel to HSpeed until data.maxspeed is reached. after it is reached runonce/repeatdelay is checked.
	HorizontalAccel;
	VerticalAccel;
	//set _this.behaviorqueue to data.queue(this is used for looping behaviors
	SetQueue;
	//releases 1 DanmakuBullet at _this.x/y
	ShootDanmakuBullet;
	//same as shootDanmakuBullet but angle is calculated from nearestplayer location
	ShootPlayerAimedDanmakuBullet;
	//add/subtract data.accel to HSpeed until data.maxspeed(or negative) is reached. after it is reached it waits until data.x then runonce/repeatdelay is checked.
	MoveToX;
	MoveToY;
	//subtracts data.scalerate from _this.scaleX/Y until <= 0 then sets alive to false
	ShrinkIntoOblivion;
}
/**
 * ...
 * @author RSGmaker
 */
class Behavior
{

	//delay until behavior activates
	public var delay:Int;
	public var active:Bool;
	//if true, active will become false after delay hits 0 and behavior runs once.
	//public var runonce:Bool;
	//if true runcount will decrement every successful behavior update and when runcount is <=0, active=false
	public var perishable:Bool;
	public var runcount:Int;
	//if in a queue run count sets back to maxruncount instead of going inactive.
	public var maxruncount:Int;
	//used for additional info eg;change sprite may use data.image to specify what to change to.(do not edit data within update() as cloning the data might not be possible)
	public var data:Dynamic;
	public var type:BehaviorType;
	//after running behavior the delay is set to this value.
	public var repeatdelay:Int;
	public var state:Dynamic;
	//set _this.alive to false after successful run.
	public var deathoncomplete:Bool;
	//what _this.behaviorqueue must be in order to run(if 0 then always run)
	public var queue:Int;
	//whether or not to progress queue on successful run.
	public var progressqueue:Bool;
	//if perishable is true and rechargetime is >=0 then instead of deactivating delay will become rechargetime instead.
	public var rechargetime:Int;
	
	
	public function new(type:BehaviorType) 
	{
		this.type = type;
		active = true;
		delay = 0;
		//runonce = false;
		perishable = false;
		runcount = 1;
		data = { };
		repeatdelay = 0;
		state = null;
		deathoncomplete = false;
		queue = 0;
		progressqueue = true;
		maxruncount = -1;
		rechargetime = -1;
	}
	public function clone(dataclone:Bool=true):Behavior
	{
		var B = new Behavior(type);
		B.active = active;
		if (data != null)
		{
			B.data = data;
			
			if (dataclone)
			{
				//clone data...although a performance hit it allows data to be somewhat separate for each DanmakuEntity meaning changing data info is safer
				//less slow than other methods but still something to be wary of...
				B.data = shallowCopy(data);
				//copy is even slower...
				//B.data = copy(data);
				//serializer is slow as hell...
				//B.data = Unserializer.run(Serializer.run(data));
			}
			
		}
		//B.data = deepCopy( data);
		B.delay = delay;
		B.repeatdelay = repeatdelay;
		//B.runonce = runonce;
		B.perishable = perishable;
		B.runcount = runcount;
		B.deathoncomplete = deathoncomplete;
		B.queue = queue;
		B.progressqueue = progressqueue;
		B.maxruncount = maxruncount;
		B.rechargetime = rechargetime;
		//B.type = type;(redundant)
		return B;
	}
	public static function shallowCopy( v:Dynamic ) : Dynamic
  {
	  //if( Type.getClass(v) == null ) // anonymous object
    {
      var obj : Dynamic = { };
	  
    for( ff in Reflect.fields(v) )
      Reflect.setField(obj, ff, Reflect.field(v, ff));
      return obj;
    }
	return null;
  }
	/**
    deep copy of anything
   **/
  /*public static function deepCopy<T>( v:T ) : T
  {
    if (!Reflect.isObject(v)) // simple type
    {
      return v;
    }
    else if( Std.is( v, Array ) ) // array
    {
      var r = Type.createInstance(Type.getClass(v), []);
      untyped
      {
    for( ii in 0...v.length )
      r.push(deepCopy(v[ii]));
      }
      return r;
    }
    else if( Type.getClass(v) == null ) // anonymous object
    {
      var obj : Dynamic = {};
    for( ff in Reflect.fields(v) )
      Reflect.setField(obj, ff, deepCopy(Reflect.field(v, ff)));
      return obj;
    }
    else // class
    {
      var obj = Type.createEmptyInstance(Type.getClass(v));
    for( ff in Reflect.fields(v) )
      Reflect.setField(obj, ff, deepCopy(Reflect.field(v, ff)));
      return obj;
    }
    return null;
  }*/
  /** 
	 * Deep copy of anything using reflection (so don't hope for much performance)
	**/ 
	/*public static function copy<T>( v:T ) : T  { 
		if (!Reflect.isObject(v)) { // simple type 
			return v; 
		}
		else if (Std.is(v, String)) { // string
			return v;
		}
		else if(Std.is( v, Array )) { // array 
			var result = Type.createInstance(Type.getClass(v), []); 
			untyped { 
				for( ii in 0...v.length ) {
					result.push(copy(v[ii]));
				}
			} 
			return result;
		}
		else if(Std.is( v, Map )) { // hashmap
			var result = Type.createInstance(Type.getClass(v), []);
			untyped {
				var keys : Iterator<String> = v.keys();
				for( key in keys ) {
					result.set(key, copy(v.get(key)));
				}
			} 
			return result;
		}
		else if(Std.is( v, List )) { // list
			//List would be copied just fine without this special case, but I want to avoid going recursive
			var result = Type.createInstance(Type.getClass(v), []);
			untyped {
				var iter : Iterator<Dynamic> = v.iterator();
				for( ii in iter ) {
					result.add(ii);
				}
			} 
			return result; 
		}
		else if(Type.getClass(v) == null) { // anonymous object 
			var obj : Dynamic = {}; 
			for( ff in Reflect.fields(v) ) { 
				Reflect.setField(obj, ff, copy(Reflect.field(v, ff))); 
			}
			return obj; 
		} 
		else { // class 
			var obj = Type.createEmptyInstance(Type.getClass(v)); 
			for(ff in Reflect.fields(v)) {
				Reflect.setField(obj, ff, copy(Reflect.field(v, ff))); 
			}
			return obj; 
		} 
		return null; 
	}*/

	public function update(_this:DanmakuEntity)
	{
		if (!active || (queue != 0 && _this.behaviorqueue != queue))
		{
			return;
		}
		if (delay>0)
		{
			delay--;
			return;
		}
		if (maxruncount == -1)
		{
			maxruncount = runcount;
		}
		var done = false;
		switch (type)
		{
			case BehaviorType.AnimationChange:
				_this.image.ChangeAnimation(GameView._this.AL.GetAnimation(data.animation));
				done = true;
				//active = false;
			case BehaviorType.ReverseDanmakuBulletRotation:
				var D:Dynamic = _this;
				D.rotrate = -D.rotrate;
				done = true;
			case BehaviorType.StarDanmakuBulletExplosion:
				//var R = 0.04;
					var S = data.spiral;
					//_this.alive = false;
					var A = GameView._this.AL.GetAnimation(data.animation);
					var i = 0;
					//6.283185
					//the max angle of radian is pi*2(6.283185)
					//t = (pi*2)/8
					var t = 0.785398125;
					var angle = data.angle;
					while (i < 8)
					{
						var B:DanmakuBullet = new DanmakuBullet();
						B.x = _this.x;
						B.y = _this.y;
						B.Vspeed = data.speed;
						B.changeangle(angle);
						angle += t;
						//angle += 0.002;
						B.image.ChangeAnimation(A);
						B.rotrate = data.rotrate;
						B.spiral = S;
						B.rotdelay = data.rotdelay;
						B.team = data.team;
						B.shotby = data.shotby;
						if (data.behaviors != null)
						{
							//B.addbehaviors(data.behaviors);
							B.addbehaviors2(data.behaviors);
						}
						//B.HP = data.HP;
						//GameView._this.addDanmakuEntity(B);
						GameView._this.AddObject(B);
						i++;
					}
					done = true;
			case BehaviorType.Die:
				_this.alive = false;
				done = true;
			case BehaviorType.HorizontalAccel:
				if (state == null)
				{
					state = { };
					if (data.maxspeed < _this.Hspeed)
					{
						state.dir = -1;
					}
					else if (data.maxspeed > _this.Hspeed)
					{
						state.dir = 1;
					}
					else
					{
						done = true;
					}
				}
				if (!done)
				{
					if (state.dir==1)
					{
						if (_this.Hspeed < data.maxspeed)
						{
							_this.Hspeed += data.accel;
							if (_this.Hspeed >= data.maxspeed)
							{
								_this.Hspeed = data.maxspeed;
								done = true;
							}
						}
						else
						{
							done = true;
						}
					}
					else if (state.dir==-1)
					{
						if (_this.Hspeed > data.maxspeed)
						{
							_this.Hspeed -= data.accel;
							if (_this.Hspeed <= data.maxspeed)
							{
								_this.Hspeed = data.maxspeed;
								done = true;
							}
						}
						else
						{
							done = true;
						}
					}
				}
				case BehaviorType.VerticalAccel:
				if (state == null)
				{
					state = { };
					if (data.maxspeed < _this.Vspeed)
					{
						state.dir = -1;
					}
					else if (data.maxspeed > _this.Vspeed)
					{
						state.dir = 1;
					}
					else
					{
						done = true;
					}
				}
				if (!done)
				{
					if (state.dir==-1)
					{
						if (_this.Vspeed < data.maxspeed)
						{
							_this.Vspeed += data.accel;
							if (_this.Vspeed >= data.maxspeed)
							{
								_this.Vspeed = data.maxspeed;
								done = true;
							}
						}
						else
						{
							done = true;
						}
					}
					else if (state.dir==1)
					{
						if (_this.Vspeed > data.maxspeed)
						{
							_this.Vspeed -= data.accel;
							if (_this.Vspeed <= data.maxspeed)
							{
								_this.Vspeed = data.maxspeed;
								done = true;
							}
						}
						else
						{
							done = true;
						}
					}
				}
				case BehaviorType.SetQueue:
					_this.behaviorqueue = data.queue;
					if (progressqueue)
					{
						progressqueue = false;
						//counteract progressqueue effect...
						//_this.behaviorqueue--;
					}
					done = true;
				case BehaviorType.ShootDanmakuBullet:
					var S = data.spiral;
					var A = GameView._this.AL.GetAnimation(data.animation);
					var angle = data.angle;
					var B:DanmakuBullet = new DanmakuBullet();
					B.x = _this.x;
					B.y = _this.y;
					B.Vspeed = data.speed;
					B.changeangle(angle);
					B.image.ChangeAnimation(A);
					B.rotrate = data.rotrate;
					B.spiral = S;
					B.rotdelay = data.rotdelay;
					B.team = data.team;
					B.shotby = data.shotby;
					if (data.behaviors != null)
					{
						B.addbehaviors2(data.behaviors);
					}
					//GameView._this.addDanmakuEntity(B);
					GameView._this.AddObject(B);
					done = true;
				case BehaviorType.ShootPlayerAimedDanmakuBullet:
					var S = data.spiral;
					var A = GameView._this.AL.GetAnimation(data.animation);
					//var angle = data.angle;
					var angle = _this.getangletoentity(_this.nearestplayer());
					if (data.angle != null)
					{
						angle += data.angle;
					}
					var B:DanmakuBullet = new DanmakuBullet();
					B.x = _this.x;
					B.y = _this.y;
					B.Vspeed = data.speed;
					B.changeangle(angle);
					B.image.ChangeAnimation(A);
					B.rotrate = data.rotrate;
					B.spiral = S;
					B.rotdelay = data.rotdelay;
					B.team = data.team;
					B.shotby = data.shotby;
					if (data.behaviors != null)
					{
						B.addbehaviors2(data.behaviors);
					}
					//GameView._this.addDanmakuEntity(B);
					GameView._this.AddObject(B);
					done = true;
			case BehaviorType.MoveToX:
				if (state == null)
				{
					state = { };
					if (data.x > _this.x)
					{
						state.dir = -1;
					}
					else if (data.x < _this.x)
					{
						state.dir = 1;
					}
					else
					{
						done = true;
					}
				}
				if (!done)
				{
					if (state.dir==-1)
					{
						
						if (_this.x >= data.x)
						{
							
							if (data.deccel == null)
							{
								done = true;
							}
							else
							{
								_this.Hspeed -= data.accel;
								if (_this.Hspeed <= 0)
								{
									_this.Hspeed = 0;
									done = true;
								}
							}
						}
						else if (_this.Hspeed < data.maxspeed)
						{
							_this.Hspeed += data.accel;
							if (_this.Hspeed >= data.maxspeed)
							{
								_this.Hspeed = data.maxspeed;
								//done = true;
							}
						}
					}
					else if (state.dir==1)
					{
						
						if (_this.x <= data.x)
						{
							if (data.deccel == null)
							{
								done = true;
							}
							else
							{
								_this.Hspeed += data.accel;
								if (_this.Hspeed >= 0)
								{
									_this.Hspeed = 0;
									done = true;
								}
							}
						}
						else if (_this.Hspeed > -data.maxspeed)
						{
							_this.Hspeed -= data.accel;
							if (_this.Hspeed <= -data.maxspeed)
							{
								_this.Hspeed = -data.maxspeed;
								//done = true;
							}
						}
					}
				}
			case BehaviorType.MoveToY:
				if (state == null)
				{
					state = { };
					if (data.y > _this.y)
					{
						state.dir = -1;
					}
					else if (data.y < _this.y)
					{
						state.dir = 1;
					}
					else
					{
						done = true;
					}
				}
				if (!done)
				{
					if (state.dir==-1)
					{
						
						if (_this.y >= data.y)
						{
							if (data.deccel == null)
							{
								done = true;
							}
							else
							{
								_this.Vspeed -= data.accel;
								if (_this.Vspeed <= 0)
								{
									_this.Vspeed = 0;
									done = true;
								}
							}
						}
						else if (_this.Vspeed < data.maxspeed)
						{
							_this.Vspeed += data.accel;
							if (_this.Vspeed >= data.maxspeed)
							{
								_this.Vspeed = data.maxspeed;
								//done = true;
							}
						}
					}
					else if (state.dir==1)
					{
						
						if (_this.y <= data.y)
						{
							if (data.deccel == null)
							{
								done = true;
							}
							else
							{
								_this.Vspeed -= data.accel;
								if (_this.Vspeed <= 0)
								{
									_this.Vspeed = 0;
									done = true;
								}
							}
						}
						else if (_this.Vspeed > -data.maxspeed)
						{
							_this.Vspeed -= data.accel;
							if (_this.Vspeed <= -data.maxspeed)
							{
								_this.Vspeed = -data.maxspeed;
								//done = true;
							}
						}
					}
				}
			case BehaviorType.ShrinkIntoOblivion:
				_this.scaleX -= data.scalerate;
				
				if (_this.scaleX <= 0)
				{
					_this.scaleX = 0;
					_this.alive = false;
					done = true;
				}
				_this.scaleY = _this.scaleX;
			default:
		}
		if (done)
		{
			delay = repeatdelay;
			if (perishable)
			{
				runcount--;
				if (runcount <= 0)
				{
					if (queue == 0)
					{
						if (rechargetime >= 0)
						{
							delay = rechargetime;
							runcount = maxruncount;
						}
						else
						{
							active = false;
						}
					}
					else
					{
						runcount = maxruncount;
						if (progressqueue && queue != 0)
						{
							_this.progressqueue = true;
						}
						else
						{
							if (rechargetime >= 0)
							{
								delay = rechargetime;
							}
							else
							{
								active = false;
							}
						}
					}
				}
			}
			else
			{
				if (progressqueue && queue != 0)
				{
					_this.progressqueue = true;
				}
			}
			if (deathoncomplete)
			{
				_this.alive = false;
			}
			
		}
	}
}