#if flash
package;

import flash.net.NetConnection;
import flash.events.NetStatusEvent;
import flash.net.GroupSpecifier;
import lime.Assets;
import haxe.Timer;

/**
 * ...
 * @author RSGmaker
 */
class NetPlay
{

	private var _nc:                            NetConnection;
	public var groupstarted:Bool;
	public var group:flash.net.NetGroup;
	public var started:Bool;
	//Your rtmfp url, we use the cirrus service, if you need your own urlkey get it at:https://www.rtmfp.net/cgi-bin/cirrusdevkey
	public var _cumulus:String="";
	public var ElapsedTime:Float;
	public var StartTime:Float;
	public var Connections:Array<Dynamic>;
	public var NID:String;
	public var Name:String;
	public var Test:String;
	public var Queue:Array<Dynamic>;
	//whether or not this client ever posted a "WhosWho" or "IAm" yet
	public var Announced:Bool;
	public var Room:String;
	public var game:GameView;
	
	public var running:Bool;
	public var error:String;
	
	public function new() 
	{
		_nc = null;
		StartTime = Timer.stamp ();
		Connections = new Array<Dynamic>();
		Announced = false;
		NID = "Unknown";
		Test = "???";
		Room = "Lobby";
		Queue = new Array<Dynamic>();
		if (Assets.exists("assets/Key.txt"))
		{
			//use a cirrus rtmfp service (requires a key), if you've cloned/copied this source code, get a key from:https://www.rtmfp.net/cgi-bin/cirrusdevkey and put it in assets/key.txt
			_cumulus = "rtmfp://p2p.rtmfp.net/"+Assets.getText("assets/Key.txt")+"/";
		}
		else if (_cumulus == "")
		{
			trace("netplay is missing an rtmfp url,netplay cannot function without it");
			error = "This version of ReimuBros is not configured properly for multiplayer, let the author of this build know.";
		}
		error = "";
		running = false;
	}
	public function end()
	{
		if (group != null)
		{
			group.removeEventListener(NetStatusEvent.NET_STATUS, NetStatusHandler);
			group.close();
			
		}
		if (_nc != null)
		{
			_nc.close();
		}
	}
	public function removeplayer(ID:String)
	{
		if (GameView._this != null)
						{
							GameView._this.RemovePlayer("" + ID);
							var i = 0;
							{
							while (i < Connections.length)
							{
								var D = Connections[i];
								if ("" + D.id == "" + ID)
								{
									Connections.remove(D);
									i -= 1;
									if (Connections[0].id == "" + _nc.nearID)
									{
										if (Main._this.game.Hoster)
										{
											Main._this.game.TF.text = "Client Left";
										}
										else
										{
											Main._this.game.TF.text = "Became\nHoster!";
										}
										var H = game.Hoster;
										Main._this.game.Hoster = true;
										if (H != Main._this.game.Hoster)
										{
											game.ShowLevel(false);
										}
										Main._this.game.TF.text = "Became/remained\nHoster!";
									}
									else
									{
										Main._this.game.TF.text = "User Left";
									}
								}
								i += 1;
							}
							}
						}
	}
	public function start()
	{
		game = GameView._this;
		started = true;
        _nc     = new NetConnection();
        var nc = _nc;
        _nc.addEventListener( 
                                NetStatusEvent.NET_STATUS, 
                                function( e: NetStatusEvent )
                                {
                                    
                                    switch ( e.info.code ) 
                                    {
                                        
                                        case "NetConnection.Connect.Success":
											var R = "org.walfasgame.ReimuBros/" + Main._this.gameversion + "/" + Room;
                                            //trace( 'connected!, moving to:'+R);
											trace( 'connected to room:'+R);
                                            trace( ' near id ' + nc.nearID );
                                            trace( ' far id ' + nc.farID );
											NID = ""+nc.nearID;
											var groupSpecifier:GroupSpecifier;
											groupSpecifier = new GroupSpecifier(R);
											groupSpecifier.postingEnabled = true;
											groupSpecifier.serverChannelEnabled = true;
											groupSpecifier.routingEnabled = true;
											
											groupSpecifier.peerToPeerDisabled = false;
											groupSpecifier.multicastEnabled = true;
											//groupSpecifier.ipMulticastMemberUpdatesEnabled = true;
											
											try
											{
												group = new flash.net.NetGroup(_nc, groupSpecifier.groupspecWithoutAuthorizations());
												group.addEventListener(NetStatusEvent.NET_STATUS, NetStatusHandler);
												running = true;
											}
											
											
                                        case "NetConnection.Connect.Failed":
											trace("CONNECTION FAIL: change your firewall settings or you are using the wrong key");
											running = false;
											error = "Connection failed, check firewall settings.\nDetails:"+e.info.details;
										case "NetGroup.Connect.Rejected":
											trace("CONNECTION REJECTED");
											running = false;
											error = "Connection rejected.\nDetails:"+e.info.details;
                                            //trace( 'CONNECTION FAIL: change your firewall settings or you are using the wrong key - 90 sec timeout' );
                                    }
                                    
                                }
                            );
        try
		{
        _nc.connect( _cumulus, 100 );
		}
		catch(e:Dynamic)
		{
			trace("CONNECTION Error");
			running = false;
			error = "An error has occured while establishing connection.";
		}
	}
	// Handles all NetStatusEvents for the NetConnection and the NetGroup.
        // This code includes cases it doesn't handle so you can see the cases
        // and their info objects for learning purposes.
        private function NetStatusHandler(e:NetStatusEvent):Void {
			var started:Bool = groupstarted;
			try
			{
				var G = groupstarted;
				groupstarted = true;
				//trace(e.info.code);
				switch ( e.info.code ) 
                {
                                        
                    case "NetConnection.Connect.Success":
							//running = true;
					case "NetConnection.Connect.Failed":
						groupstarted = false;
						error = "error:server connect.\nDetails:"+e.info.details;
					case "NetGroup.Connect.Failed":
						groupstarted = false;
						error = "error:session connect.\nDetails:"+e.info.details;
					case "NetGroup.Connect.Success":
						//running = true;
					case "NetGroup.Neighbor.Connect":
						Flush();
					case "NetGroup.Neighbor.Disconnect":
						removeplayer("" + e.info.peerID);
						
					case "NetGroup.Posting.Notify":
						var A:Array<Dynamic> = e.info.message;
						var i = 0;
						while (/*A.length > 0*/ i<A.length)
						{
							var D:Dynamic = A[i];
							OnPosting(D);
							//A.remove(D);
							i++;
						}
					case "NetGroup.SendTo.Notify":
						var A:Array<Dynamic> = e.info.message;
						var i = 0;
						while (/*A.length > 0*/ i<A.length)
						{
							var D:Dynamic = A[i];
							OnPosting(D);
							//A.remove(D);
							i++;
						}
					default:
						groupstarted = true;
				}
				/*if (!G && groupstarted)
				{
					Flush();
				}*/
			}
			if (groupstarted && !started)
			{
				if (Main._this.game != null && Main._this.game.NP == this)
				{
					
					var D:Dynamic = { };
					D.id = _nc.nearID;
					D.StartTime = StartTime;
					Connections[0] = D;
					
					Main._this.game.Hoster = false;
					
					Main._this.game.ShowLevel(false);
				}
			}
		}
		public function SendData(message:String,data:Dynamic)
		{
			//if (groupstarted)
			{
			var msg:Dynamic = { };
			msg.t = message;
			msg.d = data;
			msg.i = NID;
			Queue[Queue.length] = msg;
			}
		}
		public function SendMessage(message:String)
		{
			//if (groupstarted)
			{
			var msg:Dynamic = { };
			msg.t = message;
			msg.d = null;
			msg.i = NID;
			Queue[Queue.length] = msg;
			}
		}
		public function Flush()
		{
			if (Queue.length>0)
			{
				//post is slower apparently but works outside of neighbors, but neighbors only go up to 14 peers.
				//group.post(Queue);
				if (running)
				{
					//if (Main._this.game != null && Main._this.game.NP == this)
					if (true)
					{
						group.sendToAllNeighbors(Queue);
					}
					else
					{
						group.post(Queue);
					}
				}
				Queue = new Array<Dynamic>();
			}
			
		}
		private function GamePost(message:Dynamic)
		{
			if ((""+message.i) != (""+_nc.nearID))
			{
			//try
			{
				if (message.t == "U")
				{
					if (!Announced && groupstarted)
			{
				//GameView._this.TF.text = "Announcing!";
				var D:Dynamic = { };
				D.ElapsedTime = Timer.stamp() - StartTime;
					
				SendData("IAm", D);
				//
					
				SendMessage("WhosWho");
				Announced = true;
			}
					var i = message.d;
					var M = game.GetPlayer(message.i);
					var add = false;
					var soul = "";
					if (i.sl != null)
					{
						soul = i.sl;
					}
					if (M == null)
					{
						if (i.nm != null)
						{
							
						M = new Player(i.ch, new Array<Bool>(),soul);
						M.ID = message.i;
						//this might fix the :a bunch of reward spawning issue. so they dont spawn on a glitchy quit scenario
						M.spentscore = i.sc;
						M.playing = i.F;
						game.AddPlayer(M);
						}
					}
					if (M != null)
					{
						if (i.nm != null)
						{
							if (i.ch != M.charname)
							{
								M.init(i.ch);
							}
						}
					M.frame = game.frame;
					M.controller[0] = i.cn[0];
					M.controller[1] = i.cn[1];
					M.controller[2] = i.cn[2];
					M.controller[3] = i.cn[3];
					M.x = i.x;
					M.y = i.y;
					M.Hspeed = i.H;
					M.Vspeed = i.V;
					//M.visible = i.visible;
					
					
					if (i.nm != null)
					{
					M.UID = i.ID;
					M.playername = i.nm;
					M.score = i.sc;
					}
					M.playing = i.F;
					M.frame = game.frame;
					
					//tries to predict current state of player
					//M.catchupsmall();
					M.catchingup = true;
					M.update();
					//M.update();
					//M.update();
					M.catchingup = false;
					}
				}
				/*if (message.text != "UpdateCharacter")
			{
				GameView._this.TF.text =  message.text;
			}*/
				if (message.t == "WhosWho")
				{
					////GameView._this.TF.text = "Player request!";
					//do not send start time, as that is relative info to client.
					var D:Dynamic = { };
					D.ElapsedTime = Timer.stamp() - StartTime;
					
					SendData("IAm", D);
				}
				if (message.t == "IAm")
				{
					var i = 0;
					while (i < Connections.length)
					{
						if ((""+Connections[i].id) == (""+message.i))
						{
							i = Connections.length + 2;
						}
						else
						{
							i += 1;
						}
						
					}
					if (i != Connections.length + 2)
					{
						//GameView._this.TF.text = "blargen";
						var D:Dynamic = { };
						D.id = message.i;
						D.StartTime = Timer.stamp() - message.d.ElapsedTime;
						Connections[Connections.length] = D;
						Connections.sort(function(a:Dynamic, b:Dynamic):Int{
							if (a.StartTime < b.StartTime) return -1;
							if (a.StartTime > b.StartTime) return 1;
							//if times are exactly the same somehow, then default to ids
							a = a.id.a.toLowerCase();
							b = b.id.b.toLowerCase();
							if (a < b) return -1;
							if (a > b) return 1;
							return 0;
							} );
						var H = Main._this.game.Hoster;
						if (Connections[0].id == ""+_nc.nearID)
						{
							if (Main._this.game != null)
							{
								Main._this.game.Hoster = true;
								if (H != Main._this.game.Hoster)
								{
									game.ShowLevel(false);
								}
								//Main._this.game.TF.text = "Now Hosting!!!";
							}
						}
						else
						{
							if (Main._this.game != null)
							{
								Main._this.game.Hoster = false;
								if (H != Main._this.game.Hoster)
								{
									game.ShowLevel(false);
								}
								//Main._this.game.TF.text = "Joined game!";
							}
						}
					}
					
				}
				if (message.t == "E")
				{
					game.ProcessEvent(message.d.evt,message.i, message.d.data);
				}
				if (message.t == "Q")
				{
					game.ProcessQueueEvent(message.d.evt,message.i, message.d.data,message.d.timer);
				}
			}
			}
		}
		public function dolobbyannounce()
		{
			var D:Dynamic = { };
			D.room = Main._this.Room;
			//D.room = Main._this.roomprefix + "_" + Main._this.Room;
			D.players = Main._this.game.GetPlayers().length;
			SendData("Roomreport", D);
			Flush();
		}
		private function OnPosting(message:Dynamic):Void{
			if (message.t == "ping")
			{
				if (Main._this.game != null && Main._this.game.Hoster && !Main._this.customroom)
				{
					dolobbyannounce();
				}
				//trace("ping!");
			}
			if (message.t == "Roomreport" && Main._this.characterselect != null)
			{
				var C = Main._this.characterselect;
				C.roomreport(message.d);
				
			}
			if (Main._this.game != null && Main._this.game.NP == this)
			{
				GamePost(message);
			}
        }
}
#end