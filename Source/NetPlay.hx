#if flash
package;

import flash.net.NetConnection;
import flash.events.NetStatusEvent;
import flash.net.GroupSpecifier;
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
	//public inline static var _cumulus:         String                      = '***REMOVED***?publish=bob&nearID=a14f2ff6e205acfd0faab0d73fab0ce016b01b3d532aaf0b1ba58332ae810862';
	public inline static var _cumulus:         String                      = '***REMOVED***';
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
							/*if (Connections.length == 1)
							{
								//Connections.remove(0);
								Connections = new Array<Dynamic>();
								
							}
							else*/
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
										Main._this.game.Hoster = true;
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
                                            trace( 'connection made');
                                            trace( ' near id ' + nc.nearID );
                                            trace( ' far id ' + nc.farID );
											NID = ""+nc.nearID;
											var groupSpecifier:GroupSpecifier;
											groupSpecifier = new GroupSpecifier("org.walfasgame.ReimuBros/"+Main._this.gameversion+"/" + Room);
											groupSpecifier.postingEnabled = true;
											groupSpecifier.serverChannelEnabled = true;
											groupSpecifier.routingEnabled = true;
											
											//groupSpecifier.peerToPeerDisabled = false;
											//groupSpecifier.multicastEnabled = true;
											//groupSpecifier.
											
                                            //NG = new flash.net.NetGroup(_nc, "org.reimubrosthing");
											try
											{
												group = new flash.net.NetGroup(_nc, groupSpecifier.groupspecWithoutAuthorizations());
												group.addEventListener(NetStatusEvent.NET_STATUS, NetStatusHandler);
											}
											//groupstarted = true;
                                            //TXT.text = "Success!\n\n\n\n" + ' \nnear id ' + nc.nearID + ' \nfar id ' + nc.farID;
											
                                        case "NetConnection.Connect.Failed":
                                            trace( 'CONNECTION FAIL: change your firewall settings or you are using the wrong key - 90 sec timeout' );
											//TXT.text = 'CONNECTION FAIL: change your firewall settings or you are using the wrong key - 90 sec timeout';
                                    }
                                    
                                }
                            );
                            
        _nc.connect( _cumulus, 100 );
	}
	// Handles all NetStatusEvents for the NetConnection and the NetGroup.
        // This code includes cases it doesn't handle so you can see the cases
        // and their info objects for learning purposes.
        private function NetStatusHandler(e:NetStatusEvent):Void {
			var started:Bool = groupstarted;
			//group.addHaveObjects(
			//group.removeHaveObjects(
			try
			{
				groupstarted = true;
				switch ( e.info.code ) 
                {
                                        
                    case "NetConnection.Connect.Success":
						//TXT.text = "connected!";
											
					case "NetConnection.Connect.Failed":
						//TXT.text = "failed to connect!";
						groupstarted = false;
					case "NetGroup.Connect.Failed":
						//TXT.text = "failed to connect to group!";
					case "NetGroup.Connect.Success":
						//TXT.text = "connected to group";
						
					case "NetGroup.Neighbor.Connect":
						//
						//Test = "" + e.info.peerID;
					case "NetGroup.Neighbor.Disconnect":
						removeplayer("" + e.info.peerID);
						/*if (GameView._this != null)
						{
							GameView._this.RemovePlayer("" + e.info.peerID);
							var i = 0;
							{
							while (i < Connections.length)
							{
								var D = Connections[i];
								if ("" + D.id == "" + e.info.peerID)
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
										Main._this.game.Hoster = true;
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
						}*/
					case "NetGroup.Posting.Notify":
						//OnPosting(e.info.message);
						var A:Array<Dynamic> = e.info.message;
						while (A.length > 0)
						{
							var D:Dynamic = A[0];
							OnPosting(D);
							A.remove(D);
						}
					case "NetGroup.SendTo.Notify":
						//OnPosting(e.info.message);
						var A:Array<Dynamic> = e.info.message;
						while (A.length > 0)
						{
							var D:Dynamic = A[0];
							OnPosting(D);
							A.remove(D);
						}
					
				}
			}
			if (groupstarted && !started)
			{
				if (Main._this.game != null)
				{
					
					var D:Dynamic = { };
					D.id = _nc.nearID;
					D.StartTime = StartTime;
					Connections[0] = D;
					
					Main._this.game.Hoster = false;
					/*D = { };
					D.ElapsedTime = Timer.stamp() - StartTime;
					
					SendData("IAm", ElapsedTime);
					//
					Main._this.game.Hoster = false;
					SendMessage("WhosWho");*/
				}
			}
		}
		//public function SendMessage(message:Dynamic)
		public function SendData(message:String,data:Dynamic)
		{
			if (groupstarted)
			{
			var msg:Dynamic = { };
			msg.text = message;
			msg.data = data;
			//msg.id = _nc.nearID;
			msg.id = NID;
			//group.post(message);
			Queue[Queue.length] = msg;
			//group.post(msg);
			}
		}
		public function SendMessage(message:String)
		{
			if (groupstarted)
			{
			var msg:Dynamic = { };
			msg.text = message;
			msg.data = null;
			//msg.id = _nc.nearID;
			msg.id = NID;
			//group.post(message);
			Queue[Queue.length] = msg;
			//group.post(msg);
			}
		}
		public function Flush()
		{
			/*while (Queue.length > 0)
			{
				var Q = Queue[0];
				group.post(Q);
				Queue.remove(Q);
			}*/
			if (Queue.length>0)
			{
				//post is slower apparently but works outside of neighbors, but neighbors only go up to 14 peers.
				//group.post(Queue);
				group.sendToAllNeighbors(Queue);
				Queue = new Array<Dynamic>();
			}
			
		}
		private function OnPosting(message:Dynamic):Void{
            //StatusMessage("<" + message.user + "> " + message.text + "\n");
			//if (message.id != _nc.nearID)
			//info.peerID
			//GameView._this.TF.text = "peerid:" + Test + "\nnearid:" + message.id;
			
			if ((""+message.id) != (""+_nc.nearID))
			{
			//try
			{
				//GameView._this.TF.text = message.text;
				if (message.text == "UpdateCharacter")
				{
					if (!Announced && groupstarted)
			{
				GameView._this.TF.text = "Announcing!";
				var D:Dynamic = { };
				D.ElapsedTime = Timer.stamp() - StartTime;
					
				SendData("IAm", D);
				//
					
				SendMessage("WhosWho");
				Announced = true;
			}
					//Main._this.control2[2] = message.data;
					var i = message.data;
					//var control2 = GameView._this.control2;
					//var M = GameView._this.marisa;
					var M = GameView._this.GetPlayer(message.id);
					var add = false;
					if (M == null)
					{
						M = new Player(i.charname, new Array<Bool>());
						//M.scaleX = 0.25;
						//M.scaleY = 0.25;
						M.ID = message.id;
						//this might fix the :a bunch of reward spawning issue. so they dont spawn on a glitchy quit scenario
						M.spentscore = i.score;
						
						M.playing = i.playing;
						GameView._this.AddPlayer(M);
					}
					M.controller[0] = i.controller[0];
					M.controller[1] = i.controller[1];
					M.controller[2] = i.controller[2];
					M.controller[3] = i.controller[3];
					M.x = i.x;
					M.y = i.y;
					M.Hspeed = i.Hspeed;
					M.Vspeed = i.Vspeed;
					M.visible = i.visible;
					M.UID = i.UID;
					M.score = i.score;
					M.playername = i.playername;
					M.playing = i.playing;
					M.frame = GameView._this.frame;
					//tries to predict current state of player
					//M.catchupsmall();
					M.catchingup = true;
					M.update();
					//M.update();
					//M.update();
					M.catchingup = false;
				}
				/*if (message.text != "UpdateCharacter")
			{
				GameView._this.TF.text =  message.text;
			}*/
				if (message.text == "WhosWho")
				{
					////GameView._this.TF.text = "Player request!";
					//do not send start time, as that is relative info to client.
					var D:Dynamic = { };
					D.ElapsedTime = Timer.stamp() - StartTime;
					
					SendData("IAm", D);
				}
				if (message.text == "IAm")
				{
					////GameView._this.TF.text = "Recieved announcement!";
					var i = 0;
					while (i < Connections.length)
					{
						if ((""+Connections[i].id) == (""+message.id))
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
						GameView._this.TF.text = "blargen";
						var D:Dynamic = { };
						D.id = message.id;
						D.StartTime = Timer.stamp() - message.data.ElapsedTime;
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
						if (Connections[0].id == ""+_nc.nearID)
						{
							if (Main._this.game != null)
							{
								Main._this.game.Hoster = true;
								Main._this.game.TF.text = "Now Hosting!!!";
							}
						}
						else
						{
							if (Main._this.game != null)
							{
								Main._this.game.Hoster = false;
								Main._this.game.TF.text = "Joined game!";
							}
						}
					}
					
				}
				if (message.text == "GameEvent")
				{
					//GameView._this.ProcessEvent(message.data.evt,message.data.ID, message.data.data);
					GameView._this.ProcessEvent(message.data.evt,message.id, message.data.data);
				}
				//Main._this.TF.text = message.text;
				
				//TXT.text = TXT.text = "\n" + "<" + message.user + "> " + message.text;
			}
			}
        }
}
#end